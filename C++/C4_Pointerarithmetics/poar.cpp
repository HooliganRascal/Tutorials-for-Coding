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
