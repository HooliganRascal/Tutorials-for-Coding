#include<iostream>
#include"nsp.h"

namespace per{
	using std::cout;
	using std::cin;
	using std::endl;

	void gper(struct person& pr){
		cout << "Enter first name: ";
		cin >> pr.fname;
		cout << "Enter last name: ";
		cin >> pr.lname;
	}

	// define inside
	void sper(const struct person& pr){
		cout << pr.lname << " " << pr.fname;
	}
}

namespace deb{
	void gdeb(struct debts& db){
		gper(db.name); // in nsp.h, deb has mentioned using namespace per
		std::cout << "Enter debt: ";
		std::cin >> db.amount;
	}
	void sdeb(const struct debts& db){
		sper(db.name); 
		std::cout << ": $" << db.amount << std::endl;
	}
}

// define outside
double deb::sumdeb(const deb::debts* ar, int n){
	double total = 0;
	for(int i=0; i<n; ++i){
		total += (ar+i)->amount;
	}
	return total;
}
