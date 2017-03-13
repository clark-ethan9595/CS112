/* MovieTester.h
 * Student Name: Ethan Clark
 * Date: February 11, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Project1
 */

#ifndef MOVIETESTER_H_
#define MOVIETESTER_H_

// Includes for the Movie Tester Class
#include "Movie.h"
#include <iostream>
using namespace std;

// Creation of the Movie Tester Class and its prototypes.
class MovieTester {
public:
   void runTests() const;
   void testDefaultConstructor() const;
   void testExplicitConstructor() const;
   void testReadFrom() const;
   void testWriteTo() const;
   void testComparison() const;
};

#endif /*MOVIETESTER_H_*/
