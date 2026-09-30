#include<iostream>

using namespace std;

template<class T1, class T2>
auto xpy(T1 x, T2 y)->decltype(x+y);

int main(void){

	double x=5.6;
	short y=8;
	decltype(xpy(x,y)) z = 2.3+4;
	
	cout << x << " + " << y << " = " << xpy(x,y) << endl;
	cout << "2.3 + 4 = " << z << endl;

	return 0;
}

template<class T1, class T2>
auto xpy(T1 x, T2 y)->decltype(x+y){
	decltype(x+y) p;
	p = x+y;
	return p;
}
