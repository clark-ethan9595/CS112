/*
 * BSTApplication.cpp
 * Created on: Apr 22, 2015
 * Author: Ethan Clark
 * Project9 for CS112
 */

#include "BSTApplication.h"

/*
 * BSTApplication constructor
 * Receives a string filename and sets it to the instance variable
 * Sets the duplicate_counter variable to zero
 * Created by Ethan Clark
 * April 22, 2015
 * Project9 for CS112
 */
BSTApplication::BSTApplication(const string& input_file) {

	myInput_file = input_file;
	duplicate_counter = 0;
}

/*
 * BSTApplication readFrom() method
 * Opens the input file stream and reads in all the integer values
 * Catches the Exception if the same integer is tried to be inserted
 *   and updates the counter variable accordingly
 * Created by Ethan Clark
 * April 22, 2015
 * Project9 for CS112
 */
void BSTApplication::readFrom() {

	ifstream fin(myInput_file.c_str());
	assert (fin.is_open());
	string integer;
	long int number;

	while ( ! ( fin.eof() ) ) {
		getline(fin, integer);
		number = atoi(integer.c_str());
		try {
			binary_tree.insert(number);
		}
		catch (Exception& e) {
			duplicate_counter++;
		}
	}

	fin.close();
}

/*
 * BSTApplication displayHeight() method
 * Outputs the height of the tree and the number of duplicate variables in an
 *   organized fashion for the user to read
 * Created by Ethan Clark
 * April 22, 2015
 * Project9 for CS112
 */
void BSTApplication::displayHeight() const {

	cout << "The height of this Binary Search Tree is " <<
			binary_tree.getHeight() << "." << endl;
	cout << "There were " << duplicate_counter << " duplicate numbers from the text file." << endl;
}
