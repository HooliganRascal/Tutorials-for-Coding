#include <iostream>
#include <cstring>

int main(void){

	using namespace std;

	char name[20] = "Mteltn";
	const char *call = "Guernica";
	char *back;
	string test;

	cout << name << " and " << call << endl;

	// Address passed to cin and cout
	cout << "Input a name to name: ";
	cin >> name;
	back = name; // Address passed
	
	// Use assignment
	back = new char[strlen(name)+1]; // Allocate new memory
	back = name; // Address passed again
	cout << "Before using new to create dynamic string: " << endl;
	cout << name << " at: " << (int*) name << endl;
	cout << back << " at: " << (int*) back << endl;

	// Use strcpy()
	back = new char[strlen(name)+1]; // Allocate new memory
	strcpy(back, name);
	cout << "After using new: " << endl;
	cout << name << " at: " << (int*) name << endl;
	cout << back << " at: " << (int*) back << endl;
	delete [] back;

	// Use string class, the simplest way!
	test = name;
	cout << "Using string class: " << endl;
	cout << name << " at: " << (int*) name << endl;
	cout << test << " at: " << &test << endl;

	return 0;
}
