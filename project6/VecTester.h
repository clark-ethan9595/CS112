/* VecTester.h provides unit tests for Vec, a simple vector class.
 * Student Names: Ethan Clark (Student One) and Thomas Dykstra (Student Two)
 * Date: March 2, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#ifndef VECTESTER_H_
#define VECTESTER_H_

#include "Vec.h"

//Declaring the VecTester Class with its methods
class VecTester {
public:
	void runTests() const;
	void testDefaultConstructor() const;
	void testExplicitConstructor() const;
	void testDestructor() const;
	void testGetSize() const;
	void testSetItem() const;
	void testGetItem() const;
	void testSetSize() const;
	void testCopyConstructor() const;
	void testAssignment() const;
	void testEquality() const;
	void testWriteToStream() const;
	void testReadFromStream() const;
	void testInequality() const;
	void testAddition() const;
	void testSubtraction() const;
	void testDotProduct() const;
	void testReadFromFile() const;
	void testWriteToFile() const;
	void SubscriptTester() const;
	void TestSortVec() const;
};

#endif /*VECTESTER_H_*/
