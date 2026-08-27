#include<iostream>

int main(void){

	using namespace std;

	char ch;
	int ga = 0;
	int gb = 0;
	int so = 0;

	cout << "Enter A, B then a newline as a grade, EOF to quit: " << endl;
	while(!cin.get(ch)==false){
		cin.get();
		if(ch=='A'){
			ga++;
		}
		else if(ch=='B'){
			gb++;
		}else{
			so++;
		}
	}

	cout << "Grade of 'A' is: " << ga << endl;
	cout << "Grade of 'B' is: " << gb << endl;
	cout << "Grade of soso is: " << so << endl;

	return 0;
}
