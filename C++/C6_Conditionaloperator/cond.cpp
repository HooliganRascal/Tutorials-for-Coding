#include<iostream>

int main(void){

	using namespace std;

	int a,b,c;
	
	cout << "Enter two integers: ";
	cin >> a >> b;
	cout << "The larger of " << a << " and " << b 
		 << " is " << (c=a>b?a:b) << endl;

	return 0;
}
