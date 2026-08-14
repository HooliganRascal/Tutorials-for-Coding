#include<iostream>

int main(void){

	using namespace std;

	//assign bool to int
	int prom = true; 
	int answ = false; 
					  
	// assign to bool
	bool start_1 = -1000;
	bool start_2 = true;
	bool stop_1 = 0;
	bool stop_2 = false;

	// initialize symbolic constant
	const int money = 50;
	
	// output 1 or 0
	cout << "Promise is " << prom <<  " and " << true << endl;
	cout << "Answer is " << answ << " and " << false << endl;
	cout << "Start is " << start_1 << " and " << start_2 << endl;
	cout << "Stop is " << stop_1 << " and " << stop_2 << endl;

	// output the constant
	cout << "Crazy Thursday, v me " << money << " RMB " << endl; 

	return 0;
}
