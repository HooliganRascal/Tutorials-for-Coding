# Setting Out to C++
---
## Initiation

- C++ is *case sesitive*
- C++ uses `//` to comment as well

---
Example code:
```C++
#include<iostream>                                                    
                                                                      
int main(void){                                                       
        using namespace std;                                          
        cout << "Hello World!";                                       
        cout << endl;                                                 
        return 0;                                                     
} 
```
- `#include<iostream>` : preprocessor directive
    - `#include` : to add some files
    - `iostream` : header file, `io` refers to *input and output*, to use `cin` and `cout`
- `int main(void)` : function header
    - `int` : types of return value, refers to *integer*
    - `main` : name of the function
    - `void`: can be replaced with empty space, the function takes no *arguments*
- `{ statements; return 0; }` : function definition
    - ` statements; return 0;`: function body
        - `using namespace std;`: using directive, `std` refers to *standard*
        - `cout << "Hello World!;` : output messages where `cout` refers to *see out*
        - `cout << endl;` : start a new line
        - `return 0;`: terminates the function (necessary!)

> `0` as return value as indicated by `int` from `int main`

> Another type of function header to omit the return statement: `void main()`,while this is not C++ standard, avoid it!

---
## Namespace
Namespace discriminates the different versions of the key words
   - `iostream` needs the namespace or uses `std::cout` instead of simply `cout`
   - `using std::cout` particularly makes `cout` available
   - such *using directive* can be **local or global**

---
Local namespace:
```C++
#include <iostream>                                                   
                                                                      
int main(void){                                                       
        using namespace std;                                                  
        cout << "Hello World!" << endl;                               
        return 0;                                                     
}  
```
---
Global namespace:
```C++
#include <iostream>                                                   
using namespace std;                                                  
                                                                      
int main(void){                                                       
        cout << "Hello World!" << endl;                               
        return 0;                                                     
}  
```

## Statements

Source code
```C++
#include<iostream>

int main(void){

	using namespace std;
	
	// Declaration
	int a;
	int b = 3; // Declaration and Assignment
	int c;

	// Assignment
	a = 2;
	cout << "Enter the value of c: ";
	cin >> c; // Input

	//Output
	cout << "The value of a is " << a << endl;
	cout << "The value of b is " << b << endl;
	cout << "The value of c is " << c << endl;

	return 0;
}
```
- `int a`: declaration statement, consisting of `int`(type) and `a`(name)
- `a = 2`: assignment statement, consisting of `a`(variable) amd `2`(value)
- `int a = 2`: combination of declaration and assignment statement
- `cin >> c` : input statement
    - before input, **leave a space in the string**
    - after input, **switch to new line automatically**

> `cin >> name` means **do something to `name`**
> `cout << name` means **let `name` do something like output**
>   - leave a space **before and after** `name` when using the `cout`
>   - `iostream` stores the **class** defining the data forms amd how they can be used
>   - `cout`, `cin` are **objects** created to have the properties of the classes in `iostream`

## Functions

Source Code:
```C++
#include <iostream>
#include <cmath>
//#include <math.h>

int main(void){

	using namespace std;

	double x;
	double y;

	x = 6.25;
	y = sqrt(x);
	cout << "The square root of " 
		 << x 
		 << " is " 
		 << y 
		 << endl;
	
	return 0;
}
```
- `y = sqrt(x)` : squre root function
    - `x` : argument or parameter
    - `sqrt()` : call the function
    - `y` : return the value of `sqrt(x)` 
- `double sqrt(double);` : function prototype
- C and C++ divide the function into *prototype* and *definition* features
- For C, using `math.h` requires `-lm` like `gcc *.c -o * -lm`
- For C++, whether using `math.h` or `cmath`, it's free from `-lm`, just simply `g++ *.cpp -o *`
- `int main(void)` function return the value `0` to the *system* for responding 

## Self-Defined Function

Source code:
```C++
#include <iostream>
#include <cmath>

using namespace std;

double sqplus(double, double);

int main(void){

	double a = 2.0;
	double b = 1.0;
	double c = sqplus(a,b);

	cout << "square root of "
		 << a 
		 << " plus " 
		 << b
		 << " is equal to "
		 << c
		 << endl;

	return 0;
}

double sqplus(double m, double n){
	return sqrt(m)+n;
}
```
- `double sqplus(double, double` : prototype
- `double sqplus(double m, double n)` : header
