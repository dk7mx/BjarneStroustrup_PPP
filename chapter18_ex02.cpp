/*******************************************************************************
* description according PPP:
* Write a function, char* findx(const char* s, const char* x), that finds the
* first occurence of the C-style string x in s. Do not use any standard library
* functions: Do not use subscripting; use the dereference operator instead.
*
* myComment:
* The code is different from others on the web in that way that it uses a
* while-loop instead a for-loop. Thereby the code became shorter and with less
* cases to distinguish.
*
*******************************************************************************/

#include "std_lib_facilities.h"

char* findx(const char* s, const char* x){

    // create a non-const-copy to match the return-type
    char* swx = const_cast<char*>(s);

    // check for content
    if (*x==0){
        cout << "x is empty which means: nothing received to search for" << endl;
        return swx;                             // nothing received to search for
    }
	if (*s==0){
        cout << "s is empty which means: nothing received to search through" << endl;
        return nullptr;                         // nothing received to search through
	}

	// run through 2 loops
	for (int i=0; *(s+i); ++i){					                        // outer loop, run through s
		if (*(s+i) == *x){												// first occurence of identical chars
                                                                
			int j = 0;
			while (*(s+i+j) == *(x+j)){			                        // inner loop, compare s and x
				++j;
				if (!*(x+j)) {
                    cout << "search term x found in s" << endl;
                    return (swx+i);	                                    // x found
				}
				if (!*(s+i+j)){
                    cout << "x not found in s, because s is too short" << endl;
                    return nullptr;	                                    // s reached its end
				}
			}
		}
	}
	cout << "nothing found that fits" << endl;
	return nullptr; 							                        // nothing found
}

//------------------------------------------------------------------------------

void print_str(const char* s){
	if (!s) error("Cannot print form nullptr");
	while (*s) cout << *s++;
}


//------------------------------------------------------------------------------
int main()
try{
	char s[] = "das soll nur ein test sein";
	char x[] = "test";

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
