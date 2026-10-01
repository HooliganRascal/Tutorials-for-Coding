#ifndef COOR_H_
#define COOR_H_

const double pi=3.1415926535897;

struct pola{
	double r;
	double alpha; // radian
};

struct rect{
	double x;
	double y;
};

double dtor(double deg);
double rtod(double rad);
pola rtop(rect& xy);
rect ptor(pola& ra);
template<class type>void show(type var);
template<>void show<pola>(pola var);
template<>void show<rect>(rect var);

#endif
