/* CollectionTester.h tests the MovieCollection class.
 * Student Name: Ethan Clark
 * Date: February 11, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Project1
 */

#ifndef COLLECTIONTESTER_
#define COLLECTIONTESTER_

// Includes for the Collection Tester Class.
#include <cassert>
#include <iostream>
#include "MovieCollection.h"
#include <fstream>
using namespace std;

// Creation of the Collection Tester Class and its prototypes.
class CollectionTester {
public:
	void testConstructor() const;
    void runTests() const;
    void testSearchByYear() const;
    void testSearchByTitlePhrase() const;
    void testAddandRemoveMethods() const;
    void testSave() const;
};

#endif /*COLLECTIONTESTER_*/
