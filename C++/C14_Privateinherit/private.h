#ifndef PRIVATE_H_
#define PRIVATE_H_

#include <iostream>
#include <cstring>
#include <valarray>

class STUDENT : 
private std::string, private std::valarray<double>
{
private:
	typedef	std::valarray<double> ARRAYDB;
	std::ostream& array_out(std::ostream& os) const;

public:
	explicit inline STUDENT(const std::string& s) 
		: std::string(s), ARRAYDB(){};
	explicit inline STUDENT(int n) 
		: std::string("NULL"), ARRAYDB(n){};
	inline STUDENT(void) 
		: std::string("NULL"), ARRAYDB(){};
	inline STUDENT(const std::string& s, int n) 
		: std::string(s), ARRAYDB(n){};
	inline STUDENT(const std::string& s, const ARRAYDB& a) 
		: std::string(s), ARRAYDB(a){};
	inline STUDENT(const char* str, const double* pd, int n) 
		: std::string(str), ARRAYDB(pd,n){};
	inline ~STUDENT(void){};

	const std::string& NAME(void) const;
	double AVG(void) const;
	double& operator[](int i); // for STUDENT as lvalue
	double operator[](int i) const; // for const STUDENT

	friend std::istream& operator>>
		(std::istream& is, STUDENT& stu); // 1 word
	friend std::istream& getline
		(std::istream& is, STUDENT& stu); // 1 line
	friend std::ostream& operator<<
		(std::ostream& os, const STUDENT& stu);
};

#endif
