#include <iostream>
#include "stock00.h"

void stock::acquire(const std::string& co, long n, double pr){
	company = co;
	if(n<0){
		std::cout << "Number of shares can't be negative! "
				  << company << " shares set to 0.\n ";
		shares = 0;
	}
	else{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

void stock::buy(long num, double price){
	if(num<0){
		std::cout << "Number of shares purchased can't be negative! "
				  << "Transaction aborted.\n\n";
	}
	else{
		shares += num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::sell(long num, double price){
	using std::cout;
	if(num<0){
		cout << "Number of shares can't be negative!"
			 << "Transaction aborted.\n\n";
	}
	else if(num>shares){
		cout << "You can't sell more than you have! "
			 << "Transaction aborted.\n\n";
	}
	else{
		shares -= num; // access members in private
		share_val = price;
		set_tot();
	}
}

void stock::update(double price){
	share_val = price;
	set_tot();
}

void stock::show(void){
	std::ios_base::fmtflags	orig = std::cout.setf(
			std::ios_base::fixed, 
			std::ios_base::floatfield
			);
	std::streamsize prec = std::cout.precision(3);

	std::cout << "Company: " << company
			  << "Shares: " << shares << "\n"
			  << "Share Price: $" << share_val << "\n";
	std::cout.precision(2);
	std::cout << "Total Worth: $" << total_val << "\n";
	std::cout << std::endl;

	std::cout.setf(orig, std::ios_base::floatfield);
	std::cout.precision(prec);
}
