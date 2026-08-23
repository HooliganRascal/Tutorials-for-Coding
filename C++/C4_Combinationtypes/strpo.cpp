#include<iostream>
#include<cstring>

using namespace std;

struct info{
	char name[20];
	int age;
};

int main(void){

	info s01, s02, s03;
	info *s123[3] = {&s01, &s02, &s03}; // Pointer to pointer
	info *pa = &s01;
	auto pb = s123;

	// Different ways to assign values to the variable of pointer of pointer 
	(*pa).age = 20;
	s123[1][0].age = 25;
	(*(pb+2))->age = 30;
	strcpy(pa->name, "Cosmos");
	strcpy((*(s123+1)[0]).name, "Mteltn");
	strcpy(pb[2]->name, "Guernica");

	cout << "Name: " << s01.name << ", age: " << s01.age << endl;
	cout << "Name: " << (*pa).name << ", age: " << pa->age << endl;
	cout << "Name: " << (*(pb+1))->name << ", age: " << (**(pb+1)).age << endl;
	cout << "Name: " << (*(pb+2)[0]).name << ", age: " << pb[2][0].age << endl;
	
	return 0;
}
