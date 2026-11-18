# Reusing Code in C++
---
## Classes with Object Members
- Class including class objects as members
- Simplifying a student to a name and a set of quiz scores 
- To represent a name, simply use `string` class
- To represent the quiz scores, use fixed-size array, or simpler, use a **suitable class** to represent the data

### The `valarray` Class: A Quick Look
- Targeted to deal with **numeric values**(or with classes **with similar properties**), supporting operations like summing and finding the largest
- Defined as a **template class**
    - We have to provide a specific type when declaring an object like `valarray<int> num`
    - The `vector` and `array` class works the same
    - Create an empty array of zero size: `valarray<double> test;`
    - Create an empty array of given size: `valarray<double> v2(8);`
    - Create an array of **given size(8) each set to the same(1)**: `valarray<double> v2(1,8);`
    - Create an array initialized using the value from an **ordinary array**: `double a[5] = {...}; valarray<double> v3(a,4);`
    - In C++11: `valarray<int> v5 = {20,10,12};`
- Methods: 
    - `operator[]()` access individual elements
    - `size()` returns the number of elements
    - `sum()` returns the sum of the elements
    - `max()`, `min()` are obvious

### The `STUDENT` Class Design
- Use a `string` object to represent the name, and a `valarray<double>` object to represent the quiz scores
- Multiple `public` inheritance is allowed, but not suitable here
- Here is a *has-a* relationship, a student **has a name** and **has an array of quiz scores**
- Create a class **composed of members that are objects of another class**
- Example: `class STUDENT{private: string name; valarray<double> scores...};`
- Usually the data members are `private`, thus class `STUDENT` must use the **`public` interfaces** of class `string` and `valarray<double>` to access and modify the `name` and `scores` **internally**
- The outside world will have the access to `name` and `scores` only through the **`public` interface defined for `STUDENT` class**, for example, not directly using `STUDENT s1; s1.sum()` where `sum()` is from class `valarray<double>`
- The `STUDENT` class acquires the **implementation of its member objects** but **not inherit the interface**
- `public` inheritance: *is-a* relationship, inherits an interface and an implementation(perhaps)
- *Has-a* relationship: acquiring the implementation without an interface, **not inheriting the interface**
- To use `operator<()`, define a `STUDENT::operator<()` member function internally uses the `string::operator<()`

### The `STUDENT` Class Example
Source code: `C14_Classcontain`
```C++
/*****student.h*****/
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <cstring>
#include <valarray>

class STUDENT
{
private:
	typedef	std::valarray<double> ARRAYDB;
	std::string name;
	ARRAYDB scores;

	// helper function
	std::ostream& array_out(std::ostream& os) const;

public:
	explicit inline STUDENT(const std::string& s) 
		: name(s), scores(){};
	explicit inline STUDENT(int n) 
		: name("NULL"), scores(n){};
	inline STUDENT(void) 
		: name("NULL"), scores(){};
	inline STUDENT(const std::string& s, int n) 
		: name(s), scores(n){};
	inline STUDENT(const std::string& s, const ARRAYDB& a) 
		: name(s), scores(a){};
	inline STUDENT(const char* str, const double* pd, int n) 
		: name(str), scores(pd,n){};
	inline ~STUDENT(void){};

	const std::string& NAME(void) const;
	double AVG(void) const;
	double& operator[](int i); // for STUDENT as lvalue
	double operator[](int i) const; // for const STUDENT

	friend std::istream& operator>>
		(std::istream& is, STUDENT& stu); // 1 word
	friend std::istream& getline
		(std::istream& is, STUDENT& stu); // 1 line
	friend std::ostream& operator<<
		(std::ostream& os, const STUDENT& stu);
};

#endif

/*****student.cpp*****/
#include "student.h"

// private method
std::ostream& STUDENT::array_out(std::ostream& os) const
{
	int i;
	int lim = scores.size();
	if(lim > 0)
	{
		for(i=0; i<lim; ++i)
		{
			os << scores[i] << " ";
			if(i%5==4) // display 5 grades for one row
				os << std::endl;
		}
		// if right at 5 grades, endl is up there, else newline
		if(i%5!=0) 
			os << std::endl;
	}
	else
		os << " empty array " ;
	return os;
}

// public method
const std::string& STUDENT::NAME(void) const
{
	return name;
}

double STUDENT::AVG(void) const
{
	if(scores.size()>0)
		return scores.sum()/scores.size();
	else
		return 0; // size error
}

double& STUDENT::operator[](int i)
{
	// matching return type of valarray<double>::operator[]()
	return scores[i]; 
}

double STUDENT::operator[](int i) const // for const STUDENT
{
	return scores[i];
}

// friend functions
std::istream& operator>>(std::istream& is, STUDENT& stu)
{
	is >> stu.name;
	return is;
}

std::istream& getline(std::istream& is, STUDENT& stu)
{
	getline(is,	stu.name);
	return is;
}

std::ostream& operator<<(std::ostream& os, const STUDENT& stu)
{
	os << "Scores for " << stu.name << ":\n";
	stu.array_out(os);
	return os;
}

/*****usestudent.cpp*****/
#include <iostream>
#include "student.h"

void SET(STUDENT& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main(void)
{
	STUDENT ada[pupils] = 
	{
		STUDENT(quizzes), 
		STUDENT(quizzes), 
		STUDENT(quizzes)
	};

	for(int i=0; i<pupils; ++i)
		SET(ada[i], quizzes);

	std::cout << "\nStudent List:\n";
	for(int i=0; i<pupils; ++i)
		std::cout << ada[i].NAME() << std::endl;

	std::cout << "\nResults:";
	for(int i=0; i<pupils; ++i)
	{
		std::cout << "\n" << ada[i];
		std::cout << "Average: " << ada[i].AVG() << "\n";
	}

	std::cout << "Done!\n";
	return 0;
}

void SET(STUDENT& sa, int n)
{
	std::cout << "Please enter the student's name: ";
	getline(std::cin, sa);
	std::cout << "Please enter " << n << " quiz scores:\n";
	for(int i=0; i<n; ++i)
		std::cin >> sa[i];
	while(std::cin.get()!='\n')
		continue; // clear out input queue
}

```
- Make some `inline` `public` interfaces
- Define all the constructors `inline`
- Use `typedef` in the `private` portion of the definition to get a **`class` scope**
- Remember constructor can be called with **one argument** serves as an **implicit conversion function from the argument type to class type**
- `(int n): scores(n)` represents the number of elements in an array rather than a value! Use `explicit` to turn off implicit conversions!
- Use `explicit` and `const` to constrain the use of methods to modify data, **compile-time errors are better than runtime errors!**
- For *inherited* objects, constructors use the **class** name in the **member initializer list** to invoke a specific base-class constructor
- For *member* objects, constructors use the **member** name like `(const char* str): name(str);` matching constructor `string(const char*)`
- If we don't use the **member initializer list**, the member objects uses the **default constructors** defined for the member objects' classes
- Initialization order: in order in which **the items were declared** rather than in which they appear in the initialization list
- Using an interface for a contained object
    - Not `public`, but can be used within the class methods
    - The object invokes a its class method, and the method uses the contained `valarray` object to invoke `valarray` methods
    - Similarly, `friend` function can also work like this
    - For class **without the implementation** of output or others, use a **helper function** in the `private` portion to handle the task like `array_out()` in this case
- Using containment allows use to take advantage of the code someone else has already written
- For operator overloading, remember to provide double version, one is for `const STUDENT` object, another for `STUDENT` object, **each can not call the methods crossly**!
- `friend` functions must be placed **inside the definition of the class** and **not affected by access control** like `private` or `public`
- Remember the input using `cin` stays in buffer until the `Enter` is typed, it needs a **quit sign** like `while(ch!='#'){std::cin>>ch;}`

```Console
Please enter the student's name: Gil Bayts
Please enter 5 quiz scores:
92 94 96 93
95
Please enter the student's name: Pat Roone
Please enter 5 quiz scores:
83 89 72 78 95
Please enter the student's name: Fleur O'Day
Please enter 5 quiz scores:
92 89 96 74 64

Student List:
Gil Bayts
Pat Roone
Fleur O'Day

Results:
Scores for Gil Bayts:
92 94 96 93 95
Average: 94

Scores for Pat Roone:
83 89 72 78 95
Average: 83.4

Scores for Fleur O'Day:
92 89 96 74 64
Average: 83
Done!
```
## `private` Inheritance

