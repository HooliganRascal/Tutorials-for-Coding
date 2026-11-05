#include <cstdlib>
#include "queue.h"

extern const int MIN_PER_HOUR = 60;

void UNIT::SETI(size_t WHEN)
{
	process = std::rand()%3+1; // random at 1~3
	arrival = WHEN;
}

QUEUE::QUEUE(int qsize):max_qsize(qsize)
{
	pfore = nullptr;
	pback = nullptr;
	num_units = 0;
}

QUEUE::~QUEUE(void)
{
	NODE* temp;
	while(pfore!=nullptr)
	{
		temp = pfore;
		pfore = pfore->next;
		delete temp; // clear previous pfore content
	}
}

bool QUEUE::IS_EMPTY(void) const
{
	return (num_units==0);
}

bool QUEUE::IS_FULLY(void) const
{
	return (num_units==max_qsize);
}

bool QUEUE::ADD_UNIT(const UNIT& unit)
{
	if(IS_FULLY())
		return false;

	NODE* add = new NODE;
	add->unit = unit;
	add->next = nullptr;
	++num_units;

	if(pfore == nullptr)
		pfore = add; // put it in the first if queue emtpy
	else
		// first added, pfore->next = add
		pback->next = add; // next is the end after added

	pback = add; // let the pback point to new node
	return true;
}
	
bool QUEUE::DEL_UNIT(UNIT& unit)
{
	if(pfore==nullptr)
		return false;

	unit = pfore->unit; // analyze unit to be done
	--num_units;

	NODE* temp = pfore;
	pfore = pfore->next; // pointer expliciation
	delete temp;

	if(num_units==0)
		pback = nullptr;

	return true;
}

int QUEUE::NUM_UNITS(void) const
{
	return num_units;
}

