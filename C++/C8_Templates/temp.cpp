#include<iostream>

using namespace std;

template<class T>
void Swap(T& a, T& b);

template<typename A>
void change(A& var);

int main(void){

	int i=10;
	int j=11;
	double a=12.1;
	double b=21.2;

	cout << "Before: i=" << i << ", j=" << j << endl;
	Swap(i,j);
	cout << "Swapped: i=" << i << ", j=" << j << endl;
	change(i);
	cout << "Changed: i=" << i << endl;

	cout << "Before: a=" << a << ", b=" << b << endl;
	Swap(a,b);
	cout << "Swapped: a=" << a << ", b=" << b << endl;
	change(b);
	cout << "Changed: b=" << b << endl;

	return 0;
}

template<class T>
void Swap(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename A>
void change(A& var){
	var+=1;
}
