#include<iostream>
#include<new>

using namespace std;

const int bufsize = 512;
const int nsize = 5;
static char buffer[bufsize]; // sizeof(char)=1

int main(void){
	/*First time*/
	cout << "Call new and placement new first time: " << endl;
	double* pd1 = new double [nsize];
	double* pd2 = new (buffer) double [nsize]; // placement new
	for(int i=0; i<nsize; ++i){
		*(pd1+i) = *(pd2+i) = 1000+20.0*i;
	}

	cout << "Memory address: " << endl;
	cout << "  heap: " << pd1 << "  static: " 
		 << (void*)buffer << endl; // use void* to cast buffer as pointer
	cout << "Memory contents:" << endl;
	for(int i=0; i<nsize; ++i){
		cout << *(pd1+i) << " at " << pd1+i << "; ";
		cout << *(pd2+i) << " at " << pd2+i << endl;
	}
	cout << endl;

	/*Second time*/
	cout << "Call new and placement new a second time: " << endl;
	double* pd3 = new double [nsize];
	double* pd4 = new (buffer) double [nsize]; // overwrite old data
	for(int i=0; i<nsize; ++i){
		*(pd3+i) = *(pd4+i) = 1000+40.0*i;
	}

	cout << "Memory address: " << endl;
	cout << "  heap: " << pd3 << "  static: " << (void*)buffer << endl;
	cout << "Memory contents:" << endl;
	for(int i=0; i<nsize; ++i){
		cout << *(pd3+i) << " at " << pd3+i << "; ";
		cout << *(pd4+i) << " at " << pd4+i << endl;
	}
	cout << endl;

	/*Third time*/
	cout << "Call new and placement new a third time: " << endl;
	delete [] pd1; // free pd1
	pd1 = new double [nsize];
	pd2 = new (buffer+nsize*sizeof(double)) double [nsize]; // Offer offsets
	for(int i=0; i<nsize; ++i){
		*(pd1+i) = *(pd2+i) = 1000+60.0*i;
	}
	cout << "Memory address: " << endl;
	cout << "  heap: " << pd1 << "  static: " << (void*)buffer << endl;
	cout << "Memory contents:" << endl;
	for(int i=0; i<nsize; ++i){
		cout << *(pd1+i) << " at " << pd1+i << "; ";
		cout << *(pd2+i) << " at " << pd2+i << endl;
	}

	/* pd2, pd4 are allocated in buffer, no need to free*/
	delete [] pd1;
	delete [] pd3;
	
	return 0;
}
