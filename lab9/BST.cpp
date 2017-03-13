/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Ethan Clark
 * Date: April 21, 2015
 */

#include "BST.h"

/*
 * Constructor for BST Class
 * Set myRoot (which is a Node) to NULL
 * Set myNumItems to 0
 * Created by Ethan Clark
 * April 22, 2015
 * Lab9 for CS112
 */
BST::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

//BST destructor to deallocate any myRoot memory
BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

//Node constructor to assign myItem to it and assign myLeft and myRight to be NULL
BST::Node::Node(const Item& it) {
	myItem = it;
	myLeft = NULL;
	myRight = NULL;
}

//Node destructor to deallocate myLeft and myRight nodes
BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

/*
 * Node insert() method to insert an Item into the BST
 * Checks if the Item is less than or greater than myItem
 * Inserts the Item into the tree accordingly
 * If myItem == it, this method throws an exception
 * Created by Ethan Clark
 * April 21, 2015
 * Lab9 for CS112
 */
void BST::Node::insert(const Item& it) {

	//If it is less than myItem
	if (it < myItem) {
		if (myLeft == NULL) {
			myLeft = new Node(it);
		}
		else {
			myLeft->insert(it);
		}
	}
	//If it is greater than myItem
	else if (it > myItem) {
		if (myRight == NULL) {
			myRight = new Node(it);
		}
		else {
			myRight->insert(it);
		}
	}
	//If it equals myItem
	else {
		throw Exception("Node::Insert", "Item is already in the BST");
	}
}

/*
 * Node contains()
 * returns true if the Item it is already in the tree
 * returns false if the Item it is not already in the tree
 * Created by Ethan Clark
 * April 21, 2015
 * Lab9 for CS112
 */
bool BST::Node::contains(const Item& it) const {
	//If it is less than myItem
	if (it < myItem) {
		if (myLeft == NULL) {
			return false;
		}
		else {
			return myLeft->contains(it);
		}
	}
	//If it is greater than myItem
	else if (it > myItem) {
		if (myRight == NULL) {
			return false;
		}
		else {
			return myRight->contains(it);
		}
	}
	//Else return true because it equals myItem
	return true;
}

//Returns true if myNumItems equals 0
bool BST::isEmpty() const {
	return myNumItems == 0;
}

//Returns the number of Items in the BST
unsigned BST::getNumItems() const {
	return myNumItems;
}

/*
 * insert() method for the BST Class
 * Insert Item it in appropriate position in the tree
 * Created by Ethan Clark
 * April 21, 2015
 * Lab9 for CS112
 */
void BST::insert(const Item& it) {
	//If the BST is empty
	if (isEmpty()) {
		myRoot = new Node(it);
	}
	//else if the BST has at least one node...
	else {
		try {
			myRoot->insert(it);
		}
		catch (Exception& e) {
			throw e;
		}
	}
	//Increment the size of the BST
	myNumItems++;
}

/*
 * BST contains()
 * returns false if the BST is empty
 * returns true depending if the tree has an item of that value already
 * returns false if the tree does not have an item of that value already
 * Created by Ethan Clark
 * April 21, 2015
 * Lab9 for CS112
 */
bool BST::contains(const Item& it) const {
	//Return false if the BST is empty
	if (isEmpty()) {
		return false;
	}
	//else return the bool received from calling the Node contains() method
	return myRoot->contains(it);
}

//Processes the item in a node before the items in the left and right subtrees are processed
void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

//Processes itself before processing the Items in the subtrees
void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

//Method to insert a space and then myItem into cout
void BST::Node::processItem() {
	cout << ' ' << myItem;
}

//Processes the item in a node after the items in the left and right subtrees are processed
void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

//Processes the Items in the subtrees first before processing itself
void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

//Process the item in a node after the items in the left subtree have been processed,
//  but before the items in the right subtree have been processed.
void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

//Process the Items in the left subtrees first,
//  then process itself,
//  then process the Items in the right subtrees last
void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}
