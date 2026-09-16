#include<iostream>
#include<fstream>
#include<cstdlib>

const int namesize = 50;

using namespace std;

int main(void){

	double a_price;
	double d_price;
	int year;
	int item = 0;
	char mobile[namesize];
	char file2name[namesize] = "File2.txt";

	// Define output objects and input objects
	ofstream output1, output2;
	ifstream input1, input2;

	// Begin the output
	output1.open("File1.txt"); // Output named directly
	output2.open(file2name); // Output named in the program
	
	// Take the input
	cout << "Enter the make and model of mobile: ";
	cin.getline(mobile, namesize);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;

	// Do some algorithm
	d_price = 0.918 * a_price;

	// Output to screen
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << mobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	// Output to File1.txt
	output1 << fixed;
	output1.precision(2);
	output1.setf(ios_base::showpoint);
	output1 << "Make and model: " << mobile << endl;
	output1 << "Year: " << year << endl;
	output1 << "Was asking $" << a_price << endl;
	output1 << "Now asking $" << d_price << endl;

	// Output to File2.txt
	output2 << fixed;
	output2.precision(2);
	output2.setf(ios_base::showpoint);
	output2 << "Make and model: " << mobile << endl;
	output2 << "Year: " << year << endl;
	output2 << "Was asking $" << a_price << endl;
	output2 << "Now asking $" << d_price << endl;

	// End the output
	output1.close();
	output2.close();

	// Begin the input
	input1.open("File1.txt");
	input2.open(file2name);

	// Test if File1 succeeds to open
	if(!input1.is_open()){
		cout << "Could not open the file \"File1.txt\"! " << endl;
		cout << "Program terminating!" << endl;
		exit(EXIT_FAILURE);
	}

	// Open the input1 file and read the item
	do{
		input1.get(); // Use get() to read character 
		++item;
	}while(input1.good());

	// Test for input termination
	if(input1.eof()){
		cout << "End of file reached." << endl;
	}
	else if(input1.fail()){
		cout << "Input terminated by data mismatch." << endl;
	}
	else{
		cout << "Input terminated for unknown reason." << endl;
	}

	// Output the result to input process
	if(item==0){
		cout << "No data in the file" << endl;
	}
	else{
		cout << "Items read: " << item << endl;
	}

	// Do nothing to input2

	// End the input
	input1.close();
	input2.close();

	return 0;
}
