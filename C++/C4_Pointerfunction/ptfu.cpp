#include<iostream>
#include<cstring>

using namespace std;

// Pointer function
char *namepoint(void);
int *addition(int *a, int *b);

int main(void){

	char *name;
	int a,b;
	int *aplusb;

	name = namepoint();
	cout << "The name is " << name << " at " << (int*)name << endl;
	delete [] name; // Free memory passed by function

	// Reuse
	name = namepoint();
	cout << "The name is " << name << " at " << (int*)name << endl;
	delete [] name;

	// Pointer argument and return pointer
	a = 1; 
	b = 2;
	aplusb = addition(&a, &b);
	cout << a << " plus " << b << " by pointer is " << *aplusb << endl;
	delete aplusb;

	return 0;
}

char *namepoint(void){
	char temp[80];
	char *np;
	cout << "Enter last name: ";
	cin.getline(temp, 80);
	np = new char[strlen(temp)+1];
	strcpy(np, temp); // With '\0' at the end, while strncpy is not!
	return np;
}

int *addition(int *a, int *b){
	int *apb = new int;
	*apb = *a+*b;
	return apb;
}
