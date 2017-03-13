/*
 * BSTApplicationTester.cpp
 * Created on: Apr 23, 2015
 * Author: Ethan Clark
 * Project9 for CS112
 */

#include "BSTApplicationTester.h"

void BSTApplicationTester::runTests() {

	cout << "Testing Binary Search Tree Application" << endl;

	cout << "- Trial One:" << endl;
	BSTApplication BST("PracticeText.txt");
	BST.readFrom();
	BST.displayHeight();

	cout << "- Trial Two:" << endl;
	BSTApplication BST1("PracticeText1.txt");
	BST1.readFrom();
	BST1.displayHeight();

	cout << "- Trial Three:" << endl;
	BSTApplication BST2("PracticeText2.txt");
	BST2.readFrom();
	BST2.displayHeight();

	cout << "Tests Complete!" << endl;
}

