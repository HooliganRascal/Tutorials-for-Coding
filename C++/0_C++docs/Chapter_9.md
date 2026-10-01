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

### Scope and Linkage
Source code: `C9_ `
```C++

```
- 
- 
```Console

```

## Namespaces

