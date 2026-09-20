#include<iostream>

using namespace std;

const int length = 66; // even
const int divide = 6; // 7 levels actually
const int rumax = length-2; 
const int rumin = 0;

void separate(char* ar, int low, int high, int level);

int main(){
	
	char ruler[length];
	for(int i=0; i<rumax; ++i){
		ruler[i]=' ';
	}
	ruler[length-1]='\0'; // odd number, 65 bars at last
	ruler[rumax] = '|';
	ruler[rumin] = '|';
	cout << ruler << endl; // display first row

	for(int i=1; i<=divide; ++i){
		separate(ruler,rumin,rumax,i); // level divide will be the most
		cout << ruler << endl;
		for(int j=1; j<rumax; ++j){ // not affect the edges
			ruler[j]=' '; // reset
		}
	}

	return 0;
}

void separate(char* ar, int low, int high, int level){

	if(level==0){
		return;
	}
	
	int mid = (high+low)/2;
	ar[mid]='|';

	separate(ar, low, mid, level-1);
	separate(ar, mid, high, level-1);
}
