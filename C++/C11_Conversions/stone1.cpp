#include <iostream>
#include "stonewt1.h"

int main(void){
	STONEWT1 poppins(9,2.8);
	double p_wt = poppins; // implicit conversion
	
	std::cout << "Convert to double => "
			  << "Poppins: " << p_wt 
			  << "pounds.\n";
	std::cout << "Convert to int => "
			  << "Poppins: " << (int)poppins 
			  << "pounds.\n";

	return 0;
}
