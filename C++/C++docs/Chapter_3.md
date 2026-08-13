# Dealing with Data

---

## Integer Types

> *width*: describe the amount of memory used for an integer

> different types: char(not included), short, int, long, long long (signed for default or unsigned)

> bit and byte: 
>    - **on or off** for 1 bit
>    - 16-bit data can store $2^8 = 65536$ data
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

	char ch_1 = '1' ;
	char ch_A = 'A';
	char ch_a = 'a';
	char ch_free;

	// ASCII code
	int i = ch_1;

	// output original characters
	cout << "'1' in char is " << ch_1 << endl;
	cout << "'A' in char is " << ch_A << endl;
	cout << "'a' in char is " << ch_a << endl;
	cout << "number 65 in char is " << static_cast<char>(65) << endl;

	// output ASCII code
	cout << "Enter a character : ";
	cin >> ch_free;
	cout << ch_free << " in char is " << ch_free << endl;
	cout << ch_free << " in ASCII is " << (int)ch_free << endl;
	cout << ch_1 << " in ASCII is " << i << endl;

	return 0;
}
```
- `char` displays characters : `'#'...'0''1''2'...'a''b''c'...` with a single byte (8 bits)
- `char` stores the characters with **ASCII code** from `1~128`

