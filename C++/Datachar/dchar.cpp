#include <iostream>

int main(void){
	
	using namespace std;

	char ch_1 = '1' ;
	char ch_A = 'A';
	char ch_a = 'a';
	char ch_free;

	// ASCII code
	int i = ch_1;

	// output original characters
	cout << "'1' in char is " << ch_1 << endl;
	cout << "'A' in char is " << ch_A << endl;
	cout << "'a' in char is " << ch_a << endl;
	cout << "number 65 in char is " << static_cast<char>(65) << endl;

	// output ASCII code
	cout << "Enter a character : ";
	cin >> ch_free;
	cout << ch_free << " in char is " << ch_free << endl;
	cout << ch_free << " in ASCII is " << (int)ch_free << endl;
	cout << ch_1 << " in ASCII is " << i << endl;

	return 0;
}
