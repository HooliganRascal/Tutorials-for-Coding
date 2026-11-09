#include <iostream>
#include "table1.h"

int main(void)
{
	TABLE P1("Mteltn", "Cosmos", false);
	RATED R1(1145, "Guernica", "Cosmos", true);

	P1.NAME();
	if(P1.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";

	R1.NAME(); // use base-class method
	if(R1.HAS())
		std::cout << " : has a table\n";
	else
		std::cout << " : hasn't a table\n";

	std::cout << "Name: ";
	R1.NAME();
	std::cout << "; Rating: " << R1.RATING() << "\n";

	RATED R2(4514, P1);
	std::cout << "Name: ";
	R2.NAME();
	std::cout << "; Rating: " << R2.RATING() << "\n";

	return 0;
}

