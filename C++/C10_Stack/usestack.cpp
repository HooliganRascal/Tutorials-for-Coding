#include <iostream>
#include <cctype>
#include "stack.h"

int main(void){
	stack st;
	char ch;
	unsigned long po;

	std::cout << "Enter A to add a purchase order,\n"
			  << "Enter P to process a PO, \n"
			  << "Enter Q to quit \n";
	std::cout << std::endl;

	while((std::cin>>ch)&&(toupper(ch)!='Q')){
		while(std::cin.get()!='\n'){
			continue;
		}// empty the waste invalid input in the queue
		if(!isalpha(ch)){
			std::cout << "\a"
					  << "Please enter a valid letter,\n"
					  << "Enter A to add a purchase order,\n"
					  << "Enter P to process a PO, \n"
			  		  << "Enter Q to quit \n";
			std::cout << std::endl; 
			continue;
		}
		switch(ch){
			case 'A':
			case 'a': std::cout << "Enter a PO number to add: ";
					  std::cin >> po;
					  if(st.isfull()){
						  std::cout << "Stack already full\n";
					  }
					  else{
						  st.push(po);
					  }
					  break;
			case 'p':
			case 'P': if(st.isempty()){
						  std::cout << "Stack already empty\n";
					  }
					  else{
						  st.pop(po);
						  std::cout << "PO #" << po << " popped\n";
					  }
					  break;
		}

		std::cout << std::endl;
	//	std::cout << "Enter A to add a purchase order,\n"
	//  		  << "Enter P to process a PO, \n"
	//		      << "Enter Q to quit \n";
	}
	std::cout << "Bye!\n";

	return 0;
}
