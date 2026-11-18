#include "student.h"

// private method
std::ostream& STUDENT::array_out(std::ostream& os) const
{
	int i;
	int lim = scores.size();
	if(lim > 0)
	{
		for(i=0; i<lim; ++i)
		{
			os << scores[i] << " ";
			if(i%5==4) // display 5 grades for one row
				os << std::endl;
		}
		// if right at 5 grades, endl is up there, else newline
		if(i%5!=0) 
			os << std::endl;
	}
	else
		os << " empty array " ;
	return os;
}

// public method
const std::string& STUDENT::NAME(void) const
{
	return name;
}

double STUDENT::AVG(void) const
{
	if(scores.size()>0)
		return scores.sum()/scores.size();
	else
		return 0; // size error
}

double& STUDENT::operator[](int i)
{
	// matching return type of valarray<double>::operator[]()
	return scores[i]; 
}

double STUDENT::operator[](int i) const // for const STUDENT
{
	return scores[i];
}

// friend functions
std::istream& operator>>(std::istream& is, STUDENT& stu)
{
	is >> stu.name;
	return is;
}

std::istream& getline(std::istream& is, STUDENT& stu)
{
	getline(is,	stu.name);
	return is;
}

std::ostream& operator<<(std::ostream& os, const STUDENT& stu)
{
	os << "Scores for " << stu.name << ":\n";
	stu.array_out(os);
	return os;
}
