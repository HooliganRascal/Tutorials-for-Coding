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

- Objects, inheritance, references
- When to use reference arguments?

## Default Arguments

## Function Overloading

## Function Templates

### Overloaded templates

### Template Limitations

### Explicit Specilizations

### 3rd-Generation Specialization(ISO/ANSIC++)

### Instantiations and Specializations

### Exact Matches and Best Matches

### Template function evolution
- `decltype`
- Alternative function syntax
