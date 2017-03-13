/*
 * Tester.cpp
 * Runs the BST tests or runs the BST Application
 * Created by Ethan Clark (elc3)
 * April 22, 2015
 * Project9 for CS112
 */

#include "BST_Tester.h"
#include "BSTApplication.h"
#include "BSTApplicationTester.h"

/*
 * BST_Application() that asks the user for the name of the file to read in integer values from
 *   and then calls the BSTApplication class to do the work
 * Displays the height of the binary search tree
 * Created by Ethan Clark
 * April 22, 2015
 * Project9 for CS112
 */
void BST_Application() {

	cout << "Welcome to the BST Application!" << endl;

	while (true) {

		cout << "Enter c to continue or q to quit: ";
		string user_entry;
		cin >> user_entry;

		if (user_entry == "c" or user_entry == "C") {
			cout << "Please enter the name of the name of the file for the BST: ";
			string filename;
			cin >> filename;

			BSTApplication BSTA(filename);
			BSTA.readFrom();
			BSTA.displayHeight();
		}

		if (user_entry == "q" or user_entry == "Q") {
			break;
		}
	}
}

//int main() function for the c++ project9
//Asks if the user wants to run the BST tests or the BST Application
int main() {

	cout << "Would you like to run the BST tests or run the BST application?" << endl;
	cout << "0 for the tests and 1 for the application: ";
	int user_entry;
	cin >> user_entry;

	if (user_entry == 0) {
		BST_Tester bstt;
		bstt.runTests();
		BSTApplicationTester BSTA;
		BSTA.runTests();
	}

	if (user_entry == 1) {
		BST_Application();
	}
}
