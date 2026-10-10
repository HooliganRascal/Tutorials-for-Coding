#include<iostream>
#include"nsp.h"

inline void other(void){
	using namespace std; // namespace directive
	using namespace deb;

	struct person dg = {"Doodles", "Glister"};
	sper(dg);
	cout << endl;

	struct debts zippy[arsize];
	for(int i=0; i<arsize; ++i){
		gdeb(*(zippy+i));
	}
	for(int i=0; i<arsize; ++i){
		sdeb(*(zippy+i));
	}
	cout << "Total debts: $" << sumdeb(zippy, arsize) << endl;
}

inline void another(void){
	per::person col = {"Milo", "Rightshift"};
	per::sper(col);
	std::cout << std::endl;
}

int main(void){
	using deb::debts;
	using deb::sdeb;

	debts golf = {{"Cosmos", "Mteltn"}, 120.0};
	sdeb(golf);
	other();
	another();

	return 0;
}
