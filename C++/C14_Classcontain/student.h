#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <cstring>
#include <valarray>

class STUDENT
{
private:
	typedef	std::valarray<double> ARRAYDB;
	std::string name;
	ARRAYDB scores;

	// helper function
	std::ostream& array_out(std::ostream& os) const;

public:
	explicit inline STUDENT(const std::string& s) 
		: name(s), scores(){};
	explicit inline STUDENT(int n) 
		: name("NULL"), scores(n){};
	inline STUDENT(void) 
		: name("NULL"), scores(){};
	inline STUDENT(const std::string& s, int n) 
		: name(s), scores(n){};
	inline STUDENT(const std::string& s, const ARRAYDB& a) 
		: name(s), scores(a){};
	inline STUDENT(const char* str, const double* pd, int n) 
		: name(str), scores(pd,n){};
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
