/*******************************************************************************
* Chapter 18, exercise 07:
* Write versions of the cat_dot()s from the previous exercise to take
* C-style strings as arguments and return a free-store-allocated C-style
* string as the result. Do not use standard library functions or types in the
* implementation. Test these functions with several strings. Be sure to free
* (using delete) all the memory you allocated from free store (using new).
* Compare the effort involved in this exercise with the effort involved for
* exercise 5 and 6.
********************************************************************************

/*******************************************************************************
* latest change:
* changed by:
*
*
*******************************************************************************/

#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
char* cat_dot(const char* s1, const char* s2) {
	// get length of s1 and s2
	const char* p = s1;
	int ctr = 0;
	while (*p) { ++ctr; ++p; }
	p = s2;
	while (*p) { ++ctr; ++p; }

	// allocate new array with extra room for '.' and terminating 0
	char* res = new char[ctr+2];

	// copy arrays
	p = s1;
	char* res_ptr = res;
	while (*p) *res_ptr++ = *p++;
	*res_ptr++ = '.';
	p = s2;
	while (*p) *res_ptr++ = *p++;
	*res_ptr = 0;

	return res;
}

//------------------------------------------------------------------------------
char* cat_dot2(const char* s1, const char* s2, const char* s3) {
	// get length of s1, s2 and s3
	int ctr = 0;
	const char* p = s1;
	while (*p) { ++ctr; ++p; }
	p = s2;
	while (*p) { ++ctr; ++p; }
	p = s3;
	while (*p) { ++ctr; ++p; }
	
	// allocate new array with extra room for terminating 0
	char* res = new char[ctr+1];
	
	// copy arrays
	p = s1;
	char* res_ptr = res;
	while (*p) *res_ptr++ = *p++;
	p = s3;
	while (*p) *res_ptr++ = *p++;
	p = s2;
	while (*p) *res_ptr++ = *p++;
	*res_ptr = 0;
	
	return res;
}

//------------------------------------------------------------------------------

int main()
try {
	char* res = cat_dot("Niels","Bohr");
	cout << res << "\n";
	delete[] res;
	
	res = cat_dot2("Niels","Bohr"," dot ");
	cout << res << "\n";
	delete[] res;
	
	cin.get();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "unknown exception\n";
}
