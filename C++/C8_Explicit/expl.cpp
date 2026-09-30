#include<iostream>

using namespace std;

struct job{
	char name[40];
	double salary;
	int floor;
};

template<class T>void SWAP(T& a, T& b);
template<>void SWAP<job>(job& a, job& b); // Explicit specilization
void show(job& j);

int main(void){

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);

	int i=10; 
	int j=20;
	cout << "Before: i=" << i << ", j=" << j << endl;
	SWAP(i,j); // Use template<class T>void SWAP(T& a, T& b)
	cout << "Current: i=" << i << ", j=" << j << endl;

	job j1 = {"Mteltn", 3600.21, 4};
	job j2 = {"Cosmos", 7200.17, 6};
	cout << "Before: " << endl;
	show(j1);
	show(j2);
	SWAP(j1,j2); // Use template<>void SWAP<job>(job& a, job& b)
	cout << "Current: " << endl;
	show(j1);
	show(j2);

	return 0;
}

template<class T>void SWAP(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<>void SWAP<job>(job& a, job& b){

	double t1;
	int t2;

	t1 = a.salary;
	a.salary = b.salary;
	b.salary = t1;

	t2 = a.floor;
	a.floor = b.floor;
	b.floor = t2;
}

void show(job& j){
	cout << j.name 
		 << ": &" << j.salary 
		 << " on floor " << j.floor 
		 << endl;
}

