/*
 * List.h
 *
 *  Created on: Mar 10, 2015
 *      Author: Johan Sung (jcs56)
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

template <class Item>

class List{
public:
	List();
	~List();
	List(const List& original);
	void append(const Item& it);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	List& operator=(const List& original);
	bool operator==(const List& list2);
	bool operator!=(const List& list2);
	void readFrom(istream& in);
	void writeTo(ostream& out);
	void readFrom(const string& fileName);
	void writeTo(const string& fileName);
	void prepend(Item it);
	int getIndexOf(Item it) const;
	void insert(Item it, int index);
	Item remove(unsigned index);

private:
	struct Node {
		Node();
		~Node();
		Node(Item it, Node * next);
		Item myItem;
		Node * myNext;
	};
	unsigned mySize;
	Node * myFirst;
	Node * myLast;
//	grant access to ListTester to
	friend class ListTester;

};

template <class Item>
List<Item>::List() {
	mySize = 0;			//	assign intialized values for default List
	myFirst = NULL;
	myLast = NULL;
}

template <class Item>
List<Item>::Node::Node() {
	myItem = 0;			//	assign initialized values for default Node
	myNext = NULL;
}

template <class Item>
List<Item>::Node::Node(Item it, Node * next) {
	myItem = it;		//	assigns desired values for explicit Node
	myNext = next;
}

template <class Item>
unsigned List<Item>::getSize() const{
	return mySize;		//	returns value of mySize
}

template <class Item>
Item List<Item>::getFirst() const{
	if (mySize < 0 || myFirst == NULL){		//	checks to see if list is empty. if true, throw an error
		throw underflow_error ("List is empty or nonexistent");
	} else {								//	otherwise return first node
		return myFirst->myItem;
	}
}

template <class Item>
Item List<Item>::getLast() const{
	if (mySize < 0 || myLast == NULL){		//	checks to see if list is empty. if true, throw an error
		throw underflow_error ("List is empty or nonexistent");
	} else {								//	otherwise return last node
		return myLast->myItem;
	}
}

template <class Item>
void List<Item>::append(const Item& it) {
	Node * nodePtr = new Node (it, NULL);	//	allocate a new node in which myItem is it and myNext is NULL
	if (mySize == 0) {						//	if list is empty, make myFirst point at new node
		myFirst = nodePtr;
	} else {								//	Otherwise make myLast->myNext point at new node
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;						// make myLast point at new node
	mySize++;								// increment mySize
}

template <class Item>
List<Item>::~List() {
	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}

template <class Item>
List<Item>::Node::~Node() {
	delete myNext;  // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == NULL)
	myNext = NULL;  // clear myNext (optional)
	myItem = 0;     // clear myItem (optional)
}

template <class Item>
List<Item>::List(const List& original) {
	myFirst = myLast = NULL;          //  set pointers
	mySize = 0;                       //   and size to 'empty' values
	if (original.getSize() > 0) {     //  if there are nodes to copy:
		Node* oPtr = original.myFirst; //  start at the first node
		while (oPtr != NULL) {         //  while there are more nodes:
			append(oPtr->myItem);       //   append the item in that node
			oPtr = oPtr->myNext;        //   advance to next node
		}
	}
}

template <class Item>
List<Item>& List<Item>::operator=(const List<Item>& original){
	if (&original != this) {				//	check that the two lists don't share the same address
		delete myFirst;						//	deallocate my chain of nodes
		myFirst = myLast =NULL;				// 	set myFirst and myLast to NULL
		mySize = 0;							// 	set mySize to 0
		if (original.getSize() > 0) {		//	if original is not empty
			Node* nPtr = original.myFirst;	//	declare nPtr containing the address of original's first node
			while (nPtr != NULL) {			// 	while nPtr is pointing at something
				append(nPtr->myItem);		//	append a copy of the item in the node to which nPtr is pointing
				nPtr = nPtr->myNext;		//	advance nPtr to next node
			}
		}
	}
	return *this;							// return dereferenced address of List
}

/* By Amber Bingle
 * operator==
 *   equality operator, for comparison of two list objects
 *
 * @param:  list2, the const reference to a list object to which this is being compared
 * @return: returns true if each item in this is equivalent to the corresponding item in list2
 * 			returns false otherwise
 */
template <class Item>
bool List<Item>::operator==(const List<Item>& list2)
{
	if (mySize != list2.mySize)
	{
		return false;
	}
	else
	{
		Node * itemIn1 = myFirst;

		Node * itemIn2 = list2.myFirst;
		for (unsigned i = 0; i < mySize; i++)
		{
			if (itemIn1->myItem != itemIn2->myItem)
			{
				return false;
			}
			itemIn1 = itemIn1->myNext;
			itemIn2 = itemIn2->myNext;
		}
		return true;
	}
}

/* By Johan Sung
 * operator!=
 *   inequality operator, for comparison of two list objects
 *
 * @param:  list2, the const reference to a list object to which this is being compared
 * @return: returns true if each item in this is inequivalent to the corresponding item in list2
 * 			returns false otherwise
 */
template <class Item>
bool List<Item>::operator!=(const List& list2) {
	if (mySize == list2.mySize) {
		return true;
	} else {
		Node * itemIn1 = myFirst;
		Node * itemIn2 = list2.myFirst;
		for (unsigned i = 0; i < mySize; i++)
		{
			if (itemIn1->myItem != itemIn2->myItem)
			{
				return true;
			}
			itemIn1 = itemIn1->myNext;
			itemIn2 = itemIn2->myNext;
		}
		return false;
	}
}

/* By Amber Bingle
 * readFrom() reads values from a stream separated by whitespace into a list.
 *   Reads until a new line character is encountered, and eats that new line
 *
 * @param: in, a reference to the istream to be read from
 */
template <class Item>
void List<Item>::readFrom(istream& in) {
	if(mySize != 0) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
	}
	Item newItem;
	char look;
	string newLine;
	while (true)
	{
		look = in.peek();
		if (look == '\n')
		{
			// eats the new line character so subsequent readFrom()
			// calls for that stream do not read an empty list
			getline(in, newLine);
			break;
		}
		in >> newItem;
		append(newItem);
	}
}

/* By Johan Sung
 * writeTo() writes out to an ostream
 *   takes given values and writes out to an indicated ostream
 *
 * @param:  out, the specified ostream
 */
template <class Item>
void List<Item>::writeTo(ostream& out) {
	Node * oPtr = myFirst;
	for (unsigned i =0; i < mySize; i++) {
		if(oPtr->myNext == NULL) {
			out << oPtr->myItem << '\n';
		} else {
			out << oPtr->myItem << '\t';
			oPtr = oPtr->myNext;
		}
	}
}

/* By Johan Sung
 * readFrom() reads values from an existing file given its file name
 *   Reads until a space is encountered, and eats that space
 *
 * @param: fileName, the name of the file used to read from
 */
template <class Item>
void List<Item>::readFrom(const string& fileName) {
	if(mySize != 0) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
	}
	Item newItem;
	char look;
	string newLine;
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	while (true)
	{
		look = fin.peek();
		if (look == ' ')
		{
			// eats the space so subsequent readFrom()
			// calls for that stream do not read an empty list
			getline(fin, newLine);
			break;
		}
		fin >> newItem;
		append(newItem);
	}
	fin.close();

}

/* By Amber Bingle
 * Modified by Johan Sung
 * writeTo() writes the items in a list into a file, each item on a new line
 *
 * @param: fileName, a string containing the name of the file to be written to
 * Postcondition: a file of the name fileName is created (or written over)
 *                containing the items from the list, each on its own line
 */
template <class Item>
void List<Item>::writeTo(const string& fileName)
{
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	Node * current = myFirst;
	while (current != NULL)
	{
		fout << current->myItem;
		current = current->myNext;
		if (current != NULL)
		{
			fout << ' ';
		}
	}
}

/* By Amber Bingle
 * prepend() adds a new item to the beginning of a list
 *
 * @param: it, an Item to be added to the list
 * Postcondition: the Item it is stored in a new Node in the myFirst position of the
 *                List object, with its myNext pointing to the Node which used to be myFirst
 */
template <class Item>
void List<Item>::prepend(Item it)
{
	Node * nodePtr = new Node(it, NULL);
	if (mySize == 0)
	{
		myFirst = myLast = nodePtr;
	}
	else
	{
		Node * oldFirst = myFirst;
		myFirst = nodePtr;
		myFirst->myNext = oldFirst;
	}
	mySize++;
}


/* By Johan Sung
 * getIndexOf() is given a value and returns its index in the list
 *   If the item is non existant in the list, returns -1
 *
 * @param: it, a reference to the specified item within the list
 * @return: i, the index of a specified item
 * 		   -1, the value returned if requested item does not exist within list
 */
template <class Item>
int List<Item>::getIndexOf(Item it) const{
	Node* oPtr = myFirst;
	for (unsigned i= 0; i < mySize; i++) {
		if (it == oPtr->myItem) {
			return i;
		}
		else if (it != oPtr->myItem) {
			oPtr = oPtr->myNext;
		}
	}
	return -1;
}

/* By Amber Bingle
 * insert() creates a new Node containing the item specified,
 *          and places it at the given index in the list, assuming zero-indexing
 *          indexes less than 0 add to the beginning of the list,
 *          indexes greater than mySize add to the end of the list
 *          if the list is empty, the append method is called to simply add the item
 *
 * @param: index, an int indicating the position the item should be added at
 *         it, the Item to be added to the list
 */
template <class Item>
void List<Item>::insert(Item it, int index)
{
	if (myFirst == NULL)
	{
		append(it);
	}

	else
	{
		if (index < 0)
		{
			index = 0;
		}
		else if (index > mySize)
		{
			index = mySize;
		}

		// moves a pointer to the address of the Node that comes after the node being inserted
		Node * currentNext = myFirst;
		for (int i = 0; i < index; i++)
		{
			currentNext = currentNext->myNext;
		}
		// creates the new Node with the Item it
		Node * nodePtr = new Node(it, currentNext);
		// handles the special case where the new Item is going to be at the 0th index
		if (index == 0)
		{
			myFirst = nodePtr;
		}
		// moves a pointer to the address of the Node that comes before the node being added
		else
		{
			Node * currentPrevious = myFirst;
			for (int i = 0; i < index-1; i++)
			{
				currentPrevious = currentPrevious->myNext;
			}
			// makes the previous Node in the list point to the new Node
			currentPrevious->myNext = nodePtr;
			// handles the special case where the new Node is the last in the list
			if (index == mySize)
			{
				myLast = nodePtr;
			}
		}
		mySize++;
	}
}


/* By Johan Sung
 * remove() takes given index and deletes the item at that index
 * @param: index, a reference to the location of a certain item in the list
 * @return: returns the Item at index after the method has been used
 */
template <class Item>
Item List<Item>::remove(unsigned index) {
	Node * rep;
	Item temp;

	if (mySize == 0) {
		myFirst = NULL;
		myLast = NULL;
		return 0;
	}
	else if (mySize == 1){
		temp = myFirst->myItem;
		myLast = NULL;
		myFirst = NULL;
	}
	else if (index <= 0) {
		temp = myFirst->myItem;
		rep = myFirst->myNext;
		myFirst = rep;
	}
	else if (index >= mySize) {
		temp = myLast->myItem;
		delete myLast;
		rep = myFirst;
		for (unsigned i = 0; i < mySize; i++) {
			rep = rep->myNext;
		}
		myLast = rep;
	}
	else {
		rep = myFirst;
		for (unsigned i = 0; i < index; i++){
			rep = rep->myNext;
		}
		temp = rep->myItem;
	}
	mySize -= 1;
	return temp;
}




// -----------------------merge sort functions-------------------------


/* sort() sorts the items a List in ascending order
 *   uses a merge sort algorithm, dividing the list in half and recursively calling
 *   the sort function until each list has only one item, then merging two sorted lists
 *   until all lists are merged
 *
 * @param: original, a reference to the List object to be sorted
 */
template <class Item>
void sort(List<Item>& original)
{
	if (original.getSize() > 1)
	{
		List<Item> firstHalf, secondHalf;
		divide(original, firstHalf, secondHalf);
		sort(firstHalf);
		sort(secondHalf);
		original = merge(firstHalf, secondHalf);
	}
}

/* divide() divides a List in half, copying each item in the first half to a new list
 *   and each item in the second half to a new list
 *
 * @param: wholeList, a reference to the List object to be divided
 *         partOne, a reference to the List object that will contain
 *           the items that were in the first half of wholeList
 *         partTwo, a reference to the List object that will contain
 *           the items that were in the second half of wholeList
 * Postcondition: oldList is an empty List object of size 0
 * 				  partOne is a List containing all items from the first half of wholeList
 * 				  partTwo is a List containing all items from the second half of wholeList
 */
template <class Item>
void divide(List<Item>& wholeList, List<Item>& partOne, List<Item>& partTwo)
{
	unsigned startSize = wholeList.getSize();
	for (unsigned i = 0; i < startSize/2; i++)
	{
		partOne.append(wholeList.getFirst());
		wholeList.remove(0);
	}
	for (unsigned i = startSize/2; i < startSize; i++)
	{
		partTwo.append(wholeList.getFirst());
		wholeList.remove(0);
	}
}

/* mergeItem() utility method containing code repeatedly used in merge()
 *   moves an item from the beginning of one list to the end of another
 *
 * @param: newList, a reference to a List object to which the item is to be moved
 *         oldList, a reference to a List object from which the item is to be removed
 *
 * Postcondition: newList is one item larger, the last item being new
 *                the first item in oldList has been removed
 */
template<class Item>
void mergeItem(List<Item>& newList, List<Item>& oldList) {
	newList.append(oldList.getFirst());
	oldList.remove(0);
}

/* merge() combines to lists sorted in ascending order such that the result is also sorted
 *
 * @param:  list1 and list2, references to the List objects which are to be merged
 * @return: A List object, containing all items from list1 and list2
 *
 * Precondition: list1 and list2 are each sorted in ascending order
 * Postcondition: list1 and list2 are empty Lists and the List that is returned is sorted in ascending order
 */
template <class Item>
List<Item> merge(List<Item>& list1, List<Item>& list2)
{
	List<Item> mergedList;
	while ((list1.getSize() != 0) && (list2.getSize() != 0))
	{
		// if the item in list1 is smaller than that in list2,
		// list1 is used as the parameter in mergeItem
		// otherwise list2 is used as the parameter
		mergeItem(mergedList, list1.getFirst() < list2.getFirst() ? list1 : list2);
	}
	// adds any additional items left in either list to the merged list
	// in the event that the lists to be merged were of unequal size
	while (list1.getSize() != 0)
	{
		mergeItem(mergedList, list1);
	}
	while (list2.getSize() != 0)
	{
		mergeItem(mergedList, list2);
	}
	return mergedList;
}


#endif /* LIST_H_ */
