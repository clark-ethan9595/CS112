/*
 * PalindromeDetector.h
 * Created on: Apr 16, 2015
 * Author: ethanclark (elc3)
 * Project 8 for CS112
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

#include <iostream>
#include <fstream>
#include <cassert>
#include "Stack.h"
#include "ArrayQueue.h"
using namespace std;

class Palindrome_Detector {
public:
	Palindrome_Detector(const string& file1, const string& file2);
	void detectPalindromes();
	bool isPalindrome(const string& str);
private:
	string myInputfile;
	string myOutputfile;
};

#endif /* PALINDROMEDETECTOR_H_ */
