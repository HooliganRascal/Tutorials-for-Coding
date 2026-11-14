#include <iostream>
#include "dynamic.h"

int main(void)
{
	BASE shirt("Portabelly", 8);
	NODM balloon("red", "Blimpo", 4);
	YEDM trousers("Mercator", "Buffalo Keys", 5);

	std::cout << "Displaying BASE object:\n";
	std::cout << shirt << std::endl;
	std::cout << "Displaying NODM object:\n";
	std::cout << balloon << std::endl;
	std::cout << "Displaying YEDM object:\n";
	std::cout << trousers << std::endl;

	NODM balloon2(balloon); // implicit copy constructor
	std::cout << "Result of NODM copy:\n";
	std::cout << balloon2 << std::endl;

	YEDM trousers2(trousers);
	std::cout << "Result of YEDM copy:\n";
	std::cout << trousers2 << std::endl;

	YEDM trousers3; // default constructor
	// std::cout << "Result of YEDM default constructor:\n";
	// std::cout << trousers3 << std::endl;
	trousers3 = trousers;
	std::cout << "Result of YEDM assignment:\n";
	std::cout << trousers3 << std::endl;

	return 0;
}
