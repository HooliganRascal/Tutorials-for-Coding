#ifndef TIME2_H_
#define TIME2_H_

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
		void SHOW(void) const;

		TIME operator+(const TIME& t) const;
		TIME operator-(const TIME& t) const;
		TIME operator*(double mult) const;
};
		
#endif
