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
