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
- Three varieties of inheritance:
    - `public`: the *is-a* relationship    
    - `protected` 
    - `private`
- Is-a(maybe is-a-kind-of is more accurate):
    - A banana is a fruit
    - An object of a derived class **should also be** an object of the base class
    - Anything to do with a base-class object, should be able to do with a derived-class object
    - The derived class can **add features** though
- Inheritance can add properties to a base class, but it doesn't remove properties from a base class
- Other relationships:
    - *Has-a*: a lunch can have a fruit, but a fruit is not a lunch
    - *Is-like-a*: lawyers are like sharks, but lawyer is not a shark
    - *Is-implemented-as-a* relationship
        - Implement a stack using an array
        - But we don't derive a `STACK` class from an `ARRAY` class for a stack can be implemented in other ways like *linked list*
    - *Uses-a* relationship
        - A computer can use a laser printer
        - But we don't derive a `PRINTER` class from a `COMPUTER` class 
- For those other relationships, use other implementations like set as member or design a new class or set as object member
- *Is-a* relationship is not symmetric

## Polymorphic Public Inheritance
- We may want a method to **behave differently for the derived class than it does for the basic class**
- The way a particular method behaves may depend on the object involving it
- Polymorphic: having many forms
    - Redefining base-class methods in a derived class
    - Using **virtual methods**
- Use two class to represent a bank checking: basic and overloan

### Developing `BRASS` and `BRASSPULS` Classes
Source code: `C13_Polypublic`
```C++
/*****brass.h*****/
#ifndef BRASS_H_
#define BRASS_H_
#include <cstring>

class BRASS
{
private:
	std::string name;
	long num;
	double bal;
public:
	BRASS
	(const std::string& m_name="Null", 
	 long m_num = -1, double m_bal = 0.0);
	virtual ~BRASS(void);

	void DEPOSIT(double money);
	double BALANCE(void) const;
	virtual void WITHDRAW(double money);
	virtual void VIEW_NUM(void) const;
}

class BRASSPLUS: public BRASS // Inheritance
{
private:
	double maxloan;
	double rate;
	double owe;
public:
	BRASSPLUS
	(const std::string& m_name="Null", 
	 long m_num = -1, double m_bal = 0.0, 
	 double m_maxloan = 500, double m_rate = 0.11125);
	BRASSPLUS
	(const BRASS& m_brass, double m_maxloan = 500, 
	 double m_rate = 0.11125);
	virtual ~BRASS(void);

	inline void RESETMAX(double m){maxloan = m;}
	inline void RESETRATE(double r){rate = r;}
	inline void RESETOWE(void){owe = 0;}
	virtual void WITHDRAW(double money);
	virtual void VIEW_NUM(void) const;
}

#endif
```
- Add new private data members and and new public member functions
- Declare one same method with different behaviors, the compiler uses the **object type** to determine which version to use
- Use `virtual` keyword to determine which method is used if the method is invoked **by a reference or a pointer** to an object
    - Without `virtual`: choose methods based on **reference type or pointer type**
    - Use `virtual`: choose methods based on **the type of object the reference or pointer refers to or points to**
    - When a method is declared `virtual` in a **base class**, it is **automatically `virtual` in the derived class**
    - But explicitly documenting the `virtual` methods in derived class is a good habit
- Declare a `virtual` destructor to make sure the correct sequence of destructors is called **when a derived object is destroyed**

### Class Implementations
Source code: `C13_Polypublic`
```C++
/*****brass.cpp*****/
#include <iostream>
#include "brass.h"

// Format
form SETFORMAT(void)
{
	return std::cout.setf
	(std::ios_base::fixed, std:ios_base::floatfield);
}

void RESTORE(form f, prec p)
{
	std::cout.setf(f, std::ios_bas::floatfield);
	std::cout.precision(p);
}

// BRASS methods
BRASS::BRASS
(const std::string& m_name, long m_num, double m_bal)
{
	name = m_name;
	num = m_num;
	bal = m_bal;
}

BRASS::~BRASS(void){}

void BRASS::DEPOSIT(double money)
{
	if(money < 0)
	{
		std::cout << "Negative deposit not allowed! " 
				  << "Deposit is cancelled.\n";
	}
	else
		bal += money;
}

void BRASS::WITHDRAW(double money)
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	if(money<0)
	{
		std::cout << "Withdrawal amount must be positive! "
				  << "Withdrawal is cancelled.\n";
	}
	else if(money <= bal)
		bal -= money;
	else
	{
		std::cout << "Withdrawal amount of $" << money
				  << " exceeds your balance! ";
				  << "Withdrawal is cancelled.\n";
	}

	RESTORE(ini, pre);
}

double BRASS::BALANCE(void) const
{
	return bal;
}

void BRASS::VIEW_NUM(void) const
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	std::cout << "Client: " << name << "\n";
	std::cout << "Account Number: " << num << "\n";
	std::cout << "Balance: " << bal << "\n";

	RESTORE(ini, pre);
}

// BRASSPLUS methods
BRASSPLUS::BRASSPLUS
(const std::string& m_name, long m_num, 
 double m_bal, double m_maxloan, double m_rate) : 
BRASS(m_name, m_num, m_nal)
{
	maxloan = m_maxloan;
	owe = 0.0;
	rate = m_rate;
}

BRASSPLUS::BRASSPLUS
(const BRASS& m_brass, double m_maxloan, double m_rate) :
BRASS(m_brass)
{
	maxloan = m_maxloan;
	owe = 0.0;
	rate = m_rate;
}

BRASSPLUS::~BRASS(void){}

void BRASSPLUS::VIEW_NUM(void) const
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	BRASS::VIEW_NUM(); // use base class method
	std::cout << "Maximum loan: $" << maxloan << "\n";
	std::cout << "Owed to bank: $" << owe << "\n";
	std::cout.precision(3);
	std::cout << "Loan rate: $" << 100*rate << "%\n";

	RESTORE(ini, pre);
}

void BRASSPLUS::WITHDRAW(double money)
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	double balance = BALANCE(); // access only through public
	if(money < balance)
		BRASS::WITHDRAW(money);
	else if(money <= balance+maxloan-owe)
	{
		double advance = money-balance;
		owe += advance*(1.0+rate);
		std::cout << "Bank advance: $" << advance << "\n";
		std::cout << "Bank advance: $" << advance*rate << "\n";
		DEPOSIT(advance);
		BRASS::WITHDRAW(money);
	}
	else
		std::cout << "Credit limit exceeded!"
				  << "Transaction cancelled.\n";

	RESTORE(ini, pre);
}
```
- The `virtual` keyword is used **just in the method prototypes in the class declaration** 
- Remember that derived-class has to use base-class methods to access the private base-class data
- Derived-class **constructors** use to initialize **base-class** private data is the **member initializer list** syntax(memberwise or **implicit copy constructor**
- Derived class **non-constructors** methods call the `public` base-class methods to access the `private` base-class members, use **scope-resolution operator**!
- If the methods in base-class is not redefined, using it in the derived-class doesn't have to use scope-resolution operator
- More details about formatting in [Chapter\_17](Chapter_17.md)

### Using the `BRASS` and `BRASSPLUS` Classes
Source code: `C13_Polypublic`
```C++
/*****usebrass1.cpp*****/
#include <iostream>
#include "brass.h"

int main(void)
{
	BRASS Mteltn("Mteltn Cosmos", 114, 3500.0);
	BRASSPLUS Guernica("Guernica Cosmos", 514, 7000);

	Mteltn.VIEW_NUM();
	std::cout << std::endl;
	Guernica.VIEW_NUM();
	std::cout << std::endl;

	std::cout << "Depositing $1000 into the Guernica account:\n";
	Guernica.DEPOSIT(1000.00);
	std::cout << "New balance: $" << Guernica.BALANCE() << "\n";

	std::cout << "Withdrawing $2200 into the Mteltn account:\n";
	Mteltn.WITHDRAW(4200.00);
	std::cout << "New balance: $" << Mteltn.BALANCE() << "\n";

	std::cout << "Withdrawing $2200 into the Guernica account:\n";
	Guernica.WITHDRAW(4200.00);
	Guernica.VIEW_NUM();

	return 0;
}

```

- List some outputs

```Console
Client: Mteltn Cosmos
Account Number: 114
Balance: 3500.00

Client: Guernica Cosmos
Account Number: 514
Balance: 7000.00
Maximum loan: $500.00
Owed to bank: $0.00
Loan rate: $11.125%

Depositing $1000 into the Guernica account:
New balance: $8000
Withdrawing $2200 into the Mteltn account:
Withdrawal amount of $4200.00 exceeds your balance! Withdrawal is cancelled.
New balance: $3500
Withdrawing $2200 into the Guernica account:
Client: Guernica Cosmos
Account Number: 514
Balance: 3800.00
Maximum loan: $500.00
Owed to bank: $0.00
Loan rate: $11.125%
```

### Showing `virtual` Method Behavior
Source code: `C13_Polypublic`
```C++
/*****usebrass2.cpp*****/
#include <iostream>
#include <cstring>
#include "brass.h"

const int CLIENTS = 4;

int main(void)
{
	BRASS* p_clients[CLIENTS];
	std::string temp;
	long num_temp;
	double bal_temp;
	char kind;

	for(int i=0; i<CLIENTS; ++i)
	{
		std::cout << "Enter client's name: ";
		getline(std::cin, temp);
		std::cout << "Enter client's account number: ";
		std::cin >> num_temp;
		std::cout << "Enter opening balance: $";
		std::cin >> bal_temp;
		std::cout << "Enter 1 for BRASS account or "
				  << "2 for BRASSPLUS account: ";
		while(std::cin>>kind && (kind!='1' && kind!='2'))
			std::cout << "Enter 1 or 2: ";
		if(kind=='1')
			p_clients[i] = new BRASS(temp, num_temp, bal_temp);
		else
		{
			double tmax, trate;
			std::cout << "Enter the overdraft limit: $";
			std::cin >> tmax;
			std::cout << "Enter the interest rate as a "
					  << "decimal fraction: ";
			std::cin >> trate;
			p_clients[i] = new BRASSPLUS(temp, num_temp, bal_temp,tmax, trate);
		}

		while(std::cin.get()!='\n')
			continue; // filter input queue
	}
	std::cout << "\n";

	for(int i=0; i<CLIENTS; ++i)
	{
		p_clients[i]->VIEW_NUM();
		std::cout << "\n";
	}

	for(int i=0; i<CLIENTS; ++i)
	{
		delete p_clients[i]; // free memory
	}

	std::cout << "Done!\n";
	return 0;
}

```
- Use a single array of **pointers to base class objects** to hold a mixture of base-class and derived-class objects
- In effect, we can have a way of representing a collection of more than one type of objects with a single array(use `public` inheritance model!)

```Console
Enter client's name: Harry Potter
Enter client's account number: 112233
Enter opening balance: $1500
Enter 1 for BRASS account or 2 for BRASSPLUS account: 1
Enter client's name: Dinah Otto
Enter client's account number: 121213
Enter opening balance: $1800
Enter 1 for BRASS account or 2 for BRASSPLUS account: 2
Enter the overdraft limit: $350
Enter the interest rate as a decimal fraction: 0.12
Enter client's name: Brenda Fuck
Enter client's account number: 212118
Enter opening balance: $5200
Enter 1 for BRASS account or 2 for BRASSPLUS account: 2
Enter the overdraft limit: $800
Enter the interest rate as a decimal fraction: 0.10
Enter client's name: Tim Jerry
Enter client's account number: 233255
Enter opening balance: $688
Enter 1 for BRASS account or 2 for BRASSPLUS account: 1

Client: Harry Potter
Account Number: 112233
Balance: 1500.00

Client: Dinah Otto
Account Number: 121213
Balance: 1800.00
Maximum loan: $350.00
Owed to bank: $0.00
Loan rate: $12.000%

Client: Brenda Fuck
Account Number: 212118
Balance: 5200.00
Maximum loan: $800.00
Owed to bank: $0.00
Loan rate: $10.000%

Client: Tim Jerry
Account Number: 233255
Balance: 688.00

Done!
```

### The Need for `virtual` Destructors
- Remember to use `delete` to free the objects allocated by `new`
- If the destructors are **not `virtual`**, then just the destructor corresponding to the **pointer type** is called
- If the destructors are **`virtual`**, then that corresponding to the **object type** is called
- Using `virtual` ensures the correct sequence of destructors is called!

## Static and Dynamic Binding
- *Binding* the function name 
- C++ is more complicated for **function overloading**
- *Static(Early) binding*: binding during **compilation**
- *Dynamic(late) binding*: generating code allowing the correct **virtual** method to be selected as the program runs
- See the **virtual** methods in greater depth

### Pointer and Reference Type Compatibility
- Assciate with **methods invoked** by pointers and references(`virtual` function and `public` model inheritance)
- *Upcasting*: converting a **derived-class** reference or pointer to a **base-class** reference or pointer
> Upcasting is transitive
> Takes place for functions calls with base-class references or pointers as **parameters**

- *Downcasting*: converting a **base-class** reference or pointer to a **derived-class** reference or pointer, **not allowed without an explicit typecast**
> *Is-a* relationship is **not symmetric**
> A derived class could add new data members, the methods which uses the new members wouldn't apply to the base class

- Implicit upcasting makes it possible for a base-class pointer or reference points to or refers to either base-class object or a derived-class object
- We need the dynamic binding! Use `virtual` member functions!
### Virtual Member Functions and Dynamic Binding
- The compiler uses static binding for non-`virtual` methods
- The compiler uses dynamic binding for `virtual` methods
- Existence of static binding:
    - Static binding is default for efficiency, and it is the default choice for C++. **You shouldn't have to pay for features you don't use**
    - Go to `virtual` functions only if the program design needs them
    - For conceptual model, making the function non-`virtual` to announce **the function not be redefined**
    - Of course when we design a class, it is not always obvious into which category a method falls, but just fucking do it!
- How `virtual` function works:
    - The compiler adds a **hidden member** to each object holding a pointer of an array of function addresses(`virtual` function table or *vtbl*)
    - The vtbl holds the addresses of the `virtual` functions declared for objects of that class
        - An object of a base class contains a pointer to a table of addresses of all the `virtual` functions for that class
        - Then an object of a derived class contains a pointer to a **separate** table of addresses
    - If the derived class redefines one `virtual` function, the vtbl holds the address of the new function
    - If it doesn't redefine it, it holds the address of the **original version**(same address of `virtual` function as base class)
    - If it defines a new `virtual function`, its address is added to the vbtl, thus the table size varies
- When calling a `virtual` function, the program looks at the vbtl address stored in an object and goes to the corresponding table of function addresses
- Each object has its size increased by the amount needed to hold an address
- For each class, the compiler creates a table of addresses of virtual functions
- For each function call, there is an extra step of going to a table to look up an address
- Non-`virtual` functions don't provide dynamic binding

### Things to Know About Virtual Methods
- Constructors:
    - It **can not be `virtual`**
    - It does **not inherit the base-class constructors**
- Destructors:
    - It should be `virtual` **unless a class isn't to be used as base class**
    - If the static binding applies, the `delete` for base-class pointer invokes  the base-class destructor, and **frees the memory pointed to by the base-class components of the derived-class object**
    - Even if a base-class doesn't require the services of an explicit destructor, we should provide a `virtual` destructor even if it has nothing to do
- Friends:
    - It **can't be `virtual` function**
    - It is not a class member! But we can have the `friend` functions **use `virtual` member functions** internally
- No redefinition:
    - If a derived class fails to redefine a function, it uses the base-class version of the function
    - If a derived class is part of **a long chain of derivation**, it uses the **most recently defined version** of the function, **unless the base version is hidden**
- Redefinition Hides Methods:
    - Define base class: `class n1{public: virtual void fun(int a) const;`
    - Define derived class: `class n2:public n1{public: virtual void fun() const;`
    - It can get warnings, the redefinition **hides base class version that takes an `int` argument**
    - Redefining an inherited method is **not a variation of overloading** 
    - It does not just override the base class declaration
    - It **hides all base-class methods of the same name**
- Some rules:
    - Redefine an inherited method, we need to make sure we **match the original prototype exactly**, but the **return type being a reference or pointer to a base class can be replaced by a reference or pointer to the derived class**(covariance of return type)
    - If the base-class methods declaration is overloaded, we need to redefine **all the base-class versions in the derived class**, if no change is needed, redefine it to **simply call the base-class version** like `void n2::fun() const{n1::fun();}`

## Access Control: `protected`
- One more access category: `protected`
- Outside world can only access class members in a `protected` section only by using `public` class members(like **`private` members as far as the outside world is concerned**)
- Members of a derived class can access `protected` members of a base class directly(like **`public` members as far as derived classes are concerned**)
- It may simplify the code, but it can cause design defect
- We should **prefer `private` to `protected` access control for class datamembers**, and **use base-class methods** to provide derived classes access to base-class data
- While `protected` access control can be quite useful for **member functions**, giving derived classes **access to internal functions** unavailable publicly

## Abstract Base Classes
- Abstract from 2 classes what they have in common, and **derive them from the ABC**
- Then use an array of base-class pointers to manage a **mixture of 2 classes objects**, using a polymorphic approach!
- An **unimplemented function** using **pure `virtual` function** like `virtual type fun(par) = 0;`, where there will be a `=0` at the **end of declaration**
- We can **not create an object of a class which contains a pure `virtual` function**
    - The class exists solely to **serve as base classes**
    - A pure `virtual` function can have a definition
    - The `=0` just makes the class an **abstract base class** and the class **doesn't necessarily have to define the pure `virtual` function**
    - Remember, there is **no ABC object**!
    - Classes derived from abstract base class sometimes are termed **concrete classes** that we can create objects of those types
- An ABC describes an **interface using a least one pure `virtual` function**, classes derived from an ABC use **regular `virtual` functions`** to implement the interface in terms of the properties of the particular derived class

### Applying the ABC Concept
Source code: `C13_Abstractbase`
```C++
/*****abstract.h*****/
#ifndef ABSTRACT_H_
#define ABSTRACT_H_
#include <iostream>
#include <cstring>

class ABSTRACT
{
private:
	std::string name;
	long num_account;
	double balance;

protected:
	struct FORM
	{
		std::ios_base::fmtflags flag;
		std::streamsize prec;
	};
	inline const std::string& NAME(void) const{return name;}
	inline long NUM_ACCOUNT(void) const{return num_account;}
	FORM SET_FORMAT(void) const;
	void RESTORE(FORM& f) const;

public:
	ABSTRACT
	(const std::string& s="Nullbody", 
	 long an=-1, double bal = 0.0);
	void DEPOSIT(double money);
	inline double BALANCE(void) const{return balance;}
	virtual void WITHDRAW(double money)=0; // pure virtual 
	virtual void VIEW_ACCOUNT(void) const=0; // pure virtual no def
	virtual ~ABSTRACT(void){}; // it is necessary!
};

class BRASS : public ABSTRACT
{
public:
	inline BRASS
	(const std::string& s="Nullbody", 
	 long an=-1, double bal=0.0) : 
	ABSTRACT(s,an,bal){} // member initializer list
	inline virtual ~BRASS(void){};

	virtual void WITHDRAW(double money); // override
	virtual void VIEW_ACCOUNT(void) const;	
}; // no need the private

class BRASSPLUS : public ABSTRACT
{
private: // new features added as private members
	double max_loan;
	double rate;
	double owe_bank;

public:
	BRASSPLUS
	(const std::string& s="Nullbody",
	 long an=-1, double bal=0.0, double ml=500, double r=0.1);
	BRASSPLUS
	(const ABSTRACT& ba, double ml=500, double r=0.1);
	inline virtual ~BRASSPLUS(void){};

	virtual void WITHDRAW(double money); // pure virtual
	virtual void VIEW_ACCOUNT(void) const; 
	inline void RESER_MAX(double m){max_loan = m;}
	inline void RESER_RATE(double r){rate = r;}
	inline void RESER_OWE(void){owe_bank = 0;}
};

#endif

/*****abstract.cpp*****/
#include <iostream>
#include "abstract.h"

// abstract base class methods
ABSTRACT::ABSTRACT
(const std::string& s, long an, double bal)
{
	name = s;
	num_account = an;
	balance = bal;
}
ABSTRACT::FORM ABSTRACT::SET_FORMAT(void) const
{
	FORM f;
	f.flag = std::cout.setf
			 (std::ios_base::fixed, std::ios_base::floatfield);
	f.prec = std::cout.precision(2);

	return f;
}

void ABSTRACT::RESTORE(FORM& f) const
{
	std::cout.setf(f.flag, std::ios_base::floatfield);
	std::cout.precision(f.prec);
}

void ABSTRACT::DEPOSIT(double money)
{
	if(money < 0)
	{
		std::cout << "Negative deposit not allowed! " 
				  << "Deposit is cancelled.\n";
	}
	else
		balance += money;
}
void ABSTRACT::WITHDRAW(double money) // pure virtual function
{
	balance -= money;
}

// derived class1 methods 
void BRASS::WITHDRAW(double money) // protocol or contract
{
	if(money<0)
	{
		std::cout << "Withdrawal amount must be positive! "
				  << "Withdrawal is cancelled.\n";
	}
	else if(money <= BALANCE())
		ABSTRACT::WITHDRAW(money);
	else
	{
		std::cout << "Withdrawal amount of $" << money
				  << " exceeds your balance! "
				  << "Withdrawal is cancelled.\n";
	}
}

void BRASS::VIEW_ACCOUNT(void) const
{
	FORM f = SET_FORMAT();

	std::cout << "BRASS Client: " << NAME() << "\n";
	std::cout << "Account Number: " << NUM_ACCOUNT() << "\n";
	std::cout << "Balance: $" << BALANCE() << "\n";

	RESTORE(f);
}

// derived class2 methods 
BRASSPLUS::BRASSPLUS
(const std::string& s, long an, double bal, double ml, double r) : 
ABSTRACT(s, an, bal)
{
	max_loan = ml;
	owe_bank = 0.0;
	rate = r;
}

BRASSPLUS::BRASSPLUS
(const ABSTRACT& ba, double ml, double r) :
ABSTRACT(ba) // implicit copy constructor
{
	max_loan = ml;
	owe_bank = 0.0;
	rate = r;
}

void BRASSPLUS::VIEW_ACCOUNT(void) const
{
	FORM f = SET_FORMAT();

	std::cout << "BRASSPLUS Client: " << NAME() << "\n";
	std::cout << "Account Number: " << NUM_ACCOUNT() << "\n";
	std::cout << "Balance: $" << BALANCE() << "\n";
	std::cout << "Maximum loan: $" << max_loan << "\n";
	std::cout << "Owed to bank: $" << owe_bank << "\n";
	std::cout.precision(3);
	std::cout << "Loan rate: $" << 100*rate << "%\n";

	RESTORE(f);
}

void BRASSPLUS::WITHDRAW(double money)
{
	FORM f = SET_FORMAT();

	double bal = BALANCE(); // access only through public
	if(money < bal)
		ABSTRACT::WITHDRAW(money);
	else if(money <= bal+max_loan-owe_bank)
	{
		double advance = money-bal;
		owe_bank += advance*(1.0+rate);
		std::cout << "Bank advance: $" << advance << "\n";
		std::cout << "Bank advance: $" << advance*rate << "\n";
		DEPOSIT(advance);
		ABSTRACT::WITHDRAW(money);
	}
	else
		std::cout << "Credit limit exceeded!"
				  << "Transaction cancelled.\n";

	RESTORE(f);
}

/*****useabstract.cpp*****/
#include <iostream>
#include <cstring>
#include "abstract.h"

const int CLIENTS = 4;

int main(void)
{
	ABSTRACT* p_clients[CLIENTS]; // not objects, but pointers!
	std::string temp;
	long num_temp;
	double bal_temp;
	char kind;

	for(int i=0; i<CLIENTS; ++i)
	{
		std::cout << "Enter client's name: ";
		getline(std::cin, temp);
		std::cout << "Enter client's account number: ";
		std::cin >> num_temp;
		std::cout << "Enter opening balance: $";
		std::cin >> bal_temp;
		std::cout << "Enter 1 for BRASS account or "
				  << "2 for BRASSPLUS account: ";
		while(std::cin>>kind && (kind!='1' && kind!='2'))
			std::cout << "Enter 1 or 2: ";
		if(kind=='1')
			p_clients[i] = new BRASS(temp, num_temp, bal_temp);
		else
		{
			double tmax, trate;
			std::cout << "Enter the overdraft limit: $";
			std::cin >> tmax;
			std::cout << "Enter the interest rate as a "
					  << "decimal fraction: ";
			std::cin >> trate;
			p_clients[i] = new BRASSPLUS(temp, num_temp, bal_temp, 
										 tmax, trate);
		}

		while(std::cin.get()!='\n')
			continue; // filter input queue
	}
	std::cout << "\n";

	for(int i=0; i<CLIENTS; ++i)
	{
		p_clients[i]->VIEW_ACCOUNT();
		std::cout << "\n";
	}

	for(int i=0; i<CLIENTS; ++i)
	{
		delete p_clients[i]; // free memory
	}

	std::cout << "Done!\n";
	return 0;
}

```
- Test the ABC in previous polymorphic inheritance examples
- ABC can use `protected` member functions to handle some methods like **formatting previously handled by nonmember functions**
- Protect functions standalone from **conflicting with client-defined functions of the same name**
    - Declare the functions `static` making them **private to current file**
    - Place the functions and connected definition of `struct` into a `namespace`
    - Place them in the `protected` section of the ABC definition

```Console
Enter client's name: Harry Potter
Enter client's account number: 112233
Enter opening balance: $1500
Enter 1 for BRASS account or 2 for BRASSPLUS account: 1
Enter client's name: Dinah Otto
Enter client's account number: 121213
Enter opening balance: $1800
Enter 1 for BRASS account or 2 for BRASSPLUS account: 2
Enter the overdraft limit: $350
Enter the interest rate as a decimal fraction: 0.12
Enter client's name: Brenda Fuck
Enter client's account number: 212118
Enter opening balance: $5200
Enter 1 for BRASS account or 2 for BRASSPLUS account: 2
Enter the overdraft limit: $800
Enter the interest rate as a decimal fraction: 0.10
Enter client's name: Tim Jerry
Enter client's account number: 233255
Enter opening balance: $688
Enter 1 for BRASS account or 2 for BRASSPLUS account: 1

BRASS Client: Harry Potter
Account Number: 112233
Balance: $1500.00

BRASSPLUS Client: Dinah Otto
Account Number: 121213
Balance: $1800.00
Maximum loan: $350.00
Owed to bank: $0.00
Loan rate: $12.000%

BRASSPLUS Client: Brenda Fuck
Account Number: 212118
Balance: $5200.00
Maximum loan: $800.00
Owed to bank: $0.00
Loan rate: $10.000%

BRASS Client: Tim Jerry
Account Number: 233255
Balance: $688.00

Done!
```

### ABC Philosophy
- Much more systematic, disciplined to approach inheritance
- Develop a model of what classes are needed to represent a programming problem and the relations
- Some school of thought holds that if you design an inheritance hierarchy of classes, the **only concrete classes should be those that never serve as a base class**
- Cleaner designs with fewer complications  
- Consider them an enforcement of interface:
    - ABC demands that its pure `virtual` functions **be overriden in any concrete derived classes**, forcing derived class to obey the interface of ABC has set
    - Common in **component-based programming paradigms**, the use of ABCs allows the component designer to create an **interface contract** where all components derived from ABCs are guaranteed to uphold **at least the common functionality** specified by ABC

## Inheritance and Dynamic Memory Allocation
- Inheritance and dynamic memory allocation
- What if a base class uses dynamic memory allocation and redefines assignment operator and a copy constructor?
- If the derived class does **not itself use dynamic memory allocation**, no special steps are needed
- If the derived class does use dynamic memory allocation, there are new tricks
### Case1: Derived Class Doesn't Use `new`
- Base class using dynamic memory allocation: `class c1{private: char* label; public: c1(const char* l="null");};`
- This contains the special methods required when constructors use `new`
    - A destructor using `delete` to **free memory allocated**
    - A copy constructor for **deep copying**
    - An overloaded assignment operator for **deep copying** as well
- Define a derived class with no unusual design features requiring special treatment like `class DERIVE : public BASE{private: char ptr[40];...}`
- No need to define anything like base class for the derived class will **use those of the base class** when do anything to do with DMA

### Case2: Derived Class Does Use `new`
- Define a derived class using `new`: `class c2 : public c1{private: char* ptr; public: ...};`
- We have to define an explicit destructor, copy constructor and    assignment operator for the derived class
- A derived-class destructor **automatically** calls the base-class destructor
    - It has to clean up after what the derived-class constructors do, the base-class part is cleaned up automatically;
    - Do this like: `DERIVE::~DERIVE(void){delete [] ptr;}`, for `ptr` is not yet allocated in declaration!
- A derived-class copy constructor **must invoke the base-class copy constructor** 
    - Handle the base-class share of the data: `DERIVE::DERIVE(const DERIVE& dv) : BASE(dv)` for derived-class can only access its own members, **no access to base-class `private` members**!
    - Note that **the reference of base-class object as a parameter of base-class copy constructor** can refer to **derived-class object with its base-class data parts**
- A derived-class explicit assignment operator
    - Also has to **take care of assignment for base-class object**
    - Accomplish this by **explicit calling the base-class assignment operator** like: `DERIVE& DERIVE::operator=(const DERIVE& dv){...; BASE::operator=(dv);delete [] ptr;...}`
    - Same as `DERIVE& DERIVE::operator=(const DERIVE& dv){...; *this=dv; delete [] ptr;...}`, but using function notation(scope-resolution operator) gets the **correct assignment operator** called

### An Inheritance Example with Dynamic Memory Allocation and Friends
Source code: `C13_Inheritancedynamic`
```C++
/*****dynamic.h*****/
#ifndef DYNAMIC_H_
#define DYNAMIC_H_
#include <iostream>

class BASE
{
private:
	char* label;
	int rate;

public:
	// strlen(nullptr) undefined! don't initialize l as nullptr!
	BASE(const char* l="", int r=0);
	BASE(const BASE& bs);
	virtual ~BASE(void);

	BASE& operator=(const BASE& bs);
	friend 
	std::ostream& operator<<(std::ostream& os, const BASE& bs);
};

// derived class without dynamic memory allocation
class NODM : public BASE
{
private:
	static const int LEN=40; 
	char color[LEN];

public:
	NODM(const char* c="blank", const char* l="", int r=0);
	NODM(const char* c, const BASE& bs);
	inline virtual ~NODM(void){};

	friend 
	std::ostream& operator<<(std::ostream& os, const NODM& nd);
};

// derived class with dynamic memory allocation
class YEDM : public BASE
{
private:
	char* style;

public:
	YEDM(const char* s="blank", const char* l="", int r=0);
	YEDM(const char* s, const BASE& bs);
	YEDM(const YEDM& yd);
	virtual ~YEDM(void);

	YEDM& operator=(const YEDM& yd);
	friend 
	std::ostream& operator<<(std::ostream& os, const YEDM& yd);
};

#endif

/*****dynamic.cpp*****/
#include <iostream>
#include <cstring>
#include "dynamic.h"

// base class methods
BASE::BASE(const char* l, int r)
{
	label = new char[std::strlen(l)+1]; // strlen doesn't count '\0'
	std::strcpy(label, l);
	rate = r;
}

BASE::BASE(const BASE& bs)
{
	label = new char[std::strlen(bs.label)+1]; // inside class
	std::strcpy(label, bs.label); // access private members directly
	rate = bs.rate;
}

BASE::~BASE(void)
{
	delete [] label;
}

BASE& BASE::operator=(const BASE& bs)
{
	if(this==&bs)
		return *this;

	delete [] label;
	label = new char[std::strlen(bs.label)+1];
	std::strcpy(label, bs.label);
	rate = bs.rate;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BASE& bs)
{
	os << "Label: " << bs.label << std::endl;
	os << "Rate: " << bs.rate << std::endl;
	return os;
}

// derived class methods without dynamic memory allocation
NODM::NODM(const char* c, const char* l, int r) : BASE(l,r)
{
	std::strncpy(color, c, LEN-1);
	color[LEN-1]='\0';
}

NODM::NODM(const char* c, const BASE& bs) : BASE(bs)
{
	std::strncpy(color, c, LEN-1);
	color[LEN-1]='\0';
}

std::ostream& operator<<(std::ostream& os, const NODM& nd)
{
	os << (const BASE&) nd;
	os << "Color: " << nd.color << std::endl;
	return os;
}

// derived class methods with dynamic memory allocation 
YEDM::YEDM(const char* s, const char* l, int r) : BASE(l,r)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
}

YEDM::YEDM(const char* s, const BASE& bs) : BASE(bs)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
}

YEDM::YEDM(const YEDM& yd) : BASE(yd)
{
	style = new char[std::strlen(yd.style)+1];
	std::strcpy(style, yd.style);
}

YEDM::~YEDM(void)
{
	delete [] style;
}

YEDM& YEDM::operator=(const YEDM& yd)
{
	if(this==&yd)
		return *this;

	BASE::operator=(yd); // do the base class portion
	delete [] style;
	style = new char[std::strlen(yd.style)+1];
	std::strcpy(style, yd.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const YEDM& yd)
{
	os << (const BASE&) yd;
	os << "Style: " << yd.style<< std::endl;
	return os;
}

/*****usedynamic.cpp*****/
#include <iostream>
#include "dynamic.h"

int main(void)
{
	BASE shirt("Portabelly", 8);
	NODM balloon("red", "Blimpo", 4);
	YEDM trousers("Mercator", "Buffalo Keys", 5);

	std::cout << "Displaying BASE object:\n";
	std::cout << shirt << std::endl;
	std::cout << "Displaying NODM object:\n";
	std::cout << balloon << std::endl;
	std::cout << "Displaying YEDM object:\n";
	std::cout << trousers << std::endl;

	NODM balloon2(balloon); // implicit copy constructor
	std::cout << "Result of NODM copy:\n";
	std::cout << balloon2 << std::endl;

	YEDM trousers2(trousers);
	std::cout << "Result of YEDM copy:\n";
	std::cout << trousers2 << std::endl;

	YEDM trousers3; // default constructor
	// std::cout << "Result of YEDM default constructor:\n";
	// std::cout << trousers3 << std::endl;
	trousers3 = trousers;
	std::cout << "Result of YEDM assignment:\n";
	std::cout << trousers3 << std::endl;

	return 0;
}

```
- Discuss inheritance with dynamic memory allocation and friends
- A `friend` function: derived classes can also access friends to a base class!
    - We need to define the **function a friend to base class** 
    - We also need to define the **function a friend to all derived classes** 
    - Use **type cast** so that the prototype matching will select the correct function
- Do this like: `std::ostream& operator<<(std::ostream& os, const DERIVE& dv){os << (const BASE&)dv; os << "pointer: " << dv.ptr << "\n"; return os;}`
- Remember, for class constructor, there shouldn't be **non-default parameters following default parameters**, and `strlen(nullptr)` is undefined!

```Console
Displaying BASE object:
Label: Portabelly
Rate: 8

Displaying NODM object:
Label: Blimpo
Rate: 4
Color: red

Displaying YEDM object:
Label: Buffalo Keys
Rate: 5
Style: Mercator

Result of NODM copy:
Label: Blimpo
Rate: 4
Color: red

Result of YEDM copy:
Label: Buffalo Keys
Rate: 5
Style: Mercator

Result of YEDM assignment:
Label: Buffalo Keys
Rate: 5
Style: Mercator
```

## Class Design Review
- We can't reduce class design to some **paint-by-numbers** routine
- But we can go over some guidelines as reviewing

### Member Functions That the Compiler Generates
- The compiler automatically generates some **special `public` member functions** for us(**marked**)
- Default constructors
- Copy constructors
- Assignment operators


### Other Class Method Considerations
- Constructor considerations
- Destructor considerations
- Conversion considerations
- Passing an object by value versus by reference
- Returning an object by value versus by reference
- Using `const`

### `public` Inheritance Considerations
- *Is-a* relationship considerations
- Not inherited stuff
- Assignment operator considerations
- `private` versus `protected` members
- `virtual` method considerations
- Destructor considerations
- `friend` considerations
- Observations on using base-class methods

### Class Function Summary
- Class functions come in many variations
- Some can be inherited, some can't
- Some can be either member functions or friends, others can only be member functions

