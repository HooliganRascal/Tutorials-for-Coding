#include<iostream>

using namespace std;

const int arsize = 8;

int main(void){

	float arf[arsize];
	float *pt = arf;

	for(int i=0; i<arsize; i++)
		*(arf+i) = 5.0+0.1*(float)i; // No brackets
	
	cout << "Current addr of pt is " << pt << " with value " << *pt << endl;
	cout << "Increment pt++ is " << pt++ << " with value " << *pt << endl;
	cout << "Now pt is at " << pt << " with value " << *pt << endl;
	cout << "Increment ++pt is " << ++pt << " with value " << *pt << endl;
	cout << "Increment at " << pt << " value *++pt " << *++pt << endl;
	cout << "Increment at " << pt << " value *pt++ " << *pt++ << endl;
	cout << "Now pt is at " << pt << " with value " << *pt << endl;

	// Combination assignments
	pt+=1;
	cout << "Increment pt+=1 is " << pt << " with value " << *pt << endl;

	// Loops with blocks
	for(int i=0; i<arsize; ++i){ // Much more efficient than postfix
		cout << *(arf+i) << ", ";
	} // Ignore the ';' is OK
	cout << " Done! " << endl;

	int x = 20;
	{
		int x = 60;
		int y = 100;
		cout << x << ", " << y << ", ";
	}
	cout << x << endl;
	// cout << y << endl; // Turns out error!

	return 0;
}
