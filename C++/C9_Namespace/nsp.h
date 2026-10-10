#include<string>
#ifndef NSP_H
#define NSP_H

namespace per{
	struct person{
		std::string fname;
		std::string lname;
	};
	void gper(person&);
	void sper(const person&);
}

namespace deb{
	using namespace per;
	struct debts{
		person name;
		double amount;
	};
	void gdeb(debts&);
	void sdeb(const debts&);
	double sumdeb(const debts* ar, int n);
}

const int arsize = 3;

#endif
