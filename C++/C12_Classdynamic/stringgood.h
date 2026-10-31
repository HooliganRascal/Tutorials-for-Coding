#ifndef STRINGGOOD_H_
#define STRINGGOOD_H_
#include <iostream>

class stringgood
{
private:
	char* str;
	int len;
	static int num_str;
	static const int LIM = 80;
public:
	stringgood(const char* s);
	stringgood(const stringgood& obj); // copy constructor
	stringgood(void); 
	~stringgood(void);

	inline int length(void){return len;}

	stringgood& operator=(const stringgood& obj);
	stringgood& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	friend bool 
		operator<(const stringgood& st1,const stringgood& st2); 
	friend bool 
		operator>(const stringgood& st1,const stringgood& st2); 
	friend bool 
		operator==(const stringgood& st1,const stringgood& st2); 
	friend std::ostream& 
		operator<<(std::ostream& os, const stringgood& obj);
	friend std::istream& 
		operator>>(std::istream& is, stringgood& obj);

	static int howmany(void);
};

#endif
