/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Member 1: Myles Taft
 * Member 2: Ethan Clark
 * Date: March 9, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

//Includes for the Matrix Class
#include "Vec.h"

//Declaration of the Matrix Class and its public and private information
template<class Item>
class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const;
	unsigned getColumns() const;
	bool operator==(const Matrix& m2) const;
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator!=(const Matrix& m2);
	Matrix operator+(const Matrix& m2);
	Matrix operator-(const Matrix& m2);
	void readFrom(ifstream& cin);
	void writeTo(ostream& out) const;
	void readFrom(const string& filename);
	void writeTo(const string& filename);
	Matrix<Item> getTranspose() const;

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

//Default Constructor for the Matrix Class
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

//Explicit Constructor for the Matrix Class
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns){
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

//Matrix Class method that returns the number of rows in the Matrix
template<class Item>
unsigned Matrix<Item>::getRows() const {
	return myRows;
}

//Matrix Class method that returns the number of columns in the Matrix
template<class Item>
unsigned Matrix<Item>::getColumns() const {
	return myColumns;
}

//Matrix Class method that overloads the subscript operator to read an element from a Matrix
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
	return myVec[index];
}

//Matrix Class method that overloads the subscript operator to assign an element to a Matrix
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index) {
	return myVec[index];
}

//Matrix Class method that compares if two Matrices are the same
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return (myVec == m2.myVec);
	}
}

//Matrix Class method that subtracts one Matrix from another
template<class Item>
Matrix<Item> Matrix<Item>::operator-(const Matrix<Item>& m2) {
	/*
	 * Subtraction Operator
	 * @Param: Matrix<Item>
	 * @return: Matrix formed by subtracting one matrix from another
	 * Written by Ethan Clark
	 */
	if ( myRows == m2.getRows() ) {
		if ( myColumns == m2.getColumns() ) {
			Matrix m3(myRows, myColumns);
			for (unsigned i = 0; i < myRows; i++) {
				for (unsigned j = 0; j < myColumns; j++) {
					m3[i][j] = (myVec[i][j] - m2.myVec[i][j]);
				}
			}
			return m3;
		} else {
			throw invalid_argument("Different sized matrices!");
		}
	} else {
		throw invalid_argument("Different sized matrices!");
	}
}

//Matrix Class method that receives an output stream and write the contents
//of a Matrix to a text file.
template<class Item>
void Matrix<Item>::writeTo(ostream& out) const {
	/*
	 * Stream Output
	 * @param: ofstream
	 * Postcondition: stream has already been opened
	 * Written by Ethan Clark
	 */

	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] << " ";
		}
		out << '\n';
	}
}

//Matrix Class method that receives a filename and reads in the contents
//of the text file and creates a Matrix with those values.
template<class Item>
void Matrix<Item>::readFrom(const string& filename) {
	/*
	 * File input
	 * @param: string filename
	 * Postcondition: filename must exist as a txt file
	 * Written by Ethan Clark
	 */

	ifstream fin( filename.c_str() );
	assert ( fin.is_open() );

	fin >> myRows;
	fin >> myColumns;

	myVec.setSize(myRows);

	for (unsigned i = 0; i < myRows; i++) {
		myVec[i].setSize(myColumns);
	}

	for ( unsigned i = 0; i < myRows; i++ ) {
		for ( unsigned j = 0; j < myColumns; j++ ) {
			fin >> myVec[i][j];
		}
	}

	fin.close();
}

//Matrix Class method that returns a Matrix whose rows are a different Matrix's
//columns and whose columns are the other Matrix's rows.
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() const {
	/*
	 * Transpose a Matrix
	 * No parameters
	 * @return: matrix with flipped columns and rows
	 * Written by Ethan Clark
	 */

	Matrix mat(myColumns, myRows);

	for ( unsigned i = 0; i < myRows; i++ ) {
		for ( unsigned j = 0; j < myColumns; j++ ) {
			mat[j][i] = myVec[i][j];
		}
	}
	return mat;
}

//Matrix Class method that returns true if two matrices are not the same
// and returns false if the two matrices are the same.
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) {

	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return true;
	}
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			if (myVec[i][j] != m2[i][j]) {
				return true;
			}
		}
	}
	return false;
}

//Matrix Class method that adds one Matrix to another.
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& m2) {

	if ( myRows == m2.getRows() ) {
		if ( myColumns == m2.getColumns() ) {
			Matrix m3(myRows, myColumns);
			for (unsigned i = 0; i < myRows; i++) {
				for (unsigned j = 0; j < myColumns; j++) {
					m3[i][j] = (myVec[i][j] + m2.myVec[i][j]);
				}
			}
			return m3;
		} else {
			throw invalid_argument("Different sized matrices!");
		}
	} else {
		throw invalid_argument("Different sized matrices!");
	}
}

//Matrix Class method that receives a filename and writes out the contents
//of a Matrix to that file.
template<class Item>
void Matrix<Item>::writeTo(const string& filename) {

	ofstream out( filename.c_str() );
	assert ( out.is_open() );

	out << myRows;
	out << " ";
	out << myColumns;
	out << '\n';

	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] << " ";
		}
		out << '\n';
	}

	out.close();
}

//Matrix Class method that receives an input stream, opens a connection to that file,
// and reads in a Matrix's contents and puts them in the Matrix.
template<class Item>
void Matrix<Item>::readFrom(ifstream& in) {

	for ( unsigned i = 0; i < getRows(); i++ ) {
		for ( unsigned j = 0; j < getColumns(); j++ ) {
			in >> myVec[i][j];
		}
	}
}

#endif
