# Objects and Classes
---
- Abstraction
- Encapsulation and data hiding
- Polymorphism
- Inheritance
- Reusability of code
## Procedural and OOP
- Procedural approach:
    - Concentrate on the procedures to be followed
    - Think about how to represent the data
- Object-Oriented Programming approach:
    - Concentrate on the object as we perceive it
    - Think about the data we need to decribe the object and the operations that will describe our interaction with the data
    - After developing the description of that interface, we think about how to implement the interface and the **data storage**
    - Put together a program to use the new design
## Abstraction and Classes
- Abstraction: 
    - To represent information in terms of its interface
    - Abstract the essential operational features of a problem and express a solution in those terms!
- In C++:
    - Move a short step from abstraction to get the **user-defined type**
    - The **usr-defined type** is a class design that implements the abstract interface

### Types and Classes in C++
- We begin to think about the `type`
    - How much memory is needed for a data object
    - How the bits in memory are interpreted
    - What operations, or methods, can be performed using the data object
- Classes in C++
    - A *vehicle* for translating an abstraction to a user-defined type
    - Combined with data representation
    - Combined with methods for manipulating that data into one neat package
- Define a class:
    - A class declaration
        - Describing data component in terms of **data members**
        - Describing public interface in terms of **member functions**
    - The class method definitions: how class member functions are implemented

> Interface
> - Shared framework for interaction between two systems
> - Example: you press a key, the computer shows a character on the screen
> - Program interface manages the conversion of your **intentions to specific informations stored in the computer**
> - Public interface for classes
>   - Public: program using the class
>   - **Interacting system consisting of class objects**
>   - **Interface consisting of the methods** provided enabling the program to use the class objects
> 
> The concept corresponding to interface is **implementation**

---
Source code: `C10_Classdeclare`
```C++
/*****stock00.h*****/
#ifndef STOCK00_H_
#define STOCK00_H_

#include <cstring>

class stock{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;
		inline void set_tot(void){
			total_val = shares * share_val;
		}
	public:
		void acquire(const sdt::string& co, long n, double pr);
		void buy(long num; double price);
		void sell(long num; double price);
		void update(double price);
		void show(void);
};

#endif
```
- Develop a class:
    - A header file containing **the interface in the form of a class definition**
        - `class type_name{private: variables; functions; public: variables; functions}`
        - `type_name` is the type name for this new class
        - A class declaration enables to **declare variables called *objects* or *instances* for the `type_name`**
        - The information stored appears to be in the form of **class data members**
        - The desired operations appear as **class member functions**(**declared function prototypes** with full definitions in another source code file or **defined in place**), the prototypes suffice to describe the the function interfaces!
    - A source code containing **implementation in the form of code for the class methods**

> C++ class: **binding of data and methods** into a single unit
> Creating an object of `type_name` automatically **establishes the rules governing how that objects can be used!**

### Access Control
- `public`: any program using an object of a particular class can access the public portions directly
- `private`: a program can access the private members of an object *only* by using the **public member functions**, see in [Chapter\_11](Chapter_11.md), this insulation is called *data hiding*
- `protected`: talk about it later we cover the **class inheritance** in [Chapter\_13](Chapter.13)
- Public member functions provide the interface between object and program
- A class design:
    - Public interface: abstraction component
    - Specifics of the implementation
- Encapsulation:
    - Gathering the implementation details together
    - Separating them from the abstraction
- Data hiding(putting data into the **private section** of a class) is just an instance of encapsulation

> Notes: 
> Just like `struct`, if we define a memberin `public` section: `class name{public: int a=1;};`, we can use `name.a` to access it

- Another encapsulation example: place class function definitions in a separate file from class declaration
    - We need to know that what different member functions accomplish, the arguments they take, the value they return
    - The principle is to **separate the details of implementation from the design of the interface**, so that adjustment can be applied without changing the program interface.

### Member access control: `public` or `private`
- We can declare class members like data items or member functions either in `public` or `private` section of a class
- **Data items** normally go into `private`
- **Member functions** constituting class interface go into `public`
- We can also put member functions in `private` which only `public` methods can use
- We don't have to use **`private` for it's the default access** control for class objects:`class{type object} // default private`
- C++ extends to `struct` the same features classes have, but **default access for `struct` is `public`**, but commonly **use `class` to implement class descriptions** while restricting `struct` to representing pure data objects(*plain-old data structure*)

### Implementing Class Member Functions
Source code: `C10_Classdeclare`
```C++
/*****stock00.cpp*****/
#include <iostream>
#include "stock00.h"

void stock::acquire(const std::string& co, long n, double pr){
	company = co;
	if(n<0){
		std::cout << "Number of shares can't be negative! "
				  << company << " shares set to 0.\n ";
		shares = 0;
	}
	else{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

void stock::buy(long num; double price){
	if(num<0){
		std::cout << "Number of shares purchased can't be negative! "
				  << "Transaction aborted.\n";
	}
	else{
		shares += num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::sell(long num; double price){
	using std::cout;
	if(num<0){
		cout << "Number of shares can't be negative!"
			 << "Transaction aborted.\n";
	}
	else if(num>shares){
		cout << "You can't sell more than you have! "
			 << "Transaction aborted.\n";
	}
	else{
		shares -= num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::update(double price){
	share_val = price;
	set_tot();
}

void stock::show(void){
	std::cout << "Company: " << company
			  << " Shares: " << shares << "\n"
			  << " Share Price: $" << share_val << "\n"
			  << " Total Worth: $" << total_val << "\n";
}
```
- Like normal function definitions
- Use `::` as *scope-resolution operator* to indicate to which class the function belongs, such functions have **class scope**
- Other member functions of the same class can use the functions in the class **without `::`**
- Using the functions outside the class declaration and method definitions requires special measures, `classname::method()` is *qualified*, and `method()` is *unqualified* which can be used **just in class scope**
- A method can access the private members of a class without `::`
- If a nonmember function access the data members, it stops, except [friend functions in Chapter\_11](Chapter_11.md)
- Include the header file to access the class definitions
- Any function with a definition in the class declaration automatically becomes an `inline` function:
    - One way: `class name{private: inline type fun(par); public:...};`
    - Another way: `class name{private: type fun(par); public:...}; inline type name::fun(var){definition};` Make sure it is in the same header file though it may be able to be separated from header files to another file in some special way!
    - Do the `inline` for `private` only as a good habit!
    - Exception: some simple functions in public can be `inline` too
- Use an object:
    - Create some objects: `classname a, b;`
    - Use the member function: `a.show()`, then `shares` in `show()` to be `a.shares()`
- Each new objects we create contains storage for its own internal variables(the class members)
- All objects of the same class share the same set of class methods with just **one copy of each method** (they enter **the same block of code!**)
- Calling a member function is called *sending a message*

### Using Classes
Source code: `C10_Classdeclare`
```C++
/*****usestock00.cpp*****/
#include <iostream>
#include "stock00.h"

int main(void){
	stock test;

	test.acquire("Mteltn Cosmos", 20, 12.45);
	test.show();
	test.buy(15, 15.5);
	test.show();
	test.sell(50, 20.0);
	test.show();
	test.buy(3000, 40.125);
	test.show();
	test.sell(50, 60.1);
	test.show();
	
	return 0;
}
```
- Make using classes as similar as possible to using the basic, built-in types like `int` and `char` 
- In this case, `main()` is just a vehicle for testing the design of a class, use the class as a *user-defined* type to understand what the member functions do rather than thinking about the implementation details!
- Client/Server model:
    - Client: a program using the class 
    - Server: a resource available to the programs needing it, which is contituted by class declarations and class methods
    - Client uses the server **through the publicly defined interface** only, 
    - Client **needs to know the interface**
    - Server is responsible for seeing itself **reliably and accurately performs according to the interface**, make changes to **details of implementation only, not to the interface!!**

```Console
Company: Mteltn CosmosShares: 20
Share Price: $12.45
Total Worth: $249

Company: Mteltn CosmosShares: 35
Share Price: $15.5
Total Worth: $542.5

You can't sell more than you have! Transaction aborted.

Company: Mteltn CosmosShares: 35
Share Price: $15.5
Total Worth: $542.5

Company: Mteltn CosmosShares: 3035
Share Price: $40.125
Total Worth: $121779

Company: Mteltn CosmosShares: 2985
Share Price: $60.1
Total Worth: $179398
```

### Changing the Implementations
Source code: `C10_Classdeclare`
```C++
/*****stock00.cpp/void stock::show(void) adjusted*****/
void stock::show(void){
	std::ios_base::fmtflags	orig = std::cout.setf(
			std::ios_base::fixed, 
			std::ios_base::floatfield
			);
	std::streamsize prec = std::cout.precision(3);

	std::cout << "Company: " << company
			  << "Shares: " << shares << "\n"
			  << "Share Price: $" << share_val << "\n";
	std::cout.precision(2);
	std::cout << "Total Worth: $" << total_val << "\n";
	std::cout << std::endl;

	std::cout.setf(orig, std::ios_base::floatfield);
	std::cout.precision(prec);
}
```

- To be consistent in number formats, use member function `setf()` from class `ostream` to avoid *e-notation*
- `std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);` sets a flag in the `cout` object instructing `cout` to use **fixed-point** notation 
- `std::cout.precision(3)` causes `cout` object to **show 3 places** to the right of the decimal
- When changing the implementation for a method, the changes should not affect other parts of the client program
- It is polite to reset the information before to the state existed before the function was called
    - `std::streamsize prec = std::cout.precision(3);...std::cout.precision(prec);` to save preceding value and reset old ones
    - `std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);...std::cout.setf(orig, std::ios_base::floatfield);` to store original flags and reset to stored value
    - Here, `std` is a namespace, `cout` is an object of `ostream` class, `fmtflags` is a type defined in `ios_base` class defined in `std` namespace
>  **Attention!** `prec` stored the **old precision**, and from now on, the precision is set to 3. Similarly, `orig` saved the **old format** as a flag, and from now on, the formats is `fixed`!

```Console
Company: Mteltn CosmosShares: 20
Share Price: $12.450
Total Worth: $249.00

Company: Mteltn CosmosShares: 35
Share Price: $15.500
Total Worth: $542.50

You can't sell more than you have! Transaction aborted.

Company: Mteltn CosmosShares: 35
Share Price: $15.500
Total Worth: $542.50

Company: Mteltn CosmosShares: 3035
Share Price: $40.125
Total Worth: $121779.38

Company: Mteltn CosmosShares: 2985
Share Price: $60.100
Total Worth: $179398.50
```

### A Little Review
- Provide a *class declaration* to specify a class design
- The class declaration is modeled and can include data members and function members(or member functions);
- Typical class design: `class name{private: data member declarations; public: member function prototypes};`
    - `public`: abstract part, provide interface
    - `private`: data hiding, where the data is *encapsulated*
- Next, implement the class method(or member function), defined inside the class declaration instead of using a prototype if it is brief, more commonly we provide the function definition separately, use *scope-resolution operator* `::` to indicate which class the function belongs
- Create an object like `classname obj`, in fact, **a class is a user-defined type!**
- Invoke a member function using the *dot membership operator* like `obj.fun()`

## Class Constructors and Destructors

- Usual initialization syntax does not carry over for the objects for the data parts have `private` access status
- We need to provide an appropriate **member function if to initialize an object**
- Special *member functions*: class constructors
    - Have objects initialized automatically when created
    - Construct new objects and **assign values to their data members**
    - A possible constructor: `class name{...}; name()`
    - The constructor has **no return value and no declared type**

### Declaring and Defining Constructors
- Get the prototype in `public` section: `name(var1,var2,..);`
- Define the constructor: `name::name(var1,var2,...){};`
- Constructor is used to initialize the members in its class, and the parameters in definition should be unique! A common practice: `name::name(m_member1, m_member2...)` where `member` stands for the members in the class

### Using Constructors
- Explicitly: `name object = name(val1,val2,...);`
- Implicitly: `name object(val1,val2,...);`
- Use with `new`: `name* objpt = new name(val1,val2,...);` 
    - The object has no name but can be managed by  `objpt`
- Rather than **beging invoked by an object, constructor is to create an object**

### Default Constructor
- Create an object when we don't provide explicit initialization values
- If we don't provide any constructors, C++ **automatically supplies one**
- `name object;` uses the default one doing nothing: `name::name(){}`
> - Default constructors are provided **by the compiler** only if we don't define any constructor
> - If we define any constructor like `name(m_member1,m_member2...)`, we **need to define a default version**, or the `name object;` will **become an error**
- If to create objects without explicit initialization, **define a default construtcor taking no arguments** yourself:
    - Provide default values: `name(m_member1=val1, m_member2=val2,...)`
    - Use function overloading: `name(){member1=val1; member2=val2;...}`
    - We can only have **one default constructor**!
    - After defined, feel free to use 
        - Implicit: `name obj;`
        - Explicit: `name obj=name()`
        - Implicit: `name* obj = new name;`
    - Don't mess up with **non-default construtors**!
- We should usually define a default constructor **implicitly initializing the objects**

### Destructors
- We need to track the object until it expires
- The program **automatically** calls a special member function called *destructor* cleaning up any debris
    - If the constructor uses `new` to allocate memory, the destructor should use `delete` to free that memory
    - If not using `new`, the destructor does not have to do any task to perform, we can simply let the compiler generate an implicit, do-nothing destructor
- Declare and define a destructor:
    - Destructor for the `name` class: `~name()`
    - Destructor has **no return value and no declared type and no arguments!**
    - Prototype: `~name();`
    - Define a do nothing vital: `name::~name(){std::cout<<"Bye!\n"}`
- Normally, a code should not explicitly call a destructor, but there could be [exception when doing dynamic memory allocation](Chapter_12.md)
    - Static storage class object, destructor is called automatically when the program terminates
    - Automatic storage class object, destructor is called automatically when the program exits the block of code in which the class object is defined
    - Dynamic storage class object using `new`, destructor is called automatically when we use `delete` to free the memory
    - Program can create **temporary objects**, and it automatically calls the destructor for the object when it has finished using it
- A destructor is called automatically when a class object expires
    - There ought to be a destructor
    - If no destructor exists, the compiler **implicitly declares a default destructor**, and if the compiler detects code **leading to the destruction of an object**, it provides a definition for that destructor

### Improving the Code
Source code: `C10_Classconde`
```C++
/*****stock10.h*****/
#ifndef STOCK10_H_
#define STOCK10_H_

#include <cstring>

class stock{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;

		inline void set_tot(void){
			total_val = shares * share_val;
		}
	public:
		stock(); // default constructor
		stock(const std::string& co, long n, double pr); // self-defined constructor
		~stock(); // destructor
				  
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show(void);
};

#endif

/*****stock10.cpp*****/
#include <iostream>
#include "stock10.h"

// constructor definition
stock::stock(){
	std::cout << "Default constructor called!\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

stock::stock(const std::string& co, long n, double pr){
	std::cout << "Constructor using " << co << " called!\n";
	company = co;
	if(n<0){
		std::cout << "Number of shares can't be negative! "
				  << company << " shares set to 0.\n ";
		shares = 0;
	}
	else{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

// destructor definition
stock::~stock(){
	std::cout << "Bye, " << company << "\n";
}

void stock::buy(long num, double price){
	if(num<0){
		std::cout << "Number of shares purchased can't be negative! "
				  << "Transaction aborted.\n\n";
	}
	else{
		shares += num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::sell(long num, double price){
	using std::cout;
	if(num<0){
		cout << "Number of shares can't be negative!"
			 << "Transaction aborted.\n\n";
	}
	else if(num>shares){
		cout << "You can't sell more than you have! "
			 << "Transaction aborted.\n\n";
	}
	else{
		shares -= num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::update(double price){
	share_val = price;
	set_tot();
}

void stock::show(void){
	std::ios_base::fmtflags	orig = std::cout.setf(
			std::ios_base::fixed, 
			std::ios_base::floatfield
			);
	std::streamsize prec = std::cout.precision(3);

	std::cout << "Company: " << company << "\n"
			  << "Shares: " << shares << "\n"
			  << "Share Price: $" << share_val << "\n";
	std::cout.precision(2);
	std::cout << "Total Worth: $" << total_val << "\n";
	// std::cout << std::endl;

	std::cout.setf(orig, std::ios_base::floatfield);
	std::cout.precision(prec);
}

/*****usestock10.cpp*****/
#include <iostream>
#include "stock10.h"

int main(void){
	std::cout << "Use constructors to create new objects\n";
	std::cout << std::endl;

	// Use block to activate destructor
	{
		// default constructor
		stock stock1; 
		stock1.show();
		std::cout << std::endl;

		// self-defined constructor
		stock stock2("Mteltn Cosmos", 2, 2.0);
		stock2.show();
		std::cout << std::endl;
		
		// constructor by assignment
		// some compiler produces temporary objects
		stock stock3 = stock("Guernica Mteltn", 12, 20.0);
		stock3.show();
		std::cout << std::endl;

		// Assignment
		stock3 = stock2;
		std::cout << "Use assignment to overwrite: \n";
		stock2.show();
		stock3.show();
		std::cout << std::endl;

		// Revise with constructor
		// Create a temporary object and destruct it 
		stock2 = stock("Cosmos Guernica", 25, 32.0);
		stock2.show();
		std::cout << std::endl;
	} 

	std::cout << std::endl;
	stock stock4 = stock("KKNNF", 25, 5.21);
	stock4.show();
	std::cout << std::endl;
	//stock4.~stock(); // we don't call destructor
	std::cout << "Done!" << std::endl << std::endl;
	
	return 0;
}
```
- Incorporate the constructors and the destructors into the class and method definitions
- Put constructor and destructor declared in header file
- Implement them in a source code
- Try to use brackets to **create temporary objects in a block!**
- Assigning with constructors after initilization also creates a temporary object!
- Assigning with constructors for initialization **may create temporary objects**
- If not using **block for automatic objects**, the destructor will not be called until `main()` finishes its block. In a windowing environment, the **window would close before the destructors were called!**
- Pay attention to the order:
    - The objects defined in 1,2,3
    - The destructor is called 3,2,1
    - *LIFO*! Last In First Out!
- Explicitly calling destructor will **not cancel the automatical calling for destructor when the execution exiting the block**!
- Using object assignment **overwrites** the assigned one!
- Use initialization rather than assignment when setting object values for higher efficiency!
- In C++11, use *list-initialization*: 
    - `name object = {member1, member2,...};` 
    - `name object{member1};` for **default value**
    - `name object{}` for **default constructor**
    - matching the constructor `name::name(m_member1, m_member2,...)` or the default constructor
> Attention! `name object{}` is good for initializationwith **default constructor**, while `name object()` is **declaring a function returning an object!**
- C++11 offers a class called `std::initializer_list` used as a type for a function or method parameter, representing a **list of arbitrary length**, providing all the entries are of the **same type** or **can be converted to the same type**, [more on that see Chapter\_16](Chapter_16.md) 
- When using member functions with objects like `const name object();`, use `type name::fun(arg) const{}` to **promise not to change the objects invoking implicitly**, called  **`const` member functions**
- Constructors can be overloaded! But **only one destructor exists per class**
- If the constructor has only one argument like `name(type var)`, it could be initialized by:
    - `name object = name(val);`
    - `name object(val);`
    - `name object = val;` But we better not do it, it could lead to some unpleasant surprise, see in [Chapter\_11](Chapter_11.md)

```Console
Use constructors to create new objects

Default constructor called!
Company: no name
Shares: 0
Share Price: $0.000
Total Worth: $0.00

Constructor using Mteltn Cosmos called!
Company: Mteltn Cosmos
Shares: 2
Share Price: $2.000
Total Worth: $4.00

Constructor using Guernica Mteltn called!
Company: Guernica Mteltn
Shares: 12
Share Price: $20.000
Total Worth: $240.00

Use assignment to overwrite:
Company: Mteltn Cosmos
Shares: 2
Share Price: $2.000
Total Worth: $4.00
Company: Mteltn Cosmos
Shares: 2
Share Price: $2.000
Total Worth: $4.00

Constructor using Cosmos Guernica called!
Bye, Cosmos Guernica
Company: Cosmos Guernica
Shares: 25
Share Price: $32.000
Total Worth: $800.00

Bye, Mteltn Cosmos
Bye, Cosmos Guernica
Bye, no name

Constructor using KKNNF called!
Company: KKNNF
Shares: 25
Share Price: $5.210
Total Worth: $130.25

Done!

Bye, KKNNF
```

## Knowing Your Objects: The `this` Pointer
Source code: `C10_Classthis`
```C++
/*****stock20.h*****/
#ifndef STOCK20_H_
#define STOCK20_H_

#include <cstring>

class stock{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;

		inline void set_tot(void){
			total_val = shares * share_val;
		}

	public:
		stock(); 
		stock(const std::string& co, long n=0, double pr=0.0);
		~stock();
				  
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show(void)const;
		const stock& topval(const stock& e) const;
};

#endif

/*****stock20.cpp*****/
#include <iostream>
#include "stock20.h"

// constructor definition
stock::stock(){
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

stock::stock(const std::string& co, long n, double pr){
	company = co;
	if(n<0){
		std::cout << "Number of shares can't be negative! "
				  << company << " shares set to 0.\n ";
		shares = 0;
	}
	else{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

// destructor definition
stock::~stock(){} // silence version

void stock::buy(long num, double price){
	if(num<0){
		std::cout << "Number of shares purchased can't be negative! "
				  << "Transaction aborted.\n\n";
	}
	else{
		shares += num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::sell(long num, double price){
	using std::cout;
	if(num<0){
		cout << "Number of shares can't be negative!"
			 << "Transaction aborted.\n\n";
	}
	else if(num>shares){
		cout << "You can't sell more than you have! "
			 << "Transaction aborted.\n\n";
	}
	else{
		shares -= num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::update(double price){
	share_val = price;
	set_tot();
}

void stock::show(void)const{
	std::ios_base::fmtflags	orig = std::cout.setf(
			std::ios_base::fixed, 
			std::ios_base::floatfield
			);
	std::streamsize prec = std::cout.precision(3);

	std::cout << "Company: " << company << "\n"
			  << "Shares: " << shares << "\n"
			  << "Share Price: $" << share_val << "\n";
	std::cout.precision(2);
	std::cout << "Total Worth: $" << total_val << "\n";

	std::cout.setf(orig, std::ios_base::floatfield);
	std::cout.precision(prec);
}

const stock& stock::topval(const stock& e) const{
	// same as if(e.total_val > this->total_val)
	if(e.total_val > total_val) 
		return e;
	else
		return *this;
}

```

- A method deal with two or more objects, use `this` pointer
- If there are some contents in each object to compare
    - We can provide a method to access the contents for each object, then do the comparison
    - Or we can provide a method with directly two objects to compare, and return the greater one
- For the second way, use a function `const name& compare(const name& object) const`, the second way access one object **implicitly** and another object **explicitly**
    - First `const` refers to the returned value with the same type as the argument
    - Second `const` refers to the type of the argument as a `const`, stating that **the program will not modify the explicitly accessed objects**
    - Third `const` promise **not to change the members in the objects invoking implicitly**
- Then it is free to use either one of them: `top = object1.compare(object2)`, `top = object2.compare(object1)`
- It would be clearer to use `<` as [overloading operator in Chapter\_11](Chapter_11.md)
- There is no alias for the implicit invoking object! Use `this` pointer to access!
> - In general, all class methods have a `this` pointer **set to the address of the object that invokes the method**, including *constructor* and *destructor*
> - The `member` in `object1` when using `object1.fun()` is just a shorthand notation of `this->member`, it is used for `struct`, but also makes sense for `class`!
> - If needing to refer to the object invoking as a whole, use `*this`
> - The third `const` qualifies `this` points to a `const`, we can not use `this` to change the object's value
- The `&` means that the returned object is the **invoking object itself implicitly or explicitly** rather than a copy passed by return mechanism

## An array of objects
Source code: `C10_Classthis`
```C++
/*****usestock20.cpp*****/
#include <iostream>
#include "stock20.h"

const int obsize = 4;

int main(void){
	stock objects[obsize] = {
		stock("Mteltn Cosmos", 12, 20.0),
		stock("Cosmos Guernica", 24, 31.3),
		stock("Guernica Mteltn", 36, 42.1),
	}; // leave one default
	
	std::cout << "Stock holding: \n\n";
	for(int i=0; i<obsize; ++i){
		(objects+i)->show();
		std::cout << std::endl;
	}

	// find the most valuable holding
	const stock* top = objects;
	for(int i=1; i<obsize; ++i){
		// same as top = &((*top).topval(*(top+i)));
		top = &(top->topval(*(objects+i))); 
	}
	std::cout << "Most valuable holding:\n\n";
	(*top).show();

	return 0;
}
```

- Declare an array of objects the same way to declare an array of any of the standard types: `name objects[size];`
- The constructor default or not is called when creating such an array, and feel free to use member functions like: `objects[num].fun();`
- Use constructor *non-default* to initialize the array elements: `name objects[size] = {name(val1), name(val2),...}`
- If the program has more than 1 constructor, we can use different constructors for different elements
- And **partially initialized** array of objects will leave the rest of **implicit objects in the array initialized by default constructor**
> Original Unix system used a C++ front-end `cfront` to convert C++ programs to C programs
> - C++: `void name::fun() const{ cout << member; }`
> - C: `void fun(const name* this){ cout << this->member; }`
> 
> - It converts a `name::` qualifier to a **function argument** being a **pointer to `name` then uses the pointer to access the class members**

- For a pointer to object, use `pt->fun()` or `*pt.fun()` to call the member function!

```Console
Stock holding:

Company: Mteltn Cosmos
Shares: 12
Share Price: $20.000
Total Worth: $240.00

Company: Cosmos Guernica
Shares: 24
Share Price: $31.300
Total Worth: $751.20

Company: Guernica Mteltn
Shares: 36
Share Price: $42.100
Total Worth: $1515.60

Company: no name
Shares: 0
Share Price: $0.000
Total Worth: $0.00

Most valuable holding:

Company: Guernica Mteltn
Shares: 36
Share Price: $42.100
Total Worth: $1515.60
```

## Class Scope

- Applied to the names defined in a class, like data members and data functions
    - Known **within** the class 
    - Available to have the same class member names in different class
    - Within the class, we can use an unadorned member name like `fun()` rather than `name.fun()`
    - But outside the class, we need to use **direct`.`**, **scope-resolution `::`** or **indirect `->`** when using a class member name
- Class definition describes what an object looks like rather than creates an object
- Create class scope constant with `enum`
    - Declare an `enum` within a class to provide class scope symbolic names for integer constants, like `class name{private: enum{a=1};};`, and we **need not to provide a tag**
    - In fact, `ios_base` does something similar to this `enum`, where `fixed` is an enumerator defined in class `ios_base`
- Another way of defining a constant within a class: use `static`
    - Like `class name{private: static const type var = val;}`
    - C++ 98 can use this only for constant integer or enumeration, C++ 11 removes this restriction
    - More on `static` class members, see in [Chapter\_12](Chapter_12.md)
- For enumeration:
    - `emum a{a_1}; enum b{a_1}` can **conflict for `a_1` in the 2 enumerations would be in the same scope**
    - In C++11, use `class` to avoid this problem: `enum class a{a_1}; enum class b{a_1};`
    - Here, `class` can b altered by `struct`, and use `a enm1 = a::a_1`
    - Now, the enumerators have class scope
- Type security for scoped enumerations:
    - Regular enumerations get converted into `int` automatically
    - Scoped enumerations have no implicit conversions to `int`, thus not allowed for `int` operations like `if(a::a_1<1)`
    - But explicit conversion is available: `int text = int(a::a_1)`
- Enumerations are represented by some **underlying integer types**
    - Under C98, this was *implementation dependent*, thus the `struct` containing `enum` can be of different sizes in different systems, C++11 has removed the dependency for **scoped enumerations**
    - By default, the underlying type of *scoped* `enum` in C++11 is `int` 
    - Use `:` to indicate a different choice: `enum class:short a{a_1};`, which specifies the underlying type to be `short`, it has to be an **integer type**
    - This could work for unscoped enumerations too, but if we don't specify the underlying type, the choice the compiler makes is implementation-dependent

## Abstract Data Type
Source code: `C10_Stack`
```C++
/*****stack.h****/
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long item; // general type of stack

class stack{
	private:
		enum {limit=10};
		item items[limit];
		int top;
	public:
		stack(void);
		bool isempty(void) const;
		bool isfull(void) const;
		bool push(const item& neo); // false if the stack is full
		bool pop(item& neo); // false if the stack is empty
};

#endif

/*****stack.cpp*****/
#include "stack.h"
 
stack::stack(void){
	top=0;
}

bool stack::isempty(void) const{
	return top==0;
}

bool stack::isfull(void) const{
	return top==limit;
}

bool stack::push(const item& neo){
	if(top<limit){
		*(items+top) = neo; // overwrite
		++top;
		return true;
	}
	else{
		return false;
	}
}

bool stack::pop(item& neo){
	if(top>0){
		--top;
		neo = *(items+top);
		return true;
	}
	else{
		return false;
	}
}	

/*****usestack.cpp*****/
#include <iostream>
#include <cctype>
#include "stack.h"

int main(void){
	stack st;
	char ch;
	unsigned long po;

	std::cout << "Enter A to add a purchase order,\n"
			  << "Enter P to process a PO, \n"
			  << "Enter Q to quit \n";
	std::cout << std::endl;

	while((std::cin>>ch)&&(toupper(ch)!='Q')){
		while(std::cin.get()!='\n'){
			continue;
		}// empty the waste invalid input in the queue
		if(!isalpha(ch)){
			std::cout << "\a"
					  << "Please enter a valid letter,\n"
					  << "Enter A to add a purchase order,\n"
					  << "Enter P to process a PO, \n"
			  		  << "Enter Q to quit \n";
			std::cout << std::endl; 
			continue;
		}
		switch(ch){
			case 'A':
			case 'a': std::cout << "Enter a PO number to add: ";
					  std::cin >> po;
					  if(st.isfull()){
						  std::cout << "Stack already full\n";
					  }
					  else{
						  st.push(po);
					  }
					  break;
			case 'p':
			case 'P': if(st.isempty()){
						  std::cout << "Stack already empty\n";
					  }
					  else{
						  st.pop(po);
						  std::cout << "PO #" << po << " popped\n";
					  }
					  break;
		}

		std::cout << std::endl;
	//	std::cout << "Enter A to add a purchase order,\n"
	//  		  << "Enter P to process a PO, \n"
	//		      << "Enter Q to quit \n";
	}
	std::cout << "Bye!\n";

	return 0;
}
```

- Define a class to represent more general concepts
- Use a class to implement *abstract data types*(ADTs)
- Describe a data type **in a general fashion without bringing in language or implementation details**, like using the *stack* to manage automatic variables
    - New automatic variables generated, they are added to the top
    - When they expire, they are removed from the stack
- More on stack:
    - Stack holds several items (making stack a *container*)
    - Stack is characterized by the **operation** you can perform on it
        - Create an empty stack
        - Add an item to the top(push)
        - Remove an item from the top(pop)
        - Check whether the stack is full
        - Check whether the stack is empty
- Match the description with `class`
    - `public` member functions represent the operations, 
    - `private` data members take care of **storing** the data, with array or advanced data structure
- Always remember to use `private` members to protect the codes

```Console
Enter A to add a purchase order,
Enter P to process a PO,
Enter Q to quit

A
Enter a PO number to add: 1

A
Enter a PO number to add: 2

A
Enter a PO number to add: 3

P
PO #3 popped

P
PO #2 popped

P
PO #1 popped

P
Stack already empty

Q
Bye!
```
