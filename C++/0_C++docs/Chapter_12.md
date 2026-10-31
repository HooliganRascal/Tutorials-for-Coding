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
		stringbad(void); 
        ~stringbad(void);
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
- In this case, some flaws pop out
    - One is the non-standard character
    - Another is the *Gerneral Protection Fault*, or displaying the negative counts, **it tried to access a memory location forbidden to it**
- The default copy constructor:
    - When using `NAME obj1 = obj2`, it is the same as `NAME obj1 = NAME(obj2)`
    - The automatically generated `NAME(const NAME& obj)` is the **copy constructor**
    - It makes a copy of an object while it would not know about updating the `static` member!
- All the problems exhibited stem from **member functions that the compiler generated automatically**

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

### Special Member Functions
- Member functions defined automatically
    - Default constructor if we define no constructor
    - Default destructor if we don't define one
    - Copy constructor if we don't define one
    - Assignment operator if we don't define one
    - An address operator if we don't define one
- Implicit **address operator** returns the **address of the invoking object**, which is the **value of `this` pointer**
- C++11 provided two more special member fucntions: *move constructor* and *move assignment operator*, see in [Chapter\_18](Chapter_18.md)
- Implicit default constructor: `NAME::NAME(void){}`
    - Its value at initialization is unknown
    - Define a default constructor without any parameters: `NAME(void){member1 = val1;}`
    - Define a default constructor if all the parameters have **default values** like `NAME(int n=1){member1 = val1;}`
    - We can have **only one default constructor**
- Copy constructor:
    - Used to copy an object to a **newly created object**, which is, during **initialization** like `NAME obj1 = obj2`
    - Typical ways: 
        - `NAME obj2(obj1);`
        - `NAME obj2 = obj1;`, could use a copy constructor to directly create `obj2`, or generate *temporary object* whose contents are then assigned to `obj2`
        - `NAME obj2 = NAME(obj1);`, same condition as `NAME obj2 = obj1`
        - `NAME* po2 = new NAME(obj1)`, allocate memory and initialize an **anonymous object** to `obj1`, assign the address of the new object to `po2`
    - Less obviously, it is used when the compiler generates copies of an object, like calling `fun(const NAME obj)`, which **passes an object by value**, it is better to pass by **reference** instead
    - Also used when **generating temporary objects**
- Default constructor does:
    - Member-to-member copy of the **non-static members**
    - Membewise copying, shallow copying, each member **copied by value**, if a member itself is a class member, **the copy constructor for that class** is used to copy one member object to another
    - **Static members are unaffected** when using default copy constructors, which **belong to the class as a whole**
    - It does the copying, rather than constructing
### Where the Copy Constructor Goes Wrong and Fix It
- The premier program goes wrong for the default *copy constructor*
- When default copy constructor is called **implicitly** and makes **two pointers pointing to the same stuff**, the destrcutor freed the **same memory location twice while the second one freed nothing**, which is dangerous! It is undefined, causing *memory mismanagement*!
- To solve it, create an explicit copy constructor!
- If a class contains members that are pointers initialized by `new`, define a copy constructor copying the **point-to** data rather than copying the pointer itself, called *deep copying*, and the regularly *memberwise copying* just copies the value of a pointer

### Assignment Operators
- Class object assignment:
    - C++ automatically **overloads an assignment operator** for a class, like `NAME& NAME::operator=(const NAME&)`
    - Used when assigning one object to another existing object
- When initializing an object, it could use the **default constructor, the default copy constructor building a temporary object with overloaded assignment operator, or just the default copy constructor**!
- The problem is still the memberwise copying! It assigns the address of a string to two different pointers, and the same memory location is **freed contents for twice**!
- Solution; define a self-defined overloaded assignment operator
    - Use `delete []` to **free former obligations**
    - Protect against assigning object to itself
    - Returns a **reference to the invoking object**
- Sample: `NAME& NAME::operator=(const NAME& obj1){return *this)`
- Assigning does not create a new object, it is created when the assigning object is initialized
## The New, Improved `stringgood` Class
Source code: `C12_Classdynamic`
```C++
/*****stringgood.h*****/
#ifndef STRINGGOOD_H_
#define STRINGGOOD_H_
#include <iostream>

class stringgood
{
private:
	char* str;
	int len;
	static int num_str;
	static const int LIM = 80;
public:
	stringgood(const char* s);
	stringgood(const stringgood& obj); // copy constructor
	stringgood(void); 
	~stringgood(void);

	inline int length(void){return len;}

	stringgood& operator=(const stringgood& obj);
	stringgood& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	friend bool 
		operator<(const stringgood& st1,const stringgood& st2); 
	friend bool 
		operator>(const stringgood& st1,const stringgood& st2); 
	friend bool 
		operator==(const stringgood& st1,const stringgood& st2); 
	friend std::ostream& 
		operator<<(std::ostream& os, const stringgood& obj);
	friend std::istream& 
		operator>>(std::istream& is, stringgood& obj);

	static int howmany(void);
};

#endif

/*****stringgood.cpp*****/
#include <cstring>
#include <iostream>
#include "stringgood.h"

int stringgood::num_str = 0; // static member
int stringgood::howmany(void){
	return num_str;
} // static member function

stringgood::stringgood(const char* s){
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	num_str++;
}

stringgood::stringgood(void){
	++num_str;
	len = 1;
	str = new char[1];
	str[0] = '\0'; // or str = nullptr
}

stringgood::stringgood(const stringgood& obj){
	++num_str;
	len = obj.len;
	str = new char[len+1];
	std::strcpy(str, obj.str);
}// copy constructor

stringgood::~stringgood(void){
	--num_str;
	delete [] str;
}


stringgood& stringgood::operator=(const stringgood& obj){
	if(this == &obj)
		return *this;
	delete [] str;
	len = obj.len;
	str = new char[len+1];
	std::strcpy(str, obj.str);
	return *this;
}

stringgood& stringgood::operator=(const char* s){
	delete [] str;
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	return *this;
}

char& stringgood::operator[](int i){
	return str[i];
}

const char& stringgood::operator[](int i) const{
	return str[i];
}


bool operator<(const stringgood& st1,const stringgood& st2){
	return (std::strcmp(st1.str, st2.str)<0);
}
bool operator>(const stringgood& st1,const stringgood& st2){
	return (st2<st1);
}
bool operator==(const stringgood& st1,const stringgood& st2){
	return (std::strcmp(st1.str, st2.str)==0);
}

std::ostream& 
operator<<(std::ostream& os, const stringgood& obj){
	os << obj.str;
	return os;
}

std::istream& 
operator>>(std::istream& is, stringgood& obj){
	char temp[stringgood::LIM];
	is.get(temp, stringgood::LIM);
	if(is)
		obj = temp;
	while(is && (is.get()!='\n'))
		continue;
	return is;
}

/*****usegood.cpp*****/
#include <iostream>
#include "stringgood.h"

const int arsize = 10;
const int maxlen = 81;

int main(void)
{
	stringgood name;
	stringgood sayings[arsize];
	char temp[maxlen];
	int i, total;

	std::cout << "Hi, what is your name?\n>> ";
	std::cin >> name;
	std::cout << name << ", please enter up to "
			  << arsize << " short saying <enter to quit>:\n";
	
	for(i=0; i<arsize; ++i)
	{
		std::cout << i+1 << ": ";
		std::cin.get(temp,maxlen);
		while(std::cin && (std::cin.get()!='\n'))
			continue; // clear up the queue
		if(!std::cin || (temp[0]=='\0')) // test empty line
			break;
		else
			sayings[i] = temp;
	}

	total = i;

	if(total > 0)
	{
		std::cout << "Here are your sayings:\n";
		for(i=0; i<total; ++i)
		{
			std::cout << sayings[i][0] << ": " 
					  << sayings[i] << "\n";
		}

		int shortest = 0;
		int first = 0;
		for(i=1; i<total; ++i)
		{
			if(sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if(sayings[i] < sayings[first])
				first = i;
		}

		std::cout << "Shortest saying:\n"
				  << sayings[shortest] << "\n";
		std::cout << "First saying:\n"
				  << sayings[first] << "\n";
	}
	else
		std::cout << "No input! Bye.\n";

	return 0;
}

```
- Add the copy constructor and the overloaded assignment operator
- Mute the class constructors and destructors
- Simplify the default constructor
- Add some capabilities:
    - `int length(void) const)`
    - `friend bool operator<(const NAME&, const NAME&)`
    - `friend std::istream& operator>>(std::istream&, const NAME&)`
    - `char& operator[](int i)`, alterable version
    - `const char& operator[](int i) const`, protection
    - `static int howmany(void)`
- Null pointer in C++11:
    - Use `str=new char[1]; str[0] = '\0';` is the same as `str = 0`
    - Some C++98 uses `(void*) 0` to represent the **null pointer**
    - Better solution: `str = nullptr`
- Comparison:
    - `strcmp(str1, str2)`
    - Negative value if **the first argument of `str1` precedes `str2` alphabetically**
    - `0` if it is the same
    - Positive value if **the first argument of `str1` follows `str2` alphabetically**
- Static member function:
    - Does not have to be invoked by an object
    - Does not even get a `this` pointer to play with
    - If declared in `public` section, like `static int fun(){return val;}`, free to use `int count = NAME::fun();`
    - The only data members it could use are the `static` data members
    - It can **control the formatting** used by a method that displays class contents
- Further assignment operator overloading: to save compiling time
- For `>>` overloading, objects of `istream` class returns `false`:
    - Input failed
    - `get(char[], int)` reads an **empty line**
    - For older version, the first character is `\0` if an empty line is entered with `get(char[], int)`
    - For `get(char*, int)`, we type `abc<enter>xyz<enter>`, the `abe\0` is input, and the `\nxyz\n` stays in the buffer
> - `static` members in `private` section could be defined outside the class declaration as an exception, normally it is not allowed to directly access the `private` member function

```Console
Hi, what is your name?
>> Mteltn
Mteltn, please enter up to 10 short saying <enter to quit>:
1: A fool and his money are soon parted
2: Penny wise, pound foolish
3: The love of money is the root of much evil
4: Out of sight, out of mind
5: Absence makes the heart grow fonder
6: Absinthe makes the hart grow fonder
7:
Here are your sayings:
A: A fool and his money are soon parted
P: Penny wise, pound foolish
T: The love of money is the root of much evil
O: Out of sight, out of mind
A: Absence makes the heart grow fonder
A: Absinthe makes the hart grow fonder
Shortest saying:
Penny wise, pound foolish
First saying:
A fool and his money are soon parted
```

## Things to Remember When Using `new` in Constructors

## Observations About Returning Objects

## Using Pointers to Objects

## Reviewing Techniques

## A Queue Simulation
