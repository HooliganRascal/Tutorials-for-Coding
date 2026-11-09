#ifndef TABLE0_H_
#define TABLE0_H_

#include <cstring>

class TABLE
{
private:
	std::string first;
	std::string last;
	bool has;

public:
	TABLE
	(const std::string& fn = "none",
	 const std::string& ln = "none", bool hs = false);
	void NAME(void) const;
	bool HAS(void) const{return has;}
	void RESET(bool v){ has = v;}
};

#endif
