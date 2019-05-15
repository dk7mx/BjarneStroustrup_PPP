/*******************************************************************************
* Consider the memory layout in §17.4. Write a program that tells the order in 
* which static storage, the stack, and the free store are laid out in memory.
* In which direction does the stack grow; upward toward higer addresses or
* downward toward lower addresses? In an array on the free store, are elements
* with higher indices allocated at higher or lower addresses?
*
*******************************************************************************/
#include <iostream>

using namespace std;

// static storage
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	
int main()
try {
	// pointers on static storage
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	int* pd = &d;
	cout << pa << "\n" << pb << "\n" << pc << "\n" << pd << "\n";
	if (pd > pc) cout << "Static storage grows upwards\n";
	else cout << "Static storage grows downwards\n";
	cout << "delta " << (pc -pb) << "\n";
	
	
	// stack
	int sa = 0;
	int sb = 0;
	int sc = 0;
	int* psa = &sa;
	int* psb = &sb;
	int* psc = &sc;
	cout << "\n" << psa << "\n" << psb << "\n" << psc << "\n";
	if (psc<psb) cout << "Stack grows downwards\n";
	cout << "delta " << (psc -psb) << "\n";
	
	// free store / heap
	int* ha = new int(0);
	int* hb = new int(0);
	int* hc = new int(0);
	int* hd = new int(0);
	cout << "\n" << ha << "\n" << hb << "\n" << hc << "\n" << hd << "\n";
	if (hc>hb) cout << "Heap grows upwards\n";
	else cout << "Heap grows downwards\n";
	cout << "delta " << (ha-hb) << "\n";
	cout << "delta " << (hb-hc) << "\n";
	cout << "delta " << (hc-hd) << "\n";
	
	// array on free store
	int* harr = new int[5];
	cout << "\n";
	for (int i = 0; i<5; ++i) {
		harr[i] = 0;
		cout << &harr[i] << "\n";
	}
	if (&harr[4]>&harr[3]) cout << "Arrays on the free store grow upward\n";
	
	delete[] harr;
	delete hc;
	delete hb;
	delete ha;
	
	cin.get();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
	
	
	