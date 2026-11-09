# Class Inheritance
- To reuse the code!
- Better method for extending and modifying classes, which is *class inheritance*
- Derive new class from old ones
    - Old class inherited the properties including the methods is the **base class**
    - The new class derived from the old class is the **derived class**
    - Add functionality to an existing class
    - Add to the data that a class represents
    - Modify how a class method behaves

## Beginning with a Simple Base Class
Source code: `C13_Simplebase`
```C++
/*****table0.h*****/
#ifndef TABLE0_H_
#define TABLE0_H_

#include <cstring>

class TABLE
{
private:
	std::string first;
	std::string last;
	bool has;

public:
	TABLE
	(const std::string& fn = "none",
	 const std::string& ln = "none", bool hs = false);
	void NAME(void) const;
	bool HAS(void) const{return has;}
	void RESET(bool v){ has = v;}
};

#endif

/*****table0.cpp*****/
#include <iostream>
#include "table0.h"

TABLE::TABLE
(const std::string& fn ,
 const std::string& ln , bool hs) :
first(fn),last(ln),has(hs){}

void TABLE::NAME(void) const
{
	std::cout << last << ", " << first;
}

/*****usetable0.cpp*****/
#include <iostream>
#include "table0.h"

int main(void)
{
	TABLE P1("Mteltn", "Guernica", true);
	TABLE P2("Cosmos", "Justice", false);

	P1.NAME();
	if(P1.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";

	P2.NAME();
	if(P2.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";
	
	return 0;
}
```

- Begin with a case to see how the inheritance works
- The member initializer list syntax 
    - Saves the step of calling `string` default constructor and invoking the `string` assignment operator
    - It just uses the `string` copy constructor

```Console
Guernica, Mteltn : has a table
Justice, Cosmos : hasn't a table
```

### Deriving a Class
- To show a class derived from one(public derivation): `class DERIVE : public NAME{}`
- The `public` members of the **base class** become `public` members of the **derived class**
- But they can be accessed **only through `public` and `protected` methods** of the **base class**(interface)
- Added features:
    - Its own constructors
    - Additional data members and member functions as needed

### Constructors: Access Considerations
- A derived class has to work through the base-class methods to access `private` base-class members
- The base-class objects should be constructed before the program enters the body of the derived class constructor
- Use member initializer list syntax: `DERIVE::DERIVE(type1 var1, type2 var2) : NAME(var2)`
- It calls the `NAME` constructor first, storing `var2`, then enters the body of `DERIVE` constructor
- If we omit the member initializer list, the program uses the default constructor
- If we use `DERIVE(type1, const NAME&)` as constructor and construct an object with `DERIVE::DERIVE(type1 var1, const NAME& obj1):NAME(obj1)`, it uses a **copy constructor**
- Use member initializer list for members of the derived class as well: `DERIVE::DERIVE(type1 var1, const NAME& obj1):NAME(obj1),DERIVE_MEM(var1)`
- For implicit destructors, destroying an object occurs in the opposite order used to construct an object(LIFO!), the **derived-class destructor is executed first**, then the **base-class destructor is called automatically**
- The member initializer list can be used **only in constructors**

### Using a Derived Class
Source code:`C13_Simplebase`
```C++
/*****table1.h*****/
#ifndef TABLE1_H_
#define TABLE1_H_

#include <cstring>

class TABLE
{
private:
	std::string first;
	std::string last;
	bool has;

public:
	TABLE
	(const std::string& fn = "none",
	 const std::string& ln = "none", bool hs = false);
	void NAME(void) const;
	bool HAS(void) const{return has;}
	void RETABLE(bool v){ has = v;}
};


class RATED : public TABLE
{
private:
	unsigned int rating;

public:
	RATED
	(unsigned int r=0, const std::string& fn = "none",
	 const std::string& ln = "none", bool hs = false);
	RATED(unsigned int r, const TABLE& t);

	unsigned int RATING(void) const{return rating;}
	void RERATED(unsigned int r){rating = r;}
};

#endif

/*****table1.cpp*****/
#include <iostream>
#include "table1.h"

// Base class
TABLE::TABLE
(const std::string& fn, const std::string& ln, bool hs) : 
first(fn),last(ln),has(hs)
{
}

void TABLE::NAME(void) const
{
	std::cout << last << ", " << first;
}

// Derived class
RATED::RATED
(unsigned int r, const std::string& fn,
 const std::string& ln, bool hs) : TABLE(fn, ln, hs)
{
	rating = r;
}

RATED::RATED
(unsigned int r, const TABLE& t) : TABLE(t), rating(r)
{
}


/*****usetable1.cpp*****/
#include <iostream>
#include "table1.h"

int main(void)
{
	TABLE P1("Mteltn", "Cosmos", false);
	RATED R1(1145, "Guernica", "Cosmos", true);

	P1.NAME();
	if(P1.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";

	R1.NAME(); // use base-class method
	if(R1.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";

	std::cout << "Name: ";
	R1.NAME();
	std::cout << "; Rating: " << R1.RATING() << "\n";

	RATED R2(4514, P1);
	std::cout << "Name: ";
	R2.NAME();
	std::cout << "; Rating: " << R2.RATING() << "\n";

	return 0;
}

```

Special relationships between **derived classes** and **base classes**
- A derived class object can use base-class methods not `private`
- A **base-class pointer can point to a derived-class object** without an explicit type cast: `NAME* pt = &DERIVE_OBJ; pt->NAME_METHOD();`
- A **base-class reference can refer to a derived-class object** without an explicit type cast: `NAME& rt = DERIVE_OBJ; rt.NAME_METHOD();`
- But it can **only invoke base-class methods**, we can not use `pt` or `rt` to invoke the derived-class `DERIVE_METHOD();`
- It is **one-direction**, it is not allowed to `DERIVE* pr = &NAME_OBJ` or `DERIVE& pr = NAME_OBJ`
- Interesting consequeces:
    - Functions **defined with base-class reference or pointer arguments** can use with either base-class or derived-class objects like `SHOW(NAME_OBJ)` or `SHOW(DERIVE_OBJ)`
    - The **reference compatibility** also allows us to **initialize a base-class object to a derived-class object** using **copy constructor**, like `NAME(const NAME&);` but with `NAME::NAME obj(DERIVE_OBJ);`
    - Similarly, it works with assigning a derived-class object to a base-class object using **implicit overloaded assignment operator**, like `NAME& operator=(const NAME&) const;`, but with `NAME_OBJ = DERIVE_OBJ;`

```Console
Cosmos, Mteltn : hasn't a table
Cosmos, Guernica : has a table
Name: Cosmos, Guernica; Rating: 1145
Name: Cosmos, Mteltn; Rating: 4514
```

## Inheritance: An *Is-a* Relationship

## Polymorphic Public Inheritance

## Static and Dynamic Binding
