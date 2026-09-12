#include<iostream>

int main(void){

	using namespace std;

	for(int i=0; i<5; ++i){
		if(i==3){
			break;
		}
		else{
			cout << "This outputs 3 times" << endl;
		}
	}
	cout << endl;

	int j=0;
	do{
		cout << "This outputs 5 times" << endl;
		++j;
		if(j<=3){
			cout << "But this output 3 times" << endl;
		}
		else{
			continue;
		}
		cout << "After output once, this shows up" << endl;
	}while(j<5);
	cout << endl;

	int k=0;
	while(k<5){
		cout << "This tries to output 5 times again" << endl;
		++k;
		if(k==3){
			goto jump3;
		}
		else{
			continue;
		}
	}
	jump3: cout << "When output for 3 times, jumps to this" << endl;

	return 0;
}
