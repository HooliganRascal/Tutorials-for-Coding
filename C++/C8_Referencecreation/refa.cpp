#include<iostream>

int main(void){

	using namespace std;

	int rats = 101;
	int bunnies = 50;
	int foxes = 80;
	
	int* pt = &rats;
	int& ref = *pt; // address as rats, value as rats, needs initialization!
	cout << "rats = " << rats 
		 << ", ref = " << ref 
		 << endl;
	cout << "rats address = " << &rats << endl 
		 << "ref address = " << &ref << endl
		 << endl;

	ref = bunnies; // address as rats; rats,ref value as bunnies
	cout << "bunnies = " << bunnies
		 << "rats = " << rats 
		 << "ref = " << ref 
		 << endl;
	cout << "bunnies address = " << &bunnies << endl 
		 << "rats address = " << &rats << endl 
		 << "ref address = " << &ref << endl 
		 << endl;

	pt = &foxes; // does not affect ref
	cout << "foxes = " << foxes
		 << "rats = " << rats 
		 << "ref = " << ref 
		 << endl;
	cout << "foxes address = " << &foxes << endl
		 << "rats address = " << &rats << endl
		 << "ref address = " << &ref << endl;

	return 0;
}
