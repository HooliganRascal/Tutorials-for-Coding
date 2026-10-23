#include <cmath>
#include "vect.h"

void vect::VECTOR::set_r(void){
	r = std::sqrt(x*x+y*y);
}

void vect::VECTOR::set_w(void){
	if(x==0 && y==0)
		w = 0.0;
	else
		w = std::atan2(y,x);
}

void vect::VECTOR::set_x(void){
	x = r*std::cos(w);
}

void vect::VECTOR::set_y(void){
	y = r*std::sin(w);
}

// Constructor and Destructor
vect::VECTOR::VECTOR(void){
	x = y = r = w = 0.0;
	mode = RECT;
}
vect::VECTOR::VECTOR(double n1, double n2, vect::VECTOR::MODE form){
	mode = form;
	if (form==RECT){
		x = n1;
		y = n2;
		set_r();
		set_w();
	}
	else if (form==POLA){
		r = n1;
		w = n2*vect::deg_to_rad;
		set_x();
		set_y();
	}
	else{
		std::cout << "Incorrect 3rd argumemt to VECTOR() -- "
				  << "vector set to 0\n";
		x = y = r = w = 0.0;
	}
}
vect::VECTOR::~VECTOR(void){}

// Interface
void vect::VECTOR::reset(double n1, double n2, MODE form){
	mode = form;
	if (form==RECT){
		x = n1;
		y = n2;
		set_r();
		set_w();
	}
	else if (form==POLA){
		r = n1;
		w = n2*vect::deg_to_rad;
		set_x();
		set_y();
	}
	else{
		std::cout << "Incorrect 3rd argumemt to VECTOR() -- "
				  << "vector set to 0\n";
		x = y = r = w = 0.0;
	}
}

void vect::VECTOR::mode_pola(void){mode = POLA;}
void vect::VECTOR::mode_rect(void){mode = RECT;}

// Operator Overloading
vect::VECTOR 
vect::VECTOR::operator+(const vect::VECTOR& b) const{
	return VECTOR(x+b.x, y+b.y);
}

vect::VECTOR 
vect::VECTOR::operator-(const vect::VECTOR& b) const{
	return VECTOR(x-b.x, y-b.y);
}

vect::VECTOR 
vect::VECTOR::operator-(void) const{
	return VECTOR(-x, -y);
}

vect::VECTOR 
vect::VECTOR::operator*(double n) const{
	return VECTOR(n*x,n*y);
}

vect::VECTOR 
vect::operator*(double n, const vect::VECTOR& a){
	return a*n;
}

std::ostream& 
vect::operator<<(std::ostream& os, const vect::VECTOR& v){
	if (v.mode == vect::VECTOR::RECT){
		os << "(x,y) = (" 
		   << v.x << ", " 
		   << v.y << ")";
	}
	else if (v.mode == vect::VECTOR::POLA){
		os << "(r,w) = (" 
		   << v.r << ", "
		   << v.w*vect::rad_to_deg 
		   << ")";
	}
	else
		os << "Vector object mode is invalid";
	return os;
}
