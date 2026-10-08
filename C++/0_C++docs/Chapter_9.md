# Memory Models and Namespaces
---
## Separate Compilation
Source code: `C9_Separatecompilation`
Header file: `coor.h`
```C++
#ifndef COOR_H_
#define COOR_H_

const double pi=3.1415926535897;

struct pola{
	double r;
	double alpha; // radian
};

struct rect{
	double x;
	double y;
};

double dtor(double deg);
double rtod(double rad);
pola rtop(rect& xy);
rect ptor(pola& ra);
template<class type>void show(type var);
template<>void show<pola>(pola var);
template<>void show<rect>(rect var);

#endif
```

Definition: `defi.cpp`
```C++
#include<iostream>
#include<cmath>
#include"coor.h"

pola rtop(rect& xy){
	
	pola ans;
	ans.r = sqrt(xy.x*xy.x + xy.y*xy.y);
	ans.alpha = atan2(xy.y, xy.x);
	ans.alpha = rtod(ans.alpha);
	
	return ans;
}

rect ptor(pola& ra){

	rect ans;
	ra.alpha = dtor(ra.alpha);
	ans.x = ra.r*cos(ra.alpha);
	ans.y = ra.r*sin(ra.alpha);

	return ans;
}

double dtor(double deg){
	return deg*pi/180.0;
}

double rtod(double rad){
	return rad*180/pi;
}

template<>void show<pola>(pola var){

	using namespace std;

	cout << "Polar coordinates: " << endl;
	cout << "Radius: " << var.r << endl;
	cout << "Angle: " << var.alpha << " deg" << endl;
}

template<>void show<rect>(rect var){

	using namespace std;

	cout << "Rectangular coordinates: " << endl;
	cout << "X-coord: " << var.x << endl;
	cout << "Y-coord: " << var.y << endl;
}
```

Main file: `core.cpp`
```C++
#include<iostream>
#include"coor.h"

int main(void){

	using namespace std;
	
	// Input definition
	rect input1;
	pola input2;

	// Rectangular to polar
	cout << "Enter a coordinates in x-y:" << endl;
	cout << "x = ";
	cin >> input1.x;
	cout << "y = ";
	cin >> input1.y;
	show(rtop(input1));

	// Translate
	cout << endl;

	// Polar to rectangular
	cout << "Enter a coordinates in polar(angle in deg):" << endl;
	cout << "r = ";
	cin >> input2.r;
	cout << "alpha = ";
	cin >> input2.alpha;
	show(ptor(input2));

	return 0;
}#include<iostream>
#include"coor.h"

int main(void){

	using namespace std;
	
	// Input definition
	rect input1;
	pola input2;

	// Rectangular to polar
	cout << "Enter a coordinates in x-y:" << endl;
	cout << "x = ";
	cin >> input1.x;
	cout << "y = ";
	cin >> input1.y;
	show(rtop(input1));

	// Translate
	cout << endl;

	// Polar to rectangular
	cout << "Enter a coordinates in polar(angle in deg):" << endl;
	cout << "r = ";
	cin >> input2.r;
	cout << "alpha = ";
	cin >> input2.alpha;
	show(ptor(input2));

	return 0;
}
```

- Recall [compiling and linking](Chapter_1.md)
    - `g++ *.cpp` compiles and links and produces `a.out` as output 
    - `g++ -c *.cpp` compiles only, leave a `*.o`
    - `g++ *.o` links and produces `a.out`
    - `g++ *.cpp -o *` is always recommended
- If we modify some files, just recompile the corrsponding ones and link them to the previously compiled `*.o`, and upgrade output
- Compile separately:
    - A header file contains the **structure declaration and prototypes for functions** using those structures
    - A source code file containing **the code for the structure-related function**
    - A source code file containing the code calling the **structure-related functions**
- Don't put the **function definition or variable declaration** into a header file!
- What are in the header file:
    - Function prototypes
    - Symbolic contains defined using `#define` or `const`
    - Structure declaration
    - Class declaration
    - Template declaration
    - Inline function (can be a definition as an exception)
- Declarations that don't create variables but **tell how to do** can be in the header file
- Data declared `const` and inline functions own the special linkage properties that allow themt to be placed into a header file
- Include the header files:
    - `#include<something>` looks at the part of the host system's file first
    - `#include"something"` looks at the current working directory first
- How compiler works:
    - Give compile command: `g++ 1.cpp 2.cpp`
    - Preprocesser combines **included files** with **source codes**
    - Compiler creates an object code file for each source code file `*.o`
    - Linker combines `*.o` and library code and startup code to produce executable file `a.out`
- In IDEs, don't add header files into the project list!
- Don't use `#include` to include **source code**, it can lead to multiple declaration!
- Include a header file just once in a file
    - Possible to include that include another header file
    - Set up a file named `name.h`
    - Use preprocessor to avoid it: `#ifndef NAME_H_ #define NAME_H_ ...#endif` for *if not defined*
    - Process the statements between `#ifndef` and `#endif` only if the name `NAME_H_` has not been defined previously by the preprocessor `#define`
    - First time, `NAME_H_` should be undefined, compiler reads the line defining `NAME_H_` 
    - If then encounters a second inclusion of `name.h` in the same file, it skips to the line following `#endif`
    - It makes the compiler files ignore the contents of all but the first
- The *file* in C++ is a part of *translation units* for generality#function-overloading
- The `*.o` generated by different compilers may not get linked properly for the different [name decoration(like function overloading)](Chapter_8.md), it should be of great notice
- Don't save the standard library in any file using it!
- For `g++`, use `g++ -c *.cpp` to compile, no need to compile the header file!

```Console
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
coor.h  core.cpp  defi.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ make build
g++ -c defi.cpp core.cpp
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
coor.h  core.cpp  core.o  defi.cpp  defi.o  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ make link
g++ defi.o core.o
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
a.out  coor.h  core.cpp  core.o  defi.cpp  defi.o  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ make run
./a.out
Enter a coordinates in x-y:
x = 1
y = 1.73205
Polar coordinates: 
Radius: 2
Angle: 60 deg

Enter a coordinates in polar(angle in deg):
r = 2
alpha = 60
Rectangular coordinates: 
X-coord: 1
Y-coord: 1.73205
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
a.out  coor.h  core.cpp  core.o  defi.cpp  defi.o  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ make clean
rm defi.o core.o a.out
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
coor.h  core.cpp  defi.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ make buildall
g++ defi.cpp core.cpp -o result
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
coor.h  core.cpp  defi.cpp  Makefile  result
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ make runall
./result
Enter a coordinates in x-y:
x = 1
y = 1.73205
Polar coordinates: 
Radius: 2
Angle: 60 deg

Enter a coordinates in polar(angle in deg):
r = 2
alpha = 60
Rectangular coordinates: 
X-coord: 1
Y-coord: 1.73205
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
coor.h  core.cpp  defi.cpp  Makefile  result
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ make cleanall
rm ./result
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$ ls
coor.h  core.cpp  defi.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/C9_Separationcompilation$
```

## Storage Duration, Scope and Linkage
- Review of [Chapter4](Chapter_4.md)
- Four schemes for storing data:
    - Automatic storage duration: exist when in **blocks**
    - Static storage duration: `static` persist for the entire time a program is running
    - Thread storage duration: 
        - Multicore processors are CPUs handling several execution tasks simultaneously
        - A program split conputations into separate **threads** being processed concurrently
        - `thread_local` persists for the containing **thread** lasts
    - Dynamic storage duration: allocated by `new`, persists untile freed with `delete`

### Scope and Linkage
- Linkage: how a name can be shared in different units
    - External: shared across files
    - Internal: shared by functions within a single file
    - Automatic variables are not shared, with no linkage
- Scope: how widely a name is in a translation unit (local, global)
    - Local(Block): known only within the block
    - Global(File): known throughout the file after the point where defined
    - Names in function prototype: just within the parenthese
    - Members in class: class scope
    - Variables in namespace: namespace scope(global scope is a special namespace scope)
    - Automatic variable: local
    - Static variable: either
    - Functions: class, namespace, or global(no local scope!!! If wanted, use a `lambda`)
- C++ storage choice:
    - Storage duration
    - Scope
    - Linkage
### Automatic Storage Duration
Source code: `C9_Automatic`
```C++
#include<iostream>

using namespace std;

template<class type>void test(type x);

int main(void){
	
	int a = 5;
	int b = 6;

	cout << "In main(): a = " << a << " in " << &a << endl;
	cout << "In main(): b = " << b << " in " << &b << endl;
	test(a);        
	cout << "In main(): a = " << a << " in " << &a << endl;
	cout << "In main(): b = " << b << " in " << &b << endl;
	
	return 0;
}

template<class type>void test(type x){

	type a = 9;

	cout << "In text(): a = " << a << " in " << &a << endl;
	cout << "In text(): x = " << x << " in " << &x << endl;

	// Block
	{
		type a = 7;
		cout << "In block: a = " << a << " in " << &a << endl;
		cout << "In block: x = " << x << " in " << &x << endl; // not matter
	}

	cout << "Outside: a = " << a << " in " << &a << endl;
	cout << "Outside: x = " << x << " in " << &x << endl;

}
```

- Function parameters and variables:
    - Automatic storage duration
    - Local scope
    - No linkage
- Each variable is allocated when program execution enters block, freed when execution leaves
    - Variables defined in like `{ int a; {int a;}}` will **hide the `a` in outer block when executing the inner block**, outer `a` exists again when execution leaves the inner block
    - Variable is **allocated** when execution **enters the block**, but the **scope** begins **only after the point of declaration**
    - Nowadays, automatic storage is allocated by default
- Compiler implement the automatic variables:
    - Set aside a section of memory and treat it as a **stack** for managing the flow and ebb of variables
    - New data stacked atop old data(adjacent location), The size of stack can be changing
    - Keep track of the stack by using **two pointers**
        - One to the base where the stack begins
        - One to the top which is the next free memory location
    - Function called
        - Automatic variables added to the stack
        - Pointer to the top points to next free memory location following
    - Function terminates, top pointer reset to the value **one by one** it had before function was called
    - Stack: last-in, first-out *LIFO*, like `A-B-C > return C > back to B...`
    - New values associated to the names in the function are not erased after function terminantes, but they are no longer labeled
    - Register variables: `register type name`
        - Used to suggest that the compiler use a CPU register to store an automatic variable for faster access to the variable
        - Generalized to mean that the variable was heavily used and compilers may provide some special treatment
        - Explicitly identify a variable being automatic now
```Console
In main(): a = 5 in 0x7fff2ef31120
In main(): b = 6 in 0x7fff2ef31124
In text(): a = 9 in 0x7fff2ef31100
In text(): x = 5 in 0x7fff2ef310fc
In block: a = 7 in 0x7fff2ef31104
In block: x = 5 in 0x7fff2ef310fc
Outside: a = 9 in 0x7fff2ef31100
Outside: x = 5 in 0x7fff2ef310fc
In main(): a = 5 in 0x7fff2ef31120
In main(): b = 6 in 0x7fff2ef31124
```

### Static Duration Variables
- Static storage duration variables with **all 3 kinds of linkage**
    - Number of them does not change as the program runs, compiler allocates a fixed block of memory to hold all the static variables
    - Stay presents as long as the program executes
    - Not explicitly initialized are valued `0` in approprate type(zero-initialized), including static arrays and structures 
- Three kinds of linkage: **`static` is overloaded**
    - External: `type name; {}`
    - Internal: `static type name; {}`
    - No: `{static type name;}`
- Three kinds of initialization
    - (Static)Zero-initialized
    - (Static)Constant expression initialization: new keyword: `constexpr`
    - Dynamic initialization 
        - First, all static variables are zero-initialized `int x`
        - Next, if initialized using a **constant expression** from file contents, it's constant-expression initialized `int y = 2*sizeof(long)+1`
        - If there is not enough information, the variable is dynamically initialized `double pi = 4.0*atan2(1.0,1.0)`

### Static Duration, External Linkage
Source code: `C9_Staticexternal`
```C++
// f1.cpp
#include<iostream>

using namespace std;

double a = 0.1;

void update(double);
void local(void);

int main(void){

	cout << "Now a = " << a << endl;
	update(a);
	cout << "Now a = " << a << endl;
	local();
	cout << "Now a = " << a << endl;

	return 0;
}

// f2.cpp
#include<iostream>

using namespace std;

extern double a; // declaration

void update(double dt){
	a += dt;
	cout << "Update, a = " << a << endl;
}

void local(void){
	double a = 0.6;
	cout << "Local, a = " << a << endl; // Hide the global
	cout << "Global, a = " << ::a << endl; // Restart the global
}
```

- Variables with external linkage, external variables, global variables 
- External variables **need declaring in each file** using the variables
- ODR: one-definition rule: only one definition of a variable
    - Definition: storage for the variable to be allocated
    - Declaration: **reference** to an existing variables
    - Use `extern type var` without initialization as **the declaration**, otherwise a **definition**
    - There could be that automatic variables sharing the same name as the external variables inside a block but they can **hide the global ones**
- Use `extern type var; {::var}` called *scope-resolution operator* to call back the **global variable**
- Remember to use `const` to protect global variables to avoid unreliable programming

```Console
Now a = 0.1
Update, a = 0.2
Now a = 0.2
Local, a = 0.6
Global, a = 0.2
Now a = 0.2
```

### Static Duration, Internal Linkage
Source code: `C9_Staticinternal`
```C++

```

- 
- 

```Console

```

### Static Duration, No Linkage
Source code: `C9_Staticnolink`
```C++

```
- 
- 

```Console

```
## Namespaces

