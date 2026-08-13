#include <iostream>
#include <cmath>

using namespace std;

double sqplus(double, double);

int main(void){

	double a = 2.0;
	double b = 1.0;
	double c = sqplus(a,b);

	cout << "square root of "
		 << a 
		 << " plus " 
		 << b
		 << " is equal to "
		 << c
		 << endl;

	return 0;
}

double sqplus(double m, double n){
	return sqrt(m)+n;
}
