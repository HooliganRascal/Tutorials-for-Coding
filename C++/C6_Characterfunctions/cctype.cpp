#include<iostream>
#include<cctype>

int main(void){

	using namespace std;

	cout << "'a' is " << isalpha('a') << endl;
	cout << "'\\t ' is " << isspace('\t') << endl;
	cout << "'3' is " << isdigit('3') << endl;
	cout << "'.' is " << ispunct('.') << endl;

	return 0;
}
