#include <iostream>
#include "stonewt.h"

STONEWT::STONEWT(double lbs){
	stone = int(lbs) / lbs_per_stn;
	pds_left = int(lbs)%lbs_per_stn + lbs-int(lbs);
	pounds = lbs;
}

STONEWT::STONEWT(int stn, double lbs){
	stone = stn;
	pds_left = lbs;
	pounds = stn*lbs_per_stn + lbs;
}

STONEWT::STONEWT(void){
	stone = pounds = pds_left = 0;
}

STONEWT::~STONEWT(void){}

void STONEWT::show_stn(void) const{
	std::cout << stone << " stone, " 
		      << pds_left << " pounds\n";
}

void STONEWT::show_lbs(void) const{
	std::cout << pounds << " pounds\n";
}
