#include <iostream>
#include "brass.h"

// Format
form SETFORMAT(void)
{
	return std::cout.setf
	(std::ios_base::fixed, std::ios_base::floatfield);
}

void RESTORE(form f, prec p)
{
	std::cout.setf(f, std::ios_base::floatfield);
	std::cout.precision(p);
}

// BRASS methods
BRASS::BRASS
(const std::string& m_name, long m_num, double m_bal)
{
	name = m_name;
	num = m_num;
	bal = m_bal;
}

BRASS::~BRASS(void){}

void BRASS::DEPOSIT(double money)
{
	if(money < 0)
	{
		std::cout << "Negative deposit not allowed! " 
				  << "Deposit is cancelled.\n";
	}
	else
		bal += money;
}

void BRASS::WITHDRAW(double money)
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	if(money<0)
	{
		std::cout << "Withdrawal amount must be positive! "
				  << "Withdrawal is cancelled.\n";
	}
	else if(money <= bal)
		bal -= money;
	else
	{
		std::cout << "Withdrawal amount of $" << money
				  << " exceeds your balance! "
				  << "Withdrawal is cancelled.\n";
	}

	RESTORE(ini, pre);
}

double BRASS::BALANCE(void) const
{
	return bal;
}

void BRASS::VIEW_NUM(void) const
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	std::cout << "Client: " << name << "\n";
	std::cout << "Account Number: " << num << "\n";
	std::cout << "Balance: " << bal << "\n";

	RESTORE(ini, pre);
}

// BRASSPLUS methods
BRASSPLUS::BRASSPLUS
(const std::string& m_name, long m_num, 
 double m_bal, double m_maxloan, double m_rate) : 
BRASS(m_name, m_num, m_bal)
{
	maxloan = m_maxloan;
	owe = 0.0;
	rate = m_rate;
}

BRASSPLUS::BRASSPLUS
(const BRASS& m_brass, double m_maxloan, double m_rate) :
BRASS(m_brass) // copy constructor
{
	maxloan = m_maxloan;
	owe = 0.0;
	rate = m_rate;
}

BRASSPLUS::~BRASSPLUS(void){}

void BRASSPLUS::VIEW_NUM(void) const
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	BRASS::VIEW_NUM(); // use base class method
	std::cout << "Maximum loan: $" << maxloan << "\n";
	std::cout << "Owed to bank: $" << owe << "\n";
	std::cout.precision(3);
	std::cout << "Loan rate: $" << 100*rate << "%\n";

	RESTORE(ini, pre);
}

void BRASSPLUS::WITHDRAW(double money)
{
	form ini = SETFORMAT();
	prec pre = std::cout.precision(2);

	double balance = BALANCE(); // access only through public
	if(money < balance)
		BRASS::WITHDRAW(money);
	else if(money <= balance+maxloan-owe)
	{
		double advance = money-balance;
		owe += advance*(1.0+rate);
		std::cout << "Bank advance: $" << advance << "\n";
		std::cout << "Bank advance: $" << advance*rate << "\n";
		DEPOSIT(advance);
		BRASS::WITHDRAW(money);
	}
	else
		std::cout << "Credit limit exceeded!"
				  << "Transaction cancelled.\n";

	RESTORE(ini, pre);
}
