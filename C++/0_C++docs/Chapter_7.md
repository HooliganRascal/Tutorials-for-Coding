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
Source code: `C7_Function2darray`
```C++
#include<iostream>

using namespace std;

const int rowsize = 4;
const int colsize = 4;
const int scale = 2;

void showa(
		const int (*rowini)[colsize], 
		const int (*rowfin)[colsize]
		);
void times(
		int arr[][colsize], 
		int row, 
		int col
		);

int main(void){
	
	int ar2[rowsize][colsize];
	for(int i=0; i<rowsize; ++i){
		for(int j=0; j<colsize; ++j){
			ar2[i][j]=(i+1)*(j+1);
		}
	}
	showa(ar2, ar2+rowsize);
	cout << endl;
	times(ar2, rowsize, colsize);
	showa(ar2, ar2+rowsize);

	return 0;
}

// Print the array
void showa(
		const int (*rowini)[colsize], 
		const int (*rowfin)[colsize]
		)
{
	for(int i=0; i<(rowfin-rowini); ++i){
		for(int j=0; j<colsize; ++j){
			cout << *(*(rowini+i)+j) << " ";
		}
		cout << endl;
	}
}

// Modify by multiplication
void times(
		int arr[][colsize], 
		int row, 
		int col
		)
{
	for(int i=0; i<row; ++i){
		for(int j=0; j<col; ++j){
			arr[i][j] *= scale;
		}
	}
}
```
- Prototype: `int name(int (*ar2)[num], int size)`, `int name(int ar2[][num], int size)`
- The formal variable points to an array of `num` `ints`, **the column** needs specifying
- It is different with pointer to pointer: `type name(type** arr2, type var)`!
    - `arr[][]`, `arr` is the **pointer to the first row**, type `int (*)[colsize]`, same address as `&arr[0][0]`, but different type!
    - `arr+i` states the address of the `i`row, use `(*arr)[col]` to call!
    - 2D array is different from pointer to pointer! The former needs specifying the **column**!

```Console
1 2 3 4 
2 4 6 8 
3 6 9 12 
4 8 12 16 

2 4 6 8 
4 8 12 16 
6 12 18 24 
8 16 24 32 
```

## Functions and C-Style Strings
Source code: `C7_`
```C++
#include<iostream>

using namespace std;

const int arsize = 20;

void Show(const char*);
char* Plus(const char*);

int main(void){

	char arr[arsize] = "I am coding!";
	char* newarr;

	Show(arr);
	newarr = Plus(arr);
	Show(newarr);
	delete [] newarr;

	return 0;
}

void Show(const char* arr){
	while(*arr){
		cout << *(arr++);
	}
	cout << endl;
}

// Incremented
char* Plus(const char* arr){

	int n=0;
	char *newarr = new char[arsize];

	while(*arr){
		*(newarr+n) = *arr;
		++(*(newarr+n));
		++n;
		++arr;
	}
	return newarr;
}
```
- You don't have to pass the size of the string
- End of `*str` is `\0` and is recognized as `0` in `bool`
- We may use `new` and `delete` to return C-style string

```Console
I am coding!
J!bn!dpejoh"
```

## Functions and Structures
Source code: `C7_Functionstructure`
```C++
#include<iostream>
#include<cmath>

using namespace std;

const double pi=3.1415926535;

struct polar{
	double radius;
	double angle; // In degree, but default radicular
};
struct carte{
	double dim_x;
	double dim_y;
};

// Prototypes
carte po_ca(polar*);
polar ca_po(carte*);

int main(void){

	carte input1, output2;
	polar input2, output1;

	cout << fixed;
	cout.precision(6);
	cout.setf(ios_base::showpoint);

	// Cartesian to polar
	cout << "Input the x coordinates: ";
	cin >> input1.dim_x;
	cout << "Input the y coordinates: ";
	cin >> input1.dim_y;
	output1 = ca_po(&input1);
	cout << "Output the radius: " << output1.radius << endl;
	cout << "Output the angle: " << output1.angle << " deg"<< endl;

	// Polar to cartesian
	cout << "Input the radius: ";
	cin >> input2.radius;
	cout << "Input the angle in degree: ";
	cin >> input2.angle;
	output2 = po_ca(&input2);
	cout << "Output the x coordinates: " << output2.dim_x << endl;
	cout << "Output the y coordinates: " << output2.dim_y << endl;

	return 0;
}

carte po_ca(polar* pol){
	carte car;
	double angle_rad = (pol->angle)*pi/180.0;
	car.dim_x = (pol->radius)*cos(angle_rad);
	car.dim_y = (pol->radius)*sin(angle_rad);
	return car;
}

polar ca_po(carte* car){
	polar pol;
	pol.radius = sqrt(pow(car->dim_x,2)+pow(car->dim_y,2));
	pol.angle = atan2(car->dim_y, car->dim_x)*180.0/pi;
	return pol;
}
```
- Define a `structure`, then input as an argument and return them!
- Use `cin>>` returned `cin` as the object of `istream` class and converted into `bool` type
- Use **pointer to structure** as the arguments to save time and space

```Console
Input the x coordinates: 1
Input the y coordinates: 1.73250580757
Output the radius: 2.000394
Output the angle: 60.006516 deg
Input the radius: 2
Input the angle in degree: 60
Output the x coordinates: 1.000000
Output the y coordinates: 1.732051
```

## Functions and string class objects
Source code: `C7_Functionostring`
```C++
#include<iostream>

using namespace std;

const int stsize = 3;

void read(string*);
void write(string*);

int main(void){
	
	string sent[stsize];

	cout << "Input " << stsize << " name:" << endl;
	read(sent);
	cout << "Output repeatedly: " << endl;
	write(sent);
	
	return 0;
}

void read(string* sent){
	for(int i=0; i<stsize; ++i){
		cout << i+1 << ": ";
		getline(cin, sent[i]);
	}
}

void write(string* sent){
	for(int i=0; i<stsize; ++i){
		cout << i+1 << ": " << sent[i] << endl;
	}
}
```
- Remember the `string name; getline(cin,name);`
- `string` class is more like a structure than a C-style array
- `string` can also be used with a pointer

```Console
Input 3 name:
1: Mteltn
2: Guernica
3: Cosmos
Output repeatedly: 
1: Mteltn
2: Guernica
3: Cosmos
```

## Function and array objects
Source code: `C7_Functionoarray`
```C++
#include<iostream>
#include<array>

using namespace std;

const int season = 4;
const array<string,season> snames = {
	"Spring",
	"Summber",
	"Autumn",
	"Winter"
};

void fill(array<double,season>*); // Pass the address
void show(array<double,season>);  // Pass the name

int main(void){
	array<double,season> expense;
	fill(&expense);
	show(expense);
	return 0;
}

void fill(array<double,season>* expense){
	for(int i=0; i<season; ++i){
		cout << "Enter " << snames[i] << " expenses: ";
		cin >> (*expense)[i];
	}
}

void show(array<double,season> expense){
	double total = 0.0;
	cout << endl << "EXPENSES:" << endl;
	for(int i=0; i<season; ++i){
		cout << snames[i] << ": " << expense[i] << endl;;
		total += expense[i];
	}
	cout << endl << "Total expense:" << total << endl;
}
```

- Class objects are **based on structures**
- Cando: pass an object by value to a function, pass a pointer to an object to a function
- Use `references` may solve the inefficieny and the notational problem

```Console
Enter Spring expenses: 123
Enter Summber expenses: 254
Enter Autumn expenses: 132
Enter Winter expenses: 256

EXPENSES:
Spring: 123
Summber: 254
Autumn: 132
Winter: 256

Total expense:765
```

## Function recursion
Source code: `C7_Functionrecursion`
```C++
#include<iostream>

using namespace std;

const int length = 66; // even
const int divide = 6; // 7 levels actually
const int rumax = length-2; 
const int rumin = 0;

void separate(char* ar, int low, int high, int level);

int main(){
	
	char ruler[length];
	for(int i=0; i<rumax; ++i){
		ruler[i]=' ';
	}
	ruler[length-1]='\0'; // odd number, 65 bars at last
	ruler[rumax] = '|';
	ruler[rumin] = '|';
	cout << ruler << endl; // display first row

	for(int i=1; i<=divide; ++i){
		separate(ruler,rumin,rumax,i); // level divide will be the most
		cout << ruler << endl;
		for(int j=1; j<rumax; ++j){ // not affect the edges
			ruler[j]=' '; // reset
		}
	}

	return 0;
}

void separate(char* ar, int low, int high, int level){

	if(level==0){
		return;
	}
	
	int mid = (high+low)/2;
	ar[mid]='|';

	separate(ar, low, mid, level-1);
	separate(ar, mid, high, level-1);
}
```

- Function can call itself! `void recur(argu){ state1; if(test) recur(argu); state2; }`
- C++ can **not let `main()` to call itself** though!
- Like dig deep inside!
- Multiple recursive calls: `void name(arg){if(test){name(arg1);name(arg2);}}`
- Try to draw a ruler!
- If the necessary levels of recursion are few, it's an elegant choice
- Recursion can turns the loop into condition

```Console
|                                                               |
|                               |                               |
|               |               |               |               |
|       |       |       |       |       |       |       |       |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
```

## Pointers to functions
Source code: `C7_Functionpointer`
```C++

```
- 
- 
```Console

```
