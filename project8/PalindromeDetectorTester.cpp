/*
 * PalindromeDetectorTester.cpp
 * Created on: Apr 16, 2015
 * Author: ethanclark (elc3)
 * Project 8 for CS112
 */

#include "PalindromeDetectorTester.h"

void PalindromeDetectorTester::runTests() {

	cout << "Testing PalindromeDetector..." << flush;

	Palindrome_Detector pd1("testPalindrome.txt", "testPalindromeDone.txt");
	pd1.detectPalindromes();
	cout << " 1 " << flush;

	Palindrome_Detector pd2("testPalindrome1.txt", "testPalindromeDone1.txt");
	pd2.detectPalindromes();
	cout << " 2 " << flush;

	cout << "Passed!" << endl;

}