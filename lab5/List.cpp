/* List.cpp
 * Methods for the List Class
 * Created on: Mar 10, 2015
 * Author: elc3
 */

#include "List.h"

//Default Constructor for the List Class
List::List() {

	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

//Destructor for the List Class
List::~List() {

	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}

//Default Node Constructor for the Node Struct in the List Class
List::Node::Node() {

	myItem = 0;
	myNext = NULL;
}

//Explicit Node Constructor for the Node Struct in the List Class
List::Node::Node(Item it, Node * next) {

	myItem = it;
	myNext = next;
}

//Destructor for the Node Struct in the List Class
List::Node::~Node() {

	delete myNext;  // delete the next node, invoking ~Node() in it
					// (does nothing if myNext == NULL)
	myNext = NULL;  // clear myNext (optional)
	myItem = 0;     // clear myItem (optional)
}

//Copy Constructor for the List Class
List::List(const List& original) {
	myFirst = myLast = NULL;			// set pointers
	mySize = 0;							// and size to 'empty' values
	if (original.getSize() > 0) {		// if there are nodes to copy:
		Node* oPtr = original.myFirst;	// start at the first node
		while (oPtr != NULL) {			// while there are more nodes
			append(oPtr->myItem);		// append the item in that node
			oPtr = oPtr->myNext;		// advance to next node
		}
	}
}

//Accessor Method for the List Class to return the List's Size
unsigned List::getSize() const {

	return mySize;
}

//Accessor Method for the List Class to return the first item in the list
Item List::getFirst() const {

	if ( mySize <= 0 or myFirst == NULL ) {
		throw underflow_error("Unable to access first element");
	}
	return myFirst->myItem;
}

//Accessor Method for the List Class to return the last item in the list
Item List::getLast() const {

	if ( mySize <= 0 or myLast == NULL ) {
		throw underflow_error("Unable to access last element");
	}
	return myLast->myItem;
}

//Append an item to the current List
void List::append(const Item& it) {

	Node * nodePtr = new Node(it, NULL);

	if ( mySize == 0 ) {
		myFirst = nodePtr;
	} else {
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize += 1;
}

//Assignment Operator for the List Class
List& List::operator=(const List& original) {

	if (this == &original) {
		return *this;
	}

	if (this != &original) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node * nPtr = original.myFirst;
			while (nPtr != NULL) {
				append(nPtr->myItem);
				nPtr = nPtr->myNext;
			}
		}
	}
	return *this;
}
