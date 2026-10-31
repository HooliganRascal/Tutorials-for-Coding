#include <cstring>
#include <iostream>
#include "stringgood.h"

int stringgood::num_str = 0; // static member
int stringgood::howmany(void){
	return num_str;
} // static member function

stringgood::stringgood(const char* s){
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	num_str++;
}

stringgood::stringgood(void){
	++num_str;
	len = 1;
	str = new char[1];
	str[0] = '\0'; // or str = nullptr, or str = 0
}

stringgood::stringgood(const stringgood& obj){
	++num_str;
	len = obj.len;
	str = new char[len+1];
	std::strcpy(str, obj.str);
}// copy constructor

stringgood::~stringgood(void){
	--num_str;
	delete [] str;
}


stringgood& stringgood::operator=(const stringgood& obj){
	if(this == &obj)
		return *this;
	delete [] str;
	len = obj.len;
	str = new char[len+1];
	std::strcpy(str, obj.str);
	return *this;
}

stringgood& stringgood::operator=(const char* s){
	delete [] str;
	len = std::strlen(s);
	str = new char[len+1];
	std::strcpy(str, s);
	return *this;
}

char& stringgood::operator[](int i){
	return str[i];
}

const char& stringgood::operator[](int i) const{
	return str[i];
}


bool operator<(const stringgood& st1,const stringgood& st2){
	return (std::strcmp(st1.str, st2.str)<0);
}
bool operator>(const stringgood& st1,const stringgood& st2){
	return (st2<st1);
}
bool operator==(const stringgood& st1,const stringgood& st2){
	return (std::strcmp(st1.str, st2.str)==0);
}

std::ostream& 
operator<<(std::ostream& os, const stringgood& obj){
	os << obj.str;
	return os;
}

std::istream& 
operator>>(std::istream& is, stringgood& obj){
	char temp[stringgood::LIM];
	is.get(temp, stringgood::LIM);
	if(is)
		obj = temp;
	while(is && (is.get()!='\n'))
		continue;
	return is;
}

