#include<iostream>

using namespace std;

const int rowsize = 4;
const int colsize = 4;
const int scale = 2;

void showa(
		const int (*rowini)[colsize], 
		const int (*rowfin)[colsize]
		);
void times(
		int arr[][colsize], 
		int row, 
		int col
		);

int main(void){
	
	int ar2[rowsize][colsize];
	for(int i=0; i<rowsize; ++i){
		for(int j=0; j<colsize; ++j){
			ar2[i][j]=(i+1)*(j+1);
		}
	}
	showa(ar2, ar2+rowsize);
	cout << endl;
	times(ar2, rowsize, colsize);
	showa(ar2, ar2+rowsize);

	return 0;
}

// Print the array
void showa(
		const int (*rowini)[colsize], 
		const int (*rowfin)[colsize]
		)
{
	for(int i=0; i<(rowfin-rowini); ++i){
		for(int j=0; j<colsize; ++j){
			cout << *(*(rowini+i)+j) << " ";
		}
		cout << endl;
	}
}

// Modify by multiplication
void times(
		int arr[][colsize], 
		int row, 
		int col
		)
{
	for(int i=0; i<row; ++i){
		for(int j=0; j<col; ++j){
			arr[i][j] *= scale;
		}
	}
}
