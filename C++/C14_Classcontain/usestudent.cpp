#include <iostream>
#include "student.h"

void SET(STUDENT& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main(void)
{
	STUDENT ada[pupils] = 
	{
		STUDENT(quizzes), 
		STUDENT(quizzes), 
		STUDENT(quizzes)
	};

	for(int i=0; i<pupils; ++i)
		SET(ada[i], quizzes);

	std::cout << "\nStudent List:\n";
	for(int i=0; i<pupils; ++i)
		std::cout << ada[i].NAME() << std::endl;

	std::cout << "\nResults:";
	for(int i=0; i<pupils; ++i)
	{
		std::cout << "\n" << ada[i];
		std::cout << "Average: " << ada[i].AVG() << "\n";
	}

	std::cout << "Done!\n";
	return 0;
}

void SET(STUDENT& sa, int n)
{
	std::cout << "Please enter the student's name: ";
	getline(std::cin, sa);
	std::cout << "Please enter " << n << " quiz scores:\n";
	for(int i=0; i<n; ++i)
		std::cin >> sa[i];
	while(std::cin.get()!='\n')
		continue; // clear out input queue
}
