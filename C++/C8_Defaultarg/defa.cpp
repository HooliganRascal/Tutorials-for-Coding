#include<iostream>
#include<cstring>

const int arsize=80;
char* left(const char* str, int n=1); // default argument n=1

int main(void){

	using namespace std;

	char sample[arsize];
	char* ps;

	cout << "Enter a string: " << endl;
	cin.getline(sample, arsize);

	cout << (ps = left(sample,4)) << endl;
	delete [] ps; // free old string
	
	cout << (ps = left(sample)) << endl;
	delete [] ps; // free new string

	return 0;
}

char* left(const char* str, int n){

	if(n < 0){
		n = 0;
	}
	else{
		n = (n < strlen(str)) ? n : strlen(str);
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
