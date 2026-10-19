#include <iostream>
#include "time0.h"

int main(void){
	TIME planning;
	TIME coding(2,40);
	TIME fixing(5,55);
	TIME total;

	std::cout<< "planning time = ";
	planning.SHOW();
	std::cout<< "coding time = ";
	coding.SHOW();
	std::cout<< "fixing time = ";
	fixing.SHOW();
	
	total = coding.SUM(fixing);
	std::cout << "coding.SUM(fixing) = ";
	total.SHOW();

	return 0;
}
