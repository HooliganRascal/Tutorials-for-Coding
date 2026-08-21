#include<iostream>
#include<cstring>

using namespace std;

struct info{
	char name[20];
	int age;
	double height_cm;
};

struct memb{
	char pa1[20];
	char pa2[20];
}mem1, mem2;

// Bit fields
struct addi{
	int pluss : 4; // 4 bits for integer variable
	unsigned int : 4; // 4 bits unused for spacing
	bool booll: 1;
};


int main(void){

	// Initialization
	info myself = {"Guernica", 23, 175.6};
	info myfriend = {"Jinshin", 19, 173.1};
	info myother;
	info myarray[10]; // Array of 10 info structures
	info mytest[2] = {
		{"Mteltn", 20, 178.2},
		{"Cosmos", 20, 174.9}
	};
	addi myaddi = {7, true};

	// Assignment
	myother = myfriend;
	strcpy(mem1.pa1, "Actor");  
	strcpy(mem2.pa2, "Dresser");

	// Make use of structure arrays
	cout << "Enter a name for myarray[5]: ";
	cin.getline(myarray[5].name, 20);
	cout << "The name of myarray[5] is: " << myarray[5].name << endl;
	cout << "The name of mytest[0] is: " << mytest[0].name << endl;
	cout << "The height of mytest[0] is: " 
		 << mytest[0].height_cm 
		 << " in cm" 
		 << endl;

	// Normal output and operations
	cout << "My name is " << myself.name << endl;
	cout << "I am " << myself.age << " years old" << endl;
	cout << "I am " << myself.height_cm << " in cm" << endl;
	cout << myfriend.name << " is my friend" << endl;
	cout << "He is " << myfriend.height_cm << " in cm" << endl;
	cout << "Together will be " 
		 << myself.height_cm + myfriend.height_cm 
		 << " in cm" 
		 << endl;
	cout << "Same as " 
		 << myself.height_cm + myother.height_cm 
		 << " in cm" 
		 << endl;
	cout << "The pa1 of mem1 is " << mem1.pa1 << endl;
	cout << "The pa1 of mem2 is " << mem1.pa2 << endl; // Empty
	cout << "The pa2 of mem2 is " << mem2.pa2 << endl;
	cout << "The pluss of myaddi is " << myaddi.pluss << endl;


	return 0;
}
