#ifndef TIME3_H_
#define TIME3_H_
#include <iostream>

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
		TIME operator-(const TIME& t) const;
		TIME operator*(double mult) const;
		friend inline TIME operator*(double mult, const TIME& t){
			return t*mult;
		}
		friend std::ostream& operator<<(
			std::ostream& os, 
			const TIME&t
		);
};
		
#endif
