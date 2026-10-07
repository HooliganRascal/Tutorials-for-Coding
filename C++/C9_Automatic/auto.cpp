#include<iostream>

using namespace std;

template<class type>void test(type x);

int main(void){
	
	int a = 5;
	int b = 6;

	cout << "In main(): a = " << a << " in " << &a << endl;
	cout << "In main(): b = " << b << " in " << &b << endl;
	test(a);        
	cout << "In main(): a = " << a << " in " << &a << endl;
	cout << "In main(): b = " << b << " in " << &b << endl;
	
	return 0;
}

template<class type>void test(type x){

	type a = 9;

	cout << "In text(): a = " << a << " in " << &a << endl;
	cout << "In text(): x = " << x << " in " << &x << endl;

	// Block
	{
		type a = 7;
		cout << "In block: a = " << a << " in " << &a << endl;
		cout << "In block: x = " << x << " in " << &x << endl; // not matter
	}

	cout << "Outside: a = " << a << " in " << &a << endl;
	cout << "Outside: x = " << x << " in " << &x << endl;

}
