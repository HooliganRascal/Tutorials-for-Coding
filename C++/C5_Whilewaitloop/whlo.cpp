#include<iostream>
#include<ctime>

#define FLOP float*

typedef float *flo, olf; // olf is still float

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

	// Alias testing
	float arf[5] = {0.1,0.2,0.3};
	// FLOP a=&arf[1], b=arf; // Error of b!
	flo c=arf, d=&arf[1];
	olf e=*(arf+2);
	// cout << a << ", " << b << endl;
	cout << c << ", " << d << ", " << e << endl;

	// Time delay
	int sec;
	cout << "Enter a second: ";
	cin >> sec;

	clock_t delay = sec*CLOCKS_PER_SEC; // Second to system units
	cout << "Start\a" << endl;

	clock_t start = clock(); // Current time of execution
	while((clock()-start)<delay){ // Test for time of execution 
		if(delay/(clock()-start)==0) // Fails to count accurately!
			cout << (clock()-start)/CLOCKS_PER_SEC; // Output nothing
	} // Not exactly second of sec, the test at last will waste little time
	cout << endl << "Done!" << endl;

	return 0;
}
