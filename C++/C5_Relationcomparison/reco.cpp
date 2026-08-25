#include<iostream>
#include<cstring>

int main(void){

	using namespace std;

	// Test for simple relational expression
	cout.setf(std::ios::boolalpha);
	for(int i=0; i<=5; i++){
		cout << i << (i<5) << " ";
	}
	cout << endl;

	// Test for char comparison with ASCII code
	cout.unsetf(std::ios::boolalpha);
	for(char a='a'; a<='e'; a++){
		cout << a << (a<'e') << " ";
	}
	cout << endl;

	// Let bool value operates with other integers
	int a=5;
	cout << "a=5, a+(a!=5) = " << a+(a>4) << endl << endl;

	char ar1[6] = "Zoo";
	char ar2[8] = "Zoo";
	char ar3[9] = "aviary";
	char *pt2 = ar2;
	char *pt3 = ar3;
	string str2 = ar2;
	string str3 = ar3;

	// Compare C-style string
	cout << "\"Zoo\" is the same with 0 though size differs: " 
		 << strcmp(ar1,ar2) << endl; // ar1 == ar2
	cout << "\"Zoo\" precedes \"aviary\" in ASCII code with negative value: " 
		 << strcmp(&ar1[0],&ar3[0]) << endl; // ar1 < ar3
	cout << "\"aviary\" follows \"Zoo\" in ASCII code with positive value: " 
		 << strcmp(pt3++,pt2++) << endl; // ar3 > ar2
	cout << "'v' follows 'o' in ASCII code with positive value: " 
		 << strcmp(pt3,pt2) << endl; // ar3 > ar2
	
	// Compare string class
	cout << "\"Zoo\" precedes \"aviary\" is true with bool value: " 
		 << (str2<str3)  << endl; // Return 1
	cout << "'o' follows 'v' is false with bool value: " 
		 << (str2[1]>str3[1]) << endl; // Return 0

	return 0;
}
