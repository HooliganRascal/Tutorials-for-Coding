#include<iostream>

using namespace std;

// Union
union ofa{
	int int1;
	int int2;
	long long1;
	double double1;
};

// Anonymous union
struct stu{
	int type;
	union {
		long id_long;
		long id_long2;
		double id_double;
	};
};

// Enumeration
enum spec{red, orange, yellow, green, blue, purple, violet};
enum {a, b, c, d, e, f, g};
enum bits{one=1, two=2, three=3, four=4, five=5, six=6, seven=7};
enum succ{zero, thous=1000, thousnext}; // thousnext=1001
enum repe{null, nullz=0, onext, nexto=1}; // Same value for different variable

int main(void){
	
	ofa testofa; // Union
	stu teststu; // Anonymous union in structure
	spec color = orange; // Enumeration
	spec testcol = spec(3); // Number from 0 to 7
	int testicol = spec(2); // Assigned to integers
	int testjcol = d; // Enumeration name omitted
	int testbit = one; // Reorder the number
	succ testsuc = succ(1023); // Assign with values in the range power of 2


	// Union: Forget original int1 == int2, messed up
	testofa.int1 = 2;
	testofa.int2 = 4;
	testofa.double1 = 6.2;
	cout << testofa.int1 << endl;
	cout << testofa.int2 << endl;
	cout << testofa.double1 << endl;

	// Anonymous Union: Forget original id_long == id_long2, messed up
	teststu.id_long = 5;
	teststu.id_long2 = 10;
	teststu.id_double = 6.1;
	cout << teststu.id_long << endl;
	cout << teststu.id_long2 << endl;
	cout << teststu.id_double << endl;

	// Output enumerations
	cout << yellow << endl;
	cout << color << endl;
	cout << testcol << endl;
	cout << testicol << endl;
	cout << testjcol << endl;
	cout << testbit << endl;
	cout << "zero is " << zero 
		 << " and thous is " << thous 
		 << ", thousnext is " << thousnext << endl;
	cout << "Repeat null = " << null << " and nullz = " << nullz << endl;
	cout << "Enumeration in the range like " << testsuc << endl;

	return 0;
}
