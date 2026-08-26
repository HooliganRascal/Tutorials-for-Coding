#include<iostream>

using namespace std;

const int better = 5;

int main(void){


	// Test for simple do while loop
	int n;
	do{
		cout << "Enter a number in the range 1~10 to find the better: ";
		cin >> n;
	}while(n!=better); // Don't forget the semicolon!
	cout << "Yes, " << n << " is the better one!" << endl;

	return 0;
}
