/* Vec.h provides a simple vector class named Vec.
 * Student Name: Ethan Clark
 * Date: February 24, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

//Includes for the Vec class
#include <iostream>
#include <stdexcept>
using namespace std;

//Create double Item which can be easily changed here
typedef double Item;

//Class Vec and its public and private methods and variables.
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
	bool operator==(const Vec& v2);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;

};

#endif /*VEC_H_*/
