#include<iostream>

using namespace std;

extern int a;
static int b = 10;
int c = 20;

void remo(void){
	cout << "In in2.cpp\n";
	cout << "&a = " << &a << ", &b = " << &b << ", &c = " << &c << endl;
}
