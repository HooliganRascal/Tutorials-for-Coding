# Functions: C++'s Programming Modules
---
## Function review
Source code: `C7_Functionreview`
```C++
#include<iostream>

using namespace std;

int PLUS(int, int); // Variable names are optional

int main(void){

	int a=0;
	int b=1;
	int c=PLUS(a,b);

	cout << a << " plus " << b << " = " << c << endl;

	return 0;
}

int PLUS(int a, int b){
	return a+b;
}
```
- Prototype: `type name(list of type of parameter);`
    - The names of the parameters are optional
    - `type name(void)` means the function has **no argument**
    - `type name()` works the same as `type name(void)`
    - `type name(...)` means the the parameters are **variant**, any number,any type!
    - Prototyping produces **automatic type casts** to the expected types **only when it makes sense**
    - Prototyping takes places during compile time, termed *static type checking*
- Definition: `type name(list of parameters){statements; return value}`
- Calling: `value = name(parameters)`
- If to **avoid using a function prototype**, place the definition **before** its first use!

```Console
0 plus 1 = 1
```

## Function arguments and passing by value
Source code: `C7_Functionargumemts`
```C++
#include<iostream>

using namespace std;

int possible(int, int);

int main(void){

	int total = 51;
	int choices = 6;
	int chances = possible(total, choices);

	cout << "For " << choices << " choices in " << total << " cards" << endl;
	cout << "You have one chance in " << chances << " possibilities" << endl;

	return 0;
}

int possible(int all, int pick){

	// long double fina=1;
	// for(int i=all; i>(all-pick); --i){
	// 	fina*=i; 
	// }
	// for(int j=pick; j>0; --j){
	// 	fina/=j;
	// }

	long double fina=1.0;
	for(long double i=all,j=pick; j>0; --i,--j){ // int i,j works too!
		fina *= i;
		fina /= j;
	}

	return fina;
}
```
- Pass arguments by value 
    - Formal argument/**parameter** `type name(type par){statements;}`: variable receiving passed value
    - Actual **argument**/parameter `{value = name(arg);}`: variable passing value to the function
- Variables including **parameters** are private or **localized** to the function
    - Allocate the memory when the function is called
    - Free the memory when the function terminated
    - Same `x` in different functions are **distinct, unrelated variables**, termed *automatic variables*
- Multiple arguments are prototyped separately, `cin >> a >> b` is separated with `space`
- If algorithms involve **division**, make sure the precision and **float type** is sufficient!

```Console
For 6 choices in 51 cards
You have one chance in 18009460 possibilities
```

## Functions and arrays
Source code: `C7_`
```C++
#include<iostream>

using namespace std;

// Some necessary constant
const int sizear = 8;
const int coef = 10;

// Function prototypes
int sumar(const int*, int); 
void timesar(int*, int); 
void artimes(int* begin, int* end);
void showar(const int*, int);

// Main function
int main(void){

	int name[sizear] = {1,2,3,4,5,6,7,8};
	int sum1, sum2;
	
	const int* pt = name; // Invariant, but can point to others
	int* const tp = name+3; // Variant, but can only point to one
	const int* const ptp = name+3; // Invariant and can only point to one

	// Show the size of the full array
	cout << "Array: ";
	for(int i=0; i<sizear; ++i){
		cout << name[i] << " ";
	}
	cout << "\nAddress " << name << " with size of " << sizeof(name) << endl;

	// Show the size of the pointer
	showar(name, sizear);

	// Operate with array in function
	sum1 = sumar(name, 3); // Sum of first 3 elements
	sum2 = sumar(name+4, 4); // Sum of last 4 elements
	
	cout << endl;
	cout << "The sum of first 3 elements of array is " << sum1 << endl;
	cout << "The sum of last 4 elements of array is " << sum2 << endl;
	cout << endl;

	timesar(name, 3); // Modify for first 3 elements;
	artimes(name+4, name+sizear); // Modify for last 4 elements;
	showar(name, sizear);
	cout << endl;
	
	// Do something with pointer and const
	cout << "const int* is " << *pt << " before" << endl;
	cout << "const int* is " << *(pt = name+3) << " now" << endl;
	cout << "int* const is " << *tp << " before" << endl;
	*tp+=1;
	cout << "int* const is " << *(name+3) << " now" << endl;
	cout << "const int* const is " << *ptp << " forever" << endl;
	
	return 0;
}

// Not modifiable
int sumar(const int* ar, int limit){
	int sum = 0;
	for(int i=0; i<limit; ++i){
		sum += ar[i];
	}
	return sum;
}

// Modifiable
void timesar(int* ar, int limit){
	for(int i=0; i<limit; ++i){
		*(ar+i) *= coef;
	}
}

// Modify by range
void artimes(int* begin, int* end){
	for(int i=0; i<(end-begin); ++i){ // Index suits the rule
		*(begin+i) *= coef;
	}
}

// Show the array and its content
void showar(const int* ar, int limit){
	cout << "Array: ";
	for(int i=0; i<limit; ++i){
		cout << ar[i] << " ";
	}
	cout << "\nAddress " << ar << " with size of " <<  sizeof(ar) << endl;
}
```
- `type name(type var[], type size);` The `var[]` is a pointer
- `array == &array[0]` Array name is the pointer to the first element
- `type name(type*, type)` Prototype for array as a pointer(Make sense only when used in a function header or prototype!)
- Pass the location of the furst element can save the time and memory
- The **pointer** by itself **does not reveal the size** of the array!
    - Functions **using ordinary arguments work with a copy**
    - Functions **using arrays work with the original!**
    - Use `type name(const type*, type)` to protect the original if not to change it!
- *Bottom-up programming* for OOP: from component parts to the whole
- *Top-down programming* for PP: from a modular grand design to detail
- Functions **using array ranges**: `type name(type* begin, type* end)`; 
- Pointer and `const`: `const type* name`
    - Make a pointer point to a constant object(not to change the value with the pointer)
    - Make the pointer itself a constant(not to change where the pointer points)
- Assign the address of a `const` variable to a pointer to const is valid
- Assign the address of a regular variable to a pointer to const is valid
- Assign the address of a `const` variable to a regular pointer is **not valid**
- Pointer to pointer is a bit more complex
- Using `const` allows both `const` and non-`const` arguments, while omitting `const` in the prototype can accept only non-`const` data
- `const type* pointer` does not prevent us from changing the value of `pointer` itself!
- `int* const name` allows to using `name` to alter the value of which the address is assigned to `name`
- `type* name(const type* ar, type var)` can not alter the values in the array that passed to it, works **as long as there is just one level of indirection**
- For **pointers or pointers to pointers**, we would not use `const`!

```Console
Array: 1 2 3 4 5 6 7 8 
Address 0x7ffd9cf23b40 with size of 32
Array: 1 2 3 4 5 6 7 8 
Address 0x7ffd9cf23b40 with size of 8

The sum of first 3 elements of array is 6
The sum of last 4 elements of array is 26

Array: 10 20 30 4 50 60 70 80 
Address 0x7ffd9cf23b40 with size of 8

const int* is 10 before
const int* is 4 now
int* const is 4 before
int* const is 5 now
const int* const is 5 forever
```

## Functions and Two-Dimensional Arrays
Source code: `C7_ `
```C++

```
- 
- 
```Console

```
