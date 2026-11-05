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
- Default copy constructor does:
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
	str[0] = '\0'; // or str = nullptr, or str = 0
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
- Be cautious about using `new` to initialize pointer members of an object in a class
    - Use `new` in the constructors, use `delete` in the destructors
    - Use of `new` and `delete` should be compatible
        - Like pairing `new []` with `delete []`. 
        - If the constructors vary, all should use `new` in the same way
        - Unless initializing a pointer with `new` in one constructor with the `nullptr` or`0`, or `NULL` in C ways, thus the *null pointer*
    - Define a *copy constructor* initializing one object to another by doing **deep copying**
    - Define an *assignment operator* copying one object to another by doing **deep copying**
        - Check for self-assignment
        - Free memory formerly pointed to by the **member pointer**
        - Return a reference to the invoking object
- Memberwise copying for classes with class members
    - Consider `class N1{private: NAME obj;}`
    - The default memberwise copying and assignment behavior have some smart
    - Uses the copy constructors and assignment operators defined for the member type
    - The copy constructors and assignment operators defined in `NAME` class is used to do the **memberwise copying**
    - Things get complicated if `N1` needs a copy constructor and assignment operator for some other class member, thus **explicitly calling the copy constructor and assignment operators** of `NAME` is necessaray

## Observations About Returning Objects
- Returning a reference to a `const` object
    - For efficiency
    - Returning an object invokes the copy constructor, **returning a reference doesn't**
    - Reference should be to an object **existing when the calling function is executing**
    - `const` reference as parameters, then the return type has to be `const` reference to match
- Returning a reference to a non-`const` object
    - Example: overloading assignment operator, efficiency
        - Hint: `return *this` **doesn't force to use reference**
    - Example: overloading `<<` operator, necessity
        - Hint: `ostream` has **no public copy constructor**
- Returning an object:
    - The object being returned is local to the called function
    - When control returns to the calling function, there is no object left to which the reference can refer
    - A temporary, new object is generated possibly 
    - Example: overloaded arithmetic operators
- Returning a `const` object:
    - Consider `net = obj1 + obj2;`
    - Bizarre stuff:  `obj1 + obj2 = net;`
    - Not all the code is written for sensible reasons
    - The code is possible, `net` is assigned to the **temporary object**
    - The temporary object is **used and then discarded**
    - Return type with `const` allows for `net=obj1+obj2`, and forbiddens the `obj1+obj2=net`

## Using Pointers to Objects

### Looking at `new` and `delete`
Source code: `C12_Classdynamic`
```C++
/*****placenew1.cpp*****/
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime> // time()
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

		stringgood* shortest = &sayings[0];
		stringgood* first = &sayings[0]; // use pointer to object
		for(i=1; i<total; ++i)
		{
			if(sayings[i].length() < shortest->length())
				shortest = sayings+i;
			if(sayings[i] < *first)
				first = sayings+i;
		}

		std::cout << "Shortest saying:\n"
				  << *shortest << "\n";
		std::cout << "First saying alphabetically:\n"
				  << *first << "\n";

		// new and delete
		srand(time(0));
		int choice = rand() % total;
		stringgood* favorite = new stringgood(sayings[choice]);
		std::cout << "My favorite saying:\n"
				  << *favorite << "\n";
		delete favorite;
	}
	else
		std::cout << "No input! Bye.\n";

	return 0;
}
```
- Try to use pointers to **keep track of the change of objects**
- It is invoking `NAME(type)` when using `NAME* obj = new NAME(val)`, it is a constructor
    - It does not allocate memory for `static` member!
    - When the member invokes pointers, and the space created by `new` is cleared by `delete`, the space taken up by the pointers is removed, while the contents the pointer removed pointing to is still there
    - The destructor takes care of the contents pointed
- When the destructor is called:
    - Automatic object, exited the block in which the object is defined
    - Static object(external, internal, or from a namespace, which has **static storage duration**), when the program terminates
    - Dynamic object created by `new`, called when explicitly using `delete`
```Console
Hi, what is your name?
>> Mteltn Cosmos
Mteltn Cosmos, please enter up to 10 short saying <enter to quit>:
1: A friend in need is a friend indeed
2: Neither a borrower nor a lender be
3: A stitch in time saves nine
4: A niche in time saves stine
5: It takes a crook to catch a croom
6: Cold hands, warm heart
7:
Here are your sayings:
A: A friend in need is a friend indeed
N: Neither a borrower nor a lender be
A: A stitch in time saves nine
A: A niche in time saves stine
I: It takes a crook to catch a croom
C: Cold hands, warm heart
Shortest saying:
Cold hands, warm heart
First saying alphabetically:
A friend in need is a friend indeed
My favorite saying:
It takes a crook to catch a croom
```

### Pointers and Objects Summary
- Declare a pointer to an object: `NAME* ptrobj`
- Initialize a pointer to an existing object: `NAME* ptrobj = &obj`
- Initialize a pointer using `new` with **default constructor** like `NAME* ptrobj = new NAME`
- Initialize a pointer using `new` **creating an new object**: `NAME* ptrobj = new NAME(obj)`, using the *copy constructor*, there could be other constructor ways
- Use `->` like the `struct` to access a class method via a **pointer** like `NAME* ptr = &obj; ptr->fun()`
- Use `*` to obtain an object: `(*ptr).fun()`

### Looking at Placement `new`
Source code: `C12_Placementnew`
```C++
/*****placenew2.cpp*****/
#include <iostream>
#include <cstring>
#include <new>

namespace testnew{
	const int BUFFER = 512;
	class TEST
	{
	private:
		std::string words;
		int number;
	public:
		inline 
		TEST(const std::string& s = "Just Testing", int n = 0){
			words = s;
			number = n;
			std::cout << words << " constructed\n";
		}
		inline 
		~TEST(void){
			std::cout << words << " destroyed\n";
		}
		inline 
		void SHOW(void){
			std::cout << words << ", " << number << "\n";
		}
	};
}

int main(void){
	char* buffer = new char[testnew::BUFFER];

	testnew::TEST *pc1, *pc2;
	pc1 = new (buffer) testnew::TEST; // default constructor
	pc2 = new testnew::TEST("Heap1", 20);

	std::cout << std::endl;
	std::cout << "Memory block address:\n" 
			  << "Buffer: " << (void*) buffer << "\t"
			  << "Heap: " << pc2 << "\n";

	std::cout << "Memory contents:\n";
	std::cout << pc1 << ": "; // print the address?
	pc1->SHOW();	
	std::cout << pc2 << ": ";
	pc2->SHOW();	
	std::cout << std::endl;

	testnew::TEST *pc3, *pc4;
	pc3 = new (buffer+sizeof(testnew::TEST)) 
			 testnew::TEST("Better Idea", 6);
	pc4 = new testnew::TEST("Heap2", 10);
	std::cout << std::endl;

	std::cout << "Memory contents:\n";
	std::cout << pc3 << ": "; 
	pc3->SHOW();	
	std::cout << pc4 << ": ";
	pc4->SHOW();	

	pc1->~TEST();
	pc3->~TEST();
	delete pc2;
	delete pc4;
	delete [] buffer;

	return 0;
}

```

- Used to **specify the memory location** used to allocate memory
- Aside of C-string like `char* name`, others use `std::cout << ptr` **prints the address**
- Using the placement `new` to allocate memory in a **buffer** can cause problem:
    - Simply overwrite the original objects without calling the destructor
    - Use `delete [] buffer` never destruct the anonymous objects created by placement `new`
- Make sure the locations don't overlap, like using `new (buffer+sizeof(TEST)) TEST;`
> - Attention! The **`delete` works in conjunction with `new` rather than placement `new`**
> - Using `delete pc1` where points to the buffer location freed the buffer rather than `pc1` itself(even if the buffer is compatible with `pc1` using `new` rather than `new []`)
- Call the **destructor explicitly for any objects that the placement `new` constructs in the block**
- Let the buffer be freed **only after all the contained objects are destroyed**

```Console
Just Testing constructed
Heap1 constructed

Memory block address:
Buffer: 0x56da2ab002b0  Heap: 0x56da2ab008d0
Memory contents:
0x56da2ab002b0: Just Testing, 0
0x56da2ab008d0: Heap1, 20

Better Idea constructed
Heap2 constructed

Memory contents:
0x56da2ab002d8: Better Idea, 6
0x56da2ab00900: Heap2, 10
Just Testing destroyed
Better Idea destroyed
Heap1 destroyed
Heap2 destroyed
```

## Reviewing Techniques
- Overloading the `<<` operator: `ostream& operator<<(ostream& os, const NAME& obj)`
- Conversion functions: 
    - `double` to `NAME` object: use constructor `NAME(double)`
    - `NAME` object to `double`: use conversion function `operator double(void) const`, **returns a value without declared returned type**! 
    - Better usage: `explicit NAME(double)`, and `explicit operator double(void) const` in **class declaration**, in definition we no need to precede the `explicit`
    - Avoid the implicit stuff!
- Classes whose constructors use `new`:
    - Pair `new` with `delete`
    - If the destructor freed memory by applying `delete` to a pointer that is a class member, initialize the pointer in every constructor, do the *deep copying* and overload the `=` operator sometimes is necessary
    - Constructors should settle on using either `new` or `new []` to be consistent with destructors
    - Define a copy constructor that **allocates new memory**: `NAME(const NAME&)`
    - Define a class member function overloading assignment operator: `NAME& NAME::operator=(const NAME& obj)`

## A Queue Simulation
- A stack is LIFO(last in, first out), while the queue is FIFO(first in, first out)
- Define a `QUEUE` class
    - $1/3$ of the customers take $1$ min to be processed
    - $1/3$ of the customers take $2$ min to be processed
    - $1/3$ of the customers take $3$ min to be processed
    - Customers arrive at **random intervals**, while the **average number of customers per hour is constant**

### A Queue Class
Source code: `C12_Classlink`
```C++
/*****queue.h*****/
#ifndef QUEUE_H_
#define QUEUE_H_

extern const int MIN_PER_HOUR;

class UNIT
{
private:
	size_t arrival;
	size_t process;
public:
	UNIT(void){arrival = process = 0;}
	size_t WHEN(void){return arrival;}
	size_t TIME(void){return process;}
	void SETI(size_t WHEN);
};

class QUEUE
{
private:
	struct NODE
	{
		UNIT unit;
		struct NODE* next;
	};
	static const int QSIZE = 10;

	NODE* pfore;
	NODE* pback;
	int num_units;
	const int max_qsize;

	// prevent public copying
	QUEUE(const QUEUE& q):max_qsize(0){} 
	QUEUE& operator=(const QUEUE& q){return *this;}

public:
	QUEUE(int qsize = QSIZE);
	~QUEUE(void);

	bool IS_EMPTY(void) const;
	bool IS_FULLY(void) const;
	bool ADD_UNIT(const UNIT& unit);
	bool DEL_UNIT(UNIT& unit);
	int NUM_UNITS(void) const;
};

#endif

/*****queue.cpp*****/
#include <cstdlib>
#include "queue.h"

extern const int MIN_PER_HOUR = 60;

void UNIT::SETI(size_t WHEN)
{
	process = std::rand()%3+1; // random at 1~3
	arrival = WHEN;
}

QUEUE::QUEUE(int qsize):max_qsize(qsize)
{
	pfore = nullptr;
	pback = nullptr;
	num_units = 0;
}

QUEUE::~QUEUE(void)
{
	NODE* temp;
	while(pfore!=nullptr)
	{
		temp = pfore;
		pfore = pfore->next;
		delete temp; // clear previous pfore content
	}
}

bool QUEUE::IS_EMPTY(void) const
{
	return (num_units==0);
}

bool QUEUE::IS_FULLY(void) const
{
	return (num_units==max_qsize);
}

bool QUEUE::ADD_UNIT(const UNIT& unit)
{
	if(IS_FULLY())
		return false;

	NODE* add = new NODE;
	add->unit = unit;
	add->next = nullptr;
	++num_units;

	if(pfore == nullptr)
		pfore = add; // put it in the first if queue emtpy
	else
		pback->next = add; // next is the end after added

	pback = add; // let the pback point to new node
	return true;
}
	
bool QUEUE::DEL_UNIT(UNIT& unit)
{
	if(pfore==nullptr)
		return false;

	unit = pfore->unit; // analyze unit to be done
	--num_units;

	NODE* temp = pfore;
	pfore = pfore->next;
	delete temp;

	if(num_units==0)
		pback = nullptr;

	return true;
}

int QUEUE::NUM_UNITS(void) const
{
	return num_units;
}

/*****link.cpp*****/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

inline bool newunit(double min_per_unit) 
{
	return (std::rand()*min_per_unit/RAND_MAX < 1);
}

int main(void)
{
	int queue_size;
	int simu_hours;
	double units_per_hour;

	std::srand(std::time(0)); // setup seed
	std::cout.precision(2);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	// begin simulation
	std::cout << "Enter maximum size of queue: ";
	std::cin >> queue_size;
	std::cout << "Enter the number of simulation hours: ";
	std::cin >> simu_hours;

	QUEUE line(queue_size);
	long cycle_max = MIN_PER_HOUR * simu_hours;

	std::cout << "Enter the average number of units per hour: ";
	std::cin >> units_per_hour;

	double min_per_unit = MIN_PER_HOUR / units_per_hour;
	UNIT temp; // new unit
	long turned_units = 0; 
	long joined_units = 0;
	long served_units = 0;
	long total_length = 0;
	long total_time = 0;
	int queue_time = 0; // time until server is free
	
	// each loop for 1 min
	for(int cycle=0; cycle<cycle_max; ++cycle)
	{
		if(newunit(min_per_unit))
		{
			if(line.IS_FULLY())
				++turned_units;
			else
			{
				++joined_units;
				temp.SETI(cycle);
				line.ADD_UNIT(temp);
			}
		}
		if(queue_time<=0 && !line.IS_EMPTY())
		{
			line.DEL_UNIT(temp);
			queue_time = temp.TIME(); // take the time queued for it
			total_time += cycle-temp.WHEN();
			++served_units;
		}
		if(queue_time > 0)
			--queue_time;
		total_length += line.NUM_UNITS();
	}

	if(joined_units > 0)
	{
		std::cout << "units accepted: " << joined_units << std::endl;
		std::cout << "units served: " << served_units << std::endl;
		std::cout << "units turned: " << turned_units << std::endl;
		std::cout << "average queue size: " 
				  << (double)total_length / cycle_max 
				  << std::endl;
		std::cout << "average wait time: " 
				  << (double)total_time / served_units << " min" 
				  << std::endl;
	}
	else
		std::cout << "No customers!\n";

	return 0;
}
```

- Basic attributes:
    - Holds an ordered sequence of items with a limit number
    - Create an empty queue
    - Check whether the queue is full/empty
    - Add/remove an item
    - Determine the number of items in the queue
- Interface:
    - The size of a queue in `private` section
    - Private representations
    - Public constructros and destructors, check full/empty, count, add and remove
- Implementation:
    - Choose the way to represent the queue data: a *linked list*
    - A linked list consists of a sequence of *nodes*
    - Each node contains its own information to be held in the list 
    - Each node contains a pointer to the *next node*
    - A **singly** linked list: `struct node{ ITEM item; struct node* next}`
    - The pointer in the **last node is set to `nullptr` or `0`**, and we should know **the address of the first node**
    - Set up 2 pointers, one to the first node, and the other to the last node
    - Nest the `struct` inside a `class` to give it `class` scope
- The class methods:
    - Constructors: 
        - `QUEUE::QUEUE(int qs) : qsize(qs){};`, to initialize a `const` in the class, use *member initializer list*, which is the `qsize(qs)`
        - It is not limited to `const` initialization: `QUEUE:QUEUE(int qs) : qsize(qt), front(NULL), rear(NULL){}`
        - Use for `const` class members and declared as **reference** like `NAME::NAME(type& a) : refe(a){}`, both can be initialized only when created (This feature works for ordinary initializations too, like `int a(1)`, which is different from **defining a constant** with `static const type var = val`
        - For C++11, free to use **in-class** initialization like `class NAME{ int mem = 1; const int mem2 = 2;}`, which is the same as `NAME::NAME : mem(1), mem2(2){}`, but it only works for **non-static or static const** member, which is called **default member initializer**, initialize it when declaring the class!
    - Test the queue is full or empty is simple
    - Adding an item to the rear:
        - Terminate if the queue is full
        - Create a new node, and place proper values into it, copy the value into the data part, sets the node's next pointer to `NULL`
        - Increment the item count
        - Attach the node to the rear of the queue, **have the `next` pointer of the current rear node point to the new rear node**, and set **the member pointer `rear` to point to the new node** to directly access it.
        - If there is just one node, it's both the front and the rear node
    - Removing an item to the front:
        - Terminate if the queue is empty
        - Provide **the first item in the queue**, decrease the item counts by one
        - Save the location of the `front` node, and set the `front` pointer point to the next node
        - Delete the former **first** node, remember, `delete` **does not clear out the pointer** itself, it **just frees the content it points to**
        - If the list is now empty, set `rear` to `NULL`
    - Destructor: use `delete` to clear out former nodes
    - Better provide a **copy constructor and an assignment operator** for the class to do the *deep copying* **even if we don't need it yet!** And put them into `private` section. In C++11, it is available to **use `delete` to disable a method** alternatively, see [Chapter\_18](Chapter_18.md)
- Define a `customer` class at last to calculate the time
- For the **client**:
    - Enter the max queue size, number of hours to be simulated, average number of customers per hour
    - Use a loop in which a circle represents one minute
        - Determine whether a customer is arrived, if so, add him to the queue if available 
        - If no one is being processed, take the first from the queue,  determine his waiting time and set a counter to the processing time the new customer will need
        - If a customer is being processed, decrement the counter by one minute
        - Track the number of customers served, turned away, cumulative time spent waiting in line, cumulative queue length...
    - When the simulation cycle is finished, report various statistical findings
- Setup random but average matching flag showing whether a customer has arrived
    - A simple way is `bool test(avg){return rand()*avg/RAND_MAX < 1;}` 
    - Which states that 1/`avg` possibly a customer will arrive per minute
    - Averagely, a customer comes every `avg` minutes 
    - It could be better!
- Also notice:
    $$
    \begin{align*}
    &\lambda = \frac{15\text{ per}}{60\text{ min}} = \frac{1}{4} \text{per}/\text{min}\\
    &\mu = \frac{1\text{ per}}{1/3 * 1+1/3 * 2 + 1/3 * 3\text{ min}} = \frac{1}{2}\text{per}/\text{min}\\ 
    \end{align*}
    $$
    Where $\lambda$ is the **arrival rate**, and $\mu$ is the **service rate**, and:
    $$\rho = \frac{\lambda}{\mu},\qquad t_{\text{avg}} \approx \frac{\rho}{\mu - \lambda} = 2\,\text{min}$$
    Thus by this calculation, the **waiting time in average with service time excluded** $t_{\text{avg}}$ for 1 person is 2 min, while when the **utilization rate** $\rho$ becomes 30 per/hour:
    $$
    \rho = 1,\qquad t_{\text{avg}} \approx \lim_{\lambda\rightarrow\mu}\frac{\rho}{\mu-\lambda} = \infty
    $$
    That is the **theory of queue** with simple **M/M/1** model, the algorithm is rough, but we can get the point

```Console
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C12_Classlink$ make run
./link
Enter maximum size of queue: 10
Enter the number of simulation hours: 100
Enter the average number of units per hour: 15
units accepted: 1506
units served: 1506
units turned: 0
average queue size: 0.16
average wait time: 0.64 min

mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C12_Classlink$ make run
./link
Enter maximum size of queue: 10
Enter the number of simulation hours: 100
Enter the average number of units per hour: 30
units accepted: 2887
units served: 2883
units turned: 143
average queue size: 5.00
average wait time: 10.40 min

mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C12_Classlink$ make run
./link
Enter maximum size of queue: 20
Enter the number of simulation hours: 100
Enter the average number of units per hour: 30
units accepted: 2974
units served: 2958
units turned: 31
average queue size: 9.77
average wait time: 19.72 min

mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C12_Classlink$ make run
./link
Enter maximum size of queue: 10
Enter the number of simulation hours: 4
Enter the average number of units per hour: 30
units accepted: 126
units served: 121
units turned: 5
average queue size: 5.34
average wait time: 10.38 min

mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C12_Classlink$ make run
./link
Enter maximum size of queue: 10
Enter the number of simulation hours: 4
Enter the average number of units per hour: 30
units accepted: 127
units served: 118
units turned: 1
average queue size: 3.58
average wait time: 6.58 min

mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C12_Classlink$ make run
./link
Enter maximum size of queue: 10
Enter the number of simulation hours: 4
Enter the average number of units per hour: 30
units accepted: 121
units served: 117
units turned: 8
average queue size: 6.12
average wait time: 12.19 min
```
