#include<iostream>

int main(void){

	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point

	// integers for operating
	int m = 19;
	int n = 6;

	// float types
	float a = 10.0/3.0;
	double b = 10.0/3.0; // default type
	long double c = 10.0/3.0;

	// exponent guarantees the floating-point
	const float dmil = +2.0e+06f;
	const double obil = 1e9;
	const double neli = -8e-2L;

	// significant digits and precision varies
	cout << a*1e6 << endl;
	cout << b*1e6 << endl;
	cout << c*1e6 << endl;

	// operation
	cout << dmil << " + " << m << " = " << dmil + m << endl;
	cout << obil << " * " << n << " = " << obil * n << endl;
	cout << neli << " / " << n << " = " << neli / n << endl;
	cout << m << " / " << n << " = " << m / n << endl; // whole
	cout << m << " % " << n << " = " << m % n << endl; // remain

	return 0;
}


