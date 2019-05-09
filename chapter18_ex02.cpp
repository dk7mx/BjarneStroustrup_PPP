/*******************************************************************************
* Write a function, char* findx(const char* s, const char* x), that finds the
* first occurence of the C-style string x in s. Do not use any standard library
* functions: Do not use subscripting; use the dereference operator instead.
*******************************************************************************/

#include "std_lib_facilities.h"

char* findx(const char* s, const char* x){

    // create a pointer as work-copy to run through s
    char* swx = const_cast<char*>(s);

    // check for content
    if (*x==0) return swx;		// nothing received to search for
	if (*s==0) return nullptr;	// nothing received to search through

	// run through 2 loops
	for (int i=0; *(s+i); ++i){					// outer loop
		if (*(s+i) == *x){						// first parity
			for (int j=0; *(x+j); ++j){			// inner loop
				if (!*(s+i+j)){
                    cout << "s too short" << endl;
                    return nullptr;	// looked good, but reached end of s
				}

				if ( *(s+i+j) != *(x+j)){
                    cout << "looked good" << endl;
                    break;	// only partial parity; proceed with outer loop
				}
				if (!*(x+j+1)) return (swx+i);	// x found
			}
			//return (swx+i);
		}
	}
	return nullptr; 							// nothing found
}

//------------------------------------------------------------------------------

void print_str(const char* s){
	if (!s) error("Cannot print form nullptr");
	while (*s) cout << *s++;
}


//------------------------------------------------------------------------------
int main()
try{
	char s[] = "This test run is just a tester phrase";
	char x[] = "runo";

	cout << "s: " << s << "\n";
    cout << "x: " << x << "\n";

	print_str(findx(s,x));

	cout << "\n";
}
catch (exception& e){
	cerr << "exception: " << e.what();
}
catch (...){
	cerr << "exception: ";
}
