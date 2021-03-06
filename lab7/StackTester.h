/*
 * StackTester.h declares a test-class for a dynamically allocated (array) Stack.
 * Ethan Clark (elc3)
 * March 31, 2015
 * Joel Adams, for CS 112 at Calvin College
 */

#ifndef STACKTESTER_H_
#define STACKTESTER_H_


class StackTester {
public:
	void runTests();
	void testConstructor();
	void testIsEmpty();
	void testPushAndIsFull();
	void testGetTop();
	void testPop();
	void testCopyConstructor();
	void testAssignment();
	void testDestructor();
};

#endif /*STACKTESTER_H_*/

