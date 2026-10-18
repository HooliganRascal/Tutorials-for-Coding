#ifndef STACK_H_
#define STACK_H_

typedef unsigned long item; // general type of stack

class stack{
	private:
		enum {limit=10};
		item items[limit];
		int top;
	public:
		stack(void);
		bool isempty(void) const;
		bool isfull(void) const;
		bool push(const item& neo); // false if the stack is full
		bool pop(item& neo); // false if the stack is empty
};

#endif
