#ifndef TIME1_H_
#define TIME1_H_

class TIME{
	private:
		int hours;
		int minutes;
	public:
		TIME(void);
		TIME(int h, int m=0);
		~TIME(void);

		void ADDMIN(int m);
		void ADDHOUR(int h);
		void RESET(int h=0, int m=0);
		TIME operator+(const TIME& t) const;
		void SHOW(void) const;
};
		
#endif
