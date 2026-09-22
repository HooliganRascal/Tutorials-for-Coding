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

```
- Passing by reference: making a variable name in a function an alias for a variable in the calling program
- Use the information passed to it without modifying when using reference, use `const`
- Reference arguments are more useful with larger data units like strutures and classes
- Passing by reference, then argument should be the corresponding variable
    - Pass by statements like `ref(x+0.3)` will cause error mostly
    - If not, some older compilers use *temporary and nameless variable* initialized as the value of `x+0.3`
    - Then `ra` becomes a reference to that temporary variable
- For `const` reference
```Console

```

## Default Arguments


## Function Overloading

## Function Templates
