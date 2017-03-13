/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Ethan Clark
 * Date: April 7, 2015
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;

/*
 * Constructor for the ArrayQueue class
 * set mySize, myFirst, and myLast to 0
 * set myCapacity to parameter capacity
 * if capacity is 0 or less than, throw Exception
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
ArrayQueue::ArrayQueue(unsigned capacity) {
	if (capacity > 0) {
		myCapacity = capacity;
		mySize = myFirst = myLast = 0;
		myArray = new Item[capacity];
	}
	else {
		throw QueueException("Constructor", "Capacity must be positive");
	}
}

void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity*sizeof(Item) );
}

ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

ArrayQueue::~ArrayQueue() {
	delete [] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}


ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

//ArrayQueue method that returns if the Queue is empty or not
bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

//ArrayQueue method that returns if the Queue is full or not
bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

//ArrayQueue method that returns the capacity of the Queue
unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

//ArrayQueue method that returns the current size of the Queue
unsigned ArrayQueue::getSize() const {
	return mySize;
}

/*
 * getFirst()
 * returns the first element in the Queue if Queue is not empty
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
Item ArrayQueue::getFirst() const {

	if (isEmpty()) {
		throw EmptyQueueException("getFirst()");
	}
	else {
		return myArray[myFirst%5];
	}
}

/*
 * getLast()
 * returns the last element in the Queue if Queue is not empty
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
Item ArrayQueue::getLast() const {

	if (isEmpty()) {
		throw EmptyQueueException("getLast()");
	}
	else {
		return myArray[myLast%5 - 1];
	}
}

/*
 * append()
 * parameters: Item it
 * adds the Item to the end of the Queue
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
void ArrayQueue::append(const Item& it) {

	if (isFull()) {
		throw FullQueueException("append()");
	}
	else {
		myArray[myLast%5] = it;
		mySize += 1;
		myLast += 1;
	}
}

/*
 * remove()
 * method that removes and returns the oldest Item in the Queue
 * return: Item
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
Item ArrayQueue::remove() {

	if (isEmpty()) {
		throw EmptyQueueException("remove()");
	}
	Item result = getFirst();
	mySize -= 1;
	myArray[myFirst%5] = 0;
	myFirst += 1;
	return result;
}
