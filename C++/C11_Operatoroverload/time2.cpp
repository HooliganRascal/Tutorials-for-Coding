#include <iostream>
#include "time2.h"

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

void TIME::SHOW(void) const{
	std::cout << hours << " hours " << minutes << " minutes\n";
}

TIME TIME::operator+(const TIME& t) const{
	TIME sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}

TIME TIME::operator-(const TIME& t) const{
	TIME diff;
	int tot1 = t.minutes + 60*t.hours; // to subtract
	int tot2 = minutes + 60*hours; // to be subtracted
	diff.minutes = (tot2-tot1)%60;
	diff.hours = (tot2-tot1)/60;
	return diff;
}

TIME TIME::operator*(double mult) const{
	TIME result;
	long totalmin = hours*mult*60+minutes*mult;
	result.minutes = totalmin%60;
	result.hours = totalmin/60;
	return result;
}
