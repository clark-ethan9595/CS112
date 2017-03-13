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

typedef double Item;

//Declaration of the Vec Class and its methods, both private and public
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

};

#endif /*VEC_H_*/
