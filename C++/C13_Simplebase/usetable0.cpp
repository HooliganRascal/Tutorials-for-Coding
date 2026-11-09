#include <iostream>
#include "table0.h"

int main(void)
{
	TABLE P1("Mteltn", "Guernica", true);
	TABLE P2("Cosmos", "Justice", false);

	P1.NAME();
	if(P1.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";

	P2.NAME();
	if(P2.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";
	
	return 0;
}
