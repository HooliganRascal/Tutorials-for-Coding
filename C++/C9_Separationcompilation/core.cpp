#include<iostream>
#include"coor.h"

int main(void){

	using namespace std;
	
	// Input definition
	rect input1;
	pola input2;

	// Rectangular to polar
	cout << "Enter a coordinates in x-y:" << endl;
	cout << "x = ";
	cin >> input1.x;
	cout << "y = ";
	cin >> input1.y;
	show(rtop(input1));

	// Translate
	cout << endl;

	// Polar to rectangular
	cout << "Enter a coordinates in polar(angle in deg):" << endl;
	cout << "r = ";
	cin >> input2.r;
	cout << "alpha = ";
	cin >> input2.alpha;
	show(ptor(input2));

	return 0;
}
