#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace vect{
	class VECTOR{
		// variables
		public:
			enum MODE{
				RECT, 
				POLA
			};
		private:
			double x,y; // x-coor, y-coor
			double r,w; // magnitude, angle(radian)
			MODE mode;
		
		// function
		private:
			void set_r(void);
			void set_w(void);
			void set_x(void);
			void set_y(void);
		public:
			// constructor and destructor
			VECTOR(void);
			VECTOR(double n1, double n2, MODE form=RECT);
			~VECTOR(void);

			// basic interface
			void reset(double n1, double n2, MODE form=RECT);
			inline double xval(void) const{return x;};
			inline double yval(void) const{return y;};
			inline double rval(void) const{return r;};
			inline double wval(void) const{return w;};

			// mode transfer
			void mode_pola(void);
			void mode_rect(void);

			// overloading
			VECTOR operator+(const VECTOR& b) const;
			VECTOR operator-(const VECTOR& b) const;
			VECTOR operator-(void) const; // negation
			VECTOR operator*(double n) const; 
			
			// friend functions
			friend VECTOR operator*(
					double n, 
					const VECTOR& a
				);
			friend std::ostream& operator<<(
					std::ostream& os, 
					const VECTOR& v
				);
	};

	const double pi = 3.1415926535897;
	const double rad_to_deg = 180.0/pi;
	const double deg_to_rad = pi/180.0;

	VECTOR operator*(
			double n, 
			const VECTOR& a
		);
	std::ostream& operator<<(
			std::ostream& os, 
			const VECTOR& v
		);
}

#endif
