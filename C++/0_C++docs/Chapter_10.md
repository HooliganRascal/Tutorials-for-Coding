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
>   - **Interface consisting of the methods** provided enables the program to use the class objects

---
Source code: `C10_Classdeclare`
```C++
/*****stock00.h*****/
#ifndef STOCKzz_H_
#define STOCKzz_H_

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

### Access Control:
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
- If a nonmember function access the data members, it stops, except **friend functions** 
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
/*****usestock.cpp*****/

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

```

### Changing the Implementations
