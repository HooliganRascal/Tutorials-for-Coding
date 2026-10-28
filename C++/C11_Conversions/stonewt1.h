#ifndef STONEWT1_H_
#define STONEWT1_H_

class STONEWT1{
	private:
		enum {lbs_per_stn = 14}; // pounds per stone
		int stone;
		double pds_left; // fractional pounds 
		double pounds; // entire weight in pounds
	public:
		STONEWT1(double lbs); // pounds
		STONEWT1(int stn, double lbs); // stone, lbs
		STONEWT1(void);
		~STONEWT1(void);

		void show_lbs(void) const; // in pounds
		void show_stn(void) const; // in stone

		// conversion
		operator int(void) const;
		operator double(void) const;
};

#endif
