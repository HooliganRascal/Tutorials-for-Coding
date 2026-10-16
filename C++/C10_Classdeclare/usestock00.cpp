#include <iostream>
#include "stock00.h"

int main(void){
	stock test;

	test.acquire("Mteltn Cosmos", 20, 12.45);
	test.show();
	test.buy(15, 15.5);
	test.show();
	test.sell(50, 20.0);
	test.show();
	test.buy(3000, 40.125);
	test.show();
	test.sell(50, 60.1);
	test.show();
	
	return 0;
}
