# Getting Started with C++
---

## Creating Souce Code

Valid name: `*.C`, `*.cc`, `*.cxx`, `*.c++`, `*.cpp` (we use `*.cpp` here)

## Compiling and Linking

- For Linux: `g++ *.cpp` 
    - default running the compiling and linking, leaving one `a.out` as output
    - run `g++ -c *.cpp` producing a object file`*.o`, `-c` stands for compiling only
    - run `g++ *.o` to produce an executable file `a.out`
    - run `./a.out` as executable file
    - recommended: `g++ *.cpp -o *` where `-o` stands for output
- This can be used for writing a `Makefike`

## Preparation for HelloWorld.cpp

Source code of `HelloWorld.cpp`:
```cpp
#include<iostream>

int main(void){
	using namespace std;
	cout << "Hello World!";
	cout << endl;
	return 0;
}
```

---
Source code of `Makefile`:
```Makefile
# compile producing an object file
compile:
	g++ -c HelloWorld.cpp
# link producing an impermitted executable file
link:
	g++ HelloWorld.o
# compile and link producing only an impermitted executable file
compile-link:
	g++ HelloWorld.cpp
# run the executable file
run:
	./a.out

# recommended building
build:
	g++ HelloWorld.cpp -o HelloWorld
runall:
	./HelloWorld

# clean object files and executable files
clean-o:
	rm HelloWorld.o 
clean-e:
	rm a.out
clean-runall:
	rm HelloWorld
```

## Test result for HelloWorld.cpp

Compilation and linking separated:
```console
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
HelloWorld.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make compile
g++ -c HelloWorld.cpp
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
HelloWorld.cpp  HelloWorld.o  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make link 
g++ HelloWorld.o
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
a.out  HelloWorld.cpp  HelloWorld.o  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make run
./a.out
Hello World!
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
a.out  HelloWorld.cpp  HelloWorld.o  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make clean-e clean-o
rm a.out
rm HelloWorld.o 
```
---

Compilation and linking together:
```console
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
HelloWorld.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make compile-link 
g++ HelloWorld.cpp
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
a.out  HelloWorld.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make run
./a.out
Hello World!     
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make clean-e
rm a.out
```
---
Recommended building:
```console
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
HelloWorld.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make build 
g++ HelloWorld.cpp -o HelloWorld
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
HelloWorld  HelloWorld.cpp  Makefile
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make runall 
./HelloWorld
Hello World!
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ make clean-runall 
rm HelloWorld
mteltn@mteltn:~/Desktop/Code_Projects/Tutorials-for-Coding/C++/1$ ls
HelloWorld.cpp  Makefile
```

---
We prefer the recommended `g++ *.cpp -o *` in the future for single file building
