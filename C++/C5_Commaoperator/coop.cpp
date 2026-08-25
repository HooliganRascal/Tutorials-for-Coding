#include<iostream>
#include<cstring>

int main(void){

	using namespace std;

	int i,j;
	char med;
	string sent;
	
	// Input a string
	cout << "Enter a sentence: ";
	getline(cin, sent);
	cout << "Your input is: " << sent << endl;

	// Reverse a string with comma operation
	for(i=0,j=sent.size()-1; i<j; ++i,--j){
		med = sent[i]; // med works as a mediation to swap the order
		sent[i] = sent[j];
		sent[j] = med;
	}
	cout << "Reversed input is: " << sent << endl;

	// Reverse back with variable defined inside the for loop
	for(int x=0,y=sent.size()-1; x<y; ++x,--y){
		char medi = sent[x];
		sent[x] = sent[y];
		sent[y] = medi;
	}
	cout << "Reversed back to be: " << sent << endl;

	// Comma as expression
	{
		int i=20, j=2*i; // Value of this expression is 40
		cout << "i = " << i << ", j = " << j << endl;
	}

	// Comma as operator, with precedence testing
	{
		int i=17; 
		cout << "i = " << i << endl;
		int j=(17,240); // Set to 240
		cout << "j = " << j << endl;
	}

	return 0;
}
