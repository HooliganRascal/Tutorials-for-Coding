#include<iostream>
#include<array>

using namespace std;

const int season = 4;
const array<string,season> snames = {
	"Spring",
	"Summber",
	"Autumn",
	"Winter"
};

void fill(array<double,season>*); // Pass the address
void show(array<double,season>);  // Pass the name

int main(void){
	array<double,season> expense;
	fill(&expense);
	show(expense);
	return 0;
}

void fill(array<double,season>* expense){
	for(int i=0; i<season; ++i){
		cout << "Enter " << snames[i] << " expenses: ";
		cin >> (*expense)[i];
	}
}

void show(array<double,season> expense){
	double total = 0.0;
	cout << endl << "EXPENSES:" << endl;
	for(int i=0; i<season; ++i){
		cout << snames[i] << ": " << expense[i] << endl;;
		total += expense[i];
	}
	cout << endl << "Total expense:" << total << endl;
}
