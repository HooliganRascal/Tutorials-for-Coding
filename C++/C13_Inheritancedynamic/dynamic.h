#ifndef DYNAMIC_H_
#define DYNAMIC_H_
#include <iostream>

class BASE
{
private:
	char* label;
	int rate;

public:
	// strlen(nullptr) undefined! don't initialize l as nullptr!
	BASE(const char* l="", int r=0);
	BASE(const BASE& bs);
	virtual ~BASE(void);

	BASE& operator=(const BASE& bs);
	friend 
	std::ostream& operator<<(std::ostream& os, const BASE& bs);
};

// derived class without dynamic memory allocation
class NODM : public BASE
{
private:
	static const int LEN=40; 
	char color[LEN];

public:
	NODM(const char* c="blank", const char* l="", int r=0);
	NODM(const char* c, const BASE& bs);
	inline virtual ~NODM(void){};

	friend 
	std::ostream& operator<<(std::ostream& os, const NODM& nd);
};

// derived class with dynamic memory allocation
class YEDM : public BASE
{
private:
	char* style;

public:
	YEDM(const char* s="blank", const char* l="", int r=0);
	YEDM(const char* s, const BASE& bs);
	YEDM(const YEDM& yd);
	virtual ~YEDM(void);

	YEDM& operator=(const YEDM& yd);
	friend 
	std::ostream& operator<<(std::ostream& os, const YEDM& yd);
};

#endif
