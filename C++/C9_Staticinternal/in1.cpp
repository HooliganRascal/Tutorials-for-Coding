#include<iostream>

using namespace std;

int a = 3;
int b = 4;
static int c = 5;

void remo(void);

int main(void){
	cout << "In in1.cpp:\n";
	cout << "&a = " << &a << ", &b = " << &b << ", &c = " << &c << endl;
	remo();
	return 0;
}
