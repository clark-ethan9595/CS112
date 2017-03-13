/*
 * Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Ethan Clark
 * Date: March 31, 2015
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: size, an unsigned value.
 * Precondition: size > 0.
 * Postcondition: myTop == 0 && myCapacity == size
 *              && myArray contains the address of a dynamic array of 'size' entries.
 */
Stack::Stack(unsigned size) {

	if ( size > 0) {
		myTop = 0;
		myCapacity = size;
		myArray = new Item[size];
	}
	else {
		throw StackException("Stack(size)", "size must be positive!");
	}
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	myTop = original.myTop;
}

/* destructor
 * Postcondition: myCapacity == 0 && myTop == 0
 *             && myArray has been deallocated.
 */
Stack::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	myTop = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/*
 * isEmpty()
 * Returns true if the stack has no items
 * Returns false if the stack has at least one item
 * written by Ethan Clark (elc3)
 * written for Lab7 for CS112
 */
bool Stack::isEmpty() {

	if (myTop == 0) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * isFull()
 * Returns true if the stack's capacity is the same as the number
 * 		of Items it has
 * Returns false if the stack's capacity is not the same as the
 * 		number of Items it has
 * written by Ethan Clark (elc3)
 * written for Lab7 for CS112
 */
bool Stack::isFull() {

	if (myTop == myCapacity) {
		return true;
	}
	else {
		return false;
	}
}

/*
 * push(const Item& it)
 * parameters: an Item of any type
 * postcondition: adds the Item to the array
 * written by Ethan Clark (elc3)
 * written for Lab7 for CS112
 */
void Stack::push(const Item& it) {

	if (myTop == myCapacity) {
		throw StackException("push()", "stack is full!");
	}
	else {
		myArray[myTop] = it;
		myTop += 1;
	}
}

/*
 * getTop()
 * returns the top item of the stack
 * does not modify the stack in any way
 * written by Ethan Clark (elc3)
 * written for Lab7 for CS112
 */
Item Stack::getTop() const {

	if (myTop > 0) {
		return myArray[myTop - 1];
	}
	else {
		throw StackException("getTop()", "stack is empty");
	}
}

/*
 * pop()
 * removes and returns the top value from the Stack
 * postcondition: myTop is one less than before
 * written by Ethan Clark (elc3)
 * written for Lab7 for CS112
 */
Item Stack::pop() {

	if (myTop == 0) {
		throw StackException("pop()", "stack is empty!");
	}
	else {
		myTop -= 1;
		return myArray[myTop];
	}
}
