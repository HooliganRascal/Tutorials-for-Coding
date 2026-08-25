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
- Enclosed in braces: `for(i=0;i<4;i++){ some; };` if there are more than 1 statements, **don't forget the `;`!**
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

```

- Though `char` array is a *pointer* in fact, *side effect* of it like `char ar[2]; ar++` is not permitted! 
- If incrementation is needed, pass the location to a pointer like `double *pt = ar; ar++` makes `ar` points to `pt[1]`
- For dynamic array: `int* ar = new int[10]`, the `ar` points to `ar[0]`, and the `ar+=2` will make `ar` points to `ar[2]`

## Comma operator and relational expressions

## Loops with string comparison
