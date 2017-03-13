/*
 * BSTApplication.h
 * Created on: Apr 22, 2015
 * Author: Ethan Clark
 * Project9 for CS112
 */

#ifndef BSTAPPLICATION_H_
#define BSTAPPLICATION_H_

#include <iostream>
#include <fstream>
#include <cassert>
#include "BST.h"
#include "Exception.h"
#include <cstdlib>
using namespace std;

typedef double Item;

class BSTApplication {
public:
	BSTApplication(const string& input_file);
	void readFrom();
	void displayHeight() const;
private:
	string myInput_file;
	BST<Item> binary_tree;
	unsigned duplicate_counter;

};

#endif /* BSTAPPLICATION_H_ */
