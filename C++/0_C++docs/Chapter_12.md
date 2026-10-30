# Class and Dynamic Memory Allocation

## Dynamic Memory and Classes
- C++ lets the program decide about memory **during runtime** rather than compile time
- Memory use can depend on the **needs of a program** instead of on a set of storage-class rules
- To gain **dynamic control** of memory, use `new` and `delete` operators, which can cause some problems, and the destructors can be necessary in these matters

### A Review Example of Static Class Members
Source code: `C12_Classdynamic`
```C++
/*****stringbad.h*****/
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>

class stringbad{
	private:
		char* str; // not allocate storage space
		int len;
		static int num_str;
	public:
		stringbad(const char* str);
		stringbad(void); ~stringbad(void);
		friend std::ostream& 
		operator<<(std::ostream& os, const stringbad& stb);
};

#endif

/*****stringbad.cpp*****/
#include <cstring>
#include "stringbad.h"

int stringbad::num_str = 0; // initialization

stringbad::stringbad(const char* s){
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	num_str++;

	std::cout << num_str << ": \"" 
		      << str << "\" object created\n";
}

stringbad::stringbad(void){
	++num_str;
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");

	std::cout << num_str << ": \"" 
		      << str << "\" default object created\n";
}

stringbad::~stringbad(void){
	--num_str;
	std::cout << "\"" << str << "\" object deleted, "
	          << num_str << " objects left\n";
	delete [] str;
}

std::ostream& 
operator<<(std::ostream& os, const stringbad& stb){
	os << stb.str;
	return os;
}

/*****usebad.cpp*****/
#include <iostream>
#include "stringbad.h"

inline void call1(stringbad& rst){
	std::cout << "String passed by reference: \n" 
		      << "\t\"" << rst << "\"\n";
}

inline void call2(stringbad st){
	std::cout << "String passed by value: \n" 
		      << "\t\"" << st << "\"\n";
}

int main(void){

	std::cout << "Let us start!\n";

	stringbad h1("Celery Stalks at Midnight");
	stringbad h2("Lettuce Prey");
	stringbad h3("Spinach Leaves Bowl for Dollars");
	std::cout << "h1: " << h1 << std::endl;
	std::cout << "h2: " << h2 << std::endl;
	std::cout << "h3: " << h3 << std::endl;
	std::cout << std::endl;

	call1(h1);
	std::cout << "h1: " << h1 << std::endl;
	call2(h2);
	std::cout << "h2: " << h2 << std::endl;
	std::cout << std::endl;

	std::cout << "Initialize one object to another:\n";
	stringbad h4 = h3;
	std::cout << "h4: " << h4 << std::endl;
	std::cout << "Assign one object to another:\n";
	stringbad h5;
	h5 = h1;
	std::cout << "h5: " << h5 << std::endl;
	std::cout << "End!\n";
	std::cout << std::endl;

	return 0;
}

```
- A new storage class: the `static` class member
- A program creates **only one copy** of a static class variable, **regardless of the number of objects created**
- The `static` member **is shared among all objects**, initialize it in a source code
- Use `new` to construct an object, use `delete` in the destructor!
- Initialize it independently, with separate statements outside the class declaration, and in the source file
- The `static` member is **stored separately rather than as part of an object**, and **initialize it without the keyword `static`**
> - Don't initialize a `static` data member inside the class declaration unless it is `const`!
- Remember, `char*` points to a `char` variable, or **the first character of a string**, we can pass a **string pointer** to it like `NAME obj1("obj1")` if using the constructor `NAME::NAME(const char* s)`
- Also remember `strlen()` returns the length of a string **not counting the `\0` character**, and the member stores the address, while the string itself is **stored in heap memory separately**
- For `strcpy(c,"IAM")`, there are **two variables** storing the same `"IAM"`, one is `c`, the other is a **string literal** with `const char[4]` type
- To manifest the destructor in windows(fuck the microsoft), we may declare the objects within an **inner block**, like `{NAME::obj;}`

```Console
Let us start!
1: "Celery Stalks at Midnight" object created
2: "Lettuce Prey" object created
3: "Spinach Leaves Bowl for Dollars" object created
h1: Celery Stalks at Midnight
h2: Lettuce Prey
h3: Spinach Leaves Bowl for Dollars

String passed by reference:
        "Celery Stalks at Midnight"
h1: Celery Stalks at Midnight
String passed by value:
        "Lettuce Prey"
"Lettuce Prey" object deleted, 2 objects left
h2: }

Initialize one object to another:
h4: Spinach Leaves Bowl for Dollars
Assign one object to another:
3: "C++" default object created
h5: Celery Stalks at Midnight
End!

"Celery Stalks at Midnight" object deleted, 2 objects left
"Spinach Leaves Bowl for Dollars" object deleted, 1 objects left
"([W" object deleted, 0 objects left
free(): double free detected in tcache 2
Aborted (core dumped)
```

## The New, Improved `String` Class

## Things to Remember When Using `new` in Constructors

## Observations About Returning Objects

## Using Pointers to Objects

## Reviewing Techniques

## A Queue Simulation
