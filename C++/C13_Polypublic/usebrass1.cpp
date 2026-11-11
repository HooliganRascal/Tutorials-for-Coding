#include <iostream>
#include "brass.h"

int main(void)
{
	BRASS Mteltn("Mteltn Cosmos", 114, 3500.0);
	BRASSPLUS Guernica("Guernica Cosmos", 514, 7000);

	Mteltn.VIEW_NUM();
	std::cout << std::endl;
	Guernica.VIEW_NUM();
	std::cout << std::endl;

	std::cout << "Depositing $1000 into the Guernica account:\n";
	Guernica.DEPOSIT(1000.00);
	std::cout << "New balance: $" << Guernica.BALANCE() << "\n";

	std::cout << "Withdrawing $2200 into the Mteltn account:\n";
	Mteltn.WITHDRAW(4200.00);
	std::cout << "New balance: $" << Mteltn.BALANCE() << "\n";

	std::cout << "Withdrawing $2200 into the Guernica account:\n";
	Guernica.WITHDRAW(4200.00);
	Guernica.VIEW_NUM();

	return 0;
}

