/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Ethan Clark
 * Date: April 22, 2015
 * Project9 for CS112
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template <class Item>
class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	void insert(const Item& it);
	bool contains(const Item& it);
	unsigned getHeight() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            void insert(const Item& it);
            bool contains(const Item& it);
            unsigned getHeight() const;
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};


/*
 * Constructor for BST Class
 * Set myRoot (which is a Node) to NULL
 * Set myNumItems to 0
 * Created by Ethan Clark
 * April 22, 2015
 * Lab9 for CS112
 */
template <class Item>
BST<Item>::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

//BST destructor to deallocate any myRoot memory
template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

//Node constructor to assign myItem to it and assign myLeft and myRight to be NULL
template <class Item>
BST<Item>::Node::Node(const Item& it) {
	myItem = it;
	myLeft = NULL;
	myRight = NULL;
}

//Node destructor to deallocate myLeft and myRight nodes
template <class Item>
BST<Item>::Node::~Node() {
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
template <class Item>
void BST<Item>::Node::insert(const Item& it) {

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
template <class Item>
bool BST<Item>::Node::contains(const Item& it) {
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
template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

//Returns the number of Items in the BST
template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

/*
 * insert() method for the BST Class
 * Insert Item it in appropriate position in the tree
 * Created by Ethan Clark
 * April 21, 2015
 * Lab9 for CS112
 */
template <class Item>
void BST<Item>::insert(const Item& it) {
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
template <class Item>
bool BST<Item>::contains(const Item& it) {
	//Return false if the BST is empty
	if (isEmpty()) {
		return false;
	}
	//else return the bool received from calling the Node contains() method
	return myRoot->contains(it);
}

//Processes the item in a node before the items in the left and right subtrees are processed
template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

//Processes itself before processing the Items in the subtrees
template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

//Method to insert a space and then myItem into cout
template <class Item>
void BST<Item>::Node::processItem() {
	cout << ' ' << myItem;
}

//Processes the item in a node after the items in the left and right subtrees are processed
template <class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

//Processes the Items in the subtrees first before processing itself
template <class Item>
void BST<Item>::Node::traversePostorder() {
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
template <class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

//Process the Items in the left subtrees first,
//  then process itself,
//  then process the Items in the right subtrees last
template <class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

/*
 * BST class method getHeight()
 * returns the height of the BST by recursively calling getHeight on the nodes
 * Created by Ethan Clark
 * April 22, 2015
 * Project9 for CS112
 */
template <class Item>
unsigned BST<Item>::getHeight() const {

	//Return zero if the BST is empty
	if (isEmpty()) {
		return 0;
	}

	//Return one if the BST has only 1 Item
	if (myNumItems == 1) {
		return 1;
	}

	return myRoot->getHeight();
}

/*
 * Node getHeight() method
 * Creates two counter variables: lefth and righth
 * Recursively call getHeight if the corresponding myLeft or myRight Nodes are not null
 * Whichever counter is bigger, return that counter value + 1
 * Created by Ethan Clark
 * April 22, 2015
 * Project9 for CS112
 */
template <class Item>
unsigned BST<Item>::Node::getHeight() const {

	unsigned lefth = 0, righth = 0;

	if (myLeft != NULL) {
		lefth = myLeft->getHeight();
	}

	if (myRight != NULL) {
		righth = myRight->getHeight();
	}

	if (lefth > righth) {
		return lefth + 1;
	}

	return righth + 1;

}
#endif /*BST_H_*/
