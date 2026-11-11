#include <iostream>
#include <cstring>
#include "brass.h"

const int CLIENTS = 4;

int main(void)
{
	BRASS* p_clients[CLIENTS];
	std::string temp;
	long num_temp;
	double bal_temp;
	char kind;

	for(int i=0; i<CLIENTS; ++i)
	{
		std::cout << "Enter client's name: ";
		getline(std::cin, temp);
		std::cout << "Enter client's account number: ";
		std::cin >> num_temp;
		std::cout << "Enter opening balance: $";
		std::cin >> bal_temp;
		std::cout << "Enter 1 for BRASS account or "
				  << "2 for BRASSPLUS account: ";
		while(std::cin>>kind && (kind!='1' && kind!='2'))
			std::cout << "Enter 1 or 2: ";
		if(kind=='1')
			p_clients[i] = new BRASS(temp, num_temp, bal_temp);
		else
		{
			double tmax, trate;
			std::cout << "Enter the overdraft limit: $";
			std::cin >> tmax;
			std::cout << "Enter the interest rate as a "
					  << "decimal fraction: ";
			std::cin >> trate;
			p_clients[i] = new BRASSPLUS(temp, num_temp, bal_temp,tmax, trate);
		}

		while(std::cin.get()!='\n')
			continue; // filter input queue
	}
	std::cout << "\n";

	for(int i=0; i<CLIENTS; ++i)
	{
		p_clients[i]->VIEW_NUM();
		std::cout << "\n";
	}

	for(int i=0; i<CLIENTS; ++i)
	{
		delete p_clients[i]; // free memory
	}

	std::cout << "Done!\n";
	return 0;
}
