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
