#include <iostream>
#include <cstring>
#include <new>

namespace testnew{
	const int BUFFER = 512;
	class TEST
	{
	private:
		std::string words;
		int number;
	public:
		inline 
		TEST(const std::string& s = "Just Testing", int n = 0){
			words = s;
			number = n;
			std::cout << words << " constructed\n";
		}
		inline 
		~TEST(void){
			std::cout << words << " destroyed\n";
		}
		inline 
		void SHOW(void){
			std::cout << words << ", " << number << "\n";
		}
	};
}

int main(void){
	char* buffer = new char[testnew::BUFFER];

	testnew::TEST *pc1, *pc2;
	pc1 = new (buffer) testnew::TEST; // default constructor
	pc2 = new testnew::TEST("Heap1", 20);

	std::cout << std::endl;
	std::cout << "Memory block address:\n" 
			  << "Buffer: " << (void*) buffer << "\t"
			  << "Heap: " << pc2 << "\n";

	std::cout << "Memory contents:\n";
	std::cout << pc1 << ": "; // print the address?
	pc1->SHOW();	
	std::cout << pc2 << ": ";
	pc2->SHOW();	
	std::cout << std::endl;

	testnew::TEST *pc3, *pc4;
	pc3 = new (buffer+sizeof(testnew::TEST)) 
			 testnew::TEST("Better Idea", 6);
	pc4 = new testnew::TEST("Heap2", 10);
	std::cout << std::endl;

	std::cout << "Memory contents:\n";
	std::cout << pc3 << ": "; 
	pc3->SHOW();	
	std::cout << pc4 << ": ";
	pc4->SHOW();	

	pc1->~TEST();
	pc3->~TEST();
	delete pc2;
	delete pc4;
	delete [] buffer;

	return 0;
}

