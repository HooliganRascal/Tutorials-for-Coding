#ifndef STONEWT_H_
#define STONEWT_H_

class STONEWT{
	private:
		enum {lbs_per_stn = 14}; // pounds per stone
		int stone;
		double pds_left; // fractional pounds 
		double pounds; // entire weight in pounds
	public:
		STONEWT(double lbs); // pounds
		STONEWT(int stn, double lbs); // stone, lbs
		STONEWT(void);
		~STONEWT(void);

		void show_lbs(void) const; // in pounds
		void show_stn(void) const; // in stone
};

#endif
