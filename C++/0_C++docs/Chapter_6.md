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
#include<iostream>

int main(void){

	using namespace std;

	int a;

	do{
		cout << "Input an integer and enter -3 to quit: ";
		cin >> a;
		if(a<0 || a==0){
			cout << "It is non-positive" << endl;
		}
		else if(a>1 && a<10){
			cout << "It is smaller than 10 but greater than 1" << endl;
		}
		else if(!(a>20) and not(a<10)){
			cout << "It is not greater than 20" << endl;
		}
		else if((a>=22) and (a<30)){
			cout << "It is not greater or equal to 30" << endl;
		}
		else{
			cout << "Big number, is it?" << endl;
		}
	}while(a!=-3);

	return 0;
}
```

- Or: `||`, `or`
- And: `&&`, `and`
- Not: `!`, `not`
- Low to high: (and &&, or ||) -> ($ > $, $ < $, $==$,...) -> (not !)

```Console
Input an integer and enter -3 to quit: -1
It is non-positive
Input an integer and enter -3 to quit: 0
It is non-positive
Input an integer and enter -3 to quit: 2
It is smaller than 10 but greater than 1
Input an integer and enter -3 to quit: 3
It is smaller than 10 but greater than 1
Input an integer and enter -3 to quit: 4
It is smaller than 10 but greater than 1
Input an integer and enter -3 to quit: 9
It is smaller than 10 but greater than 1
Input an integer and enter -3 to quit: 10
It is not greater than 20
Input an integer and enter -3 to quit: 11
It is not greater than 20
Input an integer and enter -3 to quit: 13
It is not greater than 20
Input an integer and enter -3 to quit: 20
It is not greater than 20
Input an integer and enter -3 to quit: 21
Big number, is it?
Input an integer and enter -3 to quit: 29
It is not greater or equal to 30
Input an integer and enter -3 to quit: 30
Big number, is it?
Input an integer and enter -3 to quit: -3
It is non-positive
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
