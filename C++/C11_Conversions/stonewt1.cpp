#include <iostream>
#include "stonewt1.h"

STONEWT1::STONEWT1(double lbs){
	stone = int(lbs) / lbs_per_stn;
	pds_left = int(lbs)%lbs_per_stn + lbs-int(lbs);
	pounds = lbs;
}

STONEWT1::STONEWT1(int stn, double lbs){
	stone = stn;
	pds_left = lbs;
	pounds = stn*lbs_per_stn + lbs;
}

STONEWT1::STONEWT1(void){
	stone = pounds = pds_left = 0;
}

STONEWT1::~STONEWT1(void){}

void STONEWT1::show_stn(void) const{
	std::cout << stone << " stone, " 
		      << pds_left << " pounds\n";
}

void STONEWT1::show_lbs(void) const{
	std::cout << pounds << " pounds\n";
}

STONEWT1::operator int(void) const{return int(pounds+0.5);}
STONEWT1::operator double(void) const{return pounds;}
