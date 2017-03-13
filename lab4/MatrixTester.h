/* MatrixTester.h declares test-methods for class Matrix.
 * Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

//Includes for the MatrixTester class.
#include "Matrix.h"

//Declaration of the MatrixTester class and its public and private information
class MatrixTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};

#endif /*MATRIXTESTER_H_*/
