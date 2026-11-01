#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime> // time()
#include "stringgood.h"

const int arsize = 10;
const int maxlen = 81;

int main(void)
{
	stringgood name;
	stringgood sayings[arsize];
	char temp[maxlen];
	int i, total;

	std::cout << "Hi, what is your name?\n>> ";
	std::cin >> name;
	std::cout << name << ", please enter up to "
			  << arsize << " short saying <enter to quit>:\n";
	
	for(i=0; i<arsize; ++i)
	{
		std::cout << i+1 << ": ";
		std::cin.get(temp,maxlen);
		while(std::cin && (std::cin.get()!='\n'))
			continue; // clear up the queue
		if(!std::cin || (temp[0]=='\0')) // test empty line
			break;
		else
			sayings[i] = temp;
	}

	total = i;

	if(total > 0)
	{
		std::cout << "Here are your sayings:\n";
		for(i=0; i<total; ++i)
		{
			std::cout << sayings[i][0] << ": " 
					  << sayings[i] << "\n";
		}

		stringgood* shortest = &sayings[0];
		stringgood* first = &sayings[0]; // use pointer to object
		for(i=1; i<total; ++i)
		{
			if(sayings[i].length() < shortest->length())
				shortest = sayings+i;
			if(sayings[i] < *first)
				first = sayings+i;
		}

		std::cout << "Shortest saying:\n"
				  << *shortest << "\n";
		std::cout << "First saying alphabetically:\n"
				  << *first << "\n";

		// new and delete
		srand(time(0));
		int choice = rand() % total;
		stringgood* favorite = new stringgood(sayings[choice]);
		std::cout << "My favorite saying:\n"
				  << *favorite << "\n";
		delete favorite;
	}
	else
		std::cout << "No input! Bye.\n";

	return 0;
}
