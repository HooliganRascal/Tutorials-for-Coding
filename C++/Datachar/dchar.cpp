#include <iostream>

int main(void){
	
	using namespace std;

	// assign the character
	char ch_1 = '1' ;
	char ch_A = 'A';
	char ch_a = 'a';

	// assign the ASCII code
	char ch_num = 55;
	char ch_nums = ch_num + 1;
	int num = ch_num + 1;

	// output original characters
	cout << "'1' in char is " << ch_1 << endl;
	cout << "'A' in char is " << ch_A << endl;
	cout << "'a' in char is " << ch_a << endl;
	cout << "ch_num in char by initialization is " << ch_num << endl;

	// operate with char
	cout << "ch_num in ASCII initialized is " << int(ch_num) << endl;
	cout << "ch_num +1 in ASCII asigned to int is " << num << endl;
	cout << "ch_num +1 in ASCII added to output is " << ch_num + 1 << endl;
	cout << "ch_nums in char added, assigned to char is " << ch_nums << endl;
	cout << "++ch_num in char by successor is " << ++ch_num << endl;
	cout << "After that, ch_num is eternally " << ch_num << endl; 

	// transfer between char and ASCII code
	cout << "number 65 in char is " << static_cast<char>(65) << endl;
	cout << "character 'a' in ASCII is " << (int)'a' << endl;

	return 0;
}
