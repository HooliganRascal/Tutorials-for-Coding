#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>

class stringbad{
	private:
		char* str; // not allocate storage space
		int len;
		static int num_str;
	public:
		stringbad(const char* str);
		stringbad(void); ~stringbad(void);
		friend std::ostream& 
		operator<<(std::ostream& os, const stringbad& stb);
};

#endif
