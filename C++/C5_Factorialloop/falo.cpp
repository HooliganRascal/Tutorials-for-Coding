#include<iostream>

using namespace std;

const int fasize = 10; 

int main(void){
	
	long long facto[fasize];
	long long doufa[fasize];

	
	*facto = *(facto+1) = 1; // 0!=1!=1 
	doufa[0] = doufa[1] = 1; // 0!!=1!!=1
	
	// n!=n(n-1)(n-2)...(n-(n-2))(n-(n-1))
	for(int i=1; i<fasize; i++){
		facto[i] = i*facto[i-1];
	};
	cout << "Factorial of " << fasize-1 << ": " << endl;
	for(int j=0; j<fasize; j++){
		cout << j << "! = " << facto[j] << endl;
	};
	cout << endl;

	// n!!=n(n-2)(n-4)...(n-(n-4))(n-(n-2))
	for(int i=2; i<fasize; i=i+2){ // double factorial of an even number
		doufa[i] = i*doufa[i-2];
	};
	cout << "Factorial of max even number <= " << fasize-1 << ": " << endl;
	for(int j=0; j<fasize; j=j+2){
		cout << j << "!! = " << doufa[j] << endl;
	};
	cout << endl;

	// n!!=n(n-2)(n-4)...(n-(n-3))(n-(n-1))
	for(int i=3; i<fasize; i=i+2){ // double factorial of an odd number
		doufa[i] = i*doufa[i-2];
	};
	cout << "Factorial of max odd number <= " << fasize-1 << ": " << endl;
	for(int j=1; j<fasize; j=j+2){
		cout << j << "!! = " << doufa[j] << endl;
	};

	return 0;
}
