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

Source code:
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

Source code:
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

### Char type
> It's usually used to store letters, digits, punctuations and other characters, also for small integers with `1 byte`, and remember, for char integer, **what you see is not what you get**

Source code
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

	return 0;
}
```
- `char` displays characters : `...'#'...'0''1''2'...'a''b''c'...` with a single byte (8 bits)
- `char` is **signed** by default, stores the characters with **ASCII code** from `-128~127`
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
```

- operating for `char` is operating with the **ASCII code**
    - output `ch_num+1` will force the `char` variable to be an **ASCII** integer
    - output `ch_num+1` after assigned to `int` leads to an **ASCII** integer
    - output `ch_num+1` after assigned to `char` leads to `char` originally
    - output `++ch_num` will remain the `char` variable but successor eternally
- transfer between **ASCII** code and `char`:
    - use `static_cast<char>()` to force an integer to be **ASCII** code for `char` and output `char`
    - use `(int)` or `int()` to force a `char` variable to be **ASCII** code and output `int`

