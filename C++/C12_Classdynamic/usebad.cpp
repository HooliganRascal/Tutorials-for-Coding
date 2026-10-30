#include <iostream>
#include "stringbad.h"

inline void call1(stringbad& rst){
	std::cout << "String passed by reference: \n" 
		      << "\t\"" << rst << "\"\n";
}

inline void call2(stringbad st){
	std::cout << "String passed by value: \n" 
		      << "\t\"" << st << "\"\n";
}

int main(void){

	std::cout << "Let us start!\n";

	stringbad h1("Celery Stalks at Midnight");
	stringbad h2("Lettuce Prey");
	stringbad h3("Spinach Leaves Bowl for Dollars");
	std::cout << "h1: " << h1 << std::endl;
	std::cout << "h2: " << h2 << std::endl;
	std::cout << "h3: " << h3 << std::endl;
	std::cout << std::endl;

	call1(h1);
	std::cout << "h1: " << h1 << std::endl;
	call2(h2);
	std::cout << "h2: " << h2 << std::endl;
	std::cout << std::endl;

	std::cout << "Initialize one object to another:\n";
	stringbad h4 = h3;
	std::cout << "h4: " << h4 << std::endl;
	std::cout << "Assign one object to another:\n";
	stringbad h5;
	h5 = h1;
	std::cout << "h5: " << h5 << std::endl;
	std::cout << "End!\n";
	std::cout << std::endl;

	return 0;
}
