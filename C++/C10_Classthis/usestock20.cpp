#include <iostream>
#include "stock20.h"

const int obsize = 4;

int main(void){
	stock objects[obsize] = {
		stock("Mteltn Cosmos", 12, 20.0),
		stock("Cosmos Guernica", 24, 31.3),
		stock("Guernica Mteltn", 36, 42.1),
	}; // leave one default
	
	std::cout << "Stock holding: \n\n";
	for(int i=0; i<obsize; ++i){
		(objects+i)->show();
		std::cout << std::endl;
	}

	// find the most valuable holding
	const stock* top = objects;
	for(int i=1; i<obsize; ++i){
		// same as top = &((*top).topval(*(top+i)));
		top = &(top->topval(*(objects+i))); 
	}
	std::cout << "Most valuable holding:\n\n";
	(*top).show();

	return 0;
}
