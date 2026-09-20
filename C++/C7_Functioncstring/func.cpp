#include<iostream>

using namespace std;

const int arsize = 20;

void Show(const char*);
char* Plus(const char*);

int main(void){

	char arr[arsize] = "I am coding!";
	char* newarr;

	Show(arr);
	newarr = Plus(arr);
	Show(newarr);
	delete [] newarr;

	return 0;
}

void Show(const char* arr){
	while(*arr){
		cout << *(arr++);
	}
	cout << endl;
}

// Incremented
char* Plus(const char* arr){

	int n=0;
	char *newarr = new char[arsize];

	while(*arr){
		*(newarr+n) = *arr;
		++(*(newarr+n));
		++n;
		++arr;
	}
	return newarr;
}
