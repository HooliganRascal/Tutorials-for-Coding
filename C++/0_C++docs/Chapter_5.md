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

```

- `while` loop is an *entry-condition* loop
    - Update expression is contained in the body
    - Initialization is external
- `while(test-condition) body`, better with `{body}`
- For a string `char name[size]`, the expression `name[i]!='\0'` works the same as `name[i]` for the ASCII code of `\0` is `0`
- For `string` class, it works differently, how to identify the last character of `string` will be seen in [Chapter 16](Chapter_16.md)
- Time-delay loop:
    - `while(wait<10000) wait++;` is too unmanageable
    - Builtin `clock()` returns the **system time** since a program started execution, but doesn't return the time in seconds, type can be `long`, `unsigned long` or others
    - `ctime` header file with constant `CLOCKS_PER_SEC`, transfer time in system units to seconds or vice versa
    - `ctime` header file with alias `clock_t` as type of variables, can be converted into `long` or whatever is the proper type for system
- Type alias:
    - `#define BYTE char` replaces all occurrences of `BYTE` with `char`, and makes `BYTE` an alias of `char`, but **only uppercases available**
    - `typedef char byte` works the same, and `byte` is an alias of `char` in this case, format: `typedef type alias`, **lowercase available too**
    - `#define POIN float*` then `POIN pa,pb` will make `pa` a pointer, but `pb` **a simple float**
    - `typedef float* poin` then `poin pa,pb` will make them **both pointers**!
    - `typedef` is better than `#define` and sometimes is the best and only choice!

```Console

```
