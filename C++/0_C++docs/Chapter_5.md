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
