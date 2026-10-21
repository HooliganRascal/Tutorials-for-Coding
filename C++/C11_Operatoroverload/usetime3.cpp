#include <iostream> // time3.h already includes one
#include "time3.h"

int main(void){
	TIME cosmos(4,35);
	TIME mteltn(2,47);
	TIME temp;

	std::cout << "Cosmos and Mteltn:\n";
	std::cout << cosmos 
			  << mteltn << "\n";
	std::cout << "Cosmos + Mteltn:\n"
			  << (temp = cosmos+mteltn) << "\n";
	std::cout << "Cosmos*1.7:\n"
			  << (temp = cosmos*1.7) << "\n";
	std::cout << "10.2*Mteltn:\n"
			  << (temp = 10.2*mteltn) << "\n";

	return 0;
}
