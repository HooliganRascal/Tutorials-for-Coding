#include<iostream>

int main(void){

	using namespace std;

	int i;
	int limit;

	// example
	for(i=0; i<4; i++){
		cout << "Welcome to C++!" << endl;
	};

	// test with bool
	cout << "Enter a limit: ";
	cin >> limit;
	for(i=limit; i; i--){
		cout << "i = " << i << endl;
	};
	cout << "Now i = " << i << endl;

	// expressions
	int member;
	int name = member = 4;
	cout << "member = " << member << endl;
	cout << "name = " << name << endl; 
	int another = (member = 5) + 6;
	cout << "member = " << member << endl;
	cout << "another = " << another << endl; 

	// test for bool
	cout << "member < name is " << (member < name) << endl;
	cout << "member < another is " << (member < another) << endl;
	cout.setf(ios_base::boolalpha); // output true or false
	cout << "member < name is " << (member < name) << endl;
	cout << "member < another is " << (member < another) << endl;

	// for init statement
	for(int j=0; j<4; j++){
		cout << j << ", ";
	}; // no more j
	cout << "no more" << endl; 

	return 0;
}
