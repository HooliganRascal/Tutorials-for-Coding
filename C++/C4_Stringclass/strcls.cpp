#include<iostream>
#include<cstring>

int main(void){

	using namespace std;

	// Initialization
	char char1[20] = "Strings? ";
	char char2[10];
	string str1;
	string str2;
	string str3 = {"Standing in the hall of fame! "};
	string str4 = "Burn with the brightest flame! ";

	// Input
	cout << "Enter a string: "; 
	cin >> str1; // space as end, works for word
	cin.get();
	cout << "The string you enter is: " << str1 << endl;
	cout << "Enter again with getline: ";
	getline(cin, str1); // cin as argument
	cout << "The string you enter is: " << str1 << endl;
	cout << "The size of your string is " << str1.size() << endl;
	cout << "The 3rd character of your string is " << str1[2] << endl;

	// Assign and concatenate
	strcpy(char2, char1);
	str2 = str1;
	cout << "Copied: "<< char2 << endl;
	cout << "Concatenating strings: " << str2 + str3 << endl;

	// Appending
	strcat(char2, "Yes!");
	str4 += str3;
	cout << "Appending by char string: \n" << char2 << endl;
	cout << "Appending by string class: \n" << str4 << endl;
	

	return 0;
}
