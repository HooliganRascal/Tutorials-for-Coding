#include<iostream>
#include<cstring>

using namespace std;

struct info{
	string name;
	int age;
};

void display(const info&);
info& addi(info&, const info&);
info& mult(info);

int main(void){

	info ref1 = {"Mteltn", 19};
	info ref2 = {"Guernica", 20};
	info ref3 = {"Cosmos", 21};

	cout << "Originally:" << endl;
	display(ref1);
	display(ref2);
	display(ref3);
	cout << endl;

	info ref4 = addi(ref1,ref2);
	cout << "Now after addi, ref4 is: " << endl;
	display(ref4);
	cout << "And after addi, ref1 is: " << endl;
	display(ref1);
	cout << endl;

	info& ref5 = mult(ref1);
	cout << "Now after mult, ref5 is: " << endl;
	display(ref5);
	cout << "And after mult, ref1 is still though: " << endl;
	display(ref1);
	addi(ref1,ref3).age = 18; // Reference is a lvalue!
	cout << "While after addi as lvalue, ref1 is changed: " << endl;
	display(ref1);
	delete &ref5; // free the new memory created to get the copied value

	return 0;
}

// simply operate with reference input
void display(const info& ref){
	cout << "Name is " << ref.name << endl;
	cout << "Age is " << ref.age << endl;
}

// return reference by input reference and avoid modifying by const
info& addi(info& ref1, const info& ref2){
	ref1.age += ref2.age;
	return ref1;
}

// return reference by creating new memory
info& mult(info ref){
	info* pref = new info; // create new memory
	*pref = ref;
	(*pref).age *= 2;
	return *pref; // return reference to the copied info in newly allocated
}

