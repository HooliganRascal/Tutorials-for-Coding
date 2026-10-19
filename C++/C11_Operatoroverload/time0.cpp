#include <iostream>
#include "time0.h"


TIME::TIME(void){
	hours = minutes = 0;
}

TIME::TIME(int h, int m){
	hours = h;
	minutes = m;
}

TIME::~TIME(void){} // destructor

void TIME::ADDMIN(int m){
	minutes += m;
	hours += minutes/60;
	minutes %= 60;
}

void TIME::ADDHOUR(int h){
	hours += h;
}

void TIME::RESET(int h, int m){
	hours = h;
	minutes = m;
}

TIME TIME::SUM(const TIME& t) const{
	TIME sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}

void TIME::SHOW(void) const{
	std::cout << hours << " hours " << minutes << " minutes\n";
}
