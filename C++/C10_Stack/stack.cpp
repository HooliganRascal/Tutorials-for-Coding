#include "stack.h"
 
stack::stack(void){
	top=0;
}

bool stack::isempty(void) const{
	return top==0;
}

bool stack::isfull(void) const{
	return top==limit;
}

bool stack::push(const item& neo){
	if(top<limit){
		*(items+top) = neo; // overwrite
		++top;
		return true;
	}
	else{
		return false;
	}
}

bool stack::pop(item& neo){
	if(top>0){
		--top;
		neo = *(items+top);
		return true;
	}
	else{
		return false;
	}
}	
