# Loops and Relational Expressions
---

## Introducing for Loops
Source code: `C5_Forloop`
```C++
#include<iostream>

int main(void){

	using namespace std;

	int i;
	int limit;

	// example
	for(i=0; i<4; i++){
		cout << "Welcome to C++!" << endl;
	};

	// test with bool
	cout << "Enter a limit: ";
	cin >> limit;
	for(i=limit; i; i--){
		cout << "i = " << i << endl;
	};
	cout << "Now i = " << i << endl;

	// expressions
	int member;
	int name = member = 4;
	cout << "member = " << member << endl;
	cout << "name = " << name << endl; 
	int another = (member = 5) + 6;
	cout << "member = " << member << endl;
	cout << "another = " << another << endl; 

	// test for bool
	cout << "member < name is " << (member < name) << endl;
	cout << "member < another is " << (member < another) << endl;
	cout.setf(ios_base::boolalpha); // output true or false
	cout << "member < name is " << (member < name) << endl;
	cout << "member < another is " << (member < another) << endl;

	// for init statement
	for(int j=0; j<4; j++){
		cout << j << ", ";
	}; // no more j
	cout << "no more" << endl; 

	return 0;
}
```

- Format: `for(index = start; index < end; index update` like `for(i=0;i<4;i++)`
- Enclosed in braces: `for(i=0;i<4;i++){ some; };` if there are more than 1 statements, **the `;` could be saved!**
- `i++` for done then increment, `++i` for incremented then do it, same as: `i=i+1`
- Order:
    - Initial value 
    - Test the loop with index
    - Execute the loop
    - Update index
- `for` loop is an *entry-condition* loop, evaluate tst **before each loop cycle**
- Look before you loop!
- C++ expressions:
    - In C++, any value or valid combination of values and operators constitute an expression and every expression has a value!
    - C++ defines the value of an assignment expression to be the value of the member on the left
    - Relational expressions like `x<y` evaluate to the `bool` values `true` or `false`
- C++ statements:
    - `age++` is an expression
    - `age++;` is an expression statement
    - Reverse is not true, like `int a;` is a statement while `int a` is not an expression for it has no value
    - `for` loop is not an expression either
- We can declare a variable in the initiaization area of a `for` loop like `for(int i=0;i<4;i++)`, after the loop ends, the `i` is eliminated

```Console
Welcome to C++!
Welcome to C++!
Welcome to C++!
Welcome to C++!
Enter a limit: 5
i = 5
i = 4
i = 3
i = 2
i = 1
Now i = 0
member = 4
name = 4
member = 5
another = 11
member < name is 0
member < another is 1
member < name is false
member < another is true
0, 1, 2, 3, no more
```

## Using for loops to calculate factorials with different step
Source code: `C5_Factorialloop`
```C++
#include<iostream>

using namespace std;

const int fasize = 10; 

int main(void){
	
	long long facto[fasize];
	long long doufa[fasize];

	
	*facto = *(facto+1) = 1; // 0!=1!=1 
	doufa[0] = doufa[1] = 1; // 0!!=1!!=1
	
	// n!=n(n-1)(n-2)...(n-(n-2))(n-(n-1))
	for(int i=1; i<fasize; i++){
		facto[i] = i*facto[i-1];
	};
	cout << "Factorial of " << fasize-1 << ": " << endl;
	for(int j=0; j<fasize; j++){
		cout << j << "! = " << facto[j] << endl;
	};
	cout << endl;

	// n!!=n(n-2)(n-4)...(n-(n-4))(n-(n-2))
	for(int i=2; i<fasize; i=i+2){ // double factorial of an even number
		doufa[i] = i*doufa[i-2];
	};
	cout << "Factorial of max even number <= " << fasize-1 << ": " << endl;
	for(int j=0; j<fasize; j=j+2){
		cout << j << "!! = " << doufa[j] << endl;
	};
	cout << endl;

	// n!!=n(n-2)(n-4)...(n-(n-3))(n-(n-1))
	for(int i=3; i<fasize; i=i+2){ // double factorial of an odd number
		doufa[i] = i*doufa[i-2];
	};
	cout << "Factorial of max odd number <= " << fasize-1 << ": " << endl;
	for(int j=1; j<fasize; j=j+2){
		cout << j << "!! = " << doufa[j] << endl;
	};

	return 0;
}
```

- Factorial: $n!=n(n-1)(n-2)\dots (n-(n-2))(n-(n-1))$
- Double factorial: 
    - $n$ is **even**: $n!=n(n-2)(n-4)\dots (n-(n-4))(n-(n-2))$
    - $n$ is **odd**: $n!=n(n-2)(n-4)\dots (n-(n-3))(n-(n-1))$

```Console
Factorial of 9: 
0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = 5040
8! = 40320
9! = 362880

Factorial of max even number <= 9: 
0!! = 1
2!! = 2
4!! = 8
6!! = 48
8!! = 384

Factorial of max odd number <= 9: 
1!! = 1
3!! = 3
5!! = 15
7!! = 105
9!! = 945
```

## Postfix and prefix version of decrement and inrement with string
Source code: `C5_Postpreindestring`
```C++
#include<iostream>
#include<cstring>

using namespace std;

int main(void){
	
	string sent;
	int x, y;

	cout << "Enter a sentence: ";
	getline(cin, sent);

	// Output in order
	for(int i=0; i<sent.size(); i++){
		cout << sent[i];
	};
	cout << ". " << endl;

	// Output in reverse order
	for(int i=sent.size()-1; i>=0; --i){ // Prefix and postfix works the same
		cout << sent[i];
	};
	cout << ". " << endl;

	// Comparison between prefix and postfix
	x = y = 20;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "x++ = " << x++ << ", ++y = " << ++y << endl;
	cout << "x = " << x << ", y = " << y << endl;

	return 0;
}
```

- Postfix of increment: `x++`, do with `x`, then increments
- Prefix of increment: `++x`, increment `x`, then do with it
- Decrement: `--x` or `x--`
- Use `string` class or `char` array to display strings
- *Side effect*: occurs when evaluating an expression modified something
- *Sequence point*: point at which all *side effects* are evaluated before going on, like `;`
- Full expression: not a subexpression of a larger expression like test condition `a++ < 10` in `while(a++ < 10)`
- Use `n++` and `++n` in `for` loops make no difference
    - `n++` will stash a copy of the value, increment it then return the stached copy, **less efficient**. 
    - `++n` will directly increment the value and return it, suggested

```Console
Enter a sentence: I am Guernica
I am Guernica. 
acinreuG ma I. 
x = 20, y = 20
x++ = 20, ++y = 21
x = 21, y = 21
```

## Pointer increment, combination and blocks
Source code: 
```C++
#include<iostream>

using namespace std;

const int arsize = 8;

int main(void){

	float arf[arsize];
	float *pt = arf;

	for(int i=0; i<arsize; i++)
		*(arf+i) = 5.0+0.1*(float)i; // No brackets
	
	cout << "Current addr of pt is " << pt << " with value " << *pt << endl;
	cout << "Increment pt++ is " << pt++ << " with value " << *pt << endl;
	cout << "Now pt is at " << pt << " with value " << *pt << endl;
	cout << "Increment ++pt is " << ++pt << " with value " << *pt << endl;
	cout << "Increment at " << pt << " value *++pt " << *++pt << endl;
	cout << "Increment at " << pt << " value *pt++ " << *pt++ << endl;
	cout << "Now pt is at " << pt << " with value " << *pt << endl;

	// Combination assignments
	pt+=1;
	cout << "Increment pt+=1 is " << pt << " with value " << *pt << endl;

	// Loops with blocks
	for(int i=0; i<arsize; ++i){ // Much more efficient than postfix
		cout << *(arf+i) << ", ";
	} // Ignore the ';' is OK
	cout << " Done! " << endl;

	int x = 20;
	{
		int x = 60;
		int y = 100;
		cout << x << ", " << y << ", ";
	}
	cout << x << endl;
	// cout << y << endl; // Turns out error!

	return 0;
}
```

- Though `char` array is a *pointer* in fact, *side effect* of it like `char ar[2]; ar++` is not permitted! 
- If incrementation is needed, pass the location to a pointer like `double *pt = ar; ar++` makes `ar` points to `pt[1]`, **size jump!**
    - `cout << pt++` finishes output then increments;
    - `*++pt` increments then takes the value 
- For dynamic array: `int* ar = new int[10]`, the `ar` points to `ar[0]`, and the `ar+=2` will make `ar` points to `ar[2]`
- Combination assignment operators: 
    - `k+=1` is equivalent to `k=k+1`
    - Other combinations: `-=`, `*=`, `/=`, `%=`
- Blocks with `{}`, if omit the `{}` and leave with indentation, the compiler **ignores** the indentation and only executes the first statement!
- Variables declared inside the block use *stacks* to store, which is *automatic storage*, the **LIFO** in [Chapter 4](Chapter_4.md)
    - The block ends, the variables defined inside are deallocated
    - The variables defined **externally** still work inside the block!
    - Define the variable with the same name outside the block, that one inside the block hides the old one with new one until the block ends!

```Console
Current addr of pt is 0x7fff63de3630 with value 5
Increment pt++ is 0x7fff63de3630 with value 5.1
Now pt is at 0x7fff63de3634 with value 5.1
Increment ++pt is 0x7fff63de3638 with value 5.2
Increment at 0x7fff63de3638 value *++pt 5.3
Increment at 0x7fff63de363c value *pt++ 5.3
Now pt is at 0x7fff63de3640 with value 5.4
Increment pt+=1 is 0x7fff63de3644 with value 5.5
5, 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7,  Done! 
60, 100, 20
```

## Comma operator 
Source code: `C5_Commaoperator`
```C++
#include<iostream>
#include<cstring>

int main(void){

	using namespace std;

	int i,j;
	char med;
	string sent;
	
	// Input a string
	cout << "Enter a sentence: ";
	getline(cin, sent);
	cout << "Your input is: " << sent << endl;

	// Reverse a string with comma operation
	for(i=0,j=sent.size()-1; i<j; ++i,--j){
		med = sent[i]; // med works as a mediation to swap the order
		sent[i] = sent[j];
		sent[j] = med;
	}
	cout << "Reversed input is: " << sent << endl;

	// Reverse back with variable defined inside the for loop
	for(int x=0,y=sent.size()-1; x<y; ++x,--y){
		char medi = sent[x];
		sent[x] = sent[y];
		sent[y] = medi;
	}
	cout << "Reversed back to be: " << sent << endl;

	// Comma as expression
	{
		int i=20, j=2*i; // Value of this expression is 40
		cout << "i = " << i << ", j = " << j << endl;
	}

	// Comma as operator, with precedence testing
	{
		int i=17; 
		cout << "i = " << i << endl;
		int j=(17,240); // Set to 240
		cout << "j = " << j << endl;
	}

	return 0;
}
```

- Comma `,` allows to sneak two expressions into a place
- Comma can be an operator like `++j, --i` or a separator `int i,j`
- Comma as expression, such as `int i = 20, j = 2*i`:
    - Comma is a sequence point that guarantees the first expression is evaluated
    - Comma as an expression is with the value of second part, which is `40`
- Comma as operator, the precedence is the lowest:
    - `cata = 17,240` states that `cata` is `17` and `240` does nothing
    - `cata = (17,240`) states that `cata` is `240` for value of second part

```Console
Enter a sentence: I am Cosmos
Your input is: I am Cosmos
Reversed input is: somsoC ma I
Reversed back to be: I am Cosmos
i = 20, j = 40
i = 17
j = 240
```

## Relaional expressions and comparisons
Source code: `C5_Relationcomparison`
```C++
#include<iostream>
#include<cstring>

int main(void){

	using namespace std;

	// Test for simple relational expression
	cout.setf(std::ios::boolalpha);
	for(int i=0; i<=5; i++){
		cout << i << (i<5) << " ";
	}
	cout << endl;

	// Test for char comparison with ASCII code
	cout.unsetf(std::ios::boolalpha);
	for(char a='a'; a<='e'; a++){
		cout << a << (a<'e') << " ";
	}
	cout << endl;

	// Let bool value operates with other integers
	int a=5;
	cout << "a=5, a+(a!=5) = " << a+(a>4) << endl << endl;

	char ar1[6] = "Zoo";
	char ar2[8] = "Zoo";
	char ar3[9] = "aviary";
	char *pt2 = ar2;
	char *pt3 = ar3;
	string str2 = ar2;
	string str3 = ar3;

	// Compare C-style string
	cout << "\"Zoo\" is the same with 0 though size differs: " 
		 << strcmp(ar1,ar2) << endl; // ar1 == ar2
	cout << "\"Zoo\" precedes \"aviary\" in ASCII code with negative value: " 
		 << strcmp(&ar1[0],&ar3[0]) << endl; // ar1 < ar3
	cout << "\"aviary\" follows \"Zoo\" in ASCII code with positive value: " 
		 << strcmp(pt3++,pt2++) << endl; // ar3 > ar2
	cout << "'v' follows 'o' in ASCII code with positive value: " 
		 << strcmp(pt3,pt2) << endl; // ar3 > ar2
	
	// Compare string class
	cout << "\"Zoo\" precedes \"aviary\" is true with bool value: " 
		 << (str2<str3)  << endl; // Return 1
	cout << "'o' follows 'v' is false with bool value: " 
		 << (str2[1]>str3[1]) << endl; // Return 0

	return 0;
}
```

- Conditional expression test for `bool` value, which is deeply connected with  *relational expression*:
    - Less than: `<`, greater than: `>`
    - Others: `<=`, `==`, `>=`, `!=`
    - Works with numbers and characters(ASCII code), `string` class, not C-style string though
    - Return a `bool` value
- String comparison:
    - C-style string: `word=="mate"` checks whether they are **stored at the same address!**
    - Function `strcmp()` takes two string address(can be pointers, string constants, character array names), all it needs are **locations** of strings
    - Two strings identical returns value `0`
    - First string **precedes** the second, returns a **negative** value, like `strcmp("Zoo", "aviary")`
    - First string **follows** the second, returns a **positive** value, like `strcmp("aviary", "Zoo")`
    - Precede or follows, is meant in the system collating sequence (alphabetically), which means characters are compared according to the system code for characters
    - C-style strings terminate with `\0`, for comparison, size is not the case
    - `strcmp()` is **true** when strings are **not identical**!
- Class `string` is allowed to directly use traditional relational expressions
- When output with relational expression results, use `()` as a good habit

```Console
0true 1true 2true 3true 4true 5false 
a1 b1 c1 d1 e0 
a=5, a+(a!=5) = 6

"Zoo" is the same with 0 though size differs: 0
"Zoo" precedes "aviary" in ASCII code with negative value: -7
"aviary" follows "Zoo" in ASCII code with positive value: 7
'v' follows 'o' in ASCII code with positive value: 7
"Zoo" precedes "aviary" is true with bool value: 1
'o' follows 'v' is false with bool value: 0
```

## The while Loop
Source code: `C5_Whilewaitloop`
```C++
#include<iostream>
#include<ctime>

#define FLOP float*

typedef float *flo, olf; // olf is still float

int main(void){

	using namespace std;

	int i=0; // Index initialization
	char name[8]="Cosmos";

	// Simple while loop
	while(i<5){
		cout << i;
		i++; // Don't forget it!
	}
	cout << endl;

	// Test with C-style string
	i=0; // Reinitialization
	while(*(name+i)){ // Same as name[i]!=0
		cout << name[i] << " " << (int)*(name+i) << endl;
		++i;
	}

	// Alias testing
	float arf[5] = {0.1,0.2,0.3};
	// FLOP a=&arf[1], b=arf; // Error of b!
	flo c=arf, d=&arf[1];
	olf e=*(arf+2);
	// cout << a << ", " << b << endl;
	cout << c << ", " << d << ", " << e << endl;

	// Time delay
	int sec;
	cout << "Enter a second: ";
	cin >> sec;

	clock_t delay = sec*CLOCKS_PER_SEC; // Second to system units
	cout << "Start\a" << endl;

	clock_t start = clock(); // Current time of execution
	while((clock()-start)<delay){ // Test for time of execution 
		if(delay/(clock()-start)==0) // Fails to count accurately!
			cout << (clock()-start)/CLOCKS_PER_SEC; // Output nothing
	} // Not exactly second of sec, the test at last will waste little time
	cout << endl << "Done!" << endl;

	return 0;
}
```

- `while` loop is an *entry-condition* loop
    - Update expression is contained in the body
    - Initialization is external
- `while(test-condition) body`, better with `{body}`
- For a string `char name[size]`, the expression `name[i]!='\0'` works the same as `name[i]` for the ASCII code of `\0` is `0`
- For `string` class, it works differently, how to identify the last character of `string` will be seen in [Chapter 16](Chapter_16.md)
- Time-delay loop:
    - `while(wait<10000) wait++;` is too unmanageable
    - `ctime` header file with `clock()` returns the **system time** since a program started execution, but doesn't return the time in seconds, type can be `long`, `unsigned long` or others
    - `ctime` header file with constant `CLOCKS_PER_SEC`, transfer time in system units to seconds or vice versa
    - `ctime` header file with alias `clock_t` as type of variables, can be converted into `long` or whatever is the proper type for system
    - The output of `clock()` is a huge amount of numbers
    - Set `clock()` into loop, it only counts approximately!
- Type alias:
    - `#define BYTE char` replaces all occurrences of `BYTE` with `char`, and makes `BYTE` an alias of `char`, but **only uppercases available**
    - `typedef char byte` works the same, and `byte` is an alias of `char` in this case, format: `typedef type alias`, **lowercase available too**
    - `#define POIN float*` then `POIN pa,pb` will make `pa` a pointer, but `pb` **a simple float**
    - `typedef float* poin` then `poin pa,pb` will make them **both pointers**!
    - `typedef` is better than `#define` and sometimes is the best and only choice!

```Console
01234
C 67
o 111
s 115
m 109
o 111
s 115
0x7ffc3106eb30, 0x7ffc3106eb34, 0.3
Enter a second: 5
Start

Done!
```

## The do-while Loop
Source code: `C5_Dowhileloop`
```C++
#include<iostream>

using namespace std;

const int better = 5;

int main(void){


	// Test for simple do while loop
	int n;
	do{
		cout << "Enter a number in the range 1~10 to find the better: ";
		cin >> n;
	}while(n!=better); // Don't forget the semicolon!
	cout << "Yes, " << n << " is the better one!" << endl;

	return 0;
}
```

- `do while` loop is the only *exit-condition* loop, for it test the condition only after a first loop is executed!
- `do body while(test-condition);` Don't forget the semicolon!

```Console
Enter a number in the range 1~10 to find the better: 1
Enter a number in the range 1~10 to find the better: 2
Enter a number in the range 1~10 to find the better: 3
Enter a number in the range 1~10 to find the better: 4
Enter a number in the range 1~10 to find the better: 5
Yes, 5 is the better one!
```

## Range-Based for Loop
Source code: `C5_Rangebased`
```C++
#include<iostream>

int main(void){

	using namespace std;

	double ard[5] = {0.1,1.2,2.3,3.4,4.5};

	// Can't modify array value
	for(double x:ard){
		cout << x << endl;
	}

	// Can modify array value, changed!!!
	for(double &x:ard){
		x *= 0.8;
		cout << x << endl;
	}

	return 0;
}
```

- `double ar[size]={2.1,2.2,...}; for(double x:ar)body`
    - Here `x`initially represents the first element of prices array, 
    - Loop executes with `x` representing the remain elements in turn
    - **Can't modify** the value of the array!
- `double ar[size]={2.1,2.2,...}; for(double &x:ar)body`
    - Here `x`initially represents the first element of prices array, 
    - Loop executes with `x` representing the remain elements in turn
    - **Can modify** the value of the array, and **`ar` has changed**!

```Console
0.1
1.2
2.3
3.4
4.5
0.08
0.96
1.84
2.72
3.6
```

## Text input and cin.get()
Souce code: `C5_Textcinget`
```C++
#include<iostream>

int main(void){

	using namespace std;

	int count = 0;
	char ch;

	// Text input igoring space with simple cin
	cout << "Enter a character and enter '#' to quit: " << endl;
	do{
		cin >> ch;
		++count;
		cout << ch;
	}while(ch!='#');
	cin.get(); // Clear the newline character and store the queue
	cout << endl << count << " characters read" << endl;

	// Text input including space with cin.get()
	count = 0; // Reset value
	cout << "Enter a character and enter '#' to quit: " << endl;
	cin.get(ch);
	while(ch!='#'){
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read" << endl;
	cout << "Enter another character: ";
	cin.get(ch);
	cout << ch << endl;

	// EOF and cin.fail(), cin.eof()
	count = 0; // Reset value
	cout << "Enter a character and enter 'CTRL D' to EOF: " << endl;
	cin.get(ch);
	while(cin.fail()==false){
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read" << endl;
	cin.clear(); // Clear EOF flags

	return 0;
}
```

- Directly `while(ch!='#'){cin>>ch}`
    - Enter a bunch of characters, when the loop test `'#'`, terminates
    - Type one, enter one works
    - Type some, enter one? `cin` reads *spaces* and *newline* characters as **nothing!**
    - Characters typed **don't get sent** to the program until `Enter`, loop tests **one by one in turn**, quits when test is `false`
- Use `cin.get(ch)` to obtain the *space* but still **leaves the unused input including the *space*** in the queue
    - The `cin >> ch` never reads `Enter` as an input
    - The `cin.get(ch)` reads though!
- Function overloading:
    - `cin.get(name, Arsize)` fetches `cin.get(char*,int)`
    - `cin.get(ch)` fetches `cin.get(char)`
    - Allows us to use the same name for related functions 
- EOF:
    - Redirection: executable file `exec` and a text file `text`
    - Type in the command prompt: `exec <text`, takes input from `text` rather than keyboard input
    - **The `Enter` is counted in this program!**, EOF is not
    - `cin` detects EOF, sets into *eofbit* and *failbit* to `1`
    - `cin.eof()` returns `true` if EOF detected
    - `cin.fail()` returns `true` if either *eofbit* or *failbit* has been set to `1`
    - If never press `Enter`, and type `CTRL D`, the first type pops out input again, the second one is EOF 
    - If press `Enter` following `CTRL D`, execution will ends properly
    - When EOF is detected, a flag is set, `cin` does not read anymore input, use `cin.clear()` to clear EOF flags and let `cin` proceed again
    - `CTRL D` is the keywords for *End of File* in Unix system
    - `CTRL Z` stops the execution, `CTRL C` ends the execution
    - `CTRL Z` terminates both inputs and outputs effectively
---
> Output with an `Enter` following `CTRL D`
```Console
Enter a character and enter '#' to quit: 
Sent me a#
Sentmea#
8 characters read
Enter a character and enter '#' to quit: 
Sent me a#
Sent me a
9 characters read
Enter another character: 

Enter a character and enter 'CTRL D' to EOF: 
Sent me a#
Sent me a#

11 characters read
```
---
> Output with `Enter` following `CTRL C` for `./teci`
```Console
Enter a character and enter '#' to quit: 
Sent me a#
Sentmea#
8 characters read
Enter a character and enter '#' to quit: 
Sent me a#
Sent me a
9 characters read
Enter another character: 

Enter a character and enter 'CTRL D' to EOF: 
Sent me a#
Sent me a#
^C
```
---
> Output with `Enter` following `CTRL C` for `make run`
```Console
Enter a character and enter '#' to quit: 
Sent me a#
Sentmea#
8 characters read
Enter a character and enter '#' to quit: 
Sent me a#
Sent me a
9 characters read
Enter another character: 

Enter a character and enter 'CTRL D' to EOF: 
Sent me a#
Sent me a#
^Cmake: *** [Makefile:4: run] Interrupt

```
There is an empty line!!!

## Idioms of character input and other versions of cin.get()
Source code: `C5_Idiomsinputget`
```C++
#include<iostream>
#include<cstdio>

int main(void){

	using namespace std;

	char cha;
	int chi;
	int count;
	
	// Idioms: while(cin.fail()==false), while(!cin.fail()), while(cin)
	count = 0;
	cout << "Enter a letter: ";
	while(!cin.get(cha)==false){  // Same as while(cin.get(cha))
		cout.put(cha);
		++count;
	}
	cout << endl << count << " characters read" << endl;

	cin.clear(); // Clear EOF flags set by cin
	clearerr(stdin); // Clear C-level EOF flags in FILE structure

	// Use 
	count = 0;
	cout << "Enter a letter: ";
	while((chi=cin.get())!=EOF){ // chi is type int
		// cout.put(static_cast<char>(chi)); // Type cast is needed
		cout.put((char)chi); // Type cast is needed
		++count;
	}
	cout << endl << count << " characters read" << endl;

	return 0;
}
```

- Common idioms for input:
    - `cin.get(char)` returns the value of `cin`, **an object**
    - `cin.get(ch)` can be **used in chain** for it returns a `cin` object, like `cin.get(ch1).get(ch2)`
    - `while(cin.fail()==false)`
    - `while(!cin.fail())` test if `cin` detects an EOF, and test other possible failure such as **disk failure**
    - `while(cin)` converts object `cin` to a `bool` value, and it is `true` if input is successful
    - `while(cin.get(ch))` is called for once in the test condition
- Other types of `cin.get()`
    - `cin.get(ch)` returns an object, `ch` is type `char`
    - `cin.get()` returns the character input, but type `int`, ASCII code
    - `ch = cin.get()` works the same as `cin.get(ch)`
        - The **former `ch`** is type `int` **storing character codes!** 
        - The **latter `ch`** is type `char`
    - `cout.put(ch)`, the argument should be type `char` instead of `int`
    - EOF is defined with value `-1` when `cin.get()` detects and returns(others return ASCII code), testing: `int ch = cin.get()`
    - EOF is a **signal** rather than a character, it states there is **no more characters**!
- If we're to continue input after EOF:
    - Include `limits`
    - Use `cin.clear()` to clear error flags
    - Include `cstdio`
    - Use `clearerr(stdin)` to clear the C‑level EOF flag explicitly in the FILE structure
- `Enter` is counted while EOF is not in this case either

---
> Output with an `Enter` following `CTRL D`
```Console
Enter a letter: Sent me
Sent me

8 characters read
Enter a letter: Sent me 
Sent me

8 characters read
```
---
> Output without an `Enter` following `CTRL D`(Double `CTRL D` to pass)
```Console
Enter a letter: Sent meSent me
7 characters read
Enter a letter: Sent meSent me
7 characters read
```

## Nested Loops and 2-D Arrays
Source code: `C5_Nestedloops`
```C++
#include<iostream>
#include<cstring>

const int ar_row = 5;
const int in_col = 5;
const int ch_col = 25;

int main(void){

	using namespace std;

	int arin[ar_row][in_col]{
		{1, 2, 3, 4, 5},
		{2, 3, 4, 5, 6},
		{3, 4, 5, 6, 7},
		{4, 5, 6, 7, 8},
		{5, 6, 7, 8, 9},
	}; // Normal 2-D int array
	char arch[ar_row][ch_col]{
		"Chai Wan",
		"Bba Ggo",
		"Tong LoWan",
		"Wan Zai",
		"Zhong Wan"
	}; // C-style string in 2-D char array

	// Not assigned initialization
	char *arpt[ar_row]; // Array of ar_row pointers to arrays
	char (*ptar)[ch_col]; // Pointer to whole array with ch_col elements
	char **ptpt; // Pointer to pointer
	string arst[ar_row]; // Array of ar_row strings
	string *ptst; // Pointer to string
	
	// Nested for loops to output 2-D array
	for(int i=0; i<ar_row; ++i){
		cout << arch[i] << ":\t";
		for(int j=0; j<in_col; ++j){
			cout << arin[j][i] << "\t";
		}
		cout << endl;
	}

	// Pass to array of char pointers
	for(int i=0; i<ar_row; ++i){
		cout << (*(arpt+i)=arch[i]) << ", "; // Another kind of pt to pt
	}
	cout << "Done" << endl;

	// Pass to pointer of C-style string of whole array
	cout << *(ptar = &arch[0]) << ", ";
	for(int j=0; j<ch_col; ++j){
		// arch[1] is passed to the location *ptar points to
		(*ptar)[j] = arch[1][j];  
		cout << (*ptar)[j];
	}
	// arch[2] is passed to the location *ptar points to
	strcpy(*ptar, arch[2]);
	cout << ", " << *ptar << ", Done" << endl;

	// Output pointer to pointer, now arpt[0] == "Tong LoWan"
	cout << *(ptpt=arpt+0) << endl; // cout recognize *ptpt as an address

	// Output first element of second array
	cout << *(arpt[1]) << " == " << arpt[1][0]<< endl; 

	// Array of strings
	for(int i=0; i<ar_row; ++i){
		cout << (arst[i] = arch[i]) << ", ";
	}
	cout << "Done" << endl;

	// Pointer to strings
	for(int i=0; i<ar_row; ++i){
		cout << *(ptst = &arst[i]) << ", ";
	}
	cout << "Done" << endl;

	return 0;
}
```

- Definition: `type name[row][column]`
    - `name[row]` refers to subarrays
    - `name[row][column]` refers to typical elements in typical subarrays
- Initialization: `type name[row][column]={ {}, {}, {}...}`
- Equivalence of `type name[row][column]`
    - `type *name[row]`
    - Define an array of `row` pointers
    - Each `name[index] == *(name+index)` stores the address of the first element in typical array
- Danger: `*name[index]` is ambiguous, if to take the first element, use `name[index][0]` or `*(name[indexa])`
- Array of `string`:
    - Define: `char name[row][column]`
    - Equivalence but more convenient: `string name[row]`
- For array of array or pointer to pointer `char *name[size]`, clarify:
    - `name` is the address of first address as an element of the first element
    - `name[index]` is the address of the first element of `index` row
    - `&name[index]` is the address pointing to address of the first element of `index` row
    - `*(name[index])` takes the value of first element of `index` row
- Pointer to `string` as address is not compatible with pointer to `char`
- `string` can be compatible with C-style string and addresses, while pointer to `string` is only compatible with addresses of `string` class

```Console
Chai Wan:	1	2	3	4	5	
Bba Ggo:	2	3	4	5	6	
Tong LoWan:	3	4	5	6	7	
Wan Zai:	4	5	6	7	8	
Zhong Wan:	5	6	7	8	9	
Chai Wan, Bba Ggo, Tong LoWan, Wan Zai, Zhong Wan, Done
Chai Wan, Bba Ggo, Tong LoWan, Done
Tong LoWan
B == B
Tong LoWan, Bba Ggo, Tong LoWan, Wan Zai, Zhong Wan, Done
Tong LoWan, Bba Ggo, Tong LoWan, Wan Zai, Zhong Wan, Done
```
