#include<iostream>

using namespace std;

double a = 0.1;

void update(double);
void local(void);

int main(void){

	cout << "Now a = " << a << endl;
	update(a);
	cout << "Now a = " << a << endl;
	local();
	cout << "Now a = " << a << endl;

	return 0;
}
