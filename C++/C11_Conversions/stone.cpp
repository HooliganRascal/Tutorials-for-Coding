#include <iostream>
#include "stonewt.h"

void display(const STONEWT& st, int n);

int main(void){
	STONEWT incognito = 275;
	STONEWT wolfe(285.7);
	STONEWT taft(21, 8);

	std::cout << "The celebrity weighed ";
	incognito.show_stn();
	std::cout << "The detective weighed ";
	wolfe.show_stn();
	std::cout << "The president weighed ";
	taft.show_stn();

	incognito = 276.8; // auto conversion
	taft =325; // auto conversion(int-double-STONE)

	std::cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();
	std::cout << "After dinner, the president weighed ";
	taft.show_lbs();

	display(taft, 2);
	std::cout << "The wrestler weighed even more.\n";
	display(422,2); // int-double-STONE
	std::cout << "No stone left unearned.\n";

	return 0;
}

void display(const STONEWT& st, int n){
	for(int i=0; i<n; ++i){
		std::cout << "Wow! ";
		st.show_stn();
	}
}
