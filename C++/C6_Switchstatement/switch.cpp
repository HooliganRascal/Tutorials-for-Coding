#include<iostream>

enum color{
	red, orange, yellow, green, blue, violet, indigo
};

int main(void){

	using namespace std;

	char cha = '1';
	int num = 1;
	int col = color(1);

	switch(cha){
		case '1': cout << "Output '1'" << endl;
				  break;
		case '2': cout << "Output '2'" << endl;
				  break;
		case 'A': // Continue to execute case 'a' without break
		case 'a': cout << "Output 'a'" << endl;
				  break;
		default : cout << "Output non-character" << endl;
	}

	switch(num){
		case 1: cout << "Output 1" << endl;
				break;
		case 2: cout << "Output 2" << endl;
				break;
		default: cout << "Output non-num" << endl;
	}

	switch(col){
		case red : cout << "Color is red" << endl; break;
		case orange : cout << "Color is orange" << endl; break;
		case yellow : cout << "Color is yellow" << endl; break;
		default: cout << "Output non-color" << endl;
	}

	return 0;
}
