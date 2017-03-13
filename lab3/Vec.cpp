/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Ethan Clark
 * Date: February 24, 2015
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
	if ( index < 0 or index >= mySize ) {
		throw range_error("Invalid index");
	}
	else {
		myArray[index] = it;
	}
}

//Vec class method that returns the value in a certain index
Item Vec::getItem(unsigned index) const {
	if ( index < 0 or index >= mySize ) {
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
