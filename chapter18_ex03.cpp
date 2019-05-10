/*******************************************************************************
* description according PPP:
* Write a function, int strcmp(const char* s1, const char* s2), that compares
* C-style strings. Let it return a negative number if s1 is lexicographically
* before s2, zero if s1 equals s2, and a positive number if s1 is lexigraphically
* after s2. Do not use any standard library functions. Do not use subscripting;
* use the dereference operator instead.
*******************************************************************************/

/*******************************************************************************
* latest change: 	20190510 
* changed by:		dk7mx
*
*
*
*******************************************************************************/



#include <iostream>

using namespace std;

//******************************************************************************
inline void error(const string& errormessage){
	throw runtime_error(errormessage);
}

//******************************************************************************

int strcmp(const char* s1, const char* s2) {
	if (s1==0 || s2==0) error("Null pointer sent to strcmp()");

	for (int i=0; *(s1+i); ++i) {
		// if only s1 ends of s1[i]<s2[i], s1<s2
		if ((*(s1+i)==0 && *(s2+i)) || (*(s1+i) < *(s2+i)) ) return -1;
		// if only s2 ends or s1[i]>s2[i], s1>s2
		if ((*(s2+i)==0 && *(s1+i)) || (*(s1+i) > *(s2+i)) ) return  1;
	}
	// s1 and s2 are identical
	return 0;
}

//******************************************************************************
int main()
try{
	// test exercise 3
	const int max = 6;
	char a[max];
	char b[max];
	while (cin >> a >> b) {
		int comp = strcmp(a,b);
		switch (comp) {
		case -1:
			cout << a << " < " << b << "\n";
			break;
		case 0:
			cout << a << " == " << b << "\n";
			break;
		case 1:
			cout << a << " > " << b << "\n";
			break;
		default:
			error("invalid result returned by strcmp");
			break;
		}
	}
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}


