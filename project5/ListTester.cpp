/* ListTester.cpp defines the test methods for class List.
 * Student One: Ethan Clark (elc3)
 * Student Two: Elizabeth Crow (emc37)
 * March 23, 2015
 */

#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testReadFromStream();
	testWriteToFile();
	testPrepend();
	testInsert();
	testInequality();
	testWriteToStream();
	testReadFromString();
	testGetIndexOf();
	testRemove();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == 0 );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

//Equality Test Method written by Ethan Clark (elc3)
void ListTester::testEquality() {
	cout << "Testing equality... " << flush;
	// two empty lists
	List<double> list1;
	List<double> list2;
	assert( list1 == list1 );
	cout << " 1 " << flush;

	// a non-empty list
	List<double> list3;
	list3.append(33);		// [33]
	assert( !(list3 == list1) );
	cout << " 2 " << flush;

	// equal, non-empty lists of the same size
	List<double> list4;
	list4.append(33);		// [33]
	assert( list4 == list3 );
	assert( list3 == list4 );
	cout << " 3 " << flush;

	// unequal, non-empty lists of the same size
	list3.append(55);		// [33,55]
	List<double> list5;
	list5.append(44);		// [44]
	list5.append(55);		// [44,55]
	assert( !(list5 == list3) );
	assert( !(list3 == list5) );
	cout << " 4 " << flush;

	// unequal non-empty lists of different sizes
	list4.append(44);		// [33,44]
	list4.append(55);		// [33,44,55]
	assert( !(list4 == list5) );
	assert( !(list5 == list4) );
	assert( !(list5 == list3) );
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

//ReadFromStream test written by Ethan Clark (elc3)
void ListTester::testReadFromStream() {

	cout << "Testing ReadFromStream... " << flush;

	ifstream fin("testFile.txt");
	assert( fin.is_open() );
	List<double> list1;
	list1.readFrom(fin);
	assert (list1.mySize == 5);
	assert( list1.myFirst->myItem == 1);
	assert( list1.myLast->myItem == 5);
	assert( list1.getIndexOf(2) == 1);
	assert( list1.getIndexOf(3) == 2);
	assert( list1.getIndexOf(4) == 3);
	cout << " 1 " << flush;

	ifstream fin1("testFile2.txt");
	assert ( fin1.is_open() );
	List<double> list2;
	list2.readFrom(fin1);
	assert( list2.mySize);
	assert( list2.mySize == 3);
	assert( list2.myFirst->myItem == 1);
	assert( list2.myLast->myItem == 3);
	assert( list2.getIndexOf(2) == 1);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

//WriteToFile test written by Ethan Clark (elc3)
void ListTester::testWriteToFile() {

	cout << "Testing WriteToFile... " << flush;

	List<double> list1;
	for (unsigned i = 0; i < 6; i++) {
		list1.append(i+1);
	}
	list1.writeTo("TestWritetoFile.txt");

	List<double> list2;
	list2.readFrom("TestWritetoFile.txt");
	assert (list2.mySize == 6);
	for (int i = 0; i < 5; i++) {
		assert (list2.getIndexOf(i+1) == i);
	}

	cout << "Passed!" << endl;
}

//Prepend test written by Ethan Clark (elc3)
void ListTester::testPrepend() {

	cout << "Testing Prepend... " << flush;

	// prepend to empty list
	List<double> list1;
	list1.append(11);
	assert( list1.getSize() == 1 );
	assert( list1.myFirst != NULL );
	assert( list1.myLast == list1.myFirst );
	assert( list1.getFirst() == 11 );
	assert( list1.getLast() == 11 );
	assert( list1.myFirst->myNext == NULL );
	cout << " 1 " << flush;

	// prepend to a list containing 1 Item
	list1.append(22);
	assert( list1.getSize() == 2 );
	assert( list1.myFirst != NULL );
	assert( list1.myLast != NULL );
	assert( list1.myFirst != list1.myLast );
	assert( list1.getFirst() == 11 );
	assert( list1.getLast() == 22 );
	assert( list1.myFirst->myNext != NULL );
	assert( list1.myLast->myNext == NULL );
	cout << " 2 " << flush;

	// prepend to a list containing 2 Items
	list1.append(33);
	assert( list1.getSize() == 3 );
	assert( list1.myFirst != NULL );
	assert( list1.myLast != NULL );
	assert( list1.getFirst() == 11 );
	assert( list1.getLast() == 33 );
	assert( list1.myFirst->myNext->myItem == 22 );
	assert( list1.myLast->myNext == NULL );
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

//Insert test written by Ethan Clark (elc3)
void ListTester::testInsert() {

	cout << "Testing Insert... " << flush;

	//Insert to an empty list
	List<double> list1;
	list1.insert(11, 0);
	assert (list1.mySize == 1);
	assert (list1.myFirst->myItem == 11);
	assert (list1.myFirst->myNext == NULL);
	cout << " 1 " << flush;

	cout << "Passed!" << endl;

}

// Test written by Elizabeth Crow (emc37)
void ListTester::testInequality() {
	cout << "Testing inequality... " << flush;
	//	 two empty lists
	List<int> list1;
	List<int> list2;
	assert( !(list1 != list1) );
	cout << " 1 " << flush;

	// a non-empty list
	List<int> list3;
	list3.append(33);		// [33]
	assert( list3 != list1);
	cout << " 2 " << flush;

	// equal, non-empty lists of the same size
	List<int> list4;
	list4.append(33);		// [33]
	assert( !(list4 != list3) );
	assert( !(list3 != list4) );
	cout << " 3 " << flush;

	// unequal, non-empty lists of the same size
	list3.append(55);		// [33,55]
	List<int> list5;
	list5.append(44);		// [44]
	list5.append(55);		// [44,55]
	assert( list5 != list3);
	assert( list3 != list5);
	cout << " 4 " << flush;

	// unequal non-empty lists of different sizes
	list4.append(44);		// [33,44]
	list4.append(55);		// [33,44,55]
	assert( list4 != list5);
	assert( list5 != list4);
	assert( list5 != list3);
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

// Test written by Elizabeth Crow (emc37)
void ListTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)... " << flush;

	List<double> l1;
	for (unsigned i = 0.0; i < 5.0; i++) {
		l1.append(i+1);
	}
	// write to an ofstream instead of cout, to automate the test
	ofstream fout("listStreamOut.txt");
	assert( fout.is_open() );
	l1.writeTo(fout);
	fout.close();
	// then read in what was written out
	List<double> l2;
	l2.readFrom("listStreamOut.txt");
	assert( l2.mySize == 5);
	for (int i = 0; i < 5; i++) {
		assert( l2.getIndexOf(i + 1) == i );
	}

	cout << "Passed!" << endl;
}

// Test written by Elizabeth Crow (emc37)
void ListTester::testReadFromString() {
	cout << "Testing readFrom(string)... " << flush;

	List<int> l1;
	l1.readFrom("testFile.txt");
	assert( l1.mySize == 5);
	assert( l1.myFirst->myItem == 1);
	assert( l1.myLast->myItem == 5);
	assert( l1.getIndexOf(2) == 1);
	assert( l1.getIndexOf(3) == 2);
	assert( l1.getIndexOf(4) == 3);
	cout << " 1 " << flush;

	List<int> l2;
	l2.readFrom("testFile2.txt");
	cout << l2.mySize;
	assert( l2.mySize == 3);
	assert( l2.myFirst->myItem == 1);
	assert( l2.myLast->myItem == 3);
	assert( l2.getIndexOf(2) == 1);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

// Test written by Elizabeth Crow (emc37)
void ListTester::testGetIndexOf() {
	cout << "Testing getIndexOf(Item)... " << flush;

	// empty list
	List<int> l1;
	assert( l1.getIndexOf(1) == -1);
	cout << " 1 " << flush;

	// non-empty list
	List<int> l2;
	l2.append(11);
	l2.append(22);
	assert( l2.getIndexOf(11) == 0);
	assert( l2.getIndexOf(22) == 1);
	assert( l2.getIndexOf(33) == -1);
	cout << " 2 " << flush;

	// non-empty list with repeated occurrences of the same element
	List<int> l3;
	l3.append(11);
	l3.append(11);
	assert( l3.getIndexOf(11) == 0);
	assert( l3.getIndexOf(11) != 1);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

// Test written by Elizabeth Crow (emc37)
void ListTester::testRemove() {
	cout << "Testing remove(index)... " << flush;
	//	empty list
	List<int> l1;
	try {
		l1.remove(0);
		cerr << "remove() worked on an empty list" << endl;
		exit(1);
	} catch (range_error&) {
		cout << " 1 " << flush;
	}

	//	list with 1 element
	List<int> l2;
	l2.append(11);
	int removed;
	removed = l2.remove(0);
	assert( removed == 11);
	assert( l2.myFirst == l2.myLast);
	assert( l2.myFirst == NULL);
	assert( l2.myLast == NULL);
	assert(l2.mySize == 0);
	cout << " 2 " << flush;

	//	non-empty list with more than 1 element- removing the first item
	List<int> l3;
	l3.append(11);
	l3.append(22);
	l3.append(33);
	l3.append(44);
	removed = l3.remove(0);
	assert( removed == 11);
	assert( l3.mySize == 3);
	assert( l3.getIndexOf(11) == -1);
	assert( l3.getIndexOf(22) == 0);
	assert( l3.myFirst->myItem == 22);
	cout << " 3a " << flush;

	removed = l3.remove(0);
	assert( removed == 22);
	assert( l3.mySize == 2);
	assert( l3.getIndexOf(22) == -1);
	assert( l3.getIndexOf(33) == 0);
	assert( l3.myFirst->myItem == 33);
	cout << " 3b " << flush;

	//	non-empty list with more than 1 element- removing the last item
	List<int> l4;
	l4.append(11);
	l4.append(22);
	l4.append(33);
	l4.append(44);
	removed = l4.remove(3);
	assert( removed == 44);
	assert( l4.mySize == 3);
	assert( l4.getIndexOf(11) == 0);
	assert( l4.getIndexOf(44) == -1);
	assert( l4.myLast->myItem == 33);
	cout << " 4a " << flush;

	removed = l4.remove(50);
	assert( removed == 33);
	assert( l4.mySize == 2);
	assert( l4.getIndexOf(11) == 0);
	assert( l4.getIndexOf(33) == -1);
	assert( l4.myLast->myItem == 22);
	cout << " 4b " << flush;

	//	non-empty list with more than 1 element- removing an item in the middle
	List<int> l5;
	l5.append(11);
	l5.append(22);
	l5.append(33);
	l5.append(44);
	l5.append(55);
	removed = l5.remove(2);
	assert( removed == 33);
	assert( l5.mySize == 4);
	assert( l5.getIndexOf(44) == 2);
	assert( l5.getIndexOf(55) == 3);
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}
