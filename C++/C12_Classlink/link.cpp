#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

inline bool newunit(double min_per_unit) 
{
	return (std::rand()*min_per_unit/RAND_MAX < 1);
}

int main(void)
{
	int queue_size;
	int simu_hours;
	double units_per_hour;

	std::srand(std::time(0)); // setup seed
	std::cout.precision(2);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	// begin simulation
	std::cout << "Enter maximum size of queue: ";
	std::cin >> queue_size;
	std::cout << "Enter the number of simulation hours: ";
	std::cin >> simu_hours;

	QUEUE line(queue_size);
	long cycle_max = MIN_PER_HOUR * simu_hours;

	std::cout << "Enter the average number of units per hour: ";
	std::cin >> units_per_hour;

	double min_per_unit = MIN_PER_HOUR / units_per_hour;
	UNIT temp; // new unit
	long turned_units = 0; 
	long joined_units = 0;
	long served_units = 0;
	long total_length = 0;
	long total_time = 0;
	int queue_time = 0; // time until server is free
	
	// each loop for 1 min
	for(int cycle=0; cycle<cycle_max; ++cycle)
	{
		if(newunit(min_per_unit))
		{
			if(line.IS_FULLY())
				++turned_units;
			else
			{
				++joined_units;
				temp.SETI(cycle);
				line.ADD_UNIT(temp);
			}
		}
		if(queue_time<=0 && !line.IS_EMPTY())
		{
			line.DEL_UNIT(temp);
			queue_time = temp.TIME(); // take the time queued for it
			total_time += cycle-temp.WHEN();
			++served_units;
		}
		if(queue_time > 0)
			--queue_time;
		total_length += line.NUM_UNITS();
	}

	if(joined_units > 0)
	{
		std::cout << "units accepted: " << joined_units << std::endl;
		std::cout << "units served: " << served_units << std::endl;
		std::cout << "units turned: " << turned_units << std::endl;
		std::cout << "average queue size: " 
				  << (double)total_length / cycle_max 
				  << std::endl;
		std::cout << "average wait time: " 
				  << (double)total_time / served_units << " min" 
				  << std::endl;
	}
	else
		std::cout << "No customers!\n";

	return 0;
}
