/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name: Ethan Clark
 * Date: April 7, 2015
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast-1] == getLast().
 * 
 *  (When I am not empty:
 *     myFirst is the index of my oldest value;
 *     myLast is the index of the spot where the next
 *       item to be appended will be placed.)      
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <iostream>
#include <cstring>

using namespace std;

template <class Item>
class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue& original);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	ArrayQueue(unsigned capacity);
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	Item remove();
	void setCapacity(const unsigned& newCapacity);

protected:
	virtual void makeCopyOf(const ArrayQueue& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirst;      // index of oldest item (if any)
	unsigned myLast;       // index of next available spot for append (if any)
	Item*    myArray;      // dynamic array of items

	friend class ArrayQueueTester;
};

/*
 * Constructor for the ArrayQueue class
 * set mySize, myFirst, and myLast to 0
 * set myCapacity to parameter capacity
 * if capacity is 0 or less than, throw Exception
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
template <class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
	if (capacity > 0) {
		myCapacity = capacity;
		mySize = myFirst = myLast = 0;
		myArray = new Item[capacity];
	}
	else {
		throw QueueException("Constructor", "Capacity must be positive");
	}
}

template <class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity*sizeof(Item) );
}

template <class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

template <class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}

template <class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

template <class Item>
//ArrayQueue method that returns if the Queue is empty or not
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

template <class Item>
//ArrayQueue method that returns if the Queue is full or not
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

template <class Item>
//ArrayQueue method that returns the capacity of the Queue
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

template <class Item>
//ArrayQueue method that returns the current size of the Queue
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

/*
 * getFirst()
 * returns the first element in the Queue if Queue is not empty
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
template <class Item>
Item ArrayQueue<Item>::getFirst() const {

	if (isEmpty()) {
		throw EmptyQueueException("getFirst()");
	}
	else {
		return myArray[myFirst%myCapacity];
	}
}

/*
 * getLast()
 * returns the last element in the Queue if Queue is not empty
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
template <class Item>
Item ArrayQueue<Item>::getLast() const {

	if (isEmpty()) {
		throw EmptyQueueException("getLast()");
	}
	else {
		return myArray[(myLast-1+myCapacity) % myCapacity];
	}
}

/*
 * append()
 * parameters: Item it
 * adds the Item to the end of the Queue
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
template <class Item>
void ArrayQueue<Item>::append(const Item& it) {

	if (isFull()) {
		throw FullQueueException("append()");
	}
	else {
		myArray[myLast] = it;
		mySize += 1;
		myLast = (myLast + 1) % myCapacity;
	}
}

/*
 * remove()
 * method that removes and returns the oldest Item in the Queue
 * return: Item
 * written by Ethan Clark
 * written for Lab8 for CS112
 */
template <class Item>
Item ArrayQueue<Item>::remove() {

	if (isEmpty()) {
		throw EmptyQueueException("remove()");
	}
	Item result = myArray[myFirst];
	myFirst = (myFirst+1) % myCapacity;
	mySize -= 1;
	return result;
}

/*
 * setCapacity()
 * ArrayQueue method that changes the capacity of the current queue
 * 	throwing an exception if the newCapacity is less than zero or less than
 * 	the current size ( getSize() )
 * @param: int newCapacity
 * written by Ethan Clark (elc3)
 * written for Project 8 for CS112
 */
template <class Item>
void ArrayQueue<Item>::setCapacity(const unsigned& newCapacity) {

	//Throw exception if newCapacity is less than zero or the current size
	if ( newCapacity == 0 or newCapacity < getSize() ) {
		throw QueueException("setCapacity()", "new capacity is too small");
	}

	//Create a new array with capacity of newCapacity
	Item * newArray = new Item[newCapacity];

	//Copy the Items from myArray into the newArray
	for (unsigned i = myFirst; i < myFirst+mySize; i++) {
		newArray[i-myFirst] = myArray[i%myCapacity];
	}

	//Set the instance variable of myCapacity to be the newCapacity
	myCapacity = newCapacity;

	//Set myFirst to the zero index and set myLast to be the last element in the queue
	myFirst = 0;
	myLast = myFirst + mySize;

	//Deallocate myArray, assign myArray to newArray, then deallocate newArray
	delete [] myArray;
	myArray = newArray;
}

#endif /*ARRAY_QUEUE_H_*/
