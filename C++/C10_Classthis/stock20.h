#ifndef STOCK20_H_
#define STOCK20_H_

#include <cstring>

class stock{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;

		inline void set_tot(void){
			total_val = shares * share_val;
		}

	public:
		stock(); 
		stock(const std::string& co, long n=0, double pr=0.0);
		~stock();
				  
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show(void)const;
		const stock& topval(const stock& e) const;
};

#endif
