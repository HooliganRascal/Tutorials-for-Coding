#include<iostream>
#include<cstring>

using namespace std;

struct info{
	string name;
	char loca[20];
	int age;
	double height;
};

int main(void){
	
	info *myself; // Create pointer of structure
	info *others = new info; // Create dynamic structure
	info wuhao = {"Wu Hao", "Chaozhou", 22, 175.0};

	// Output pointer structure
	myself = &wuhao;
	cout << "Myself from wuhao is named: " << myself->name << endl;
	cout << "Myself from wuhao is located: " << (*myself).loca << endl;
	cout << "Address is " << myself << endl;

	// Output for dynamic structure
	cout << "Enter a name: ";
	getline(cin, others->name); // Input string class
	cout << "Enter a location: ";
	cin.getline((*others).loca, 20); // Input char array string
	cout << "Others is named: " << (*others).name << endl; // Dot
	cout << "Others is located: " << others->loca << endl; // Arrow
	cout << "Address is : " << others << endl;

	delete others;

	return 0;
}
