#ifndef TABLE1_H_
#define TABLE1_H_

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
	void RETABLE(bool v){ has = v;}
};


class RATED : public TABLE
{
private:
	unsigned int rating;

public:
	RATED
	(unsigned int r=0, const std::string& fn = "none",
	 const std::string& ln = "none", bool hs = false);
	RATED(unsigned int r, const TABLE& t);

	unsigned int RATING(void) const{return rating;}
	void RERATED(unsigned int r){rating = r;}
};

#endif

