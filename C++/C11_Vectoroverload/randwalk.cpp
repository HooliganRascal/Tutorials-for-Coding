#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main(void){

	vect::VECTOR step_vec, result_vec;
	unsigned long step_num = 0;
	double angle_dir, target, step_len;

	srand(time(0));
	std::cout << "Enter target distance (q to quit): ";

	while(std::cin >> target){
		std::cout << "Enter step length: ";
		if(!(std::cin >> step_len))
			break;

		while(result_vec.rval() < target){
			angle_dir = rand() % 360;
			step_vec.reset(step_len, angle_dir, vect::VECTOR::POLA);
			result_vec = result_vec + step_vec;
			step_num++;
		}

		std::cout << "After " << step_num 
				  << " steps, the subject has the following location:\n";
		std::cout << result_vec << std::endl;
		result_vec.mode_pola();
		std::cout << "or\n" << result_vec << std::endl;
		std::cout << "Average outward distance per step = "
				  << result_vec.rval()/step_num << std::endl;
		
		step_num = 0;
		result_vec.reset(0.0, 0.0);
		std::cout << "Enter target distance (q to quit): ";
	}

	std::cout << "Bye!\n";
	std::cin.clear(); // clean out flags including eof
	while(std::cin.get()!='\n')
		continue;
	
	return 0;
}
