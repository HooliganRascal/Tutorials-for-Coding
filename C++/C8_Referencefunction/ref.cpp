#include<iostream>

using namespace std;

void swaprr(int& a, int& b);
void swapcr(const int& a, const int& b); // Unmodifiable

int main(void){

	int a=5;
	int b=6;
	double c=7.1;
	double d=8.6;
	double& e=c; // reference or lvalue reference of c
	double&& f=e*5+6; // rvalue reference
	
	cout << "Originally: a = " << a << ", b = " << b << endl;
	swaprr(a,b); // works
	cout << "After swaprr: a = " << a << ", b = " << b << endl;
	swapcr(a,b); // not works
	cout << "After swapcr: a = " << a << ", b = " << b << endl;

	cout << "Originally: c = " << c << ", d = " << d << endl;
	swapcr(c,d); // not works, type cast and temporary variable
	cout << "After swapcr: c = " << c << ", d = " << d << endl;

	cout << "Originally: e = " << e << ", d = " << d << endl;
	swapcr(e,d); // not works, type cast and temporary variable
	cout << "After swapcr: e = " << e << ", d = " << d << endl;
	
	cout << "Test for rvalue reference: f = e*5+6 = " << f << endl;
	
	return 0;
}

void swaprr(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swapcr(const int& a, const int& b){
	// Yes, it is nothing
}
