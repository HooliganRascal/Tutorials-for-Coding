#ifndef QUEUE_H_
#define QUEUE_H_

extern const int MIN_PER_HOUR;

class UNIT
{
private:
	size_t arrival;
	size_t process;
public:
	UNIT(void){arrival = process = 0;}
	size_t WHEN(void){return arrival;}
	size_t TIME(void){return process;}
	void SETI(size_t WHEN);
};

class QUEUE
{
private:
	struct NODE
	{
		UNIT unit;
		struct NODE* next; // link building
	};
	static const int QSIZE = 10;

	NODE* pfore;
	NODE* pback;
	int num_units;
	const int max_qsize;

	// prevent public copying
	QUEUE(const QUEUE& q):max_qsize(0){} 
	QUEUE& operator=(const QUEUE& q){return *this;}

public:
	QUEUE(int qsize = QSIZE);
	~QUEUE(void);

	bool IS_EMPTY(void) const;
	bool IS_FULLY(void) const;
	bool ADD_UNIT(const UNIT& unit);
	bool DEL_UNIT(UNIT& unit);
	int NUM_UNITS(void) const;
};

#endif
