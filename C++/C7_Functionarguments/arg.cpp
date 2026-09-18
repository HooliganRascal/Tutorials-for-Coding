#include<iostream>

using namespace std;

int possible(int, int);

int main(void){

	int total = 51;
	int choices = 6;
	int chances = possible(total, choices);

	cout << "For " << choices << " choices in " << total << " cards" << endl;
	cout << "You have one chance in " << chances << " possibilities" << endl;

	return 0;
}

int possible(int all, int pick){

	// long double fina=1;
	// for(int i=all; i>(all-pick); --i){
	// 	fina*=i; 
	// }
	// for(int j=pick; j>0; --j){
	// 	fina/=j;
	// }

	long double fina=1.0;
	for(long double i=all,j=pick; j>0; --i,--j){ // int i,j works too!
		fina *= i;
		fina /= j;
	}

	return fina;
}
