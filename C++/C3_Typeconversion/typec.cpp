#include<iostream>

int main(void){

	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);

	// conversion on initialization
	float tree = 3; 
	int guess = 35.9832;

	// initialization conversions with {}
	const int code = 77;
	char c1 = {77};
	char c2 = {code};
	char c3 = guess;
	
	// type cast
	double dguess = (double)guess;
	double guessd = double(guess);

	// declare by auto
	auto test = 1e3;

	cout << "Integer 3 converted into float is " << tree << endl;
	cout << "Float 35.9832 converted into int guess is " << guess << endl;
	cout << "Constant integer code in int is " << code << endl;
	cout << "character c1 initialized by number 77 is " << c1 << endl;
	cout << "character c2 initialized by constant code is " << c2 << endl;
	cout << "character c3 initialized by assinged guess is " << c3 << endl;
	cout << "double dguess initialized by casted guess is " << dguess << endl;
	cout << "double guessd initialized by guess casted is " << guessd << endl;
	cout << "auto for 1e3 is type double with value: " << test << endl;

	return 0;
}

