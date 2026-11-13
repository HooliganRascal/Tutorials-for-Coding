#include <iostream>
#include "abstract.h"

// abstract base class methods
ABSTRACT::ABSTRACT
(const std::string& s, long an, double bal)
{
	name = s;
	num_account = an;
	balance = bal;
}
ABSTRACT::FORM ABSTRACT::SET_FORMAT(void) const
{
	FORM f;
	f.flag = std::cout.setf
			 (std::ios_base::fixed, std::ios_base::floatfield);
	f.prec = std::cout.precision(2);

	return f;
}

void ABSTRACT::RESTORE(FORM& f) const
{
	std::cout.setf(f.flag, std::ios_base::floatfield);
	std::cout.precision(f.prec);
}

void ABSTRACT::DEPOSIT(double money)
{
	if(money < 0)
	{
		std::cout << "Negative deposit not allowed! " 
				  << "Deposit is cancelled.\n";
	}
	else
		balance += money;
}
void ABSTRACT::WITHDRAW(double money) // pure virtual function
{
	balance -= money;
}

// derived class1 methods 
void BRASS::WITHDRAW(double money) // protocol or contract
{
	if(money<0)
	{
		std::cout << "Withdrawal amount must be positive! "
				  << "Withdrawal is cancelled.\n";
	}
	else if(money <= BALANCE())
		ABSTRACT::WITHDRAW(money);
	else
	{
		std::cout << "Withdrawal amount of $" << money
				  << " exceeds your balance! "
				  << "Withdrawal is cancelled.\n";
	}
}

void BRASS::VIEW_ACCOUNT(void) const
{
	FORM f = SET_FORMAT();

	std::cout << "BRASS Client: " << NAME() << "\n";
	std::cout << "Account Number: " << NUM_ACCOUNT() << "\n";
	std::cout << "Balance: $" << BALANCE() << "\n";

	RESTORE(f);
}

// derived class2 methods 
BRASSPLUS::BRASSPLUS
(const std::string& s, long an, double bal, double ml, double r) : 
ABSTRACT(s, an, bal)
{
	max_loan = ml;
	owe_bank = 0.0;
	rate = r;
}

BRASSPLUS::BRASSPLUS
(const ABSTRACT& ba, double ml, double r) :
ABSTRACT(ba) // implicit copy constructor
{
	max_loan = ml;
	owe_bank = 0.0;
	rate = r;
}

void BRASSPLUS::VIEW_ACCOUNT(void) const
{
	FORM f = SET_FORMAT();

	std::cout << "BRASSPLUS Client: " << NAME() << "\n";
	std::cout << "Account Number: " << NUM_ACCOUNT() << "\n";
	std::cout << "Balance: $" << BALANCE() << "\n";
	std::cout << "Maximum loan: $" << max_loan << "\n";
	std::cout << "Owed to bank: $" << owe_bank << "\n";
	std::cout.precision(3);
	std::cout << "Loan rate: $" << 100*rate << "%\n";

	RESTORE(f);
}

void BRASSPLUS::WITHDRAW(double money)
{
	FORM f = SET_FORMAT();

	double bal = BALANCE(); // access only through public
	if(money < bal)
		ABSTRACT::WITHDRAW(money);
	else if(money <= bal+max_loan-owe_bank)
	{
		double advance = money-bal;
		owe_bank += advance*(1.0+rate);
		std::cout << "Bank advance: $" << advance << "\n";
		std::cout << "Bank advance: $" << advance*rate << "\n";
		DEPOSIT(advance);
		ABSTRACT::WITHDRAW(money);
	}
	else
		std::cout << "Credit limit exceeded!"
				  << "Transaction cancelled.\n";

	RESTORE(f);
}
