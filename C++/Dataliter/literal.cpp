#include <iostream>

int main(void){

	using namespace std;

	int octa = 042;
	int deci = 42;
	int hexa = 0x42;

	// default output type of integer is decimal
	cout << "Base 10 of octa is " << octa << "(042 in octal)" << endl;
	cout << "Base 10 of deci is " << deci << "(42 in decimal)" << endl;
	cout << "Base 10 of hexa is " << hexa << "(0x42 in hexadecimal)" << endl;

	// manipulator for changing number base 16
	cout << hex;
	cout << "Base 16 of deci is " << deci << "(42 in decimal)" << endl;
	cout << "Base 16 of octa is " << octa << "(042 in octal)" << endl;

	return 0;
}

