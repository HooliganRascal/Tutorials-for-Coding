#include<iostream>

const int arsize=80;
const int LIMITS=9;
char* left(const char* str, int n=1); // default argument n=1
unsigned long left(unsigned long num, unsigned ct); // function overloading

int main(void){

	using namespace std;

	char trip[LIMITS] = "Hawaii!!"; // 9th character is '\0'
	unsigned long n = 123456789;
	int i;
	char* temp;

	for(i=1; i<=LIMITS; ++i){
		cout << left(n,i) << endl; // display first left of i digits
		cout << (temp=left(trip,i)) << endl;
		delete [] temp;
	}

	return 0;
}

unsigned long left(unsigned long num, unsigned ct){
	unsigned digits = 1;
	unsigned long n=num;

	if(ct==0||num==0){
		return 0; // return 0 if no digits
	}

	while(n/=10){
		++digits; // counting digits
	}

	if(digits>ct){
		ct=digits-ct;
		while(ct--){
			num /= 10;
		}
		return num; // return first left ct digits
	}
	else{
		return num; // return the whole if digits<=ct
	}
}

char* left(const char* str, int n){

	if(n < 0){
		n = 0;
	}

	// alternative for efficiency
	int m=0;
	while((m<=n)&&(str[m])){ // non-zero are true, zero to false
		++m;
	}

	char* p=new char[m+1]; // allocate new memory
	int i;

	for(i=0; i<n && *(str+i); ++i){
		*(p+i)=str[i]; // copy
	}

	while(i<=n){
		p[i++]='\0'; // set rest to '\0'
	}

	return p;
}
