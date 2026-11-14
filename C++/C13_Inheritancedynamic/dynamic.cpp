#include <iostream>
#include <cstring>
#include "dynamic.h"

// base class methods
BASE::BASE(const char* l, int r)
{
	label = new char[std::strlen(l)+1]; // strlen doesn't count '\0'
	std::strcpy(label, l);
	rate = r;
}

BASE::BASE(const BASE& bs)
{
	label = new char[std::strlen(bs.label)+1]; // inside class
	std::strcpy(label, bs.label); // access private members directly
	rate = bs.rate;
}

BASE::~BASE(void)
{
	delete [] label;
}

BASE& BASE::operator=(const BASE& bs)
{
	if(this==&bs)
		return *this;

	delete [] label;
	label = new char[std::strlen(bs.label)+1];
	std::strcpy(label, bs.label);
	rate = bs.rate;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BASE& bs)
{
	os << "Label: " << bs.label << std::endl;
	os << "Rate: " << bs.rate << std::endl;
	return os;
}

// derived class methods without dynamic memory allocation
NODM::NODM(const char* c, const char* l, int r) : BASE(l,r)
{
	std::strncpy(color, c, LEN-1);
	color[LEN-1]='\0';
}

NODM::NODM(const char* c, const BASE& bs) : BASE(bs)
{
	std::strncpy(color, c, LEN-1);
	color[LEN-1]='\0';
}

std::ostream& operator<<(std::ostream& os, const NODM& nd)
{
	os << (const BASE&) nd;
	os << "Color: " << nd.color << std::endl;
	return os;
}

// derived class methods with dynamic memory allocation 
YEDM::YEDM(const char* s, const char* l, int r) : BASE(l,r)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
}

YEDM::YEDM(const char* s, const BASE& bs) : BASE(bs)
{
	style = new char[std::strlen(s)+1];
	std::strcpy(style, s);
}

YEDM::YEDM(const YEDM& yd) : BASE(yd)
{
	style = new char[std::strlen(yd.style)+1];
	std::strcpy(style, yd.style);
}

YEDM::~YEDM(void)
{
	delete [] style;
}

YEDM& YEDM::operator=(const YEDM& yd)
{
	if(this==&yd)
		return *this;

	BASE::operator=(yd); // do the base class portion
	delete [] style;
	style = new char[std::strlen(yd.style)+1];
	std::strcpy(style, yd.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const YEDM& yd)
{
	os << (const BASE&) yd;
	os << "Style: " << yd.style<< std::endl;
	return os;
}
