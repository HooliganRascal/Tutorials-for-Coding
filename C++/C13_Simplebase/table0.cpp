#include <iostream>
#include "table0.h"

TABLE::TABLE
(const std::string& fn ,
 const std::string& ln , bool hs) :
first(fn),last(ln),has(hs){}

void TABLE::NAME(void) const
{
	std::cout << last << ", " << first;
}
