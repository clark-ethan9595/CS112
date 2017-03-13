/*
 * PalindromeDetector.cpp
 * Created on: Apr 16, 2015
 * Author: ethanclark (elc3)
 * Project 8 for CS112
 */

#include "PalindromeDetector.h"
#include <cctype>
using namespace std;

//Palindrome_Detector Class constructor
Palindrome_Detector::Palindrome_Detector(const string& file1, const string& file2) {

	//set the input file and output file instance variables to the constructor arguments
	myInputfile = file1;
	myOutputfile = file2;

}

/*
 * isPalindrome(string)
 * returns true if the string is a palindrome
 *   returns false if the string is not a palindrome
 * Puts every character of the string into both the Stack and Queue
 * Pops and removes and checks if each character is the same
 */
bool Palindrome_Detector::isPalindrome(const string& str) {

	Stack<char> s1(1);
	ArrayQueue<char> q1(1);

	//If the string is just a newline character, return false
	if (str.size() == 0) {
		return false;
	}

	//Loop to push and append the character to the Stack and Queue
	for (unsigned i = 0; i < str.size(); i++) {

		char c1 = str[i];

		//Only append and push alphanumeric values to the queue and stack
		if (isalpha(c1)) {

			//Convert the letter to lowercase
			c1 = tolower(c1);

			//Try and catch to see if the Stack is full
			try {
				s1.push(c1);
			}
			catch(StackException& se) {
				unsigned x = s1.getCapacity() * 2;
				s1.setCapacity(x);
				s1.push(c1);
			}

			//Try and catch to see if the Queue is full
			try {
				q1.append(c1);
			}
			catch(QueueException& qe) {
				unsigned x = q1.getCapacity() * 2;
				q1.setCapacity(x);
				q1.append(c1);
			}
		}
	}

	//Loop to pop and remove from the Stack and Queue
	while ( !s1.isEmpty() and !q1.isEmpty() ) {
		char c1, c2;
		c1 = s1.pop();
		c2 = q1.remove();
		//If the characters are not the same, return false
		if (c1 != c2) {
			return false;
		}
	}
	//If all characters are the same, return true
	return true;
}

/*
 * Method called to detect if the string is a palindrome
 * No parameters; no return value
 * Open both the input and output files
 *   getline into a string
 *   call isPalindrome to check if the string is a palindrome
 */
void Palindrome_Detector::detectPalindromes() {

	//Open both the input and output streams
	ifstream fin(myInputfile.c_str());
	assert (fin.is_open());

	ofstream fout(myOutputfile.c_str());
	assert (fout.is_open());

	//Until the end of the file has been reached...
	while (! fin.eof() ) {

		//read in the whole line, outputting it right away
		string line;
		getline(fin, line);
		fout << line;

		//If the line is a palindrome, output *** to show the line is a palindrome
		if ( isPalindrome(line) ) {
			fout << " ***";
		}
		fout << "\n";
	}
	//Close both the input and output files
	fin.close();
	fout.close();
}
