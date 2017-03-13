/* Matrix.cpp defines Matrix class methods.
 * Student Name: Ethan Clark
 * Date: March 3, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"

//Default Constructor for the Matrix Class
Matrix::Matrix() {
	myRows = myColumns = 0;
}

//Explicit Constructor for the Matrix Class
Matrix::Matrix(unsigned rows, unsigned columns){
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

//Matrix Class method that returns the number of rows in the Matrix
unsigned Matrix::getRows() const {
	return myRows;
}

//Matrix Class method that returns the number of columns in the Matrix
unsigned Matrix::getColumns() const {
	return myColumns;
}

//Matrix Class method that overloads the subscript operator to read an element from a Matrix
const Vec<Item>& Matrix::operator[](unsigned index) const {
	return myVec[index];
}

//Matrix Class method that overloads the subscript operator to assign an element to a Matrix
Vec<Item>& Matrix::operator[](unsigned index) {
	return myVec[index];
}

//Matrix Class method that compares if two Matrices are the same
bool Matrix::operator==(const Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return (myVec == m2.myVec);
	}
}
