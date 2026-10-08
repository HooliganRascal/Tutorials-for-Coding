#include<iostream>

using namespace std;

extern double a; // declaration

void update(double dt){
	a += dt;
	cout << "Update, a = " << a << endl;
}

void local(void){
	double a = 0.6;
	cout << "Local, a = " << a << endl; // Hide the global
	cout << "Global, a = " << ::a << endl; // Restart the global
}
