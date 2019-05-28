/*******************************************************************************
* Look at the "array solution" to the palindrome problem in §18.7.2. Fix it to 
* deal with long strings by (a) reporting if an input string was too long and (b)
* allowing an arbitrarily long string. Comment on the complexity of the two 
* versions.
*******************************************************************************/

#include <iostream>
#include <cstring>

// using arrays
bool is_palindrome(const char s[], int n) {
	int first = 0;
	int last = n-1;
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
		cout << "Input cut off after " << max-1 " characters!\n";
		char ch;
		while (is.get(ch)) {
			if (ch=='\n') break;
		}
	}
	return is;
}

//------------------------------------------------------------------------------
istream& read_long_word(istream& is, char*& buffer) {
	int max = 128;
	char* temp1 = new char[max];
	*temp1 = 0;
	
	char ch;
	while (cin.get(ch)) {
		if (ch=='\n') break;
		if (strlen(temp1) == max-1) {
			// double length of temp1
			char* temp2 = new char[max];
			strcpy(temp2, temp1);
			delete[] temp1;
			max *= 2;
			temp1 = new char[max];
			strcpy(temp1,temp2);
			delete[] temp2;
		}
		temp1[strlen(temp1)+1] = 0;
		temp1[strlen(temp1)] = ch;
		buffer = temp1;
		return is;

//----- 

	


catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
			