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
Source code: `C6_Characterfunctions`
```C++
#include<iostream>
#include<cctype>

int main(void){

	using namespace std;

	cout << "'a' is " << isalpha('a') << endl;
	cout << "'\\t ' is " << isspace('\t') << endl;
	cout << "'3' is " << isdigit('3') << endl;
	cout << "'.' is " << ispunct('.') << endl;

	return 0;
}
```

- The arguments of these functions are all **characters**!
- `isalpha(ch)` returns a nonzero value if it is a letter, return type `int`
- `isdigit()` tests for digit characters like `3`
- `isspace()` tests for whitespace characters like newlines, spaces and tabs

```Console
'a' is 1024
'\t ' is 8192
'3' is 1
'.' is 4
```

## The ?: operator
Source code: `C6_Conditionaloperator`
```C++
#include<iostream>

int main(void){

	using namespace std;

	int a,b,c;
	
	cout << "Enter two integers: ";
	cin >> a >> b;
	cout << "The larger of " << a << " and " << b 
		 << " is " << (c=a>b?a:b) << endl;

	return 0;
}
```

- `expression1 ? expression2 : expression3`
- If `expression1` is **true**, returns the value of `expression2`, otherwise `expression3`
- `(5>3)?1:0` returns `1`
- About `cin >> a >> b`: Enter two integers split by any white spaces!

```Console
Enter two integers: 1
2
The larger of 1 and 2 is 2
```

## The switch statement
Source code: `C6_Switchstatement`
```C++
#include<iostream>

enum color{
	red, orange, yellow, green, blue, violet, indigo
};

int main(void){

	using namespace std;

	char cha = '1';
	int num = 1;
	int col = color(1);

	switch(cha){
		case '1': cout << "Output '1'" << endl;
				  break;
		case '2': cout << "Output '2'" << endl;
				  break;
		case 'A': // Continue to execute case 'a' without break
		case 'a': cout << "Output 'a'" << endl;
				  break;
		default : cout << "Output non-character" << endl;
	}

	switch(num){
		case 1: cout << "Output 1" << endl;
				break;
		case 2: cout << "Output 2" << endl;
				break;
		default: cout << "Output non-num" << endl;
	}

	switch(col){
		case red : cout << "Color is red" << endl; break;
		case orange : cout << "Color is orange" << endl; break;
		case yellow : cout << "Color is yellow" << endl; break;
		default: cout << "Output non-color" << endl;
	}

	return 0;
}
```
- Form: `switch(num){case 1: st1 break; case 2: st2 break; st3 break; ... default: stnum}` 
- Label can be a `char` like `q` or an integer like `1` or `enumerator`
- Execution does **not** automatically stop at the case, use `break`
- If `num` does not match any case listed, the programs triggers `default`, which is optional and program jumps to next statement following the `switch` with or without `default`
- If alternatives involve ranges or floating-point tests or comparison, use `if-else`

```Console
Output '1'
Output 1
Color is orange
```

## The break and continue statements
Source code: `C6_Breakcontinue`
```C++
#include<iostream>

int main(void){

	using namespace std;

	for(int i=0; i<5; ++i){
		if(i==3){
			break;
		}
		else{
			cout << "This outputs 3 times" << endl;
		}
	}
	cout << endl;

	int j=0;
	do{
		cout << "This outputs 5 times" << endl;
		++j;
		if(j<=3){
			cout << "But this output 3 times" << endl;
		}
		else{
			continue;
		}
		cout << "After output once, this shows up" << endl;
	}while(j<5);
	cout << endl;

	int k=0;
	while(k<5){
		cout << "This tries to output 5 times again" << endl;
		++k;
		if(k==3){
			goto jump3;
		}
		else{
			continue;
		}
	}
	jump3: cout << "When output for 3 times, jumps to this" << endl;

	return 0;
}
```

- Enable a program to skip over parts of the code
- `break` causes program execution to pass to the next statement following `switch` statements or loops
- `continue` in the loop causes the program to skip the rest of the body of the loop and start a new one
- `goto` like `goto name; ... name: statement` means to **jump** to the location bearing the `name:` label

```Console
This outputs 3 times
This outputs 3 times
This outputs 3 times

This outputs 5 times
But this output 3 times
After output once, this shows up
This outputs 5 times
But this output 3 times
After output once, this shows up
This outputs 5 times
But this output 3 times
After output once, this shows up
This outputs 5 times
This outputs 5 times

This tries to output 5 times again
This tries to output 5 times again
This tries to output 5 times again
When output for 3 times, jumps to this
```

## Number reading loops
Souce code: `C6_Numberreading`
```C++
#include<iostream>

const int Max = 5;
using namespace std;

int main(void){

	double fish[Max];
	double golf[Max];

	int i = 0;
	double total = 0.0;
	double avg = 0.0;

	// Simple quit of cin
	cout << "Enter the weights of your fish and <q to quit>" << endl;
	cout << "fish #1: ";
	while(i<Max && cin >> fish[i]){
		if(++i<Max){
			cout << "fish #" << i+1 << ": ";
		}
	}
	for(int j=0; j<i; ++j){
		total += fish[j];
	}
	avg = total/(double)i;
	if(i==0){
		cout << "No fish" << endl;
	}
	else{
		cout << avg << " = average weight of " << i << " fish" << endl;
	}
	cout << "Done !" << endl;

	// Reset and continue of cin
	cin.clear(); // Clear input queue;
	cin.get(); // Read the newline
	cout << "Enter your scores of " << Max << " rounds!" << endl; 
	for(int j=0; j<Max; ++j){
		cout << "Round #" << j+1 << ": ";
		while(!(cin >> golf[j])){
			cin.clear(); // Clear error flags
			while(cin.get()!='\n'){ // Error input in the queue cleared
				continue;
			}
			cout << "Please enter a number!" << endl;
			cout << "Round #" << j+1 << ": ";
		}
	}
	total = 0.0; // Reset 
	for(int j=0; j<Max; ++j){
		total += golf[j];
	}
	avg = total/Max;
	cout << avg << " = average score of " << Max << " rounds" << endl;

	return 0;
}
```

- `cin` for **mismatched** input: 
    - Value left unchanged;
    - Mismatched input left in the input queue
    - Error flag is set in the `cin` object
    - Call to `cin` method converted to `bool` type and returns `false`
- `while(i<Max && cin >> test[i])`: if `i=Max`, loop **terminates without trying to read a value** into a location past the end of the array
- `while(!(cin>>test[i])){cin.clear(); while(!='\n') continue; cout << ...}`
    - Reset `cin` to accept new input
    - Get rid of bad input
    - Prompt to try again

```Console
Enter the weights of your fish and <q to quit>
fish #1: 12
fish #2: 12
fish #3: 12
fish #4: q
12 = average weight of 3 fish
Done !
Enter your scores of 5 rounds!
Round #1: 1
Round #2: 2
Round #3: 3
Round #4: 4
Round #5: 5
3 = average score of 5 rounds
```

## Simple file input/output
Source code: `C6_SimplefileIO`
```C++
#include<iostream>
#include<fstream>
#include<cstdlib>

const int namesize = 50;

using namespace std;

int main(void){

	double a_price;
	double d_price;
	int year;
	int item1 = 0;
	int item2 = 0;
	char value;
	char mobile[namesize];
	char file2name[namesize] = "File2.txt";

	// Define output objects and input objects
	ofstream output1, output2;
	ifstream input1, input2;

	// Begin the output
	output1.open("File1.txt"); // Output named directly
	output2.open(file2name); // Output named in the program
	
	// Take the input
	cout << "Enter the make and model of mobile: ";
	cin.getline(mobile, namesize);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;

	// Do some algorithm
	d_price = 0.918 * a_price;

	// Output to screen
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << mobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	// Output to File1.txt
	output1 << fixed;
	output1.precision(2);
	output1.setf(ios_base::showpoint);
	output1 << "Make and model: " << mobile << endl;
	output1 << "Year: " << year << endl;
	output1 << "Was asking $" << a_price << endl;
	output1 << "Now asking $" << d_price << endl;

	// Output to File2.txt
	output2 << fixed;
	output2.precision(2);
	output2.setf(ios_base::showpoint);
	output2 << "Make and model: " << mobile << endl;
	output2 << "Year: " << year << endl;
	output2 << "Was asking $" << a_price << endl;
	output2 << "Now asking $" << d_price << endl;

	// End the output
	output1.close();
	output2.close();

	// Begin the input
	input1.open("File1.txt");
	input2.open(file2name);

	// Test if File1 succeeds to open
	if(!input1.is_open()){
		cout << "Could not open the file \"File1.txt\"! " << endl;
		cout << "Program terminating!" << endl;
		exit(EXIT_FAILURE);
	}

	// Open the input1 file and read the item
	do{
		input1.get(); // Use get() to read character 
		++item1;
	}while(input1.good());

	// Alternative to read the item
	while(input2>>value){
		++item2;
	}

	// Test for input termination
	if(input1.eof()){
		cout << "End of file reached." << endl;
	}
	else if(input1.fail()){
		cout << "Input terminated by data mismatch." << endl;
	}
	else{
		cout << "Input terminated for unknown reason." << endl;
	}

	// Output the result to input process
	if(item1==0){
		cout << "No data in the file" << endl;
	}
	else{
		cout << "Items read: " << item1 << endl;
		cout << "Items read: " << item2 << endl;
	}

	// End the input
	input1.close();
	input2.close();

	return 0;
}
```

- Text input with `cin`, it reads as a series of bytes interpreted as a `char` code
- Then `cin` translates the **text data** into other types
- Input with **text file!**
- Necessity for writing to a text file:
    - Included `fstream` defines an `ofstream` class for handing output 
    - Declare some `ofstream` objects as named
    - Account for `std` namespace
    - Associate an `ofstream` object with a file, use `open()`
    - Use `close()` when finishing with a file
    - It is available to use `<<` for `ofstream` objects
    - Output object preparation:
        - `object << fixed`: Set the `precision` after the point rather than *significant figure*
        - `object.precision(num)`: Use a precision of `num` for display
        - `object.setf(ios_base::showpoint)`: Always show points for floating number
    - If output with existing file, it is **trimmed to zero length**, replaced with new output
- Necessity for reading from a text file:
    - Included `fstream` defines an `ifstream` class for handing input 
    - Declare some `ifstream` objects as named
    - Account for `std` namespace
    - Associate an `ifstream` object with a file, use `open()`
    - Use `close()` when finishing with a file
    - It is available to use `>>` for `ifstream` objects
    - It is available to use `get()` and `getline()` for `ifstream` objects
    - It is available to use `eof()` and `fail()` to monitor the success of an input attempt
    - If an `ifstream` object used as a test condition like `if(object >> value)`, it is concerted to `bool` type
    - Input object preparation:
        - Include `cstdlib` for `exit()` and `EXIT_FAILUERE` to terminates the program if necessary
        - Use `get()` to count **including the space**
        - Use `object >> value` to count **excluding the space!**
        - Use `good()` to check if input is good. Alternative: `char value; while(object >> value){ statements; }`
        - Use `eof()` to check if it is terminated by end of file
        - Use `fail()` to check if it is terminated for data mismatch (Always used for `type name;object >> name`, and `object.get()` reads as `char` type data by default), **also check the `eof`!**
        - Few to use `bad()` to test if the program encounters a corrupted file or a hardware failure
    - If input with an non-existent file, the attempts to input fail. Use `is_open()` to check: `if(!file.is_open()){exit(EXIT_FAILURE);}`
    - For `input.open()`, if initialized with `input.open(filename); filename[namesize]="name"`, the name can contain the **location**: `file[namesize]="./address/subaddress/name"`
    - Some text editors may require an `Enter` after typing the final text before exiting for they don't automatically add a *carriage return character followed by a linefeed character* to the final line to terminate a line of text

```Console
Enter the make and model of mobile: Flitz Perky
Enter the model year: 2009
Enter the original asking price: 13500
Make and model: Flitz Perky
Year: 2009
Was asking $13500.00
Now asking $12393.00
End of file reached.
Items read: 82
Items read: 68
```
