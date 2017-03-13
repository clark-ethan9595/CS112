/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

#include "List.h"            // List
#include <iostream>          // cin, cout
#include <cassert>           // assert()
#include <cstdlib>           // exit()
#include <stdexcept>         // underflow_error
#include <fstream>		     // ifstream, ofstream

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testReadFromStream();
	void testWriteTo();
	void testReadFromString();
	void testWriteToString();
	void testPrepend();
	void testGetIndexOf();
	void testInsert();
	void testRemove();
	void testSort();
};

#endif /*LISTTESTER_H_*/
