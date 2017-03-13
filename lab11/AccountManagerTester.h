/* AccountManagerTester.h declares a test-class for class AccountManager.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Ethan Clark (elc3)
 * May 12, 2015
 * Lab11 for CS112
 */

#ifndef ACCOUNTMANAGERTESTER_H_
#define ACCOUNTMANAGERTESTER_H_

#include "AccountManager.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class AccountManagerTester {
public:
   void runTests();
   void testCreateAndDelete();
   void testChangeUser();
   void testChangePassword();
};

#endif /*ACCOUNTMANAGERTESTER_H_*/

