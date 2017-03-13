/* tester.cpp drives the testing of our Vec class.
 * Student Names: Ethan Clark (Student One) and Thomas Dykstra (Student Two)
 * Date: March 2, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

//Include the VecTester class to run the Vec tests
#include "VecTester.h"

//Function to print out the Vecs in nice and clean fashion
void vecPrint(const Vec& v1, const int& num_dimensions){
	cout << "{";
	for (int i = 0; i < num_dimensions-1; i++) {
		cout << v1[i] << ",";
	}
	cout << v1[num_dimensions-1] << "}" << endl;
}

//Function to run the Vec Application program
void vecApplication() {

	//Forever Loop to run the application until the user quits
	while (true) {

		//Output and input to see if the user ends the application
		cout << "Enter 'C' to continue the application or 'Q' to quit: ";
		string user_entry;
		cin >> user_entry;

		//Break the forever loop if the user quits
		if (user_entry == "Q" or user_entry == "q") {
			break;
		}

		//Ask the user how many dimensions they would like to work with
		cout << "How many dimensions would you like to use? ";
		int num_dimensions;
		cin >> num_dimensions;

		//Create a starting Vec and assign starting values based off the user's choices
		Vec starting_vec(num_dimensions);

		cout << "Please enter " << num_dimensions << " values for the starting location: " << endl;

		for (int i = 0; i < num_dimensions; i++) {

			cout << "Value " << i+1 << ": ";

			int number;
			cin >> number;
			starting_vec[i] = number;
		}

		//Call to print out the starting Vec the user created
		cout << "The starting Vec is ";
		vecPrint(starting_vec, num_dimensions);

		//Ask the user how many Vecs they would like to create
		cout << "Please enter the number of Vecs you would like to create: ";
		int num_vecs;
		cin >> num_vecs;

		//Create a copy of the starting vec to use as the ending vec
		Vec ending_vec(num_dimensions);
		ending_vec = starting_vec;

		//Loop through and add the vecs entered by the user to the ending vec
		for (int i = 0; i < num_vecs; i++) {

			Vec adding_vec(num_dimensions);
			cout << "Vec" << i+1 << endl;

			for (int i = 0; i < num_dimensions; i++) {

				cout << "Value " << i+1 << ": ";

				int number;
				cin >> number;
				adding_vec[i] = number;
			}
			ending_vec = ending_vec + adding_vec;
			cout << endl;
		}

		//Print out the ending vec
		cout << "The starting Vec is ";
		vecPrint(starting_vec, num_dimensions);
		cout << "The ending Vec is ";
		vecPrint(ending_vec, num_dimensions);
	}
}

//Main function to run the testing program or the Vec application
int main() {
	cout << "Would you like to run the Vec tests or run the Vec application?" << endl;
	cout << "Type 0 for tests or 1 for the application: ";

	int user_entry;
	cin >> user_entry;

	//If user enters 0, run the Vec tests
	if (user_entry == 0) {

		VecTester vt;
		vt.runTests();
	}

	//If user enters 1, run the Vec application
	if (user_entry == 1) {
		vecApplication();
	}
}
