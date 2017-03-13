/* List.h
 * Header file for the List Class
 * Created on: Mar 10, 2015
 * Author: elc3
 */

#ifndef LIST_H_
#define LIST_H_

//Includes for the List Class
#include <iostream>
#include <stdexcept>
using namespace std;

typedef double Item;

//Declaration of the public and private parts of List Class
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

#endif /* LIST_H_ */
