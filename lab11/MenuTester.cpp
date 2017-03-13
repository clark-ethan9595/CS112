/* MenuTester.cpp defines test-methods for class Menu.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Ethan CLark (elc3)
 * May 12, 2014
 * Lab11 for CS112
 */

#include "MenuTester.h"

void MenuTester::runTests() {
	cout << "Testing the Menu class..." << endl;
	Menu m;
	assert( m.containsChoice('a') );
	assert( m.containsChoice('b') );
	assert( m.containsChoice('c') );
	assert( m.containsChoice('d') );
	assert( m.containsChoice('q') );
	assert( !m.containsChoice('e') );
	cout << "Passed!\n" << endl;
}

