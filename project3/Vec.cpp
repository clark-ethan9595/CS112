/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Names: Ethan Clark (Student One) and Thomas Dykstra (Student Two)
 * Date: March 2, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

//Include the header file for this class
#include "Vec.h"

//Default Constructor for the Vec class
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

//Explicit Constructor for the Vec class
Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size]();
}

//Copy constructor for the Vec class
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if ( original.mySize > 0 ) {
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
	else {
		myArray = NULL;
	}
}

//Destructor to deallocate the memory for myArray for the Vec class
Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

//Assignment Operator for the Vec class
Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize != original.mySize) {
			if (mySize > 0) {
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

//Vec class method that returns the size of the Vec
unsigned Vec::getSize() const {
	return mySize;
}

//Vec class method that sets a certain index to a value
void Vec::setItem(unsigned index, const Item& it) {
	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}
	else {
		myArray[index] = it;
	}
}

//Vec class method that returns the value at a certain index
Item Vec::getItem(unsigned index) const {
	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}
	else {
		return myArray[index];
	}
}

//Vec class method that sets the size of the Vec
void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete [] myArray;
			myArray = NULL;
			mySize = 0;
		}
		else {
			Item *newArray = new Item[newSize];
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; i++) {
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize; i < newSize; i++) {
					newArray[i] = 0;
				}
			}
			else {
				for (unsigned i = 0; i < newSize; i++) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}
	}
}

//Vec class method that compares two Vecs and returns true if they are the same
//and returns false if they are not the same
bool Vec::operator==(const Vec& v2) {
	if (mySize != v2.getSize()) {
		return false;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArray[i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

//Vec class method to write the Vecs elements to a file
void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << " ";
	}
}

//Vec class method that reads in elements from a file and puts them in a Vec
void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

/*
 * Ethan Clark (student one) wrote the next three methods
 * Vec class method that compares two vecs, returning true if they are not equal
 * and returning false if they are equal
 */
bool Vec::operator!=(const Vec& v2) {
	if (mySize != v2.getSize()) {
		return true;
	}
	if (mySize == v2.getSize()) {
		for (unsigned i = 0; i < mySize; i++) {
			if (myArray[i] != v2.myArray[i]) {
				return true;
			}
		}
	}
	return false;
}

//Vec class method that takes two vecs and subtracts one from the other
Vec Vec::operator-(const Vec& v1) {
	if ( mySize == v1.getSize() ) {
		Vec v3(mySize);
		for ( unsigned i =0; i < mySize; i++ ) {
			v3.myArray[i] = ( myArray[i] - v1.myArray[i] );
		}
		return v3;
	}
	else {
		throw invalid_argument("Different sized vecs");
	}
}

//Vec class method that reads in values from a file and puts them in a Vec
void Vec::readFrom(const string& filename) {
	ifstream fin( filename.c_str() );
	assert ( fin.is_open() );

	fin >> mySize;

	delete [] myArray;

	myArray = new Item[mySize];

	for ( unsigned i = 0; i < mySize; i++ ) {
		fin >> myArray[i];
	}

	fin.close();
}
//end Student One methods

/*
 * Thomas Dykstra (Student Two) wrote the next three methods
 * Vec class method that writes a Vec's elements to a file
 */
void Vec::writeTo(string fileName){
	ofstream out ( fileName.c_str() );
	assert (out.is_open());
	out << mySize << endl;
	for (unsigned i = 0; i<mySize; i++){
		out << myArray[i] << endl;
	}
}

//Vec class method that adds two vecs together
Vec Vec::operator+(const Vec& v2) {
	//operator= takes care of possible memory leak of v3
	if ( mySize == v2.getSize() ) {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; i++){
			v3.myArray[i] = (myArray[i] + v2.myArray[i]);
		}
	return v3;
	}
	else {
		throw invalid_argument("One Size is Too Big");
}
}

//Vec class method that returns the dot product of two vecs
double Vec::operator*(const Vec& v2) {
	double dProd = 0;
	if ( mySize == v2.getSize() ){
		for (unsigned i=0; i<mySize; i++){
			dProd += (myArray[i] * v2.myArray[i]);
		}
		return dProd;
	}
	else {
		throw invalid_argument("Different sized Vecs");
	}
}
//end Student Two methods.

//Student One Method (Ethan Clark)
//Vec class method that returns the value at a given index using the subscript operator
const Item& Vec::operator[](unsigned index) const {

	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}

	return myArray[index];
}

//Student Two Method (Thomas Dykstra)
//Vec class method that assigns the value to the given index using the subscript operator
Item& Vec::operator[](unsigned index) {

	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}
	return myArray[index];
}
