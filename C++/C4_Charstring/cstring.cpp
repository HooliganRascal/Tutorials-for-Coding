#include<iostream>

int main(void){

	using namespace std;

	// initialization of char array and string
	char name_char[6] = {'M','t','e','l','t','n'};
	char name_string[7] = {'M','t','e','l','t','n','\0'}; // last null takes
	char name_strings[7] = {"Mteltn"}; // still needs one more place
	char name_stringes[] = {"Mteltn"};
	char name_stringbs[7] = "Mteltn";
	char name_stringzs[] = "Mteltn"; // let the compiler counts
	
	// inputting
	char name[20];
	char dessert[20];
	char letter;
	
	// output the initialization
	cout << "char array : " << name_char << endl;
	cout << "strings by array : " << name_string << endl;
	cout << "strings by total sring: " << name_strings << endl;
	cout << "strings by total sring with no size: " << name_stringes << endl;
	cout << "strings without brackets: " << name_stringbs << endl;
	cout << "strings without brackets and size: " << name_stringzs << endl;
	cout << "Let's concatenating the " // concatenating
			"strings !" << endl;

	// output the input with  getline()
	cout << "Enter your name: ";
	cin.getline(name, 20); // use getline() member function
	cout << "Enter what you want: ";
	cin.getline(dessert, 20);
	cout << "Your name is " << name << ", and you want " << dessert << endl;

	// output the input with get()
	cout << "Enter your name again: ";
	cin.get(name, 20).get(); // use get() member function
							 // same as: cin.get(name, 20); cin.get()
	cout << "Enter a letter: ";
	(cin >> letter).get(); // restore input queue
						   // same as : cin >> letter; cin.get()
	cout << "Enter what you want again: ";
	cin.get(dessert, 20);
	cout << "Your name is " << name 
		 << ", you entered " << letter 
		 << ", and you want " << dessert << endl;

	return 0;
}
