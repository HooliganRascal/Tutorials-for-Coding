#include<iostream>

int main(void){

	using namespace std;

	double ard[5] = {0.1,1.2,2.3,3.4,4.5};

	// Can't modify array value
	for(double x:ard){
		cout << x << endl;
	}

	// Can modify array value, changed!!!
	for(double &x:ard){
		x *= 0.8;
		cout << x << endl;
	}

	return 0;
}
