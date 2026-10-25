# Working with Classes
---
## Operator Overloading

- Overloading just like the language, one word for multiplie meanings
- Many operators are already overloaded like `*`
- *Operator function* to overload operators: `operatorop(arguments)`
    - Example, to overload `+`, use `operator+()`
    - Define an operator function in a class, and all the objects in the same class share it
    - Translation: `obj1=obj2+obj3` is `obj1 = obj2.operator+(obj3)`
- There are some restrictions though

## Develop an Operator Overloading Example
Source code: `C11_Operatoroverload`
```C++
/*****time0.h*****/
#ifndef TIME0_H_
#define TIME0_H_

class TIME{
	private:
		int hours;
		int minutes;
	public:
		TIME(void);
		TIME(int h, int m=0);
		~TIME(void);

		void ADDMIN(int m);
		void ADDHOUR(int h);
		void RESET(int h=0, int m=0);
		TIME SUM(const TIME& t) const;
		void SHOW(void) const;
};
		
#endif

/*****time0.cpp*****/
#include <iostream>
#include "time0.h"


time::time(void){
	hours = minutes = 0;
}

time::time(int h, int m){
	hours = h;
	minutes = m;
}

time::~time(void){} // destructor

void time::addmin(int m){
	minutes += m;
	hours += minutes/60;
	minutes %= 60;
}

void time::addhour(int h){
	hours += h;
}

void time::reset(int h, int m){
	hours = h;
	minutes = m;
}

time time::sum(const time& t) const{
	time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}

void time::show(void) const{
	std::cout << hours << " hours " << minutes << " minutes\n";
}

/*****usetime0.cpp*****/
#include <iostream>
#include "time0.h"

int main(void){
	TIME planning;
	TIME coding(2,40);
	TIME fixing(5,55);
	TIME total;

	std::cout<< "planning time = ";
	planning.SHOW();
	std::cout<< "coding time = ";
	coding.SHOW();
	std::cout<< "fixing time = ";
	fixing.SHOW();
	
	total = coding.SUM(fixing);
	std::cout << "coding.SUM(fixing) = ";
	total.SHOW();

	return 0;
}
```
- For comparison, we make an ordinary version first
- For addition, we can use division and modulus

```Console
planning time = 0 hours 0 minutes
coding time = 2 hours 40 minutes
fixing time = 5 hours 55 minutes
coding.SUM(fixing) = 8 hours 35 minutes
```  

### Adding an Addition Operator
Source code: `C11_Operatoroverload`
```C++
/*****time1.h*****/
#ifndef TIME1_H_
#define TIME1_H_

class TIME{
	private:
		int hours;
		int minutes;
	public:
		TIME(void);
		TIME(int h, int m=0);
		~TIME(void);

		void ADDMIN(int m);
		void ADDHOUR(int h);
		void RESET(int h=0, int m=0);
		TIME operator+(const TIME& t) const;
		void SHOW(void) const;
};
		
#endif

/*****time1.cpp*****/
#include <iostream>
#include "time1.h"

TIME::TIME(void){
	hours = minutes = 0;
}

TIME::TIME(int h, int m){
	hours = h;
	minutes = m;
}

TIME::~TIME(void){} // destructor

void TIME::ADDMIN(int m){
	minutes += m;
	hours += minutes/60;
	minutes %= 60;
}

void TIME::ADDHOUR(int h){
	hours += h;
}

void TIME::RESET(int h, int m){
	hours = h;
	minutes = m;
}

TIME TIME::operator+(const TIME& t) const{
	TIME sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}

void TIME::SHOW(void) const{
	std::cout << hours << " hours " << minutes << " minutes\n";
}

/*****usetime1.cpp*****/
#include <iostream>
#include "time1.h"

int main(void){
	TIME planning;
	TIME coding(2,40);
	TIME fixing(5,55);
	TIME morefixing(3,28);
	TIME total;

	std::cout<< "planning time = ";
	planning.SHOW();
	std::cout<< "coding time = ";
	coding.SHOW();
	std::cout<< "fixing time = ";
	fixing.SHOW();
	
	total = coding+fixing; 
	std::cout << "coding + fixing = ";
	total.SHOW();

	std::cout<< "more fixing time = ";
	morefixing.SHOW();
	total=total.operator+(morefixing);
	std::cout<< "total.operator+(morefixing) = ";
	total.SHOW();

	return 0;
}
```
- Change the `SUM` to `operator+`
- The object to the left of`+` is **the invoking object**
- The object to the right of `+` is the one **passed as an argument**
- The order matters sometimes
- Operating function allows to be invoked by either function notation or operator notation
- For *left-to-right* `+` operator, it is available to do `t4=t1+t2+t3`

```Console
planning time = 0 hours 0 minutes
coding time = 2 hours 40 minutes
fixing time = 5 hours 55 minutes
coding + fixing = 8 hours 35 minutes
more fixing time = 3 hours 28 minutes
total.operator+(morefixing) = 12 hours 3 minutes
```

### Overloading Restriction
- Overloaded operators with some exceptions do **not necessarily have to be member functions**!
- Restrictions:
    - Overloaded operator must have **at least one operand with user-defined type**, `double operator-(double a, double b){return a+b}` is not allowed
    - We can’t use an operator in a manner that **violates the syntax rules for the original**, overloaded `%` is not allowed for simply `% a;`, and **precedence is not allowed to be altered**
    - We can't create new operator symbols like `operator**()`
    - List of not allowable overloading operators like `::`
    - Most of the allowable overloading operators can be done by using **member functions or nonmember functions**, but list of operators **only allowable for member functions like `=`**
- Use **sensible restraint** in overloading operators as a good habit

### More Overloaded Operators
Source code: `C11_Operatoroverload`
```C++
/*****time2.h*****/
#ifndef TIME2_H_
#define TIME2_H_

class TIME{
	private:
		int hours;
		int minutes;
	public:
		TIME(void);
		TIME(int h, int m=0);
		~TIME(void);

		void ADDMIN(int m);
		void ADDHOUR(int h);
		void RESET(int h=0, int m=0);
		void SHOW(void) const;

		TIME operator+(const TIME& t) const;
		TIME operator-(const TIME& t) const;
		TIME operator*(double mult) const;
};
		
#endif

/*****time2.cpp*****/
#include <iostream>
#include "time1.h"

TIME::TIME(void){
	hours = minutes = 0;
}

TIME::TIME(int h, int m){
	hours = h;
	minutes = m;
}

TIME::~TIME(void){} // destructor

void TIME::ADDMIN(int m){
	minutes += m;
	hours += minutes/60;
	minutes %= 60;
}

void TIME::ADDHOUR(int h){
	hours += h;
}

void TIME::RESET(int h, int m){
	hours = h;
	minutes = m;
}

TIME TIME::operator+(const TIME& t) const{
	TIME sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}

void TIME::SHOW(void) const{
	std::cout << hours << " hours " << minutes << " minutes\n";
}

/*****usetime2.cpp*****/
#include <iostream>
#include "time2.h"

int main(void){
	TIME weeding(4,35);
	TIME waxing(2,47);
	TIME total;
	TIME diff;
	TIME adjusted;

	std::cout<< "weeding time = ";
	weeding.SHOW();
	std::cout<< "waxing time = ";
	waxing.SHOW();
	
	total = weeding+waxing; 
	std::cout << "total work time = ";
	total.SHOW();

	diff = weeding-waxing; 
	std::cout<< "weeding time - waxing time = ";
	diff.SHOW();

	adjusted = total*1.5; 
	std::cout << "adjusted work time = ";
	adjusted.SHOW();

	return 0;
}
```

- The overloaded `-` or `*` works in the same principle as `operator+`

```Console
weeding time = 4 hours 35 minutes
waxing time = 2 hours 47 minutes
total work time = 7 hours 22 minutes
weeding time - waxing time = 1 hours 48 minutes
adjusted work time = 11 hours 3 minutes
```

## Introducing Friends

- Another way to access the `private` portion of a class despite the methods declared in `public`
- Friend: 
    - Friend functions
    - Friend classes
    - Friend member functions
- Look into friend functions now, other 2 features in [Chapter\_15](Chapter_15.md)
    - Consider `A = B * 2.75` to `A = B.operator* (2.75)`
    - What about `A = 2.75 * B`?
    - Consider a nonmember oveloaded operator function: `A = operator* (double m,const classtype& t)`, that might work
    - Thus we need the nonmember function to access `private` data to get our **desired order of parameters**

### Creating Friends

- Place a function prototype in **class declaration**: `friend name operator+(type1,const name& t);` It is not a member function
- Implement the function definition like `name operator+(type1, const name& t){}`
- A friend function to a class is a **nonmember function with the same access rights as a member function**
- A tricky thought, implement it by overloading operators: `name operator* (type1 m, const name& t){return t * m;}`

### A Common Kind of Friend: Overloading `<<`
Source code:`C11_Operatoroverloaded`
```C++
/*****time3.h*****/
#ifndef TIME3_H_
#define TIME3_H_
#include <iostream>

class TIME{
	private:
		int hours;
		int minutes;
	public:
		TIME(void);
		TIME(int h, int m=0);
		~TIME(void);

		void ADDMIN(int m);
		void ADDHOUR(int h);
		void RESET(int h=0, int m=0);

		TIME operator+(const TIME& t) const;
		TIME operator-(const TIME& t) const;
		TIME operator*(double mult) const;
		friend inline TIME operator*(double mult, const TIME& t){
			return t*mult;
		}
		friend std::ostream& operator<<(
			std::ostream& os, 
			const TIME&t
		);
};
		
#endif

/*****time3.cpp*****/
#include "time3.h"

TIME::TIME(void){
	hours = minutes = 0;
}

TIME::TIME(int h, int m){
	hours = h;
	minutes = m;
}

TIME::~TIME(void){} // destructor

void TIME::ADDMIN(int m){
	minutes += m;
	hours += minutes/60;
	minutes %= 60;
}

void TIME::ADDHOUR(int h){
	hours += h;
}

void TIME::RESET(int h, int m){
	hours = h;
	minutes = m;
}

TIME TIME::operator+(const TIME& t) const{
	TIME sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}

TIME TIME::operator-(const TIME& t) const{
	TIME diff;
	int tot1 = t.minutes + 60*t.hours; // to subtract
	int tot2 = minutes + 60*hours; // to be subtracted
	diff.minutes = (tot2-tot1)%60;
	diff.hours = (tot2-tot1)/60;
	return diff;
}

TIME TIME::operator*(double mult) const{
	TIME result;
	long totalmin = hours*mult*60+minutes*mult;
	result.minutes = totalmin%60;
	result.hours = totalmin/60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const TIME& t){
	os << t.hours << " hours, " << t.minutes << " minutes\n";
	return os;
}

/*****usetime3.cpp*****/
#include <iostream> // time3.h already includes one
#include "time3.h"

int main(void){
	TIME cosmos(4,35);
	TIME mteltn(2,47);
	TIME temp;

	std::cout << "Cosmos and Mteltn:\n";
	std::cout << cosmos 
			  << mteltn << "\n";
	std::cout << "Cosmos + Mteltn:\n"
			  << (temp = cosmos+mteltn) << "\n";
	std::cout << "Cosmos*1.7:\n"
			  << (temp = cosmos*1.7) << "\n";
	std::cout << "10.2*Mteltn:\n"
			  << (temp = 10.2*mteltn) << "\n";

	return 0;
}
```

- It is already heavily overloaded in `ostream` class
- `ostream` class definition includes an overloaded `operator<<()`
- It’s a dangerous idea to alter the iostream file and mess around with a standard interface.
- Use the `name` class declaration to teach `name` class how to use `<<`
- Remember that `cout` is an object of `ostream` class
- First version: `friend void operator<<(ostream& os, const name& t)`
    - Declared in `name` class definition, thus a friend of `name` rather than `ostream`
    - Another `ostream` object: `cerr` to route output to the standard error stream, the display by default
    - By [inheritance](Chaper_13.md), methods in `ostream` can work in `ofstream`, thus we can *redirect the standard error stream to a file, just replace the first**argument**with `ofstream`
- Second version: `friend ostream& operator<<(ostream& os, const name& t)`
    - First version works with `cout << obj`, but not for `cout << obj << ...`
    - The `cout` works in `cout << x << y` as `(cout << x) << y`, thus it **returns a reference to the `ostream` object**
- Use `friend` for prototypes found in class declaration only

```Console
Cosmos and Mteltn:
4 hours, 35 minutes
2 hours, 47 minutes

Cosmos + Mteltn:
7 hours, 22 minutes

Cosmos*1.7:
7 hours, 47 minutes

10.2*Mteltn:
28 hours, 23 minutes
```

## Overloaded Operators: Member Versus Nonmember Functions
- The nonmember version is typically a `friend` function to directly access the private data for a class
- Member version passed one object **implicitly** while another one **explicitly**
- Nonmember version passed them all **explicitly**
- For the **same signatures**, we can choose **only one version**

## More Overloading: A Vector Class
Source code:`C11_Vectoroverload`
```C++
/*****vect.h*****/
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace vect{
	class VECTOR{
		// variables
		public:
			enum MODE{
				RECT, 
				POLA
			};
		private:
			double x,y; // x-coor, y-coor
			double r,w; // magnitude, angle(radian)
			MODE mode;
		
		// function
		private:
			void set_r(void);
			void set_w(void);
			void set_x(void);
			void set_y(void);
		public:
			// constructor and destructor
			VECTOR(void);
			VECTOR(double n1, double n2, MODE form=RECT);
			~VECTOR(void);

			// basic interface
			void reset(double n1, double n2, MODE form=RECT);
			inline double xval(void) const{return x;};
			inline double yval(void) const{return y;};
			inline double rval(void) const{return r;};
			inline double wval(void) const{return w;};

			// mode transfer
			void mode_pola(void);
			void mode_rect(void);

			// overloading
			VECTOR operator+(const VECTOR& b) const;
			VECTOR operator-(const VECTOR& b) const;
			VECTOR operator-(void) const; // negation
			VECTOR operator*(double n) const; 
			
			// friend functions
			friend VECTOR operator*(
					double n, 
					const VECTOR& a
				);
			friend std::ostream& operator<<(
					std::ostream& os, 
					const VECTOR& v
				);
	};

	const double pi = 3.1415926535897;
	const double rad_to_deg = 180.0/pi;
	const double deg_to_rad = pi/180.0;

	VECTOR operator*(
			double n, 
			const VECTOR& a
		);
	std::ostream& operator<<(
			std::ostream& os, 
			const VECTOR& v
		);
}

#endif

/*****vect.cpp*****/
#include <cmath>
#include "vect.h"

void vect::VECTOR::set_r(void){
	r = std::sqrt(x*x+y*y);
}

void vect::VECTOR::set_w(void){
	if(x==0 && y==0)
		w = 0.0;
	else
		w = std::atan2(y,x);
}

void vect::VECTOR::set_x(void){
	x = r*std::cos(w);
}

void vect::VECTOR::set_y(void){
	y = r*std::sin(w);
}

// Constructor and Destructor
vect::VECTOR::VECTOR(void){
	x = y = r = w = 0.0;
	mode = RECT;
}
vect::VECTOR::VECTOR(double n1, double n2, vect::VECTOR::MODE form){
	mode = form;
	if (form==RECT){
		x = n1;
		y = n2;
		set_r();
		set_w();
	}
	else if (form==POLA){
		r = n1;
		w = n2*vect::deg_to_rad;
		set_x();
		set_y();
	}
	else{
		std::cout << "Incorrect 3rd argumemt to VECTOR() -- "
				  << "vector set to 0\n";
		x = y = r = w = 0.0;
	}
}
vect::VECTOR::~VECTOR(void){}

// Interface
void vect::VECTOR::reset(double n1, double n2, MODE form){
	mode = form;
	if (form==RECT){
		x = n1;
		y = n2;
		set_r();
		set_w();
	}
	else if (form==POLA){
		r = n1;
		w = n2*vect::deg_to_rad;
		set_x();
		set_y();
	}
	else{
		std::cout << "Incorrect 3rd argumemt to VECTOR() -- "
				  << "vector set to 0\n";
		x = y = r = w = 0.0;
	}
}

void vect::VECTOR::mode_pola(void){mode = POLA;}
void vect::VECTOR::mode_rect(void){mode = RECT;}

// Operator Overloading
vect::VECTOR 
vect::VECTOR::operator+(const vect::VECTOR& b) const{
	return VECTOR(x+b.x, y+b.y);
}

vect::VECTOR 
vect::VECTOR::operator-(const vect::VECTOR& b) const{
	return VECTOR(x-b.x, y-b.y);
}

vect::VECTOR 
vect::VECTOR::operator-(void) const{
	return VECTOR(-x, -y);
}

vect::VECTOR 
vect::VECTOR::operator*(double n) const{
	return VECTOR(n*x,n*y);
}

vect::VECTOR 
vect::operator*(double n, const vect::VECTOR& a){
	return a*n;
}

std::ostream& 
vect::operator<<(std::ostream& os, const vect::VECTOR& v){
	if (v.mode == vect::VECTOR::RECT){
		os << "(x,y) = (" 
		   << v.x << ", " 
		   << v.y << ")";
	}
	else if (v.mode == vect::VECTOR::POLA){
		os << "(r,w) = (" 
		   << v.r << ", "
		   << v.w*vect::rad_to_deg 
		   << ")";
	}
	else
		os << "Vector object mode is invalid";
	return os;
}

/*****randwalk.cpp*****/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main(void){

	vect::VECTOR step_vec, result_vec;
	unsigned long step_num = 0;
	double angle_dir, target, step_len;

	srand(time(0));
	std::cout << "Enter target distance (q to quit): ";

	while(std::cin >> target){
		std::cout << "Enter step length: ";
		if(!(std::cin >> step_len))
			break;

		while(result_vec.rval() < target){
			angle_dir = rand() % 360;
			step_vec.reset(step_len, angle_dir, vect::VECTOR::POLA);
			result_vec = result_vec + step_vec;
			step_num++;
		}

		std::cout << "After " << step_num 
				  << " steps, the subject has the following location:\n";
		std::cout << result_vec << std::endl;
		result_vec.mode_pola();
		std::cout << "or\n" << result_vec << std::endl;
		std::cout << "Average outward distance per step = "
				  << result_vec.rval()/step_num << std::endl;
		
		step_num = 0;
		result_vec.reset(0.0, 0.0);
		std::cout << "Enter target distance (q to quit): ";
	}

	std::cout << "Bye!\n";
	std::cin.clear(); // clean out flags including eof
	while(std::cin.get()!='\n')
		continue;
	
	return 0;
}
```

- Vector: a quantity with both size and direction
- Implement a 2-D vector with 2 numbers, either `x-y` or `mag-ang`
- Define a class to represent such stuff in a `namespace` to reflesh our memory
- Short functions could be good to be inlining
- Define all the functions in a namespace with its **open nature**
- Define constants in a namespace or globally in a header file. former is the better
- `friend` operator overloading functions 
    - Declared in a class in a namespace have namespace scop
    - though it is not a member function, scope is **out of class**, more like global but not,
    - **The name of friend function has namespace scope**
- State member describe the state an object is in, like `mode = RECT`
- Operator overloading is implemented with functions, we can overload the same operator many times as long as the **signature is distinct** and same **number of operands as the built-in C++ operators** 
- For overloading operators, the **order of parameters determines the order of operands!**
    - Subtraction: *binary operator*
    - Minus sign: *unary operator*
- A class can help us think of a quantity in terms of its essential nature rather than in terms of representations
- If a method is to compute a new class object, see if we can use a class constructor to make sure it is in a proper fashion
- This case uses a *random walk problem* as an example, to estimate how a drunckard inefficient in walking can be, the variations are shown from trial to trial, but by probability:
    $$\bar N = \left(\frac{D}{s}\right)^{2}$$
    - $\bar N$ is the average steps it takes
    - $D$ is the total distance
    - $s$ is the step size
- So if you find yourself walking randomly, be confident and take long steps.You still won’t have any control over the direction you wind up going, **but at least you’ll get farther**.

> Note:
> For multifile compilation, each translation unit is quite independent, thus the **header file including function prototypes needs including** to have each unit **sees the function declarations**

- Random numbers:
    - `rand()` returns a **random integer from zero to some implementation-dependent** value
    - `rand()` apply an algorithm to an **initial seed** to get a random value
    - The first random value is **used as the seed for the second** function call, and so on
    - The numbers are **pseudorandom**
        - Simply using the `rand()` for multiple times can produce different random numbers
        - But each time we rerun the program, **the same sequence of random numbers** will be applied
    - `srand()` can **override the default seed value** and initiate a different sequence of random numbers
    - Typically, we use the return value of `time(0)` or `time(NULL)` to set the seed
- About `time()`
    - Take the **address of a type `time_t` variable**
    - Put the time into that variable, return it
    - Use `0` as the address argument obviates the need for an otherwise unneeded `time_t` variable
- C++11 provides more extensive random numbers support with functions functions supported by `random` header file
- Overloading operator function, when using it, it creates the object by using the **default constructor**, then it is assigned to the value(temporary object!)
- We can **override the default assignment by defining an assignment operator for the class**, see [Chapter\_12](Chapter_12.md)
- To save successive positions in a file, use `<fstream>` and create `ofstream obj1`, then use `obj1.open("filename")` and replace `cout` with `obj1`
```Console
Enter target distance (q to quit): 50
Enter step length: 2
After 999 steps, the subject has the following location:
(x,y) = (50.4941, -2.28782)
or
(r,w) = (50.5459, -2.59422)
Average outward distance per step = 0.0505965
Enter target distance (q to quit): 50
Enter step length: 2
After 387 steps, the subject has the following location:
(x,y) = (-21.2538, -46.4217)
or
(r,w) = (51.0558, -114.6)
Average outward distance per step = 0.131927
Enter target distance (q to quit): 50
Enter step length: 1
After 4068 steps, the subject has the following location:
(x,y) = (31.8877, -38.6079)
or
(r,w) = (50.0739, -50.4455)
Average outward distance per step = 0.0123092
Enter target distance (q to quit): q
Bye!
```

## Automatic Conversions and Type Casts for Classes
Source code: `C11_Conversions`
```C++

```
- Automatic conversions may lose **precisions like `int a = 0.3`**
- C++ does not convert incompatible types like `int* p = 10`, to do so, use `int* p = (int*) 10`, called *type-casting*
- Use a class to do the type casting

```Console

```
### Conversion Functions

### Conversions and Friends
