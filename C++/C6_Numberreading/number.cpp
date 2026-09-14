#include<iostream>

const int Max = 5;
using namespace std;

int main(void){

	double fish[Max];
	double golf[Max];

	int i = 0;
	double total = 0.0;
	double avg = 0.0;

	// Simple quit of cin
	cout << "Enter the weights of your fish and <q to quit>" << endl;
	cout << "fish #1: ";
	while(i<Max && cin >> fish[i]){
		if(++i<Max){
			cout << "fish #" << i+1 << ": ";
		}
	}
	for(int j=0; j<i; ++j){
		total += fish[j];
	}
	avg = total/(double)i;
	if(i==0){
		cout << "No fish" << endl;
	}
	else{
		cout << avg << " = average weight of " << i << " fish" << endl;
	}
	cout << "Done !" << endl;

	// Reset and continue of cin
	cin.clear(); // Clear input queue;
	cin.get(); // Read the newline
	cout << "Enter your scores of " << Max << " rounds!" << endl; 
	for(int j=0; j<Max; ++j){
		cout << "Round #" << j+1 << ": ";
		while(!(cin >> golf[j])){
			cin.clear(); // Clear error flags
			while(cin.get()!='\n'){ // Error input in the queue cleared
				continue;
			}
			cout << "Please enter a number!" << endl;
			cout << "Round #" << j+1 << ": ";
		}
	}
	total = 0.0; // Reset 
	for(int j=0; j<Max; ++j){
		total += golf[j];
	}
	avg = total/Max;
	cout << avg << " = average score of " << Max << " rounds" << endl;

	return 0;
}
