#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

const int LIMIT=5;

const string& conca(string& s1, const string& s2);
void fit(ostream& os, double fo, const double* fe, int n);

int main(void){

	string input;
	string copy;
	string result;

	double objective;
	double eps[LIMIT];
	ofstream fout;
	const char* fn="ep-data.txt";

	cout << "Enter a string: ";
	getline(cin,input); // cin uses reference for basic type
	cout << "Your string as entered: " << input << endl;
	copy = input;

	// result 1
	result = conca(input, copy); // pass string objects
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	// result2
	result = conca(input, "***"); // pass string objects
	cout << "Your string enhanced by C-string: " << result << endl;
	cout << "Your original string by C-string: " << input << endl;

	// class object inheritation
	fout.open(fn);
	cout << "Enter the focal length of your telescope in mm: ";;
	cin >> objective;
	cout << "Enter the focal lengths of " << LIMIT << " eyepieces: "<< endl;
	for(int i=0; i<LIMIT; ++i){
		cout << "Eyepiece #" << i+1 << ": ";
		cin >> eps[i];
	}
	fit(fout, objective, eps, LIMIT);
	fit(cout, objective, eps, LIMIT);
	fout.close();

	return 0;
}

const string& conca(string& s1, const string& s2){
	s1 = s2 + s1 + s2;
	return s1;
}

void fit(ostream& os, double fo, const double* fe, int n){

	// define the settings needed to be recovered
	ios_base::fmtflags initial;

	// fixed decimal-point notation
	initial = os.setf(ios_base::fixed); // return a copy of format settings

	os.precision(0); // number of figures to the right of the decimal fixed
	os << "Focal length of objective: " << fo << " mm" << endl;

	// showing a trailing decimal point
	os.setf(ios::showpoint); 

	os.precision(1);
	os.width(12); // field width to be used for the next output action
	os << "f.l.eyepiece";
	os.width(15);
	os << "Magnification" << endl;
	for(int i=0; i<n; ++i){
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / *(fe+1) + 0.5) << endl;
	}

	os.setf(initial); // restore the initial formatting states
}
