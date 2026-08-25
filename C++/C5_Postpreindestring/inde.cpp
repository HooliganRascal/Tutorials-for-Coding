#include<iostream>
#include<cstring>

using namespace std;

int main(void){
	
	string sent;
	int x, y;

	cout << "Enter a sentence: ";
	getline(cin, sent);

	// Output in order
	for(int i=0; i<sent.size(); i++){
		cout << sent[i];
	};
	cout << ". " << endl;

	// Output in reverse order
	for(int i=sent.size()-1; i>=0; --i){ // Prefix and postfix works the same
		cout << sent[i];
	};
	cout << ". " << endl;

	// Comparison between prefix and postfix
	x = y = 20;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "x++ = " << x++ << ", ++y = " << ++y << endl;
	cout << "x = " << x << ", y = " << y << endl;

	return 0;
}
