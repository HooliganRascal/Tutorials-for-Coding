#include<iostream>

using namespace std;

struct debts{
	char name[50];
	double amount;
};

template<class T>void Shar(T* arr, int n);
template<class T>void Shar(T** arr, int n); // Exact match
template<class T>inline T Less(T a, T b); // Inline template
inline int Less(int a, int b);

int main(void){

	int m=20, n=-30;
	double x=15.5, y=25.9;
	int ar[6] = {13,31,103,310,130};
	debts deb[3] = {
		{"Mteltn Guernica", 2400.6},
		{"Guernica Cosmos", 1020.9},
		{"Mteltn Cosmoses", 2691.1}
	};
	double* pd[3];
	for(int i=0; i<3; ++i){
		pd[i] = &(deb+i)->amount;
	}

	cout << "deb things ";
	Shar(ar, 6); // Exact match template A
	cout << "pds things ";
	Shar(pd, 3); // Exact match template B
	cout << "Absolute lesser is " << Less(m,n) << endl; // Match regular
	cout << "Lesser is " << Less(x,y) << endl; // Match template
	cout << "Lesser is " << Less<>(m,n) << endl; // Match explicit
	cout << "Lesser is " << Less<int>(x,y) << endl; // Match explicit int

	return 0;
}

template<class T>void Shar(T* arr, int n){
	cout << "template A: " << endl;
	for(int i=0; i<n; ++i){
		cout << *(arr+i) << ' ';
	}
	cout << endl;
}

template<class T>void Shar(T** arr, int n){
	cout << "template B: " << endl;
	for(int i=0; i<n; ++i){
		cout << **(arr+i) << ' ';
	}
	cout << endl;
}

template<class T>inline T Less(T a, T b){
	return a<b?a:b;
}

inline int Less(int a, int b){
	a = a<0?-a:a;
	b = b<0?-b:b;
	return a<b?a:b; // Return lesser absolute value
}
