/*
 * Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Ethan Clark
 * Date: March 31, 2015
 * 
 * Invariant: myTop == 0 && isEmpty() && !isFull()
 *         || myTop == myCapacity && !isEmpty() && isFull()
 *         || myTop > 0 && myTop < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member myTop always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or getTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

template <class Item>
class Stack {
public:
	Stack(unsigned size);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty();
	bool isFull();
	void push(const Item& it);
	Item getTop() const;
	Item pop();
	unsigned getSize() const;
	unsigned getCapacity() const;
	void setCapacity(const unsigned& newCapacity);
	
protected:
	void makeCopyOf(const Stack& original);
	
private:
	unsigned myCapacity;
	unsigned myTop;
	Item*    myArray;
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: size, an unsigned value.
 * Precondition: size > 0.
 * Postcondition: myTop == 0 && myCapacity == size
 *              && myArray contains the address of a dynamic array of 'size' entries.
 */
template <class Item>
Stack<Item>::Stack(unsigned size) {

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
template <class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template <class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
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
template <class Item>
Stack<Item>::~Stack() {
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
template <class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
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
template <class Item>
bool Stack<Item>::isEmpty() {

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
template <class Item>
bool Stack<Item>::isFull() {

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
template <class Item>
void Stack<Item>::push(const Item& it) {

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
template <class Item>
Item Stack<Item>::getTop() const {

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
template <class Item>
Item Stack<Item>::pop() {

	if (myTop == 0) {
		throw StackException("pop()", "stack is empty!");
	}
	else {
		myTop -= 1;
		return myArray[myTop];
	}
}

/*
 * getSize()
 * returns the number of Items currently in the Stack
 * written by Ethan Clark (elc3)
 * written for project7 for CS112
 * March 31, 2015
 */
template <class Item>
unsigned Stack<Item>::getSize() const {

	return myTop;
}

/*
 * getCapacity()
 * returns the current capacity of the Stack
 * written by Ethan Clark (elc3)
 * written for project7 for CS112
 * March 31, 2015
 */
template <class Item>
unsigned Stack<Item>::getCapacity() const {

	return myCapacity;
}

/*
 * setCapacity()
 * parameters: newCapacity for the Stack that is greater than the myTop value
 * postcondition: a Stack with newCapacity capacity
 * written by Ethan Clark (elc3)
 * written for project7 for CS112
 * March 31, 2015
 */
template <class Item>
void Stack<Item>::setCapacity(const unsigned& newCapacity) {

	if ( newCapacity < getSize() ) {
		throw StackException("setCapacity()", "New Capacity is too small");
	}

	if ( newCapacity > getSize() ) {
		myCapacity = newCapacity;
		Item* newArray;
		newArray = new Item[newCapacity];
		for (unsigned i = 0; i < getSize(); i++) {
			newArray[i] = myArray[i];
		}
		delete [] myArray;
		myArray = newArray;
	}
}

#endif

