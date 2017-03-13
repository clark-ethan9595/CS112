/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Member 1: Myles Taft
 * Member 2: Ethan Clark
 * Date: March 9, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

//Include the MatrixTester Class
#include "MatrixTester.h"

//Function to neatly and orderly print out a Matrix
void MatrixPrint(const Matrix<double>& m1) {

	cout << "Your new Matrix is:" << endl;
	cout << "{" << flush;
	for (unsigned i = 0; i < m1.getRows(); i++) {
		for (unsigned j = 0; j < m1.getColumns(); j++) {
			cout << m1[i][j] << " ";
			if (i == m1.getRows() - 1 and j == m1.getColumns() - 1) {
				cout << "}";
			}
		}
		cout << '\n';
	}
}

//Function to perform the addition of Matrices for the MatrixApplication
void MatrixAddition() {

	cout << "Matrix Addition!" << endl;
	cout << "Please enter the filename for Matrix One:" << flush;

	string filename;
	cin >> filename;

	cout << "Please enter the filename for Matrix Two:" << flush;

	string filename2;
	cin >> filename2;

	cout << "Would you like to perform..." << '\n' << "a. Matrix One + Matrix Two? " <<
			"or b. Matrix Two + Matrix One?" << endl;
	cout << "Enter answer here: " << flush;

	string user_entry;
	cin >> user_entry;

	Matrix<double> m3;

	if (user_entry == "a") {
		Matrix<double> m1;
		Matrix<double> m2;

		m1.readFrom(filename);
		m2.readFrom(filename2);

		m3 = m1 + m2;
	}

	if (user_entry == "b") {
		Matrix<double> m1;
		Matrix<double> m2;

		m1.readFrom(filename);
		m2.readFrom(filename2);

		m3 = m2 + m1;
	}

	cout << endl;
	MatrixPrint(m3);
	cout << endl;
}

//Function to perform the subtraction of Matrices for the MatrixApplication
void MatrixSubtraction() {

	cout << "Matrix Subtraction!" << endl;
	cout << "Please enter the filename for Matrix One:" << flush;

	string filename;
	cin >> filename;

	cout << "Please enter the filename for Matrix Two:" << flush;

	string filename2;
	cin >> filename2;

	cout << "Would you like to perform..." << '\n' << "a. Matrix One - Matrix Two? " <<
			"or b. Matrix Two - Matrix One?" << endl;
	cout << "Enter answer here: " << flush;

	string user_entry;
	cin >> user_entry;

	Matrix<double> m3;

	if (user_entry == "a") {
		Matrix<double> m1;
		Matrix<double> m2;

		m1.readFrom(filename);
		m2.readFrom(filename2);

		m3 = m1 - m2;
	}

	if (user_entry == "b") {
		Matrix<double> m1;
		Matrix<double> m2;

		m1.readFrom(filename);
		m2.readFrom(filename2);

		m3 = m2 - m1;
	}

	cout << endl;
	MatrixPrint(m3);
	cout << endl;
}

//Function to perform the transposing of a Matrix for the MatrixApplication.
void MatrixTranspose() {

	cout << "Matrix Transpose!" << endl;
	cout << "Please enter the filename for Matrix One:" << flush;

	string filename;
	cin >> filename;

	Matrix<double> m1;
	m1.readFrom(filename);

	Matrix<double> m3 = m1.getTranspose();

	cout << endl;
	MatrixPrint(m3);
	cout << endl;
}

//Main MatrixApplication function to ask the user which method they would like to do
void MatrixApplication() {

	while (true) {
		cout << "Welcome to the Matrix Application!" << endl;
		cout << "Choose one of the following three operations to perform:" << endl;
		cout << "Enter 1 for Matrix addition:" << endl;
		cout << "Enter 2 for Matrix subtraction:" << endl;
		cout << "Enter 3 to transpose a Matrix:" << endl;
		cout << "Enter 4 to quit the application:" << endl;
		cout << "What is your choice? " << flush;

		int user_entry;
		cin >> user_entry;

		cout << endl;

		if (user_entry == 1) {
			MatrixAddition();
		}
		if (user_entry == 2) {
			MatrixSubtraction();
		}
		if (user_entry == 3) {
			MatrixTranspose();
		}
		if (user_entry == 4) {
			break;
		}
	}
}

//Main function for Project4 that asks the user if they would like to run
//Matrix Tests or run the Matrix Application.
int main() {

	cout << "Would you like to run the Matrix tests or run the Matrix application?" << endl;
	cout << "Enter 0 for the tests or 1 for the application: " << flush;

	int user_entry;
	cin >> user_entry;

	if (user_entry == 0) {
		MatrixTester mt;
		mt.runTests();
	}
	if (user_entry == 1) {
		MatrixApplication();
	}
}
