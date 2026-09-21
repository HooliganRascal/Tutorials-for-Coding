#include<iostream>

using namespace std;

// Prototype
const double* f1(const double ar[], int n);
const double* f2(const double [], int);
const double* f3(const double*, int);

int main(void){

	double av[3] = {1112.3, 1542.6, 2227.9};
	const double* (*p1)(const double*, int) = f1; // pointer to a function
	auto p2 = f2; // auto works the same as form of p1
	
	// use the pointer to a function
	cout << "Using the p to f:" << endl;
	cout << " Address  Value" << endl;
	cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
	cout << p2(av,3) << ": " << *p2(av,3) << endl;

	const double* (*pa[3])(const double*, int) = {f1,f2,f3};
	auto pb = pa; // pointer to the first element
	auto pc = &pa; // pointer to the array of pointers to functions
	const double* (*(*pd)[3])(const double*, int) = &pa;
	
	// use the array of pointers to functions
	cout << endl << "Using the array of pointers to functions:" << endl;
	cout << " Address  Value" << endl;
	for(int i=0; i<3; ++i){
		cout << pa[i](av,3) << ": " << *pa[i](av,3) << endl;
	}

	// use the pointer to a pointer to a function
	cout << endl << "Using the pointer to a pointer to a function:" << endl;
	cout << " Address  Value" << endl;
	for(int i=0; i<3; ++i){
		cout << (*(pb+i))(av,3) << ": " << *(*(pb+i))(av,3) << endl;
	}

	// use the pointer to an array of pointers tp functions
	cout << endl 
		 << "Using the pointer to an array of pointers tp functions:" << endl;
	cout << " Address  Value" << endl;
	cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
	cout << (*(*pd)[1])(av,3) << ": " << *(*(*pd)[1])(av,3) << endl;
	// more conveniently
	const double* pdb = (*pd)[2](av,3);
	cout << pdb << ": " << *pdb << endl;

	return 0;
}

// Definition
const double* f1(const double ar[], int n){
	return ar;
}
const double* f2(const double ar[], int n){
	return ar+1;
}
const double* f3(const double* ar, int n){
	return ar+2;
}
