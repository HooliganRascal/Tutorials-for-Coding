#include<iostream>

using namespace std;

const int arsize = 10;

inline void strcount(const char* str){
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\" containes: " << endl;
	while(*str++){
		count++;
	}
	cout << count << " characters\n" 
		 << (total += count) << " characters in total\n";
}

int main(void){
	char input[arsize];
	char next;

	cout << "Enter a line: " << endl;
	cin.get(input, arsize);

	while(cin){
		cin.get(next);

		while(next != '\n'){
			cin.get(next); // wasted
		}

		strcount(input);
		cout << "Enter next line, empty line to quit: " << endl;
		cin.get(input, arsize);
	}
	cout << "End" << endl;

	return 0;
}
