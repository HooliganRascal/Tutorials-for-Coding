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

- Access control:
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
    - We need to know that different member functions accomplish, the arguments they take, the value they return
    - The principle is to **separate the details of implementation from the design of the interface**, so that adjustment can be applied without changing the program interface.
- Member access control: `public` or `private`
