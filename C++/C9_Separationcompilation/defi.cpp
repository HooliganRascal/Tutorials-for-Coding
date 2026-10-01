#include<iostream>
#include<cmath>
#include"coor.h"

pola rtop(rect& xy){
	
	pola ans;
	ans.r = sqrt(xy.x*xy.x + xy.y*xy.y);
	ans.alpha = atan2(xy.y, xy.x);
	ans.alpha = rtod(ans.alpha);
	
	return ans;
}

rect ptor(pola& ra){

	rect ans;
	ra.alpha = dtor(ra.alpha);
	ans.x = ra.r*cos(ra.alpha);
	ans.y = ra.r*sin(ra.alpha);

	return ans;
}

double dtor(double deg){
	return deg*pi/180.0;
}

double rtod(double rad){
	return rad*180/pi;
}

template<>void show<pola>(pola var){

	using namespace std;

	cout << "Polar coordinates: " << endl;
	cout << "Radius: " << var.r << endl;
	cout << "Angle: " << var.alpha << " deg" << endl;
}

template<>void show<rect>(rect var){

	using namespace std;

	cout << "Rectangular coordinates: " << endl;
	cout << "X-coord: " << var.x << endl;
	cout << "Y-coord: " << var.y << endl;
}
