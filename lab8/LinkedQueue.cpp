/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ethan Clark
 * Date: April 7, 2015
 */

#include "LinkedQueue.h"

/*
 * LinkedQueue Constructor
 * initialize mySize to 0
 * initialize myFirst and myLast to NULL
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirst = myLast = NULL;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirst = myLast = NULL;
	} else {
		myFirst = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirst->myNext;
		Node * temp1 = myFirst;
		while (temp0 != NULL) {
			temp1->myNext = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNext;
			temp0 = temp0->myNext;
		}
		myLast = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirst;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

/*
 * getFirst()
 * returns the first Item in the Queue
 * throws exception if Queue is empty
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
Item LinkedQueue::getFirst() const {

	if (isEmpty()) {
		throw EmptyQueueException("getFirst()");
	}
	return myFirst->myItem;
}

/*
 * geLast()
 * returns the Last Item in the Queue
 * throws exception if Queue is empty
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
Item LinkedQueue::getLast() const {

	if (isEmpty()) {
		throw EmptyQueueException("getLast()");
	}
	return myLast->myItem;
}

/*
 * append()
 * parameters: Item it
 * adds the Item to the end of the Queue
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
void LinkedQueue::append(const Item& it) {

	try {
		Node * nPtr = new Node(it, NULL);
		if (isEmpty()) {
			myFirst = nPtr;
		}
		else {
			myLast->myNext = nPtr;
		}
		myLast = nPtr;
		mySize += 1;
	}
	catch(std::bad_alloc) {
		throw FullQueueException("append()");
	}
}

/*
 * remove()
 * returns the Item that it removed from the Queue
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
Item LinkedQueue::remove() {

	if (isEmpty()) {
		throw EmptyQueueException("remove()");
	}
	Item result = myFirst->myItem;
	Node * nptr = myFirst;
	myFirst = myFirst->myNext;
	nptr->myNext = NULL;
	delete nptr;
	mySize -= 1;
	return result;
}
