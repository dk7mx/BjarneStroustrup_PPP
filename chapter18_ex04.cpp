/********************************************************************************
* Consider what happens if you give strdup(), findx(), strcmp() an argument that
* is not a C-style string. Try it! First figure out how to get a char* that
* doesn't point to a zero-terminated array of characters and then use it
* (never do this in real - non-experimental - code; it can create havoc).
* Try it with free-store-allocated and stack-allocated "fake C-style strings."
* If the results still looks reasonable, turn off debug mode. Redesign and
* re-implement those three functions so that they take another argument giving
* the maximum number o elements allowed in argument strings. Then test with
* C-style strings and "bad strings".
*******************************************************************************/

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
void error(const string errormessage) {
    throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------
char* strdup(const char* s) {
	// get size of s
	int i = 0;
	const char* p = s;
	while (*p++) ++i;

	// allocate new string, add space for terminating 0
	char* s_cpy = new char[i+i];

	// copy s, add terminating 0
	char* s_cpy_ptr = s_cpy;
	while (*s) *s_cpy_ptr++ = *s++;
	*s_cpy_ptr = 0;
	return s_cpy;
}

//------------------------------------------------------------------------------
char* findx(const char* s, const char* x){

    // create a non-const-copy to match the requirements for the return-type
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
		if (*(s+i) == *x){								// first occurence of identical chars

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

//------------------------------------------------------------------------------
void print_str(const char* s) {
	if (s==0) {
		cout << "Cannot print from null pointer";
		return;
	}
	int i = 0;
	while (*s) {
        printf("%i %c  ",i,*s++);
        ++i;
	}
	printf("\n");
	int x = *(s);
	printf("und jetzt noch was hinten dran haengt: %i %i", i, x);

        //cout << *s++;
}

//------------------------------------------------------------------------------
void test1() {
	char a[] = "MyTest";
	//a[sizeof(a)-1] = 't';
	char a1[] = {'t','e','s','t'};
	char* ap = new char[4];				// on the free store
	ap[0] = 'T';
	ap[1] = 'E';
	ap[2] = 'S';
	ap[3] = 'T';

	print_str(a);
	cout << "\n";
	char* a_dup = strdup(a);
	char* ap_dup = strdup(ap);
	print_str(a_dup);
	cout << "\n";
	print_str(ap_dup);
	cout << "\n";
	delete[] ap_dup;
	delete[] a_dup;
	delete[] ap;
}

//------------------------------------------------------------------------------
void test2() {
	char a[] = "Longer test string";
	//a[sizeof(a)-1] = 'g';
	char b[] = {'t','e','s','t',0};
	char* sub = findx(a,b);
	print_str(sub);
	cout << "\n";

	char* ap = new char[sizeof(a)];
	for (int i = 0; i<sizeof(a); ++i)
		ap[i] = a[i];
	char* bp = new char[4];
	bp[0] = 't';
	bp[1] = 'e';
	bp[2] = 's';
	bp[3] = 't';
	char* subp = findx(ap,bp);
	print_str(subp);
	cout << "\n";

	delete[] bp;
	delete[] ap;
}

//------------------------------------------------------------------------------
void test3() {
	char a[] = {'t','e','s','t','1'};
	char b[] = {'t','e','s','t','2'};
	cout << "strcmp(" << a << "," << b << "):" << strcmp(a,b) << "\n";

	char* ap = new char[5];
	char* bp = new char[5];
	for (int i=0; i<5; ++i) {
		ap[i] = a[i];
		bp[i] = b[i];
	}
	cout << "strcmp(" << ap << "," << bp << "): " << strcmp(ap,bp) << "\n";
	delete[] bp;
	delete[] ap;
}

//------------------------------------------------------------------------------
int main()
try{
	// call strdup with not-zero-terminated string
	test1();

	// call findx with non-zero terminated string
	test2();

	// call strcmp with non-zero terminated strings
	test3();

}
catch (exception& e){
    cerr << "exception: " << e.what() << endl;
}
catch (...){
    cerr << "exception\n";
}
