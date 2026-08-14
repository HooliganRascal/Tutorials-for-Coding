#include<iostream>

int main(void){

	using namespace std;

	const int siza = 3;

	// define
	int integer[3];
	cout << "Defined Unassigned first of the array is " << integer[0] << endl;

	// assign and operate
	int integers[siza];
	integers[0] = 7;
	cout << "Assigned first number is " << integers[0] << endl;
	cout << "Assigned first number plus 1 is " << integers[0] + 1 << endl;

	// initialize
	float stock[4] = {6.2, 2.7 ,3.5, 4.1};
	float etock[4] = {1.9, 2.7, 3.5};
	float ztock[4] = {};
	float dtock[]  = {5.1, 2.3, 4.7, 9.6};
	float qtock[]  = {};
	cout << "Last 1 of stock is " << stock[3] << endl;
	cout << "Over 1 of stock is " << stock[4] << endl; // surpasses to etock!
	cout << "Unassigned last 1 of etock is " << etock[3] << endl;
	cout << "All elements in an empty array are " << ztock[2] << endl;
	cout << "Let the compiler decides, one element is " << dtock[2] << endl;
	cout << "Let the compiler decides, over 1 element is " << dtock[4] << endl;
	cout << "Let the compiler decides, no element for " << qtock[0] << endl;

	// explore empty array, does not affect other memories
	qtock[0] = 1.2;
	qtock[1] = 2.1;
	cout << "Let the compiler decides, assigned 1 be " << qtock[0] << endl;
	cout << "Let the compiler decides, assigned 2 be " << qtock[1] << endl;

	// assign overly
	float atock[5] = {6.3}; // assigned, initialized, does not work
	float btock[5];
	dtock[4] = 5.5;
	cout << "Assigned overly nextly be " << atock[0] << endl; // taken hard
	cout << "Assigned overly nextly again be " << btock[0] << endl; // recover

	return 0;
}
