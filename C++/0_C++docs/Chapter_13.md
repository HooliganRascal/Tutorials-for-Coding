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

### Pointer and Reference Type Compatibility

### Virtual Member Functions and Dynamic Binding

### Things to Know About Virtual Methods
