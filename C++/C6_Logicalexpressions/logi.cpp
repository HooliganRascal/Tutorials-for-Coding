#include<iostream>

int main(void){

	using namespace std;

	int a;

	do{
		cout << "Input an integer and enter -3 to quit: ";
		cin >> a;
		if(a<0 || a==0){
			cout << "It is non-positive" << endl;
		}
		else if(a>1 && a<10){
			cout << "It is smaller than 10 but greater than 1" << endl;
		}
		else if(!(a>20) and not(a<10)){
			cout << "It is not greater than 20" << endl;
		}
		else if((a>=22) and (a<30)){
			cout << "It is not greater or equal to 30" << endl;
		}
		else{
			cout << "Big number, is it?" << endl;
		}
	}while(a!=-3);

	return 0;
}
