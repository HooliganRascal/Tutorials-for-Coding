#include <iostream>
#include "time2.h"

int main(void){
	TIME weeding(4,35);
	TIME waxing(2,47);
	TIME total;
	TIME diff;
	TIME adjusted;

	std::cout<< "weeding time = ";
	weeding.SHOW();
	std::cout<< "waxing time = ";
	waxing.SHOW();
	
	total = weeding+waxing; 
	std::cout << "total work time = ";
	total.SHOW();

	diff = weeding-waxing; 
	std::cout<< "weeding time - waxing time = ";
	diff.SHOW();

	adjusted = total*1.5; 
	std::cout << "adjusted work time = ";
	adjusted.SHOW();

	return 0;
}
