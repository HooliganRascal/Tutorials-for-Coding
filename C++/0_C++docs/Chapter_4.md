# Compound Types
---

## Create an array

Source code: `C4_Arrayinitialize`
```C++
#include<iostream>

int main(void){

	using namespace std;

	const int siza = 3;

	// define
	int integer[3];
	cout << "Defined Unassigned first of the array is " << integer[0] << endl;

	// assign and operate
	int integers[siza];
	integers[0] = 7;
	cout << "Assigned first number is " << integers[0] << endl;
	cout << "Assigned first number plus 1 is " << integers[0] + 1 << endl;

	// initialize
	float stock[4] = {6.2, 2.7 ,3.5, 4.1};
	float etock[4] = {1.9, 2.7, 3.5};
	float ztock[4] = {};
	float dtock[]  = {5.1, 2.3, 4.7, 9.6};
	float qtock[]  = {};
	cout << "Last 1 of stock is " << stock[3] << endl;
	cout << "Over 1 of stock is " << stock[4] << endl; // surpasses to etock!
	cout << "Unassigned last 1 of etock is " << etock[3] << endl;
	cout << "All elements in an empty array are " << ztock[2] << endl;
	cout << "Let the compiler decides, one element is " << dtock[2] << endl;
	cout << "Let the compiler decides, over 1 element is " << dtock[4] << endl;
	cout << "Let the compiler decides, no element for " << qtock[0] << endl;

	// explore empty array, does not affect other memories
	qtock[0] = 1.2;
	qtock[1] = 2.1;
	cout << "Let the compiler decides, assigned 1 be " << qtock[0] << endl;
	cout << "Let the compiler decides, assigned 2 be " << qtock[1] << endl;

	// assign overly
	float atock[5] = {6.3}; // assigned, initialized, does not work
	float btock[5];
	dtock[4] = 5.5;
	cout << "Assigned overly nextly be " << atock[0] << endl; // taken hard
	cout << "Assigned overly nextly again be " << btock[0] << endl; // recover

	return 0;
}
```
- define rule: `type array[constant integer]`
    - **don't define without size!**
    - define with size of constant number, don't with variables
    - every time defining an array, memory allocated
- assignment: `integer[0] = 7`
    - assign individually
    - **not allowed** for `int array[]; array = {1,2,3,4}`
    - defined but not assigned will be *shit*
    - assign overly will take up when nextly allocating memory
    - assign overly and nextly defined, whether initialized or not, get taken
    - assign overly and nextly defined, whether assigned or not, get taken
- initialization: `float stock[4] = {1.0, 2.0, 3.0, 4.0}`
    - unassigned one is `null`
    - over location **surpasses**
    - initialized with no size: *over terms are shits*
    - initialized with nothing: *any term is shit*
- don't output the array directly unless it's a **string** !

```console
Defined Unassigned first of the array is 262039296
Assigned first number is 7
Assigned first number plus 1 is 8
Last 1 of stock is 4.1
Over 1 of stock is 1.9
Unassigned last 1 of etock is 0
All elements in an empty array are 0
Let the compiler decides, one element is 4.7
Let the compiler decides, over 1 element is 1.07648e+21
Let the compiler decides, no element for 4.59149e-41
Let the compiler decides, assigned 1 be 1.2
Let the compiler decides, assigned 2 be 2.1
Assigned overly nextly be 5.5
Assigned overly nextly again be -6.00985e-21
```
## Char array and string

Source code: `C4_Charstring`
```C++
#include<iostream>

int main(void){

	using namespace std;

	// initialization of char array and string
	char name_char[6] = {'M','t','e','l','t','n'};
	char name_string[7] = {'M','t','e','l','t','n','\0'}; // last null takes
	char name_strings[7] = {"Mteltn"}; // still needs one more place
	char name_stringes[] = {"Mteltn"};
	char name_stringbs[7] = "Mteltn";
	char name_stringzs[] = "Mteltn"; // let the compiler counts
	
	// inputting
	char name[20];
	char dessert[20];
	char letter;
	
	// output the initialization
	cout << "char array : " << name_char << endl;
	cout << "strings by array : " << name_string << endl;
	cout << "strings by total sring: " << name_strings << endl;
	cout << "strings by total sring with no size: " << name_stringes << endl;
	cout << "strings without brackets: " << name_stringbs << endl;
	cout << "strings without brackets and size: " << name_stringzs << endl;
	cout << "Let's concatenating the " // concatenating
			"strings !" << endl;

	// output the input with  getline()
	cout << "Enter your name: ";
	cin.getline(name, 20); // use getline() member function
	cout << "Enter what you want: ";
	cin.getline(dessert, 20);
	cout << "Your name is " << name << ", and you want " << dessert << endl;

	// output the input with get()
	cout << "Enter your name again: ";
	cin.get(name, 20).get(); // use get() member function
							 // same as: cin.get(name, 20); cin.get()
	cout << "Enter a letter: ";
	(cin >> letter).get(); // restore input queue
						   // same as : cin >> letter; cin.get()
	cout << "Enter what you want again: ";
	cin.get(dessert, 20);
	cout << "Your name is " << name 
		 << ", you entered " << letter 
		 << ", and you want " << dessert << endl;

	return 0;
}
```

- last character of a string is `'\0'` or *null*
- initialize a string by *char array*
- limitation of string or character array :
    - assigning limits the size much stronger than other array, thus safer
    - inputting over the size prints the stack smashing
- directly output the character array interprets any next bytes until `null`
- middle: 
    - initializing `char boss[8] = "Bozo"`. 4 next empty space set to `\0`
    - assigning or inputting as well
- concatenating strings is only permitted for explicit string like `"aa" "bb"`
- input the strings:
    - inputting the `empty space` with `cin` will be seen as `null` and ends the memory
    - using `getline()` *member function* in `istream` **discards the `Enter`**
    - using `get()` *member function* in `istream` **leaves the `Enter` in the input queue, which will be the first character for next input**
    - mixing input of `cin` and nextly `cin.getline()` or `cin.get()` will leave the first `Enter` in the input queue
    - use `get()` to restore the input queue!

```console
char array : MteltnMteltn
strings by array : Mteltn
strings by total sring: Mteltn
strings by total sring with no size: Mteltn
strings without brackets: Mteltn
strings without brackets and size: Mteltn
Let's concatenating the strings !
Enter your name: Mteltn Guernica
Enter what you want: Steak and wine
Your name is Mteltn Guernica, and you want Steak and wine
Enter your name again: Cosmos Streamer
Enter a letter: P
Enter what you want again: Eternal Life
Your name is Cosmos Streamer, you entered P, and you want Eternal Life
```

## String class
Source code:
```C++
#include<iostream>
#include<cstring>

int main(void){

	using namespace std;

	// Initialization
	char char1[20] = "Strings? ";
	char char2[10];
	string str1;
	string str2;
	string str3 = {"Standing in the hall of fame! "};
	string str4 = "Burn with the brightest flame! ";

	// Input
	cout << "Enter a string: "; 
	cin >> str1; // space as end, works for word
	cin.get();
	cout << "The string you enter is: " << str1 << endl;
	cout << "Enter again with getline: ";
	getline(cin, str1); // cin as argument
	cout << "The string you enter is: " << str1 << endl;
	cout << "The size of your string is " << str1.size() << endl;
	cout << "The 3rd character of your string is " << str1[2] << endl;

	// Assign and concatenate
	strcpy(char2, char1);
	str2 = str1;
	cout << "Copied: "<< char2 << endl;
	cout << "Concatenating strings: " << str2 + str3 << endl;

	// Appending
	strcat(char2, "Yes!");
	str4 += str3;
	cout << "Appending by char string: \n" << char2 << endl;
	cout << "Appending by string class: \n" << str4 << endl;
	

	return 0;
}
```

- Make `string` more like an variable
- Initialization and assignment:
    - No size needed
    - Recognize `space` as end
    - **Only works for word input**
- Concatenate by `+` and appendable
- Operation for *char strings*, include `<cstring>`, and use `strcpy`, `strcat`...
- Operate for *string class* with `getline` and `size`
- There are also other `string` literals like: `wchar_t`, `char16_t` ...

```Console
Enter a string: swad
The string you enter is: swad
Enter again with getline: swad sasf
The string you enter is: swad sasf
The size of your string is 9
The 3rd character of your string is a
Copied: Strings? 
Concatenating strings: swad sasfStanding in the hall of fame! 
Appending by char string: 
Strings? Yes!
Appending by string class: 
Burn with the brightest flame! Standing in the hall of fame!
```

## Structure
Source code
```C++
#include<iostream>
#include<cstring>

using namespace std;

struct info{
	char name[20];
	int age;
	double height_cm;
};

struct memb{
	char pa1[20];
	char pa2[20];
}mem1, mem2;

// Bit fields
struct addi{
	int pluss : 4; // 4 bits for integer variable
	unsigned int : 4; // 4 bits unused for spacing
	bool booll: 1;
};


int main(void){

	// Initialization
	info myself = {"Guernica", 23, 175.6};
	info myfriend = {"Jinshin", 19, 173.1};
	info myother;
	info myarray[10]; // Array of 10 info structures
	info mytest[2] = {
		{"Mteltn", 20, 178.2},
		{"Cosmos", 20, 174.9}
	};
	addi myaddi = {7, true};

	// Assignment
	myother = myfriend;
	strcpy(mem1.pa1, "Actor");  
	strcpy(mem2.pa2, "Dresser");

	// Make use of structure arrays
	cout << "Enter a name for myarray[5]: ";
	cin.getline(myarray[5].name, 20);
	cout << "The name of myarray[5] is: " << myarray[5].name << endl;
	cout << "The name of mytest[0] is: " << mytest[0].name << endl;
	cout << "The height of mytest[0] is: " 
		 << mytest[0].height_cm 
		 << " in cm" 
		 << endl;

	// Normal output and operations
	cout << "My name is " << myself.name << endl;
	cout << "I am " << myself.age << " years old" << endl;
	cout << "I am " << myself.height_cm << " in cm" << endl;
	cout << myfriend.name << " is my friend" << endl;
	cout << "He is " << myfriend.height_cm << " in cm" << endl;
	cout << "Together will be " 
		 << myself.height_cm + myfriend.height_cm 
		 << " in cm" 
		 << endl;
	cout << "Same as " 
		 << myself.height_cm + myother.height_cm 
		 << " in cm" 
		 << endl;
	cout << "The pa1 of mem1 is " << mem1.pa1 << endl;
	cout << "The pa1 of mem2 is " << mem1.pa2 << endl; // Empty
	cout << "The pa2 of mem2 is " << mem2.pa2 << endl;
	cout << "The pluss of myaddi is " << myaddi.pluss << endl;


	return 0;
}
```

- A variable type: `struct name {variable1; variable2 } `
- Define with `;` between variables, create with `,`
- Use `name.variable1` to take the value;
- Multi-types, globly and locally sensible, `;` required
- Directly assign specific variable of a structure is allowed
- Create a struct variable after definition: `struct name{} var1,var2;`
- Array of structure
- Bit fields creation:
    - Declare by `type : bits`;
    - **Unnamed fields** as spacing;
    - Limit the bits for specific hardware properties;
    - Field type should be *integral* or *enumeration* type;


```Console
Enter a name for myarray[5]: Justice Cosmos
The name of myarray[5] is: Justice Cosmos
The name of mytest[0] is: Mteltn
The height of mytest[0] is: 178.2 in cm
My name is Guernica
I am 23 years old
I am 175.6 in cm
Jinshin is my friend
He is 173.1 in cm
Together will be 348.7 in cm
Same as 348.7 in cm
The pa1 of mem1 is Actor
The pa1 of mem2 is 
The pa2 of mem2 is Dresser
The pluss of myaddi is 7
```

## Union
Source code
```C++

```

- 1
- 2

```Console

```
