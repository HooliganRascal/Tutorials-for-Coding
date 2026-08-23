# Dealing with Data

---

## Integer Types

> *width*: describe the amount of memory used for an integer

> different types: char(not included), short, int, long, long long (signed for default or unsigned)

> bit and byte: 
>    - **on or off** for 1 bit
>    - 16-bit data can store $2^{16} = 65536$ data
>    - **C++ byte**: 8 bits for a byte (others can be 16-bit byte or else)
>    - 1024 bytes for a kilobyte

Source code: `C3_Datatype`
```C++
#include <iostream>
#include <climits>

using namespace std;

int main(void){

	short n_short = SHRT_MAX;
	int n_int = INT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	unsigned long long n_ullong = ULLONG_MAX;

	// Output size
	cout << "Bits per byte for C++ is " << CHAR_BIT << endl;
	cout << "The byte size of short is " << sizeof(short) << endl;
	cout << "The byte size of int is " << sizeof(int) << endl;
	cout << "The byte size of long is " << sizeof(long) << endl;
	cout << "The byte size of long long is " << sizeof(long long) << endl;
	cout << endl;

	// Output max
	cout << "The max num of short is " << n_short << endl;
	cout << "The max num of int is " << n_int << endl;
	cout << "The max num of long is " << n_long << endl;
	cout << "The max num of long long is " << n_llong << endl;
	cout << "The max num of unsigned long long is " << n_ullong << endl;
	cout << "The min num of long long is " << LLONG_MIN << endl;

	return 0;
}
``` 
- `sizeof` function shows 
    - the size of data type `sizeof(type-name)`
    - or the type of the data whatever its value is `sizeof(variable-name)`
- no minimum for `unsigned` types of data
- `CHAR_BIT` and other uppercased keywords are from `climits`
- add `1` to the limit of `short`: `32767` + `1` = `-32768`

## Integer Literals

> - first and second digit of base 8: `01~07`
> - first digit of base 10: `1~9`
> - first and second digit of base 16: `0x` or `0X`

Source code: `C3_Dataliter`
```C++
#include <iostream>

int main(void){

	using namespace std;

	int octa = 042;
	int deci = 42;
	int hexa = 0x42;

	// default output type of integer is decimal
	cout << "Base 10 of octa is " << octa << "(042 in octal)" << endl;
	cout << "Base 10 of deci is " << deci << "(42 in decimal)" << endl;
	cout << "Base 10 of hexa is " << hexa << "(0x42 in hexadecimal)" << endl;

	// manipulator for changing number base 16
	cout << hex;
	cout << "Base 16 of deci is " << deci << "(42 in decimal)" << endl;
	cout << "Base 16 of octa is " << octa << "(042 in octal)" << endl;

	return 0;
}

```

- default constant type of C++ is `decimal`, changeable
- declare the data type with **first and second** digits
- output will save the first and second digits for specifi types

## Char type
> It's usually used to store letters, digits, punctuations and other characters, also for small integers with `1 byte`, and remember, for char integer, **what you see is not what you get**

Source code: `C3_Datachar`
```C++
#include <iostream>

int main(void){
	
	using namespace std;

	// assign the character
	char ch_1 = '1' ;
	char ch_A = 'A';
	char ch_a = 'a';

	// assign the ASCII code
	char ch_num = 55;
	char ch_nums = ch_num + 1;
	int num = ch_num + 1;

	// output original characters
	cout << "'1' in char is " << ch_1 << endl;
	cout << "'A' in char is " << ch_A << endl;
	cout << "'a' in char is " << ch_a << endl;
	cout << "ch_num in char by initialization is " << ch_num << endl;

	// operate with char
	cout << "ch_num in ASCII initialized is " << int(ch_num) << endl;
	cout << "ch_num +1 in ASCII asigned to int is " << num << endl;
	cout << "ch_num +1 in ASCII added to output is " << ch_num + 1 << endl;
	cout << "ch_nums in char added, assigned to char is " << ch_nums << endl;
	cout << "++ch_num in char by successor is " << ++ch_num << endl;
	cout << "After that, ch_num is eternally " << ch_num << endl; 

	// transfer between char and ASCII code
	cout << "number 65 in char is " << static_cast<char>(65) << endl;
	cout << "character 'a' in ASCII is " << (int)'a' << endl;

	// output with member function
	cout << "'a' outputs with cout << 'a' is ";
	cout << 'a' << endl;;
	cout << "'a' outputs with cout << ch_a is " << ch_a << endl;;
	cout << "'a' outputs with cout.put('a') is ";
	cout.put('a');
	cout << endl;
	cout << "'a' outputs with cout.put(ch_a) is ";
	cout.put(ch_a);
	cout << endl;

	return 0;
}
```
- `char` displays characters : `...'#'...'0''1''2'...'a''b''c'...` with a single byte (8 bits)
- `char` can be **signed** or **unsigned**, stores the characters with **ASCII code** from `-128~127`
---
Outputs:
```console
'1' in char is 1
'A' in char is A
'a' in char is a
ch_num in char by initialization is 7
ch_num in ASCII initialized is 55
ch_num +1 in ASCII asigned to int is 56
ch_num +1 in ASCII added to output is 56
ch_nums in char added, assigned to char is 8
++ch_num in char by successor is 8
After that, ch_num is eternally 8
number 65 in char is A
character 'a' in ASCII is 97
'a' outputs with cout << 'a' is a
'a' outputs with cout << ch_a is a
'a' outputs with cout.put('a') is a
'a' outputs with cout.put(ch_a) is a
```
- operating for `char` is operating with the **ASCII code**
    - output `ch_num+1` will force the `char` variable to be an **ASCII** integer
    - output `ch_num+1` after assigned to `int` leads to an **ASCII** integer
    - output `ch_num+1` after assigned to `char` leads to `char` originally
    - output `++ch_num` will remain the `char` variable but successor eternally
- transfer between **ASCII** code and `char`:
    - use `static_cast<char>()` to force an integer to be **ASCII** code for `char` and output `char`
    - use `(int)` or `int()` to force a `char` variable to be **ASCII** code and output `int`
- output with `cout << 'a'` and `cout.put('a')` hold the same result now
    - `cout.put()` is a *member function* with the *object* `cout` belonging to the *class* `ostream` 

## Char literals

Source code: `C3_Charslashliter`
```C++
#include <iostream>

int main(void){

	using namespace std;
	
	long code;

	cout << "\aEnter a 8-bit code : ________\b\b\b\b\b\b\b\b";
	cin >> code;
	cout << "\aYou entered " << code << endl;
	
	return 0;
}
```
> `\b` provides backspace

```console
Enter a 8-bit code : 12345678
You entered 12345678

Enter a 8-bit code : 12345___
You entered 12345
```

## Other character names
Source code: `C3_Otherchar`
```C++
#include<iostream>

int main(void){

	using namespace std;

	// universal character name
	char k\u00F6rper = 'a';
	cout << "Output g\u00E2teau and " << k\u00F6rper << endl;

	// wchar_t for wide character set
	wchar_t bob = L'P';
	cout << "cout of L is " << L"tall" << " and " << bob << endl;
	wcout << "wcout of L is " << L"tall" << " and " << bob << endl;

	// char16_t and char32_t
	char16_t ch1 = u'q';
	char32_t ch2 = U'\U0000222B';
	cout << "1 cout or wcout cutoff of U is " << ch1 << endl;
	cout << "2 cout or wcout cutoff of U is " << ch2 << endl;
	wcout << "1 cout.put cutoff of U is "; 
	cout.put(ch1) ; 
	cout << endl;
	wcout << "2 cout.put cutoff of U is "; 
	cout.put(ch2) ; 
	cout << endl;

	return 0;
}
```
- Universal character name:
    - Designed for international letters, `\U` for 16 hex digits, `\u` for 8 hex digits
    - These digits represent the `ISO 10646` code point for the characters
    - Universal character names can be used for identifiers, strings and else
- when using `wchar_t`: 
    - same size and sign properties as *underlying* type, which could be `unsigned short` or `int`
    - parallel facilities: `wcin` and `wcout`
    - `L"string"` or `L'P'` (double for string, single for character)
    - `cout` the `L'P'` will be `ASCII` code, and `L"string"` will be hex
- when using `char16_t` and `char32_t` : 
    - `u'q'` for 16-bit and `U'\U0000222B` for 32-bit and `universal char`
    - also have their each *underlying type*
    - `cout` and `wcout` outputs their **cutoff** `ISO 10646` code or **ASCII** code
    - `cout.put` outputs their **cutoff** `char`

```console
Output gâteau and a
cout of L is 0x640736cd9028 and 80
wcout of L is tall and P
1 cout or wcout of U is 113
2 cout or wcout of U is 8747
1 cout.put of U is q
2 cout.put of U is +
```

## Bool and constant
Source code: `C3_Boolconst`
```C++
#include<iostream>

int main(void){

	using namespace std;

	//assign bool to int
	int prom = true; 
	int answ = false; 
					  
	// assign to bool
	bool start_1 = -1000;
	bool start_2 = true;
	bool stop_1 = 0;
	bool stop_2 = false;

	// initialize symbolic constant
	const int money = 50;
	
	// output 1 or 0
	cout << "Promise is " << prom <<  " and " << true << endl;
	cout << "Answer is " << answ << " and " << false << endl;
	cout << "Start is " << start_1 << " and " << start_2 << endl;
	cout << "Stop is " << stop_1 << " and " << stop_2 << endl;

	// output the constant
	cout << "Crazy Thursday, v me " << money << " RMB " << endl; 

	return 0;
}
```
- `true` assigned is `1`, `false` assigned is `0`
    - *non-zero* number assigned to `bool` is `true`, outputs `1`
    - *zero* number assigned to `bool` is `false`, outputs `0`
- `const` initialzed **immediately** after **defined**

```console
Promise is 1 and 1
Answer is 0 and 0
Start is 1 and 1
Stop is 0 and 0
Crazy Thursday, v me 50 RMB
```

## Floating number and operations
Source code: `C3_Floatoperate`
```C++
#include<iostream>

int main(void){

	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point

	// integers for operating
	int m = 19;
	int n = 6;

	// float types
	float a = 10.0/3.0;
	double b = 10.0/3.0; // default type
	long double c = 10.0/3.0;

	// exponent guarantees the floating-point
	const float dmil = +2.0e+06f;
	const double obil = 1e9;
	const long double neli = -8e-2L;

	// significant digits and precision varies
	cout << a*1e6 << endl;
	cout << b*1e6 << endl;
	cout << c*1e6 << endl;

	// operation
	cout << dmil << " + " << m << " = " << dmil + m << endl;
	cout << obil << " * " << n << " = " << obil * n << endl;
	cout << neli << " / " << n << " = " << neli / n << endl;
	cout << m << " / " << n << " = " << m / n << endl; // whole
	cout << m << " % " << n << " = " << m % n << endl; // remain

	return 0;
}
```

- exponent expression guarantees the type is `floating-point` and `double` by default
- `cout.setf()` function displays the floating-point number from exponent to total
- Floating type:
    - default type: `double`
    - `f` or `F` at the end for `float`
    - `l` or `L`, preferred `L` at the end for `long double`
- Operation:
    - `int` operates with `int` will be int, otherwise *floating-point*
    - `%` for modulus operation, only works with `int` series types
    - **better operate with same type!**

```console
3333333.253860
3333333.333333
3333333.333333
2000000.000000 + 19 = 2000019.000000
1000000000.000000 * 6 = 6000000000.000000
-0.080000 / 6 = -0.013333
19 / 6 = 3
19 % 6 = 1
```

## Type conversion

Source code: `C3_Typeconversion`
```C++
#include<iostream>

int main(void){

	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);

	// conversion on initialization
	float tree = 3; 
	int guess = 35.9832;

	// list initialization conversions with {}
	const int code = 77;
	char c1 = {77};
	char c2 = {code};
	char c3 = guess; // narrow to and integer and assigned
	
	// type cast
	double dguess = (double)guess;
	double guessd = double(guess);

	// declare by auto
	auto test = 1e3;

	cout << "Integer 3 converted into float is " << tree << endl;
	cout << "Float 35.9832 converted into int guess is " << guess << endl;
	cout << "Constant integer code in int is " << code << endl;
	cout << "character c1 initialized by number 77 is " << c1 << endl;
	cout << "character c2 initialized by constant code is " << c2 << endl;
	cout << "character c3 initialized by assinged guess is " << c3 << endl;
	cout << "double dguess initialized by casted guess is " << dguess << endl;
	cout << "double guessd initialized by guess casted is " << guessd << endl;
	cout << "auto for 1e3 is type double with value: " << test << endl;

	return 0;
}
```

- C++ is liberal of converting `int` to `float`, `double` to `int` or else
    - assign `int` to `char` is seen **ASCII** code and stores a character
    - assign `char` to `int` stores **ASCII** code
- using *list initialization* `{}` does not permit narrowing
    - `int` to other integer types or `float` is allowed
    - `float` to `int` is not allowed
    - only `const` or other constant is allowed
- type casting by `(type)variable` or `type(variable)` such as `double(guess)`
- declare the type by `auto` is refined

```console
Integer 3 converted into float is 3.000000
Float 35.9832 converted into int guess is 35
Constant integer code in int is 77
character c1 initialized by number 77 is M
character c2 initialized by constant code is M
character c3 initialized by assinged guess is #
double dguess initialized by casted guess is 35.000000
double guessd initialized by guess casted is 35.000000
auto for 1e3 is type double with value: 1000.000000
```
