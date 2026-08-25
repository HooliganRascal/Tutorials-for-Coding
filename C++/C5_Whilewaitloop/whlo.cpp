#include<iostream>

int main(void){

	using namespace std;

	int i=0; // Index initialization
	char name[8]="Cosmos";

	// Simple while loop
	while(i<5){
		cout << i;
		i++; // Don't forget it!
	}
	cout << endl;

	// Test with C-style string
	i=0; // Reinitialization
	while(*(name+i)){ // Same as name[i]!=0
		cout << name[i] << " " << (int)*(name+i) << endl;
		++i;
	}

	return 0;
}
