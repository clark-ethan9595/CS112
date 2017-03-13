/*
 * tester.cpp is a "driver" to run the tests in the StackTester class
 * 	 and run the decoding/encoding application.
 * Joel Adams, for CS 112 at Calvin College.
 * Ethan Clark (elc3)
 * Project 7 for CS112
 * April 8, 2015
 */

#include "StackTester.h"
#include <fstream>
#include <cctype>
using namespace std;

/*
 * Function to do the encoding and decoding of a textfile
 * @param: two string filenames that should not be changed
 * Written by Ethan Clark (elc3)
 * Project7 for CS112
 * April 9, 2015
 */
void EncodingWork(const string& filename1, const string& filename2) {

	//Open and check that the input and output streams are open
	ifstream fin(filename1.c_str());
	ofstream fout(filename2.c_str());
	assert(fin.is_open());
	assert(fout.is_open());

	//Create the Stack of capacity 1
	Stack<char> S1(1);

	//While the end of the file has not been reached
	while ( !( fin.eof() ) ) {

		//Create a char variable and read in a character from the file
		char character;
		fin.get(character);

		//If the character is alpanumeric (letter or number)
		if ( isalnum(character) ) {

			//Try pushing the character into the Stack
			try {
				S1.push(character);
			}
			//If exception is thrown, double the capacity and then push character into Stack
			catch(StackException& se) {
				int x = S1.getCapacity();
				S1.setCapacity(x*2);
				S1.push(character);
			}
		}

		//If the character is not alphanumeric
		else {

			//If the Stack is not empty
			if ( !( S1.isEmpty() ) ) {

				//Create a variable of the Stack's size
				unsigned x = S1.getSize();

				//Pop out the characters into the list into the output file
				for (unsigned j = 0; j < x; j++) {
					fout << S1.pop();
				}
			}
			//Output the non-alphanumeric character to the file
			if ( !(fin.eof() ) ) {
				fout << character;
			}
		}
	}
	//Close both the file output and input streams
	fin.close();
	fout.close();
}

/*
 * Function to get the two filenames from the user
 * Allows the user to encode/decode another message or quit
 * Written by Ethan Clark (elc3)
 * Project7 for CS112
 * April 9, 2015
 */
void DecodingApp() {

	cout << endl << "Welcome to the Encoding/Decoding Application!" << endl;

	//Forever loop to ask the user if he/she wants to decode/encode another message
	while (true) {

		cout << "Would you like to continue (c) or quit (q)? ";
		string user_entry;
		cin >> user_entry;

		//Determine if user wants to continue or if the user wants to quit
		if (user_entry == "c" or user_entry == "C") {
			cout << "Please enter the name of the file you would like to encode/decode: ";
			string filename1;
			cin >> filename1;

			cout << endl;
			cout << "Please enter the name of the file you would like to write the encoding/decoding to: ";
			string filename2;
			cin >> filename2;

			EncodingWork(filename1, filename2);
			cout << endl;
		}

		if (user_entry == "q" or user_entry == "Q") {
			break;
		}
	}
}

/*
 * Main function to either run the Stack tests or the Decoding/Encoding Application
 * Written by Ethan Clark (elc3)
 * Project7 for CS112
 * April 9, 2015
 */
int main() {

	//Ask the user if he/she wants to run the tests or the application
	cout << "Would you like to run the tests or run the application?" << endl;
	cout << "Choose 0 for tests and 1 for application: ";
	int user_entry;
	cin >> user_entry;

	if ( user_entry == 0) {
		StackTester st;
		st.runTests();
	}
	else {
		DecodingApp();
	}
}
