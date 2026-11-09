#include <iostream>
#include "table1.h"

// Base class
TABLE::TABLE
(const std::string& fn, const std::string& ln, bool hs) : 
first(fn),last(ln),has(hs)
{
}

void TABLE::NAME(void) const
{
	std::cout << last << ", " << first;
}

// Derived class
RATED::RATED
(unsigned int r, const std::string& fn,
 const std::string& ln, bool hs) : TABLE(fn, ln, hs)
{
	rating = r;
}

RATED::RATED
(unsigned int r, const TABLE& t) : TABLE(t), rating(r)
{
}
