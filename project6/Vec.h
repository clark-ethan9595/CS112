/* Vec.h provides a simple vector class named Vec.
 * Student Names: Ethan Clark (Student One) and Thomas Dykstra (Student Two)
 * Date: March 2, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

//Includes for the Vec Class
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <fstream>
using namespace std;

//Declaration of the Vec Class and its methods, both private and public
template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	bool operator!=(const Vec& v2);
	Vec operator-(const Vec& v1);
	void readFrom(const string& filename);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	void writeTo(string fileName);
	Vec operator+(const Vec& v2);
	double operator*(const Vec& v2);
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
	friend class MatrixTester;

};

//Default Constructor for the Vec class
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

//Explicit Constructor for the Vec class
template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size]();
}

//Copy constructor for the Vec class
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
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
template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

//Assignment Operator for the Vec class
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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
template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

//Vec class method that sets a certain index to a value
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}
	else {
		myArray[index] = it;
	}
}

//Vec class method that returns the value at a certain index
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}
	else {
		return myArray[index];
	}
}

//Vec class method that sets the size of the Vec
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
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
template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << " ";
	}
}

//Vec class method that reads in elements from a file and puts them in a Vec
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

/*
 * Ethan Clark (student one) wrote the next three methods
 * Vec class method that compares two vecs, returning true if they are not equal
 * and returning false if they are equal
 */
template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) {
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
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v1) {
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
template<class Item>
void Vec<Item>::readFrom(const string& filename) {
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
template<class Item>
void Vec<Item>::writeTo(string fileName){
	ofstream out ( fileName.c_str() );
	assert (out.is_open());
	out << mySize << endl;
	for (unsigned i = 0; i<mySize; i++){
		out << myArray[i] << endl;
	}
}

//Vec class method that adds two vecs together
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) {
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
template<class Item>
double Vec<Item>::operator*(const Vec<Item>& v2) {
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
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {

	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}

	return myArray[index];
}

//Student Two Method (Thomas Dykstra)
//Vec class method that assigns the value to the given index using the subscript operator
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {

	if ( index >= mySize ) {
		throw range_error("Invalid index");
	}
	return myArray[index];
}

/*
 * merge() method written to merge two Vecs together and put them in ascending order
 * written by Ethan Clark (elc3)
 * written for project 6 for CS 112
 * March 29, 2015
 */
template<class Item>
void mergeVec(const Vec<Item>& Vec1, const Vec<Item>& Vec2, Vec<Item>& Vec3) {

	//Create three counter variables for the three Vecs
	unsigned i = 0;
	unsigned j = 0;
	unsigned k = 0;

	//While loop to run while i and j are less than the sizes of the Vecs, respectively
	while (i < Vec1.getSize() and j < Vec2.getSize()) {

		//If the current element in Vec1 is less than the current element in Vec2...
		if (Vec1[i] < Vec2[j]) {
			Vec3[k] = Vec1[i];
			i++;
		}

		//Else if the current element in Vec2 is less than the current element in Vec1...
		else {
			Vec3[k] = Vec2[j];
			j++;
		}

		//Increase the Vec3 counter variable
		k++;

		//If i is greater than Vec1's size and j is not greater than Vec2's size...
		if (i >= Vec1.getSize() and j < Vec2.getSize()) {
			while (j < Vec2.getSize()) {
				Vec3[k] = Vec2[j];
				j++;
				k++;
			}
		}

		//If j is greater than Vec2's size and i is not greater than Vec1's size...
		if (j >= Vec2.getSize() and i < Vec1.getSize()) {
			while (i < Vec1.getSize()) {
				Vec3[k] = Vec1[i];
				i++;
				k++;
			}
		}
	}
}

/*
 * sortVec() method to sort the elements of a Vec in ascending order
 * written by Ethan Clark (elc3)
 * written for project 6 for CS 112
 * March 25, 2015
 */
template <class Item>
void sortVec(Vec<Item>& original) {

	//Create two new Vecs
	Vec<double> LeftVec;
	Vec<double> RightVec;

	//Make sure the size of the Vec is greater than one
	if (original.getSize() > 1) {

		//Get the mid value of the size of the Vec
		int mid = original.getSize() / 2;

		//If the size is an odd number...
		if (original.getSize() % 2 != 0) {

			LeftVec.setSize(mid);
			RightVec.setSize(mid + 1);

			for (int i = 0; i < mid; i++) {
				LeftVec[i] = original[i];
			}

			int j = 0;
			for (unsigned i = mid; i < original.getSize(); i++) {
				RightVec[j] = original[i];
				j++;
			}
		}

		//else if the size is an even number...
		else {

			LeftVec.setSize(mid);
			RightVec.setSize(mid);

			for (int i = 0; i < mid; i++) {
				LeftVec[i] = original[i];
			}

			int j = 0;
			for (unsigned i = mid; i < original.getSize(); i++) {
				RightVec[j] = original[i];
				j++;
			}
		}

		//Recursive call to now sort the two new Vecs
		sortVec(LeftVec);
		sortVec(RightVec);

		//Create a new Vec with the size of RightVec + LeftVec
		Vec<double> Vec3(LeftVec.getSize() + RightVec.getSize());

		//Create a new Vec by merging two Vecs
		mergeVec(LeftVec, RightVec, Vec3);

		original = Vec3;
	}
}

#endif /*VEC_H_*/
