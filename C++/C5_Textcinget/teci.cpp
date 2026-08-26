#include<iostream>

int main(void){

	using namespace std;

	int count = 0;
	char ch;

	// Text input igoring space with simple cin
	cout << "Enter a character and enter '#' to quit: " << endl;
	do{
		cin >> ch;
		++count;
		cout << ch;
	}while(ch!='#');
	cin.get(); // Clear the newline character and store the queue
	cout << endl << count << " characters read" << endl;

	// Text input including space with cin.get()
	count = 0; // Reset value
	cout << "Enter a character and enter '#' to quit: " << endl;
	cin.get(ch);
	while(ch!='#'){
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read" << endl;
	cout << "Enter another character: ";
	cin.get(ch);
	cout << ch << endl;

	// EOF and cin.fail(), cin.eof()
	count = 0; // Reset value
	cout << "Enter a character and enter 'CTRL D' to EOF: " << endl;
	cin.get(ch);
	while(cin.fail()==false){
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read" << endl;
	cin.clear(); // Clear EOF flags

	return 0;
}
