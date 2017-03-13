/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin College.
 * Ethan Clark (elc3)
 * Project 8 for CS112
 * April 19, 2015
 */

#include "ArrayQueueTester.h"
#include "PalindromeDetectorTester.h"

int main() {

	ArrayQueueTester aqt;
	aqt.runTests();

	PalindromeDetectorTester pd;
	pd.runTests();

}


