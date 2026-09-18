#include<iostream>

using namespace std;

int PLUS(int, int); // Variable names are optional

int main(void){

	int a=0;
	int b=1;
	int c=PLUS(a,b);

	cout << a << " plus " << b << " = " << c << endl;

	return 0;
}

int PLUS(int a, int b){
	return a+b;
}
