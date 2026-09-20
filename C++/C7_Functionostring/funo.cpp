#include<iostream>

using namespace std;

const int stsize = 3;

void read(string*);
void write(string*);

int main(void){
	
	string sent[stsize];

	cout << "Input " << stsize << " name:" << endl;
	read(sent);
	cout << "Output repeatedly: " << endl;
	write(sent);
	
	return 0;
}

void read(string* sent){
	for(int i=0; i<stsize; ++i){
		cout << i+1 << ": ";
		getline(cin, sent[i]);
	}
}

void write(string* sent){
	for(int i=0; i<stsize; ++i){
		cout << i+1 << ": " << sent[i] << endl;
	}
}
