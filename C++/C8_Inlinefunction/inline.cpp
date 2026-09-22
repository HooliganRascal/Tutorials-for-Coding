#include<iostream>

using namespace std;

inline void call(void){
	cout << "For inline function!" << endl;
}

int main(void){
	call();
	return 0;
}
