/* List.h
 * Header file for the List Class
 * Created on: Mar 23, 2015
 * Student One: Ethan Clark (elc3)
 * Student Two: Elizabeth Crow (emc37)
 */

#ifndef LIST_H_
#define LIST_H_

//Includes for the List Class
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cassert>
using namespace std;

//Declaration of the template List Class
template<class Item>
class List {
public:
	List();
	virtual ~List();
	List(const List& original);
	List& operator=(const List& original);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	bool operator!=(const List& l2) const;
	void writeTo(ostream& out) const;
	void readFrom(const string& filename);
	int getIndexOf(const Item& it) const;
	Item remove(unsigned index);
	bool operator==(const List& list1) const;
	void readFrom(istream& in);
	void writeTo(const string& filename) const;
	void prepend(const Item& it);
	void insert(const Item& it, unsigned index);
private:
	struct Node {
		Node();
		virtual ~Node();
		Node(Item it, Node * next);
		Item myItem;
		Node * myNext;
	};
	unsigned mySize;
	Node * myFirst;
	Node * myLast;
	friend class ListTester;
};

//Default Constructor for the List Class
template<class Item>
List<Item>::List() {

	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

//Destructor for the List Class
template<class Item>
List<Item>::~List() {

	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}

//Default Node Constructor for the Node Struct in the List Class
template<class Item>
List<Item>::Node::Node() {

	myItem = 0;
	myNext = NULL;
}

//Explicit Node Constructor for the Node Struct in the List Class
template<class Item>
List<Item>::Node::Node(Item it, Node * next) {

	myItem = it;
	myNext = next;
}

//Destructor for the Node Struct in the List Class
template<class Item>
List<Item>::Node::~Node() {

	delete myNext;  // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == NULL)
	myNext = NULL;  // clear myNext (optional)
	myItem = 0;     // clear myItem (optional)
}

//Copy Constructor for the List Class
template<class Item>
List<Item>::List(const List<Item>& original) {
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
template<class Item>
unsigned List<Item>::getSize() const {

	return mySize;
}

//Accessor Method for the List Class to return the first item in the list
template<class Item>
Item List<Item>::getFirst() const {

	if ( mySize <= 0 or myFirst == NULL ) {
		throw underflow_error("Unable to access first element");
	}
	return myFirst->myItem;
}

//Accessor Method for the List Class to return the last item in the list
template<class Item>
Item List<Item>::getLast() const {

	if ( mySize <= 0 or myLast == NULL ) {
		throw underflow_error("Unable to access last element");
	}
	return myLast->myItem;
}

//Append an item to the current List
template<class Item>
void List<Item>::append(const Item& it) {

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
template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {

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

//Begin Student 2 Methods (Elizabeth Crowe)

/* operator!=(const List<Item>& l2) const is the equivalence operator and determines
 * if two lists are identical
 * written by: Elizabeth Crow (emc37)
 * @param: const List<Item>& l2 is a const reference to the second list that a
 * list is being compared to.
 */
template<class Item>
bool List<Item>::operator!=(const List& l2) const {
	if (mySize != l2.mySize) {
		return true;
	}
	Node * list1Node = myFirst;
	Node * list2Node = l2.myFirst;
	while (list1Node != NULL) {
		if (list1Node->myItem != list2Node->myItem) {
			return true;
		}
		list1Node = list1Node->myNext;
		list2Node = list2Node->myNext;
	}
	return false;
}

/* writeTo(ostream& out) const writes a list to a specified out stream
 * written by: Elizabeth Crow (emc37)
 * @param: ostream& out, where the list is written to
 */
template<class Item>
void List<Item>::writeTo(ostream& out) const {
	Node * currentNode = myFirst;
	while (currentNode != NULL) {
		out << " " << currentNode->myItem;
		currentNode = currentNode->myNext;
	}
}

/* readFrom(const string& filename) reads in a list from a specified file
 * written by: Elizabeth Crow (emc37)
 * @param: the filename containing the list elements
 */
template<class Item>
void List<Item>::readFrom(const string& filename) {
	ifstream fin(filename.c_str());
	assert (fin.is_open());
	Item it;
	while (!fin.eof()) {
		fin >> it;
		append(it);
	}
	fin.close();
}

/* getIndexOf(const Item& it) const returns the index of an item if it appears in a list.
 * Otherwise, it returns -1
 * written by: Elizabeth Crow (emc37)
 * @param: a reference to a string called filename
 */
template<class Item>
int List<Item>::getIndexOf(const Item& it) const {
	Node * currentNode = myFirst;
	int index = 0;
	while (currentNode != NULL) {
		if (currentNode->myItem == it) {
			return index;
		}
		currentNode = currentNode->myNext;
		index++;
	}
	return -1;
}

/* remove(int index) returns the element at the specified index, and deletes it from the list
 * written by: Elizabeth Crow (emc37)
 * @param: the index of the item being removed
 * Note: If index is below 0, the first item is removed. If index is
 * greater than largest valid index, the last item is removed.
 */
template<class Item>
Item List<Item>::remove(unsigned index) {
	if (mySize == 0) {
		throw range_error("This list is empty");
	}
	Item removed = 0;
	if (mySize == 1) {
		removed = myFirst->myItem;
		mySize--;
		delete myFirst;
		myFirst = myLast = NULL;
		return removed;
	}
	Node * currentNode = myFirst;
	if (index <= 0) {
		myFirst = currentNode->myNext;
		currentNode->myNext = NULL;
		removed = currentNode->myItem;
		delete currentNode;
		mySize--;
		return removed;
	}
	unsigned i = 0;
	while (i < index -1 and i < mySize - 2) {
		currentNode = currentNode->myNext;
		i++;
	}
	if (mySize <= index + 1) {
		myLast = currentNode;
	}
	Node * tempNode = currentNode->myNext;
	removed = currentNode->myNext->myItem;
	currentNode->myNext = currentNode->myNext->myNext;
	tempNode->myNext = NULL;
	delete tempNode;
	mySize--;
	return removed;
}

//End Student 2 (Elizabeth Crowe) Methods

//Begin Student 1 (Ethan Clark) Methods

/* written by: Ethan Clark (elc3)
 * Equality Operator to return true if two lists are equal and false if two lists are not equal
 * @param: List of any size values and elements
 */
template<class Item>
bool List<Item>::operator==(const List& list1) const {

	if ( mySize != list1.getSize() ) {
		return false;
	}

	Node * firstnode = myFirst;
	Node * secondnode = list1.myFirst;
	while (firstnode != NULL) {
		if (firstnode->myItem != secondnode->myItem) {
			return false;
		}
		firstnode = firstnode->myNext;
		secondnode = secondnode->myNext;
	}
	return true;
}

/* written by Ethan Clark (elc3)
 * readFrom() method to read in values for a list from an input stream
 * @param: a valid input stream
 */
template<class Item>
void List<Item>::readFrom(istream& in) {

	Item it;
	while (true) {
		in >> it;
		this->append(it);
		if (in.eof()) {
			break;
		}
	}
}

/* written by Ethan Clark (elc3)
 * writeTo() method to write a list's values to a file
 * @param: a valid string of a filename
 */
template<class Item>
void List<Item>::writeTo(const string& filename) const {

	ofstream fout( filename.c_str() );
	assert (fout.is_open());

	Node * currentnode = myFirst;
	while (currentnode != NULL) {
		fout << " " << currentnode->myItem;
		currentnode = currentnode->myNext;
	}
	fout.close();
}

/* written by Ethan Clark
 * prepend() method to add an element at the beginning of the list
 * @param: an item of the same kind as the list
 */
template<class Item>
void List<Item>::prepend(const Item& it) {

	Node * myNextPtr = myFirst->myNext;
	Node * newNode = new Node(it, myNextPtr);
	Node * currentNode = myFirst->myNext;

	if (mySize == 0) {
		myFirst = newNode;
	}
	else {
		while (currentNode != NULL) {
			myFirst = newNode;
			currentNode = currentNode->myNext;
		}
	}
}

/* written by Ethan Clark (elc3)
 * insert() method to insert an item at the given index
 * @param: item of the same kind as the list's items; valid index for the list
 */
template<class Item>
void List<Item>::insert(const Item& it, unsigned index) {

	Node * newNode = new Node(it, NULL);
	if (index <= 0) {
		Node * firstPtr = myFirst;
		newNode->myNext = firstPtr;
		myFirst = newNode;
		mySize++;
	}

	else if (index >= mySize) {
		myLast->myNext = newNode;
		myLast = newNode;
		mySize++;
	}

	else {
		Node * currentNode = myFirst;
		for (unsigned i = 0; i < index - 1; i++) {
			currentNode = currentNode->myNext;
		}
		newNode->myNext = currentNode->myNext;
		currentNode->myNext = newNode;
		mySize++;
	}
}

//End Student 1 (Ethan Clark) Methods


#endif /* LIST_H_ */
