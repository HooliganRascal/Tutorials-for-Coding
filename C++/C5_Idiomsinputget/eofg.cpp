#include<iostream>
#include<cstdio>

int main(void){

	using namespace std;

	char cha;
	int chi;
	int count;
	
	// Idioms: while(cin.fail()==false), while(!cin.fail()), while(cin)
	count = 0;
	cout << "Enter a letter: ";
	while(!cin.get(cha)==false){  // Same as while(cin.get(cha))
		cout.put(cha);
		++count;
	}
	cout << endl << count << " characters read" << endl;

	cin.clear(); // Clear EOF flags set by cin
	clearerr(stdin); // Clear C-level EOF flags in FILE structure

	// Use 
	count = 0;
	cout << "Enter a letter: ";
	while((chi=cin.get())!=EOF){ // chi is type int
		// cout.put(static_cast<char>(chi)); // Type cast is needed
		cout.put((char)chi); // Type cast is needed
		++count;
	}
	cout << endl << count << " characters read" << endl;

	return 0;
}
