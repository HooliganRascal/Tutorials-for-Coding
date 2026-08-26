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
Source code: `C4_Stringclass`
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
Source code: `C4_Structure`
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

## Union and enumerations
Source code: `C4_UnionEnumerations`
```C++
#include<iostream>

using namespace std;

// Union
union ofa{
	int int1;
	int int2;
	long long1;
	double double1;
};

// Anonymous union
struct stu{
	int type;
	union {
		long id_long;
		long id_long2;
		double id_double;
	};
};

// Enumeration
enum spec{red, orange, yellow, green, blue, purple, violet};
enum {a, b, c, d, e, f, g};
enum bits{one=1, two=2, three=3, four=4, five=5, six=6, seven=7};
enum succ{zero, thous=1000, thousnext}; // thousnext=1001
enum repe{null, nullz=0, onext, nexto=1}; // Same value for different variable

int main(void){
	
	ofa testofa; // Union
	stu teststu; // Anonymous union in structure
	spec color = orange; // Enumeration
	spec testcol = spec(3); // Number from 0 to 7
	int testicol = spec(2); // Assigned to integers
	int testjcol = d; // Enumeration name omitted
	int testbit = one; // Reorder the number
	succ testsuc = succ(1023); // Assign with values in the range power of 2


	// Union: Forget original int1 == int2, messed up
	testofa.int1 = 2;
	testofa.int2 = 4;
	testofa.double1 = 6.2;
	cout << testofa.int1 << endl;
	cout << testofa.int2 << endl;
	cout << testofa.double1 << endl;

	// Anonymous Union: Forget original id_long == id_long2, messed up
	teststu.id_long = 5;
	teststu.id_long2 = 10;
	teststu.id_double = 6.1;
	cout << teststu.id_long << endl;
	cout << teststu.id_long2 << endl;
	cout << teststu.id_double << endl;

	// Output enumerations
	cout << yellow << endl;
	cout << color << endl;
	cout << testcol << endl;
	cout << testicol << endl;
	cout << testjcol << endl;
	cout << testbit << endl;
	cout << "zero is " << zero 
		 << " and thous is " << thous 
		 << ", thousnext is " << thousnext << endl;
	cout << "Repeat null = " << null << " and nullz = " << nullz << endl;
	cout << "Enumeration in the range like " << testsuc << endl;

	return 0;
}
```

- Union:
    - Hold different data types but one type at a time
    - If we define `int int1; int int2`, assigned for `int1` then `int2`, the latter value of `int2` will replace that of `int1`
    - Anonymous union without name, the member of which share the *same address*, and **only one member** can be current at a time
    - For (anonymous) union, If we assign `double` after `int`, the `int` is **messed up**
- Enumerations:
    - Alternative for *symbolic constant* with `const int` for *default*
    - Replacement: `enum name{a,b,c}` for `0,1,2`
    - Define with `,` instead of `;` like `struct` or `union`
    - Output integers from `0` to end, arithmetic operations not defined
    - Another assignment: `enum type{}; type name = type(0)`
    - Omitted name is allowed, `int` is allowed to be assigned
    - Values are set *successively*, same value can be assigned to different variables
    - Limits of range: 
        - Values lying the range can be assigned freely **even not defined**
        - Upper: `101`, then upper bound is `128-1=127`
        - Lower: `>=0`, then lower bound is `0`, if `-6`, then is `-8+1=-7`
    - Extension with *scoped enumeration* in [Chapter 10](Chapter_10.md)
        
```Console
-858993459
-858993459
6.2
4618554007859127910
4618554007859127910
6.1
2
1
3
2
3
1
zero is 0 and thous is 1000, thousnext is 1001
Repeat null = 0 and nullz = 0
Enumeration in the range like 1023
```

## Pointers and the free store
Source code: `C4_Pointerstore`
```C++
#include <iostream>

int main(void){

	using namespace std;

	int a = 6;
	double b = 7.1;

	// Initialization by address
	int *loc_a = &a;
	int *loc_aa = &a; // When assigned with value later, initialize it!!!
	double *loc_b = &b;
	double *loc_bb;
	
	// Assignment by address or value
	*loc_aa = a; // assigned value passes to the variable in that location!
	loc_bb = &b;

	// Output pointer and value
	cout << "a is " << a << " with location " << &a << endl;
	cout << "a is " << *loc_aa 
		 << " with location " << loc_a 
		 << " too!" << endl;
	cout << "b is " << b << " with location " << &b << endl;
	cout << "b+1 is " << *loc_bb+1  // Operation with value
		 << " with location " << loc_b 
		 << " too!" << endl;

	// Allocate new memory and delete for reuse
	int *loc_int = new int;
	int *loc_iint = loc_int;
	*loc_int = 5;
	cout << "New allocated memory with value: " << *loc_int 
		 << " location: " << loc_int 
		 << endl;
	cout << "Same as " << *loc_iint << " with location " << loc_iint << endl;
	delete loc_int; // Remove the value of the pointer, pointer to that deleted
	cout << "Memory deleted with value: " << *loc_int 
		 << " location: " << loc_int 
		 << endl;
	cout << "Same as " << *loc_iint << " with location " << loc_iint << endl;

	// Dynamic array
	int *dyar = new int [10];
	dyar[0] = 1; 
	dyar[1] = 2; 
	dyar[2] = 3; 
	cout << "dyar[0] is " << *dyar << " with location " << dyar << endl;
	cout << "dyar[1] is " << *(dyar+1) 
		 << " with location " << &(dyar[1]) << endl;
	cout << "dyar[1] is " << dyar[1] 
		 << " with location " << dyar+1 
		 << " too" << endl;
	delete [] dyar;

	// Array of pointers
	int aa = 8;
	int *loc_aaa[2] = {&a, &aa};
	cout << "Array of pointers 1st: " << loc_aaa[0][0] << endl;
	cout << "Array of pointers 2nd: " << loc_aaa[1][0] << endl;
	cout << "Array of pointers *1st: " << *loc_aaa[0] << endl;
	cout << "Array of pointers *2nd: " << *loc_aaa[1] << endl;

	return 0;
}
```

- Pointers: variables that **store address of values**, `&` to get the location
- *Compile-time* decision: declare an array, size sets when compiled
- *Run-time* decision: declare an array, but size setting delayed until runtime
- Pointers and address:
    - `int *name` defines a pointer (indirect value, or dereferencing operator)
    - `int` states the *type of the value* in that location
    - `name` as a pointer stores the location of variables
    - `*name` as the **value** at that location, can be treated as integer
    - Initialize the pointer by assigning address: `int *loc_a = &a`
    - Assign by value or address: `loc_a = &a` or `*loc_a = a`(**latter initialized required!**)
    - For pointers, you get the address allocated, and you get the value secondly
- Allocate memory with `new` like: `type *name = new type;`
- Free memory with `delete` like: `delete name` 
    - For reusing pointer allocated by `new` formerly
    - Computer stores data with memory, thus `delete` removes the value in that location, the address of the location remains
    - the pointer storing address is **stored with another pointer**!
- Dynamic array:
    - *Static binding*: array built into the program at compile time
    - *Dynamic binding*: array created during runtime and skip creation if not needed
    - With `type *name = new type[size]`, the `name` stores the **address of the first element**
    - With `type (*name)[size] = new type[size]`, the `name` points to the **whole address of the new dynamic array**
    - Treat the dynamic array as a real array name! 
        - Use `name[0]` rather than `*name` as the value of first element
        - Arithmetics like `name = name+1` increments the pointer, **not for array name!!!**
    - Free the **whole** array with `delete [] name`
- Array is infact a bunch of address, pass the address of the address to pointer, we need double `**`
- **Array name is a pointer!**

```Console
a is 6 with location 0x7fffee5f65e8
a is 6 with location 0x7fffee5f65e8 too!
b is 7.1 with location 0x7fffee5f65f0
b+1 is 8.1 with location 0x7fffee5f65f0 too!
New allocated memory with value: 5 location: 0x62eddcbe06c0
Same as 5 with location 0x62eddcbe06c0
Memory deleted with value: 786287584 location: 0x62eddcbe06c0
Same as 786287584 with location 0x62eddcbe06c0
dyar[0] is 1 with location 0x62eddcbe06e0
dyar[1] is 2 with location 0x62eddcbe06e4
dyar[1] is 2 with location 0x62eddcbe06e4 too
Array of pointers 1st: 6
Array of pointers 2nd: 8
Array of pointers *1st: 6
Array of pointers *2nd: 8
```

## Pointers, arrays, and pointer arithmetic
Source code: `C4_Pointerarithmetics`
```C++
#include <iostream>

int main(void){

	using namespace std;

	// Array and pointer
	double wage[3] = {1000.0, 2000.0, 3000.0};
	double *pw = wage;
	double *pw1 = pw+1;
	double (*pw2)[3]= &wage; // Pass location of the whole array to pointer

	// Arrays
	cout << "Addr &wage: " << &wage << ", wage: " << wage << endl;
	cout << "Addr &wage[1]: " << &wage[1] << ", wage[1]: " << wage[1] << endl;
	cout << "Addr wage+1: " << wage+1 << ", *(wage+1): " << *(wage+1) << endl;
	cout << endl;

	// Pointers
	cout << "Addr pw: " << pw << ", *pw: " << *pw << endl;
	cout << "Addr pw+1: " << pw+1 << ", *(pw+1): " << *(pw+1) << endl;
	cout << "Addr pw1: " << pw1 << ", *pw1: " << *pw1 << endl;
	cout << "Addr &pw1[1]: " << &pw1[1] << ", pw1[1]: " << pw1[1] << endl;
	cout << endl;

	// Array pointers
	cout << "Addr pw2: " << pw2 << ", *pw2: " << *pw2 << endl;
	cout << "Addr &pw2+1: " << &pw2+1 << ", pw2: " << pw2 << endl;
	cout << "Addr &pw2[0]: " << &pw2[0] << ", pw2[0]: " << pw2[0] << endl;
	cout << "Addr &(*pw2): " << &(*pw2) << ", (*pw2): " << (*pw2) << endl;
	cout << "Addr &(*pw2)[0]: " << &(*pw2)[0] 
		 << ", (*pw2)[0]: " << (*pw2)[0] << endl;
	cout << "Addr &(*pw2[0]): " << &(*pw2[0]) 
		 << ", *pw2[0]: " << *pw2[0] << endl;
	cout << "Value pw2[0][0]: "<< pw2[0][0] << ", **pw2: "<< **pw2 << endl;
	cout << endl;

	// Size of arrays, pointers
	cout << "Size of array wage: " << sizeof(wage) << endl;
	cout << "Size of value wage[0]: " << sizeof(wage[0]) << endl;
	cout << "Size of pointer pw: " << sizeof(pw) << endl;
	cout << "Size of pointer &pw[0]: " << sizeof(&pw[0]) << endl;
	cout << "Size of value *pw: " << sizeof(*pw) << endl;
	cout << endl;

	// Size of array pointers
	cout << "Size of pointer pw2: " << sizeof(pw2) << endl;
	cout << "Size of pointer *pw2: " << sizeof(*pw2) << endl;
	cout << "Size of pointer &pw2+1: " << sizeof(&pw2+1) << endl;
	cout << "Size of pointer &(*pw2): " << sizeof(&(*pw2)) << endl;
	cout << "Size of pointer &pw2[0]: " << sizeof(&pw2[0]) << endl;
	cout << "Size of pointer pw2[0]: " << sizeof(pw2[0]) << endl;
	cout << "Size of pointer &(*pw2)[0]: " << sizeof(&(*pw2)[0]) << endl;
	cout << "Size of value *pw2[0]: " << sizeof(*pw2[0]) << endl;

	return 0;
}
```

- Adding `1` to a pointer adds its value **by the number of bytes** of the type to which it points!
    - `double *name; name+1` add 8 bytes to 8-byte `double` variable
    - `short *name; name+1` add 2 bytes to 2-byte `short` variable
    - The increment `name++` **is not defined!!!**
- Pass `type *name = array` is equal to `type name = &array[0]`
- Take the location of array: `type (*name)[size] = &array` as a whole
    - And `(*name)` is the array, size 24
    - Address: `&array == array` 
    - Address: `name == *name == &name+1 == &name[0] == name[0] `
    - Address: `name == (*name) == &(*name) == &(*name)[0]`
    - Size: `array == *name == name[0]`
    - Value: `*name[0] == (*name)[0] == **name == name[0][0]`
    - If we omit the `()`, the `name` will be an *array of #size pointers to type*, it's an **array of pointer** rather than a **pointer of array**

```Console
Addr &wage: 0x7ffe9ee851d0, wage: 0x7ffe9ee851d0
Addr &wage[1]: 0x7ffe9ee851d8, wage[1]: 2000
Addr wage+1: 0x7ffe9ee851d8, *(wage+1): 2000

Addr pw: 0x7ffe9ee851d0, *pw: 1000
Addr pw+1: 0x7ffe9ee851d8, *(pw+1): 2000
Addr pw1: 0x7ffe9ee851d8, *pw1: 2000
Addr &pw1[1]: 0x7ffe9ee851e0, pw1[1]: 3000

Addr pw2: 0x7ffe9ee851d0, *pw2: 0x7ffe9ee851d0
Addr &pw2+1: 0x7ffe9ee851c0, pw2: 0x7ffe9ee851d0
Addr &pw2[0]: 0x7ffe9ee851d0, pw2[0]: 0x7ffe9ee851d0
Addr &(*pw2): 0x7ffe9ee851d0, (*pw2): 0x7ffe9ee851d0
Addr &(*pw2)[0]: 0x7ffe9ee851d0, (*pw2)[0]: 1000
Addr &(*pw2[0]): 0x7ffe9ee851d0, *pw2[0]: 1000
Value pw2[0][0]: 1000, **pw2: 1000

Size of array wage: 24
Size of value wage[0]: 8
Size of pointer pw: 8
Size of pointer &pw[0]: 8
Size of value *pw: 8

Size of pointer pw2: 8
Size of pointer *pw2: 24
Size of pointer &pw2+1: 8
Size of pointer &(*pw2): 8
Size of pointer &pw2[0]: 8
Size of pointer pw2[0]: 24
Size of pointer &(*pw2)[0]: 8
Size of value *pw2[0]: 8
```

## Pointers and strings
Source code: `C4_Pointerstrings`
```C++
#include <iostream>
#include <cstring>

int main(void){

	using namespace std;

	char name[20] = "Mteltn";
	const char *call = "Guernica";
	char *back;
	string test;

	cout << name << " and " << call << endl;

	// Address passed to cin and cout
	cout << "Input a name to name: ";
	cin >> name;
	back = name; // Address passed
	
	// Use assignment
	back = new char[strlen(name)+1]; // Allocate new memory
	back = name; // Address passed again
	cout << "Before using new to create dynamic string: " << endl;
	cout << name << " at: " << (int*) name << endl;
	cout << back << " at: " << (int*) back << endl;

	// Use strcpy()
	back = new char[strlen(name)+1]; // Allocate new memory
	strcpy(back, name);
	cout << "After using new: " << endl;
	cout << name << " at: " << (int*) name << endl;
	cout << back << " at: " << (int*) back << endl;
	delete [] back;

	// Use string class, the simplest way!
	test = name;
	cout << "Using string class: " << endl;
	cout << name << " at: " << (int*) name << endl;
	cout << test << " at: " << &test << endl;

	return 0;
}
```

- `cout` can obtain the address of a character, print till the first `\0`
- Using `new` will allocate new memory and **new location** to pointer!
- Assign string to `char` pointer **when initialized** with `const` like: `const char *name = "xxx"`
- `char` array needn't the `const`
- For seeing addresses of the string or pointer pointed to that:
    - **Type cast** it 
    - Like `char *name = char stri[20] = "SSS"`
    - Prints the contents: `stri` and `name`
    - Prints the location: `(int *)stri` and `(int *)name`
- Assignment of string to `char` pointer copies the **address**!
- Copy of string with different address: use `new` and `strcpy()`, **directly assignment will change the address** newly allocated
- For directly assigning strings, use `string` class instead, it's the **simplest way!**
- While `strcpy()` could cause problem, `strncpy(A,B,num); A[num-1] = '\0'` can avoid the crash 

```Console
Mteltn and Guernica
Input a name to name: Cosmos
Before using new to create dynamic string: 
Cosmos at: 0x7ffefc716e40
Cosmos at: 0x7ffefc716e40
After using new: 
Cosmos at: 0x7ffefc716e40
Cosmos at: 0x5f66c459daf0
Using string class: 
Cosmos at: 0x7ffefc716e40
Cosmos at: 0x7ffefc716e20
```

## Pointers and dynamic structure
Source code: `C4_Pointerstructure`
```C++
#include<iostream>
#include<cstring>

using namespace std;

struct info{
	string name;
	char loca[20];
	int age;
	double height;
};

int main(void){
	
	info *myself; // Create pointer of structure
	info *others = new info; // Create dynamic structure
	info wuhao = {"Wu Hao", "Chaozhou", 22, 175.0};

	// Output pointer structure
	myself = &wuhao;
	cout << "Myself from wuhao is named: " << myself->name << endl;
	cout << "Myself from wuhao is located: " << (*myself).loca << endl;
	cout << "Address is " << myself << endl;

	// Output for dynamic structure
	cout << "Enter a name: ";
	getline(cin, others->name); // Input string class
	cout << "Enter a location: ";
	cin.getline((*others).loca, 20); // Input char array string
	cout << "Others is named: " << (*others).name << endl; // Dot
	cout << "Others is located: " << others->loca << endl; // Arrow
	cout << "Address is : " << others << endl;

	delete others;

	return 0;
}
```

- Create *dynamic structure* with *structure pointer* and `new`
- Use `->` to access the members, or parentheses quoted `.`:
    - Arrow: `structure *name = new structure`, and `name->member`
    - Dot: `structure *name = new structure`, and `(*name).member`

``` Console
Myself from wuhao is named: Wu Hao
Myself from wuhao is located: Chaozhou
Address is 0x7ffed768cdf0
Enter a name: Cosmos Guernica
Enter a location: Shaanxi Xi'an
Others is named: Cosmos Guernica
Others is located: Shaanxi Xi'an
Address is : 0x63e3075382b0
```

## Pointer function
Source code: `C4_Pointerfunction`
```C++
#include<iostream>
#include<cstring>

using namespace std;

// Pointer function
char *namepoint(void);
int *addition(int *a, int *b);

int main(void){

	char *name;
	int a,b;
	int *aplusb;

	name = namepoint();
	cout << "The name is " << name << " at " << (int*)name << endl;
	delete [] name; // Free memory passed by function

	// Reuse
	name = namepoint();
	cout << "The name is " << name << " at " << (int*)name << endl;
	delete [] name;

	// Pointer argument and return pointer
	a = 1; 
	b = 2;
	aplusb = addition(&a, &b);
	cout << a << " plus " << b << " by pointer is " << *aplusb << endl;
	delete aplusb;

	return 0;
}

char *namepoint(void){
	char temp[80];
	char *np;
	cout << "Enter last name: ";
	cin.getline(temp, 80);
	np = new char[strlen(temp)+1];
	strcpy(np, temp);
	strcpy(np, temp); // With '\0' at the end, while strncpy is not!
	return np;
}

int *addition(int *a, int *b){
	int *apb = new int;
	*apb = *a+*b;
	return apb;
}
```
> Use `new` and `delete` and *pointer function* to program and to save memory!
> Doesn't guarantee the newly allocated address is the previous one!
> Not a good idea to separate `new` and `delete` into different functons, but it works, just in case you forget the `delete`
> More of how C++ handles memory, see [Chapter 9](Chapter_9.md)

Storage:
- Automatic: 
    - Variables defined inside a function
    - Exist when the function is invoked, expire when the function terminates
    - Local to the block enclosed between braces(like function)
    - Stored on a *stack*: added consecutively and freed in reverse order, **LIFO** 
- Static:
    - Exists throughout the execution of an entire program
    - Defined externally, or use: `static type name = value`
- Dynamic(Free store, Heap):
    - Use `new` and `delete`
    - Existence not tied arbitrarily to the life of the program or function
    - Interplay between `new` and `delete` can **leave holes in the free store**, difficult to keep track of where to allocate new memory
    - Use `new` without `delete` will cause the variable or construct allocated by `new` to continue to persist, no way to access it.
    - Eventurally, it leads to *memory leak*, unusable, allocated but can't be deallocated, can use upall the memory available
- Thread: see [Chapter 9](Chapter_9.md)

```Console
Enter last name: Cosmos
The name is Cosmos at 0x621e71e45ad0
Enter last name: Guernica
The name is Guernica at 0x621e71e45ad0
1 plus 2 by pointer is 3
```

## Combination of types
Source code: `C4_Combinationtypes`
```C++
#include<iostream>
#include<cstring>

using namespace std;

struct info{
	char name[20];
	int age;
};

int main(void){

	info s01, s02, s03;
	info *s123[3] = {&s01, &s02, &s03}; // Pointer to pointer
	info *pa = &s01;
	auto pb = s123;

	// Different ways to assign values to the variable of pointer of pointer 
	(*pa).age = 20;
	s123[1][0].age = 25;
	(*(pb+2))->age = 30;
	strcpy(pa->name, "Cosmos");
	strcpy((*(s123+1)[0]).name, "Mteltn");
	strcpy(pb[2]->name, "Guernica");

	cout << "Name: " << s01.name << ", age: " << s01.age << endl;
	cout << "Name: " << (*pa).name << ", age: " << pa->age << endl;
	cout << "Name: " << (*(pb+1))->name << ", age: " << (**(pb+1)).age << endl;
	cout << "Name: " << (*(pb+2)[0]).name << ", age: " << pb[2][0].age << endl;
	
	return 0;
}
```
- Structure, array, pointer, structure pointer, array pointer...
- `type *name[size] = {&a1, &a2, &a3}`, use `type **name2 = name` 
- We could forget the `**`, so use `auto` instead
- For *structure pointer*, use `->` can save a `*` when take the value

```Console
Name: Cosmos, age: 20
Name: Cosmos, age: 20
Name: Mteltn, age: 25
Name: Guernica, age: 30
```

## Array Alternatives
Source code: `C4_ArrayAlternative`
```C++
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(void){

	int i;
	int arsize = 4;

	double ar1[4] = {4.2, 2.1, 6.3, 2.4};

	// vector
	vector<double> ar2(arsize);
	for(i=0; i<4; i++){
		ar2[i] = (double)i/3.0;
	};
	
	// array
	array<double, 4> ar3 = {5.6, 2.3, 7.1, 8.9};
	array<double, 4> ar4 = ar3; // assign directly

	// unsafe behavior, but now C++ can protect it automatically
	ar1[-2] = 0.5;
	// ar3.at(-1) = 0.02; // check invalid index
	//ar4[200] = 11.23;

	cout << "ar1[1] = " << ar1[1] << " at " << ar1+1 << endl;
	cout << "ar1[2] = " << *(ar1+3) << " at " << (double*)ar1+3 << endl;
	cout << "ar2[2] = " << ar2.at(2) << " at " << &ar2[2] << endl;
	cout << "ar3[2] = " << ar3[2] << " at " << &ar3[2] << endl;
	cout << "ar4[2] = " << ar4[2] << " at " << &ar4[2] << endl;

	// unsafe output 
	cout << "ar1[-2] = " << ar1[-2] << " at " << &ar1[-2] << endl;
	cout << "ar3[-1] = " << ar1[-1] << " at " << &ar3[-1] << endl;
	cout << "ar3[2] = " << ar3[2] << " at " << &ar3[2] << endl;
	cout << "ar4[2] = " << ar4[2] << " at " << &ar4[2] << endl;

	return 0;
}
```

- `vector` template class
    - Alternative to using `new` to create dynamic array
    - Use `new` and `delete` automatically
    - Include `vector` header file, declare `std`
    - Definition: `vector<type> name` for zero-size, `vector<type> name(size)` for `size` types array
    - `size` can be an **integer constant** or **integer variable**
    - `name` is an object of type `vector<type>` 
- `array` template class
    - For a fixed-size array, `array` is part of the `std` namespace
    - Use *stack* or else *static memory allocation* rather than free store
    - Include `array` header file
    - Format: `array<type, size> name`, where `size` can't be a variable
    - Much safer
- Nowadays C++ can protect it automatically, but for safer, use **member function `name.at(loc)`** like `ar2.at(2)` for `vector` and `array` templates, so that they will **warn us when the index is out of range**

```Console
ar1[1] = 2.1 at 0x7ffdbbd4b038
ar1[2] = 2.4 at 0x7ffdbbd4b048
ar2[2] = 0.666667 at 0x55c3bf9fb2c0
ar3[2] = 7.1 at 0x7ffdbbd4b060
ar4[2] = 7.1 at 0x7ffdbbd4b080
ar1[-2] = 0.5 at 0x7ffdbbd4b020
ar3[-1] = 6.54264e-310 at 0x7ffdbbd4b048
ar3[2] = 7.1 at 0x7ffdbbd4b060
ar4[2] = 7.1 at 0x7ffdbbd4b080
```
