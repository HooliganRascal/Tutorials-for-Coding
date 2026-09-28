#include<iostream>

using namespace std;

const int arsize = 8;

template<typename T>void SWAP(T& a, T& b);
template<typename T>void SWAP(T* a, T* b, int n); // Overloaded function
template<typename T>void SHOW(T* a, int n);

int main(void){

	int i=10;
	int j=20;
	double ari[arsize] = {0,1,2,3,4,5,6,7};
	double arj[arsize] = {1,3,5,7,9,11,13,15};

	cout << "Before: i=" << i << ", j=" << j << endl;
	SWAP(i,j);
	cout << "Current: i=" << i << ", j=" << j << endl;

	cout << "Before: " << endl ;
	cout << "ari = ";
	SHOW(ari, arsize);
	cout << "arj = ";
	SHOW(arj, arsize);
	SWAP(ari,arj,arsize);
	cout << "Current: " << endl ;
	cout << "ari = ";
	SHOW(ari, arsize);
	cout << "arj = ";
	SHOW(arj, arsize);

	return 0;
}

template<typename T>void SWAP(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>void SWAP(T* a, T* b, int n){
	T temp;
	for(int i=0; i<n; ++i){
		temp = *(a+i);
		*(a+i) = b[i];
		*(b+i) = temp;
	}
}

template<typename T>void SHOW(T* a, int n){
	for(int i=0; i<n; ++i){
		cout << *(a+i) << " ";
	}
	cout << endl;
}
