#include <cstring>
#include "stringbad.h"

int stringbad::num_str = 0; // initialization

stringbad::stringbad(const char* s){
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	num_str++;

	std::cout << num_str << ": \"" 
		      << str << "\" object created\n";
}

stringbad::stringbad(void){
	++num_str;
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");

	std::cout << num_str << ": \"" 
		      << str << "\" default object created\n";
}

stringbad::~stringbad(void){
	--num_str;
	std::cout << "\"" << str << "\" object deleted, "
	          << num_str << " objects left\n";
	delete [] str;
}

std::ostream& 
operator<<(std::ostream& os, const stringbad& stb){
	os << stb.str;
	return os;
}
