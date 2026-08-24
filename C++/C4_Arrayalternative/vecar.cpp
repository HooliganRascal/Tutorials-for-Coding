#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main(void){

	int i;
	int arsize = 4;

	double ar1[4] = {4.2, 2.1, 6.3, 2.4};

	// vector
	vector<double> ar2(arsize);
	for(i=0; i<4; i++){
		ar2[i] = (double)i/3.0;
	};
	
	// array
	array<double, 4> ar3 = {5.6, 2.3, 7.1, 8.9};
	array<double, 4> ar4 = ar3; // assign directly

	// unsafe behavior, but now C++ can protect it automatically
	ar1[-2] = 0.5;
	// ar3.at(-1) = 0.02; // check invalid index
	//ar4[200] = 11.23;

	cout << "ar1[1] = " << ar1[1] << " at " << ar1+1 << endl;
	cout << "ar1[2] = " << *(ar1+3) << " at " << (double*)ar1+3 << endl;
	cout << "ar2[2] = " << ar2.at(2) << " at " << &ar2[2] << endl;
	cout << "ar3[2] = " << ar3[2] << " at " << &ar3[2] << endl;
	cout << "ar4[2] = " << ar4[2] << " at " << &ar4[2] << endl;

	// unsafe output 
	cout << "ar1[-2] = " << ar1[-2] << " at " << &ar1[-2] << endl;
	cout << "ar3[-1] = " << ar1[-1] << " at " << &ar3[-1] << endl;
	cout << "ar3[2] = " << ar3[2] << " at " << &ar3[2] << endl;
	cout << "ar4[2] = " << ar4[2] << " at " << &ar4[2] << endl;

	return 0;
}
