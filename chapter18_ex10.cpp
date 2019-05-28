/*******************************************************************************
* Look at the "array solution" to the palindrome problem in §18.7.2. Fix it to 
* deal with long strings by (a) reporting if an input string was too long and (b)
* allowing an arbitrarily long string. Comment on the complexity of the two 
* versions.
*******************************************************************************/

#include <iostream>
#include <cstring>

// using arrays
bool is_palindrome(const s[], int n) {
	int first = 0;
	int last = n - 1;
	while (first < last) {
		if (s[first] != s[last]) return false;
		++first;
		--last;
	}
	return true;
}

//------------------------------------------------------------------------------

istream& read_word(istream& is, char* buffer, int max) {
	is.width(max);
	is >> buffer;
	if (strlen(buffer) == max-1) {
		cout << "Input cut off after " << max-1 << " characters!\n";
		char ch;
		while (is.get(ch)) {
			if (ch=='\n') break;
		}
	}
	return is;
}

//------------------------------------------------------------------------------

istream& read_long_word