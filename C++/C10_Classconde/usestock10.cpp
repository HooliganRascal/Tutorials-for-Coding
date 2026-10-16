#include <iostream>
#include "stock10.h"

int main(void){
	std::cout << "Use constructors to create new objects\n";
	std::cout << std::endl;

	// Use block to activate destructor
	{
		// default constructor
		stock stock1; 
		stock1.show();
		std::cout << std::endl;

		// self-defined constructor
		stock stock2("Mteltn Cosmos", 2, 2.0);
		stock2.show();
		std::cout << std::endl;
		
		// constructor by assignment
		// some compiler produces temporary objects
		stock stock3 = stock("Guernica Mteltn", 12, 20.0);
		stock3.show();
		std::cout << std::endl;

		// Assignment
		stock3 = stock2;
		std::cout << "Use assignment to overwrite: \n";
		stock2.show();
		stock3.show();
		std::cout << std::endl;

		// Revise with constructor
		// Create a temporary object and destruct it 
		stock2 = stock("Cosmos Guernica", 25, 32.0);
		stock2.show();
		std::cout << std::endl;
	} 

	std::cout << std::endl;
	stock stock4 = stock("KKNNF", 25, 5.21);
	stock4.show();
	std::cout << std::endl;
	//stock4.~stock(); // we don't call destructor
	std::cout << "Done!" << std::endl << std::endl;
	
	return 0;
}
