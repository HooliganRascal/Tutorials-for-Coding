# Adventures in Functions
---
## C++ Inline Functions
Source code: `C8_Inlinefunction`
```C++
#include<iostream>

using namespace std;

inline void call(void){
	cout << "For inline function!" << endl;
}

int main(void){
	call();
	return 0;
}
```
- Normal function calls involve jumping to another address(function's address)
- Jumping back and forth and keeping track of where to jump, overhead!
- For **inline function**, code is **in line** with the other code
    - Replace the function call with corresponding function code
    - Faster than regular functions, but **come with a memory penalty**!
- Use inline function
    - Preface the function declaration with `inline`
    - Preface the function definition with `inline`
- **Definition comes before the function's first use to omit the prototype** and to place the entire definition where the prototype would normally go
- **Recursion is not allowed for inline functions!**
- *Macros in C*: `#define SQ(X) X*X`, works through text substitution

```Console
For inline function!
```

## Reference Variables
### Reference Variables Creation
Source code:`C8_Referencecreation`
```C++
#include<iostream>

int main(void){

	using namespace std;

	int rats = 101;
	int bunnies = 50;
	int foxes = 80;
	
	int* pt = &rats;
	int& ref = *pt; // address as rats, value as rats, needs initialization!
	cout << "rats = " << rats 
		 << ", ref = " << ref 
		 << endl;
	cout << "rats address = " << &rats << endl 
		 << "ref address = " << &ref << endl
		 << endl;

	ref = bunnies; // address as rats; rats,ref value as bunnies
	cout << "bunnies = " << bunnies
		 << "rats = " << rats 
		 << "ref = " << ref 
		 << endl;
	cout << "bunnies address = " << &bunnies << endl 
		 << "rats address = " << &rats << endl 
		 << "ref address = " << &ref << endl 
		 << endl;

	pt = &foxes; // does not affect ref
	cout << "foxes = " << foxes
		 << "rats = " << rats 
		 << "ref = " << ref 
		 << endl;
	cout << "foxes address = " << &foxes << endl
		 << "rats address = " << &rats << endl
		 << "ref address = " << &ref << endl;

	return 0;
}
```
- Reference: a name acts as an alias or an alternative name for a previously defined variable
- Use for a reference is as a formal argument, function **works with the original data instead of a copy!**
- A convenient alternative to pointers
- Alias using: `type var1; type & var2 = var1;`, now `var2` is an alias for `var1`
- `type&` means *reference to `type`*, both refer to **the same value** and share **the same address**!  
- For reference variable, initialization is needed and determines how the reference behaves! It's always determined by address and value, **address is the key!**

```Console
rats = 101, ref = 101
rats address = 0x7fffb988fdfc
ref address = 0x7fffb988fdfc

bunnies = 50rats = 50ref = 50
bunnies address = 0x7fffb988fe00
rats address = 0x7fffb988fdfc
ref address = 0x7fffb988fdfc

foxes = 80rats = 50ref = 50
foxes address = 0x7fffb988fe04
rats address = 0x7fffb988fdfc
ref address = 0x7fffb988fdfc
```
### Used in Functions
Source code: `C8_Referencefunction`
```C++
#include<iostream>

using namespace std;

void swaprr(int& a, int& b);
void swapcr(const int& a, const int& b); // Unmodifiable

int main(void){

	int a=5;
	int b=6;
	double c=7.1;
	double d=8.6;
	double& e=c; // reference or lvalue reference of c
	double&& f=e*5+6; // rvalue reference
	
	cout << "Originally: a = " << a << ", b = " << b << endl;
	swaprr(a,b); // works
	cout << "After swaprr: a = " << a << ", b = " << b << endl;
	swapcr(a,b); // not works
	cout << "After swapcr: a = " << a << ", b = " << b << endl;

	cout << "Originally: c = " << c << ", d = " << d << endl;
	swapcr(c,d); // not works, type cast and temporary variable
	cout << "After swapcr: c = " << c << ", d = " << d << endl;

	cout << "Originally: e = " << e << ", d = " << d << endl;
	swapcr(e,d); // not works, type cast and temporary variable
	cout << "After swapcr: e = " << e << ", d = " << d << endl;
	
	cout << "Test for rvalue reference: f = e*5+6 = " << f << endl;
	
	return 0;
}

void swaprr(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swapcr(const int& a, const int& b){
	// Yes, it is nothing
}
```
- Passing by reference: making a variable name in a function an alias for a variable in the calling program
- Use the information passed to it without modifying when using reference, use `const`
- Reference arguments are more useful with larger data units like strutures and classes
- Passing by reference, then argument should be the corresponding variable
    - Pass by statements like `ref(x+0.3)` will cause error mostly
    - If not, some older compilers use *temporary and nameless variable* initialized as the value of `x+0.3`
    - Then `ra` becomes a reference to that temporary variable
- For `const` reference, *temporary variable* exists in:
    - Actual argument is the correct type but not an *lvalue* like `x+0.3`
    - Actual argument is the wrong type but of a type can be converted
- *lvalue*: a data object that can **be referenced by address**
    - `const`: *non-modifiable lvalue* 
- Temporary variables last for the duration of the function call, and the compiler is free to dump them
- Situation creating temporary variables **fails to modify** the variable the parameters refer to
- We may use `const` whenver it is appropriate to do so
- *rvalue reference*: `type&& rref = rvalue`
    - For provide more efficient implementation of certain operations
    - To implement an approach called *move semantics*
- Reference variable can recurse!

```Console
Originally: a = 5, b = 6
After swaprr: a = 6, b = 5
After swapcr: a = 6, b = 5
Originally: c = 7.1, d = 8.6
After swapcr: c = 7.1, d = 8.6
Originally: e = 7.1, d = 8.6
After swapcr: e = 7.1, d = 8.6
Test for rvalue reference: f = e*5+6 = 41.5
```

### Used with Structures
Source code:`C8_Referencestructure`
```C++
#include<iostream>
#include<cstring>

using namespace std;

struct info{
	string name;
	int age;
};

void display(const info&);
info& addi(info&, const info&);
info& mult(info);

int main(void){

	info ref1 = {"Mteltn", 19};
	info ref2 = {"Guernica", 20};
	info ref3 = {"Cosmos", 21};

	cout << "Originally:" << endl;
	display(ref1);
	display(ref2);
	display(ref3);
	cout << endl;

	info ref4 = addi(ref1,ref2);
	cout << "Now after addi, ref4 is: " << endl;
	display(ref4);
	cout << "And after addi, ref1 is: " << endl;
	display(ref1);
	cout << endl;

	info& ref5 = mult(ref1);
	cout << "Now after mult, ref5 is: " << endl;
	display(ref5);
	cout << "And after mult, ref1 is still though: " << endl;
	display(ref1);
	addi(ref1,ref3).age = 18; // Reference is a lvalue!
	cout << "While after lvalue, ref1 is changed: " << endl;
	display(ref1);
	delete &ref5; // free the new memory created to get the copied value

	return 0;
}

// simply operate with reference input
void display(const info& ref){
	cout << "Name is " << ref.name << endl;
	cout << "Age is " << ref.age << endl;
}

// return reference by input reference and avoid modifying by const
info& addi(info& ref1, const info& ref2){
	ref1.age += ref2.age;
	return ref1;
}

// return reference by creating new memory
info& mult(info ref){
	info* pref = new info; // create new memory
	*pref = ref;
	(*pref).age *= 2;
	return *pref; // return reference to the copied info in newly allocated
}

```

- `struct name{}; name& fun1()`, `fun1` returns a reference, thus a *lvalue reference*, which can be assigned with value
- Traditional return mechanism: `double m=sqrt(4)`, it returns `2` by copying it to a temporary location and the value in that location is copied to `m`
- Returning by reference variable actually copies the content in that variable directly to the lvalue variable
- **Don't return reference to a memory location thhat ceases to exist when function terminates like temporary variable!**
- Use `type& fun(type& var)` or create new storage by `new` like pointer: `type& fun(type var){type* pt=var; return *pt}; type& var2=fun(var1);`
- If not assigning to `type&`, the memory is lost!
- Remember to use `delete` to free memory no longer needed
- Use `const type& fun(type& var)` to create *nonmodifiable lvalue* in case `fun(var) = 5` modifies the variable returned reference referred to

```Console
Originally:
Name is Mteltn
Age is 19
Name is Guernica
Age is 20
Name is Cosmos
Age is 21

Now after addi, ref4 is: 
Name is Mteltn
Age is 39
And after addi, ref1 is: 
Name is Mteltn
Age is 39

Now after mult, ref5 is: 
Name is Mteltn
Age is 78
And after mult, ref1 is still though: 
Name is Mteltn
Age is 39
While after addi as lvalue, ref1 is changed: 
Name is Mteltn
Age is 18
```  

### Used with Class Objects
Source code: `C8_Referenceclass`
```C++
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

const int LIMIT=5;

const string& conca(string& s1, const string& s2);
void fit(ostream& os, double fo, const double* fe, int n);

int main(void){

	string input;
	string copy;
	string result;

	double objective;
	double eps[LIMIT];
	ofstream fout;
	const char* fn="ep-data.txt";

	cout << "Enter a string: ";
	getline(cin,input); // cin uses reference for basic type
	cout << "Your string as entered: " << input << endl;
	copy = input;

	// result 1
	result = conca(input, copy); // pass string objects
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	// result2
	result = conca(input, "***"); // pass string objects
	cout << "Your string enhanced by C-string: " << result << endl;
	cout << "Your original string by C-string: " << input << endl;

	// class object inheritation
	fout.open(fn);
	cout << "Enter the focal length of your telescope in mm: ";;
	cin >> objective;
	cout << "Enter the focal lengths of " << LIMIT << " eyepieces: "<< endl;
	for(int i=0; i<LIMIT; ++i){
		cout << "Eyepiece #" << i+1 << ": ";
		cin >> eps[i];
	}
	fit(fout, objective, eps, LIMIT);
	fit(cout, objective, eps, LIMIT);
	fout.close();

	return 0;
}

const string& conca(string& s1, const string& s2){
	s1 = s2 + s1 + s2;
	return s1;
}

void fit(ostream& os, double fo, const double* fe, int n){

	// define the settings needed to be recovered
	ios_base::fmtflags initial;

	// fixed decimal-point notation
	initial = os.setf(ios_base::fixed); // return a copy of format settings

	os.precision(0); // number of figures to the right of the decimal fixed
	os << "Focal length of objective: " << fo << " mm" << endl;

	// showing a trailing decimal point
	os.setf(ios::showpoint); 

	os.precision(1);
	os.width(12); // field width to be used for the next output action
	os << "f.l.eyepiece";
	os.width(15);
	os << "Magnification" << endl;
	for(int i=0; i<n; ++i){
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / *(fe+1) + 0.5) << endl;
	}

	os.setf(initial); // restore the initial formatting states
}
```

- To pass class objects to a function, to use references!
- Example: using `string` class: `string ver1(const string& s1, const string& ver2);`
    - When return with `string` rather than `string&`, the returned value will be copied to a **temporary return location**
    - then the content of the temporary location will be copied to the `result=ver1(s1,s2)`
- `ver1(s1,"***")`, input2 is a *C-style string as pointer to `char`*
    - `string` class defines a `char*`-to-`string` conversion
    - `const` type-casting: mismatching happens, and can be converted to the correct reference type
- Class inheritance: possible to pass features from one class to another
    - `ostream` like `cout`: *base class*
    - `ofstream` like `ofstream file1`" *derived class*
- A base class reference can refer to a derived class object without **requiring a type cast**
    - `void fun1(ostream& s1)` can accept `cout` or `ofstream fout`
- Using reference arguments: 
    - Alter a data object in the function
    - Speed up a program by passing a reference
- References are just **a different interface** for **pointer-based code**
- Note: for array, pointer is the only way!
- Note: `cin` uses references for basic types so that we can use `cin >> n`!

```Console
Enter a string: I am
Your string as entered: I am
Your string enhanced: I amI amI am
Your original string: I amI amI am
Your string enhanced by C-string: ***I amI amI am***
Your original string by C-string: ***I amI amI am***
Enter the focal length of your telescope in mm: 1800
Enter the focal lengths of 5 eyepieces: 
Eyepiece #1: 30
Eyepiece #2: 19
Eyepiece #3: 15
Eyepiece #4: 7.4
Eyepiece #5: 3.6
Focal length of objective: 1800 mm
f.l.eyepiece  Magnification
        30.0             95
        19.0             95
        15.0             95
         7.4             95
         3.6             95
```


## Default Arguments
Source code: `C8_Defaultarg`
```C++
#include<iostream>
#include<cstring>

const int arsize=80;
char* left(const char* str, int n=1); // default argument n=1

int main(void){

	using namespace std;

	char sample[arsize];
	char* ps;

	cout << "Enter a string: " << endl;
	cin.getline(sample, arsize);

	cout << (ps = left(sample,4)) << endl;
	delete [] ps; // free old string
	
	cout << (ps = left(sample)) << endl;
	delete [] ps; // free new string

	return 0;
}

char* left(const char* str, int n){

	if(n < 0){
		n = 0;
	}
	else{
		n = (n < strlen(str)) ? n : strlen(str);
	}

	// alternative for efficiency
	int m=0;
	while((m<=n)&&(str[m])){ // non-zero are true, zero to false
		++m;
	}

	char* p=new char[m+1]; // allocate new memory
	int i;

	for(i=0; i<n && *(str+i); ++i){
		*(p+i)=str[i]; // copy
	}

	while(i<=n){
		p[i++]='\0'; // set rest to '\0'
	}

	return p;
}
```

- Used automatically if **omitting the corresponding actual argument** from a function call
- Establish a default value in *function prototype*: `type fun(type1 var=value)` 
- Define the default for a particular argument with all the right: `type fun(type1 var1, type2 var2=val2, type3 var3=val3)`
- Actual arguments are assigned to the corresponding formal arguments from **left to right**
- C programmers are more on faster running, while C++ is more on *reliability*

```Console
Enter a string: 
Mteltn is Cosmos
Mtel
M
```

## Function Overloading
Source code: `C8_Functionoverloading` 
```C++
#include<iostream>

const int arsize=80;
const int LIMITS=9;
char* left(const char* str, int n=1); // default argument n=1
unsigned long left(unsigned long num, unsigned ct); // function overloading

int main(void){

	using namespace std;

	char trip[LIMITS] = "Hawaii!!"; // 9th character is '\0'
	unsigned long n = 123456789;
	int i;
	char* temp;

	for(i=1; i<=LIMITS; ++i){
		cout << left(n,i) << endl; // display first left of i digits
		cout << (temp=left(trip,i)) << endl;
		delete [] temp;
	}

	return 0;
}

unsigned long left(unsigned long num, unsigned ct){
	unsigned digits = 1;
	unsigned long n=num;

	if(ct==0||num==0){
		return 0; // return 0 if no digits
	}

	while(n/=10){
		++digits; // counting digits
	}

	if(digits>ct){
		ct=digits-ct;
		while(ct--){
			num /= 10;
		}
		return num; // return first left ct digits
	}
	else{
		return num; // return the whole if digits<=ct
	}
}

char* left(const char* str, int n){

	if(n < 0){
		n = 0;
	}

	// alternative for efficiency
	int m=0;
	while((m<=n)&&(str[m])){ // non-zero are true, zero to false
		++m;
	}

	char* p=new char[m+1]; // allocate new memory
	int i;

	for(i=0; i<n && *(str+i); ++i){
		*(p+i)=str[i]; // copy
	}

	while(i<=n){
		p[i++]='\0'; // set rest to '\0'
	}

	return p;
}
```

- *Function polymorphism*, also called *function overloading* 
- Use multiple functions **sharing the same name**!
- Key: function's argument list, also called *function signature*
    - Same signature: same number and types of arguments in the same order
    - Signatures differ in **number and type** of arguments
    - Clarify in prototypes, and call for different uses
    - Be careful of the proper argument types!
    - Some signatures different from each other nonetheless can't coexist! `double cube(double x)` and `double cube(double& x)` will be considered with the same signature!
    - Function-matching discriminate between `const` and non-`const` variables
    - Overloading functions needn't to be the same type **only if the signatures are also different**
- Overloading reference parameters:
    - `void fun(const type& f2)` matches modifiable or const lvalue and rvalue
    - `void fun(type& f1); void fun(const type& f2); void fun(type&& f3)` appear at the same time, the **more exact match** is made
    - `void fun(const type& f2); void fun(type&& f3);` if we omit the `fun(type&&)` function, `fun(2+3)` will call the `fun(const type& f2)` instead
- Use function overloading only for functions performing basically the same task but with different forms of data or testing default arguments or other specific tasks, **don't overuse it!**

> C++ use *name decoration* or *name mangling* to keep track of overloaded function:
> - Each function name is encrypted based on the formal parameter types specified in the function's prototype
> - Example: `long MyFunction(int,float)`, for compiler, it documented this by transforming the name into an internal representation with an appearance perhaps like this: `?MyFunction@@YAXH`

```Console
1
H
12
Ha
123
Haw
1234
Hawa
12345
Hawai
123456
Hawaii
1234567
Hawaii!
12345678
Hawaii!!
123456789
Hawaii!!
```

## Function Templates
Source code: `C8_Templates`
```C++
#include<iostream>

using namespace std;

template<class T>
void Swap(T& a, T& b);

template<typename A>
void change(A& var);

int main(void){

	int i=10;
	int j=11;
	double a=12.1;
	double b=21.2;

	cout << "Before: i=" << i << ", j=" << j << endl;
	Swap(i,j);
	cout << "Swapped: i=" << i << ", j=" << j << endl;
	change(i);
	cout << "Changed: i=" << i << endl;

	cout << "Before: a=" << a << ", b=" << b << endl;
	Swap(a,b);
	cout << "Swapped: a=" << a << ", b=" << b << endl;
	change(b);
	cout << "Changed: b=" << b << endl;

	return 0;
}

template<class T>
void Swap(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename A>
void change(A& var){
	var+=1;
}
```

- Generic function discription: in terms of a generic type that can be subsituted
- Generic programming
- Parameterized types: types represented by parameters
- Example: `template<typename younameit> void fun(younameit& var){}`, `typename` by `class`
- Use templates if needing functions applying the same algorithm to a variety of types

```Console
Before: i=10, j=11
Swapped: i=11, j=10
Changed: i=12
Before: a=12.1, b=21.2
Swapped: a=21.2, b=12.1
Changed: b=13.1
```

### Overloaded templates
- 

### Template Limitations

### Explicit Specilizations

### 3rd-Generation Specialization(ISO/ANSIC++)

### Instantiations and Specializations

### Exact Matches and Best Matches

### Template function evolution
- `decltype`
- Alternative function syntax
