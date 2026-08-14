# Compound Types
---

## Create an array

Source code: `C4_Arrayinitialize`
```C++
#include<iostream>

int main(void){

	using namespace std;

	const int siza = 3;

	// define
	int integer[3];
	cout << "Defined Unassigned first of the array is " << integer[0] << endl;

	// assign and operate
	int integers[siza];
	integers[0] = 7;
	cout << "Assigned first number is " << integers[0] << endl;
	cout << "Assigned first number plus 1 is " << integers[0] + 1 << endl;

	// initialize
	float stock[4] = {6.2, 2.7 ,3.5, 4.1};
	float etock[4] = {1.9, 2.7, 3.5};
	float ztock[4] = {};
	float dtock[]  = {5.1, 2.3, 4.7, 9.6};
	float qtock[]  = {};
	cout << "Last 1 of stock is " << stock[3] << endl;
	cout << "Over 1 of stock is " << stock[4] << endl; // surpasses to etock!
	cout << "Unassigned last 1 of etock is " << etock[3] << endl;
	cout << "All elements in an empty array are " << ztock[2] << endl;
	cout << "Let the compiler decides, one element is " << dtock[2] << endl;
	cout << "Let the compiler decides, over 1 element is " << dtock[4] << endl;
	cout << "Let the compiler decides, no element for " << qtock[0] << endl;

	// explore empty array, does not affect other memories
	qtock[0] = 1.2;
	qtock[1] = 2.1;
	cout << "Let the compiler decides, assigned 1 be " << qtock[0] << endl;
	cout << "Let the compiler decides, assigned 2 be " << qtock[1] << endl;

	// assign overly
	float atock[5] = {6.3}; // assigned, initialized, does not work
	float btock[5];
	dtock[4] = 5.5;
	cout << "Assigned overly nextly be " << atock[0] << endl; // taken hard
	cout << "Assigned overly nextly again be " << btock[0] << endl; // recover

	return 0;
}
```
- define rule: `type array[constant integer]`
    - **don't define without size!**
    - define with size of constant number, don't with variables
    - every time defining an array, memory allocated
- assignment: `integer[0] = 7`
    - assign individually
    - **not allowed** for `int array[]; array = {1,2,3,4}`
    - defined but not assigned will be *shit*
    - assign overly will take up when nextly allocating memory
    - assign overly and nextly defined, whether initialized or not, get taken
    - assign overly and nextly defined, whether assigned or not, get taken
- initialization: `float stock[4] = {1.0, 2.0, 3.0, 4.0}`
    - unassigned one is `null`
    - over location **surpasses**
    - initialized with no size: *over terms are shits*
    - initialized with nothing: *any term is shit*
- don't output the array directly unless it's a **string** !

```console
Defined Unassigned first of the array is 262039296
Assigned first number is 7
Assigned first number plus 1 is 8
Last 1 of stock is 4.1
Over 1 of stock is 1.9
Unassigned last 1 of etock is 0
All elements in an empty array are 0
Let the compiler decides, one element is 4.7
Let the compiler decides, over 1 element is 1.07648e+21
Let the compiler decides, no element for 4.59149e-41
Let the compiler decides, assigned 1 be 1.2
Let the compiler decides, assigned 2 be 2.1
Assigned overly nextly be 5.5
Assigned overly nextly again be -6.00985e-21
```
## Char array and string

Source code: `C4_Charstring`
```C++

```

- 1
- 2

```console

```
