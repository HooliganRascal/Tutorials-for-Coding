#include<iostream>

int main(void){

	using namespace std;

	// universal character name
	char k\u00F6rper = 'a';
	cout << "Output g\u00E2teau and " << k\u00F6rper << endl;

	// wchar_t for wide character set
	wchar_t bob = L'P';
	cout << "cout of L is " << L"tall" << " and " << bob << endl;
	wcout << "wcout of L is " << L"tall" << " and " << bob << endl;

	// char16_t and char32_t
	char16_t ch1 = u'q';
	char32_t ch2 = U'\U0000222B';
	cout << "1 cout or wcout cutoff of U is " << ch1 << endl;
	cout << "2 cout or wcout cutoff of U is " << ch2 << endl;
	wcout << "1 cout.put cutoff of U is "; 
	cout.put(ch1) ; 
	cout << endl;
	wcout << "2 cout.put cutoff of U is "; 
	cout.put(ch2) ; 
	cout << endl;

	return 0;
}
