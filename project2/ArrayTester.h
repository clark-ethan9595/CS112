/*ArrayTester.h provides a class to test C-style array operations.
 * Student: Ethan Clark
 * Date: February 22, 2015
 * By: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef ARRAY_TESTER_H_
#define ARRAY_TESTER_H_

//Includes for the ArrayTester class.
#include "array.h"  // the functions we are testing
#include <iostream>
#include <cassert>
using namespace std;

//Declaring the private and public methods of the ArrayTester class.
class ArrayTester
{
public:
	ArrayTester();
	virtual ~ArrayTester();
	void runTests();
	void setup();
	void cleanup();
	void testInitialize();
	void testPrint();
	void testAverage();
	void testSum();
	void testResize();
	void testConcat();
	void testFill();
	void testRead();
private:
	double * a1;
	double * a2;
	double * a3;
};

#endif /*ARRAY_TESTER_H_*/
