# Branching Statements and Logical Operators
---

## If-else statements
Source code: `C6_Ifelsestatement`
```C++
#include<iostream>

int main(void){

	using namespace std;

	char ch;
	int ga = 0;
	int gb = 0;
	int so = 0;

	cout << "Enter A, B then a newline as a grade, EOF to quit: " << endl;
	while(!cin.get(ch)==false){
		cin.get();
		if(ch=='A'){
			ga++;
		}
		else if(ch=='B'){
			gb++;
		}else{
			so++;
		}
	}

	cout << "Grade of 'A' is: " << ga << endl;
	cout << "Grade of 'B' is: " << gb << endl;
	cout << "Grade of soso is: " << so << endl;

	return 0;
}
```

- `if` syntax: `if(test_1) body` or `if(test_1){body}`, when `test_1` is not met, the program skips the `if`
- `ifelse` syntax: `if(test_1)body1 else body2`
- `ifelseifelse` syntax: `if(test_1){body1} else if(test_2)body2 else body3`
> Branching condition **should not conflict** with loop test condition if they are nested

```Console
Enter A, B then a newline as a grade, EOF to quit: 
A
B
C
A
Grade of 'A' is: 2
Grade of 'B' is: 1
Grade of soso is: 1
```

## Logical expressions
Source code: `C6_Logicalexpressions`
```C++

```

- Or: `||`, `or`
- And: `&&`, `and`
- Not: `!`, `not`
- Low to high: (and, or) -> ($ > $, $ < $, $==$) -> (!)

```Console

```

## The cctype library of character functions
Source code: `C6_Librarycctype`
```C++

```
- 
- 

```Console

```

## The ?: operator
Source code: `C6_Conditionaloperator`
```C++
```

- 
- 

```Console

```

## The switch statement
Source code: `C6_Switchstatement`
```C++

```
- 
- 

```Console
```

##
