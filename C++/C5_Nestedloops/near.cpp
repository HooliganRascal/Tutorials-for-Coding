#include<iostream>
#include<cstring>

const int ar_row = 5;
const int in_col = 5;
const int ch_col = 25;

int main(void){

	using namespace std;

	int arin[ar_row][in_col]{
		{1, 2, 3, 4, 5},
		{2, 3, 4, 5, 6},
		{3, 4, 5, 6, 7},
		{4, 5, 6, 7, 8},
		{5, 6, 7, 8, 9},
	}; // Normal 2-D int array
	char arch[ar_row][ch_col]{
		"Chai Wan",
		"Bba Ggo",
		"Tong LoWan",
		"Wan Zai",
		"Zhong Wan"
	}; // C-style string in 2-D char array

	// Not assigned initialization
	char *arpt[ar_row]; // Array of ar_row pointers to arrays
	char (*ptar)[ch_col]; // Pointer to whole array with ch_col elements
	char **ptpt; // Pointer to pointer
	string arst[ar_row]; // Array of ar_row strings
	string *ptst; // Pointer to string
	
	// Nested for loops to output 2-D array
	for(int i=0; i<ar_row; ++i){
		cout << arch[i] << ":\t";
		for(int j=0; j<in_col; ++j){
			cout << arin[j][i] << "\t";
		}
		cout << endl;
	}

	// Pass to array of char pointers
	for(int i=0; i<ar_row; ++i){
		cout << (*(arpt+i)=arch[i]) << ", "; // Another kind of pt to pt
	}
	cout << "Done" << endl;

	// Pass to pointer of C-style string of whole array
	cout << *(ptar = &arch[0]) << ", ";
	for(int j=0; j<ch_col; ++j){
		// arch[1] is passed to the location *ptar points to
		(*ptar)[j] = arch[1][j];  
		cout << (*ptar)[j];
	}
	// arch[2] is passed to the location *ptar points to
	strcpy(*ptar, arch[2]);
	cout << ", " << *ptar << ", Done" << endl;

	// Output pointer to pointer, now arpt[0] == "Tong LoWan"
	cout << *(ptpt=arpt+0) << endl; // cout recognize *ptpt as an address

	// Output first element of second array
	cout << *(arpt[1]) << " == " << arpt[1][0]<< endl; 

	// Array of strings
	for(int i=0; i<ar_row; ++i){
		cout << (arst[i] = arch[i]) << ", ";
	}
	cout << "Done" << endl;

	// Pointer to strings
	for(int i=0; i<ar_row; ++i){
		cout << *(ptst = &arst[i]) << ", ";
	}
	cout << "Done" << endl;

	return 0;
}
