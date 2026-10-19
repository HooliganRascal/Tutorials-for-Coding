#include <iostream>
#include "time1.h"

int main(void){
	TIME planning;
	TIME coding(2,40);
	TIME fixing(5,55);
	TIME morefixing(3,28);
	TIME total;

	std::cout<< "planning time = ";
	planning.SHOW();
	std::cout<< "coding time = ";
	coding.SHOW();
	std::cout<< "fixing time = ";
	fixing.SHOW();
	
	total = coding+fixing; 
	std::cout << "coding + fixing = ";
	total.SHOW();

	std::cout<< "more fixing time = ";
	morefixing.SHOW();
	total=total.operator+(morefixing);
	std::cout<< "total.operator+(morefixing) = ";
	total.SHOW();

	return 0;
}
