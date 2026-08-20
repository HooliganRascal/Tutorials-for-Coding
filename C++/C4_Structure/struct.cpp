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

int main(void){

	// Initialization
	info myself = {"Guernica", 23, 175.6};
	info myfriend = {"Jinshin", 19, 173.1};
	info myother;

	// Assignment
	myother = myfriend;
	strcpy(mem1.pa1, "Actor");  
	strcpy(mem2.pa2, "Dresser");

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
	cout << "The pa1 of mem2 is " << mem1.pa2 << endl;
	cout << "The pa2 of mem2 is " << mem2.pa2 << endl;


	return 0;
}
