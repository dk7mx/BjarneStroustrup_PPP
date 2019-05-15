/******************************************************************************
* Rewrite all the functions in §18.7 to use the approach of making a backward
* copy of the string and then comparing; for example, take "home", generate
* "emoh", and compare those two strings to see that they are different, so home
* isn't a palindrome.
*******************************************************************************/

/*******************************************************************************
* create date:
* create number: 0
* create engineer:
* create description:
*
*
* revision date:
* revision number:
* revision engineer:
* revision description:
*
*******************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

//----- using std::string ------------------------------------------------------
bool is_palindrome(const string& s) {
	string s_cp;	// Rückwärts-String
	for (int i = s.size()-1; i>=0; --i) s_cp.push_back(s[i]);
	if (s==s_cp) return true;
	return false;
}

//----- using arrays -----------------------------------------------------------
bool is_palindrome(const char s[], int n) {
	char* s_cp = new char[n+1];
	s_cp[n] = 0;
	for (int i=0; i<n; ++i) s_cp[n-1-i] = s[i];

	if (strcmp(s,s_cp)) {
		delete[] s_cp;
		return false;
	}

	delete[] s_cp;
	return true;
}

//----- using pointers ---------------------------------------------------------
bool is_palindrome(const char* first, const char* last) {
	char* s_cp = new char[last-first+2];
	char* s_cp_ptr = s_cp;
	while (last>=first) {
		*s_cp_ptr = *last;
		++s_cp_ptr;
		--last;
	}
	*s_cp_ptr = 0;

	if (strcmp(first, s_cp)) {
		delete[] s_cp;
		return false;
	}

	delete[] s_cp;
	return true;
}

//------------------------------------------------------------------------------
istream& read_word(istream& is, char* buffer, int max) {
	is.width(max);
	is >> buffer;
	return is;
}

//------------------------------------------------------------------------------



int main()
try {
	// test string
	string s;
	while (cin >> s && s!="quit") {
		cout << s << " is";
		if (!is_palindrome(s)) cout << " not";
		cout << " a palindrome\n";
	}

	// test array
	const int max = 5;
	char s2[max];
	while (read_word(cin,s2,max) && strcmp(s2,"quit")) {
		cout << s2 << " is";
		if (!is_palindrome(s2,strlen(s2))) cout << " not";
		cout << " a palindrome\n";
	}

	// test poiner
	while (read_word(cin,s2,max) && strcmp(s2,"quit")) {
		cout << s2 << " is";
		if (!is_palindrome(&s2[0],&s2[strlen(s2)-1])) cout << " not";
		cout << " a palindrome\n";
	}

}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "unknown exception: " << endl;
}

