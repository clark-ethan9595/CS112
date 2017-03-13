/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Ethan Clark
 * Date: March 3, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

//Includes for the Matrix Class
#include "Vec.h"

typedef double Item;

//Declaration of the Matrix Class and its public and private information
class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const;
	unsigned getColumns() const;
	bool operator==(const Matrix& m2) const;
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

#endif
