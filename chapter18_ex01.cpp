/*******************************************************************************
* Write a function, char* strdup(const char*), that copies a C-style string
* into memory it allocates on the free store. Do not use any standard library
* functions. Do not use subscripting; use the dereference operator * instead:
*
*******************************************************************************/
/*******************************************************************************
* changed date: 20190510
* changed by: dk7mx
*   - new
*
*
*******************************************************************************/


#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

char* strdup(const char* s){
	// get size of s
	int i = 0;
	const char* p = s;		// a pointer to run through the string
							// the value pointed by cannot be changed
	while (*p++) ++i;

	// allocate new string, add space for terminating 0
	char* s_cpy = new char[i+1]; 	// a pointer to new allocated space

	// copy s, add terminating 0
	char* s_cpy_ptr = s_cpy;		// a pointer to run through the copied string
	while (*s) *s_cpy_ptr++ = *s++;	// copy maneuver
	*s_cpy_ptr = 0;
	return s_cpy;
}

//------------------------------------------------------------------------------
inline void error(const string& errormessage){
	throw runtime_error(errormessage);
}

//------------------------------------------------------------------------------
void print_str(const char* s) {
	if (s==0) error("Cannot print from null pointer");
	while (*s) cout << *s++;
}

//------------------------------------------------------------------------------
int main()
try{
	// test exercise 1
	char s[] = "Test-String";
	char* s_cpy = strdup(s);
	print_str(s_cpy);
	cout << "\n";
	delete[] s_cpy;

	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}

