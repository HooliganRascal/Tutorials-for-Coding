#include<iostream>

using namespace std;

// Some necessary constant
const int sizear = 8;
const int coef = 10;

// Function prototypes
int sumar(const int*, int); 
void timesar(int*, int); 
void artimes(int* begin, int* end);
void showar(const int*, int);

// Main function
int main(void){

	int name[sizear] = {1,2,3,4,5,6,7,8};
	int sum1, sum2;
	
	const int* pt = name; // Invariant, but can point to others
	int* const tp = name+3; // Variant, but can only point to one
	const int* const ptp = name+3; // Invariant and can only point to one

	// Show the size of the full array
	cout << "Array: ";
	for(int i=0; i<sizear; ++i){
		cout << name[i] << " ";
	}
	cout << "\nAddress " << name << " with size of " << sizeof(name) << endl;

	// Show the size of the pointer
	showar(name, sizear);

	// Operate with array in function
	sum1 = sumar(name, 3); // Sum of first 3 elements
	sum2 = sumar(name+4, 4); // Sum of last 4 elements
	
	cout << endl;
	cout << "The sum of first 3 elements of array is " << sum1 << endl;
	cout << "The sum of last 4 elements of array is " << sum2 << endl;
	cout << endl;

	timesar(name, 3); // Modify for first 3 elements;
	artimes(name+4, name+sizear); // Modify for last 4 elements;
	showar(name, sizear);
	cout << endl;
	
	// Do something with pointer and const
	cout << "const int* is " << *pt << " before" << endl;
	cout << "const int* is " << *(pt = name+3) << " now" << endl;
	cout << "int* const is " << *tp << " before" << endl;
	*tp+=1;
	cout << "int* const is " << *(name+3) << " now" << endl;
	cout << "const int* const is " << *ptp << " forever" << endl;
	
	return 0;
}

// Not modifiable
int sumar(const int* ar, int limit){
	int sum = 0;
	for(int i=0; i<limit; ++i){
		sum += ar[i];
	}
	return sum;
}

// Modifiable
void timesar(int* ar, int limit){
	for(int i=0; i<limit; ++i){
		*(ar+i) *= coef;
	}
}

// Modify by range
void artimes(int* begin, int* end){
	for(int i=0; i<(end-begin); ++i){ // Index suits the rule
		*(begin+i) *= coef;
	}
}

// Show the array and its content
void showar(const int* ar, int limit){
	cout << "Array: ";
	for(int i=0; i<limit; ++i){
		cout << ar[i] << " ";
	}
	cout << "\nAddress " << ar << " with size of " <<  sizeof(ar) << endl;
}
