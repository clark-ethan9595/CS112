/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin College.
 * Added onto by Johan Sung (jcs56)
 */


#include "ListTester.h" // ListTester
#include "List.h"		// List

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
	testInequality();
	testReadFromStream();
	testWriteTo();
	testReadFromString();
	//	testWriteToString();
	testPrepend();
	testGetIndexOf();
	testInsert();
	testRemove();
	testSort();
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

void ListTester::testInequality() {
	cout << "Testing inequality... " << flush;
	// two empty lists
	List<double> list1;
	List<double> list2;
	assert( list1 != list1 );
	cout << " 1 " << flush;

	// a non-empty list
	List<double> list3;
	list3.append(33);		// [33]
	assert( !(list3 == list1) );
	cout << " 2 " << flush;

	// equal, non-empty lists of the same size
	List<double> list4;
	list4.append(33);		// [33]
	assert( list4 != list3 );
	assert( list3 != list4 );
	cout << " 3 " << flush;

	// unequal, non-empty lists of the same size
	list3.append(55);		// [33,55]
	List<double> list5;
	list5.append(44);		// [44]
	list5.append(55);		// [44,55]
	assert( list5 != list3 );
	assert( list3 != list5 );
	cout << " 4 " << flush;

	// unequal non-empty lists of different sizes
	list4.append(44);		// [33,44]
	list4.append(55);		// [33,44,55]
	assert( list4 != list5 );
	assert( list5 != list4 );
	assert( list5 != list3 );
	cout << " 5 " << flush;

	cout << "Passed!" << endl;

}

void ListTester::testReadFromStream()
{
	cout << "Testing reading from a stream..." << flush;
	ifstream fin("sampleLists.txt");
	assert( fin.is_open() );

	// reading an empty list into an empty list
	List<double> list1;
	list1.readFrom(fin);
	assert( list1.mySize == 0 );
	assert( list1.myFirst == NULL );
	assert( list1.myLast == NULL );
	cout << " 1 " << flush;

	// reading a list with one item into an empty list
	List<double> list2;
	list2.readFrom(fin);
	assert( list2.mySize == 1 );
	assert( list2.myFirst == list2.myLast );
	assert( list2.getFirst() == 1 );
	cout << " 2 " << flush;

	// reading a list with multiple items into an empty list
	List<double> list3;
	list3.readFrom(fin);
	assert( list3.mySize == 3 );
	assert( list3.myFirst != list3.myLast );
	assert( list3.getFirst() == 11 );
	assert( list3.myFirst->myNext->myItem == 22 );
	assert( list3.getLast() == 33 );
	cout << " 3 " << flush;

	// reading an empty list into a list with items already in it
	// also ensures only one new line is eaten at the end of a readFrom call
	list2.readFrom(fin);
	assert( list2.mySize == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 4 " << flush;

	// reading a list with one item into a list with a different number of items
	list3.readFrom(fin);
	assert( list3.mySize == 1 );
	assert( list3.myFirst == list3.myLast );
	assert( list3.getFirst() == 1 );
	cout << " 5 " << flush;

	// reading a list with multiple items into a list with a different number of items
	list3.readFrom(fin);
	assert( list3.mySize == 3 );
	assert( list3.myFirst != list3.myLast );
	assert( list3.getFirst() == 11 );
	assert( list3.myFirst->myNext->myItem == 22 );
	assert( list3.getLast() == 33 );
	cout << " 6 " << flush;

	fin.close();
	cout << "Passed!" << endl;
}


void ListTester::testWriteTo() {
	cout << "Testing writeTo(ostream)... " << flush;

	// create list with multiple elements
	List<double> list;
	list.append(11);
	list.append(22);
	list.append(33);
	assert( list.getSize() == 3 );
	assert( list.getFirst() == 11 );
	assert( list.getLast() == 33 );
	assert( list.myFirst->myNext->myItem == 22 );
	cout << " 0 " << flush;

	// prepare a file to stream out to
	ofstream fout("output_stream.txt");
	assert (fout.is_open());
	list.writeTo(fout);
	fout.close();
	cout << " 1a " << flush;

	// prepare to check efficacy of method
	ifstream fin("output_stream.txt");
	assert( fin.is_open() );
	cout<< " 1b " << flush;

	// check to see if method worked
	List<double> list1;
	list1.readFrom(fin);
	assert( list1.getSize() == 3 );
	assert( list1.getFirst() == 11 );
	assert( list1.getLast() == 33 );
	assert( list1.myFirst->myNext->myItem == 22 );
	fin.close();
	cout << " 2 " << flush;

	cout <<" Passed! " << endl;

}

void ListTester::testReadFromString() {
	// create list using values in given file using filename as parameter
	cout << "Testing readFrom(string)... " << flush;
	List<double> list;
	list.readFrom("readFromStringEx.txt");

	// make assertions to test method
	assert(list.getSize() == 3);
	assert(list.getFirst() == 11);
	assert(list.getLast() == 33);
	assert(list.myFirst->myNext->myItem == 22);

	cout << " Passed! " << endl;

}

void ListTester::testWriteToString()
{
	cout << "Testing writing to a file..." << flush;

	// writing an empty list
	List<double> list1;
	list1.writeTo("emptyList.txt");
	List<double> list2;
	// (to ensure lists are not equivalent just because they were both created empty)
	ifstream fin("emptyList.txt");
	list2.append(11);
	list2.append(22);
	list2.append(33);
	list2.readFrom(fin);
	assert( list1 == list2 );
	cout << " 1 " << flush;

	// writing a list with items
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	list3.writeTo("listWithItems.txt");
	List<double> list4;
	list4.readFrom("listWithItems.txt");
	assert ( list3 == list4 );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testPrepend()
{
	cout << "Testing prepend()...";
	List<double> list1;

	// test prepend to empty list
	list1.prepend(22);
	assert( list1.mySize == 1 );
	assert( list1.getFirst() == 22 );
	assert( list1.getLast() == 22 );
	assert( list1.myFirst == list1.myLast );
	cout << " 1 " << flush;

	// test prepend to non-empty list
	list1.prepend(11);
	assert( list1.mySize == 2 );
	assert( list1.getFirst() == 11 );
	assert( list1.getLast() == 22 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}


void ListTester::testGetIndexOf() {
	cout << "Testing getIndexOf()..." << flush;
	// test method on empty list
	List<double> list;
	assert(list.getIndexOf(35) == -1);
	cout << " 1 " << flush;

	// create a list with multiple elements (list1)
	List<double> list1;
	list1.append(11);
	list1.append(22);
	list1.append(33);
	assert( list1.getSize() == 3 );
	assert( list1.getFirst() == 11 );
	assert( list1.getLast() == 33 );
	assert( list1.myFirst->myNext->myItem == 22 );
	cout << " 2a " << flush;

	// test method on list1
	assert(list1.getIndexOf(11) == 0);
	assert(list1.getIndexOf(22) == 1);
	assert(list1.getIndexOf(33) == 2);
	cout << " 2b " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsert()
{
	cout << "Testing insert()..." << flush;

	// test inserting at the 0th index to an empty list
	List<double> list1;
	list1.insert(11, 0);
	assert( list1.mySize == 1 );
	assert( list1.getFirst() == 11 );
	assert( list1.getLast() == 11 );
	assert( list1.myFirst == list1.myLast );
	assert( list1.myLast->myNext == NULL );
	cout << " 1 " << flush;

	// test inserting at less than 0th index to an empty list
	List<double> list2;
	list2.insert(11, -3);
	assert( list2.mySize == 1 );
	assert( list2.getFirst() == 11 );
	assert( list2.getLast() == 11 );
	assert( list2.myFirst == list2.myLast );
	assert( list2.myLast->myNext == NULL );
	cout << " 2 " << flush;

	// test inserting at greater than 0th index to an empty list
	List<double> list3;
	list3.insert(11, 4);
	assert( list3.mySize == 1 );
	assert( list3.getFirst() == 11 );
	assert( list3.getLast() == 11 );
	assert( list3.myFirst == list3.myLast );
	assert( list3.myLast->myNext == NULL );
	cout << " 3 " << flush;

	// test inserting at the 0th index to a non-empty list
	list1.insert(00, 0);
	assert( list1.mySize == 2 );
	assert( list1.getFirst() == 00 );
	assert( list1.getLast() == 11 );
	cout << " 4 " << flush;

	// test inserting at greater than 0th index to a non-empty list
	list2.insert(33, 1);
	assert( list2.mySize == 2 );
	assert( list2.getFirst() == 11 );
	assert( list2.getLast() == 33 );
	cout << " 5 " << flush;

	// test inserting at less than 0th index to a non-empty list
	list3.insert(00, -4);
	assert( list3.mySize == 2 );
	assert( list3.getFirst() == 00 );
	assert( list3.getLast() == 11 );
	cout << " 6 " << flush;

	// test inserting to the middle of a non-empty list
	list2.insert(22, 1);
	assert( list2.mySize == 3);
	assert( list2.getFirst() == 11 );
	assert( list2.myFirst->myNext->myItem == 22 );
	assert( list2.myFirst->myNext->myNext == list2.myLast );
	assert( list2.getLast() == 33 );
	cout << " 7 " << flush;

	// test inserting to the end of a non-empty list
	list3.insert(22, 2);
	assert( list3.mySize == 3 );
	assert( list3.getFirst() == 00 );
	assert( list3.getLast() == 22 );
	assert( list3.myFirst->myNext->myItem == 11 );
	assert( list3.myFirst->myNext->myNext == list3.myLast );
	assert( list1.myLast->myNext == NULL );
	cout<< " 8 " << flush;
	cout << "Passed!" << endl;

}

void ListTester::testRemove() {
	cout << "Testing remove()..." << flush;

	// test with empty list
	List<double> list;
	assert( list.remove(0) == 0);
	cout << " 1 " << flush;

	// test list with only one item
	List<double> list1;
	list1.append(50);
	assert( list1.remove(0) == 50);
	assert( list1.getSize() == 0);
	assert( list1.myFirst == NULL);
	assert( list1.myLast == NULL);
	cout << " 2 " << flush;

	// test removal of first element of list with multiple items
	List<double> list2;
	list2.append(11);
	list2.append(22);
	list2.append(33);
	list2.append(44);
	list2.append(55);
	assert(list2.remove(0) == 11);
	assert( list2.getSize() == 4 );
	cout << " 3 " << flush;

	//test removal of mid element from list with multiple items
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	list3.append(44);
	list3.append(55);
	assert(list3.remove(2) == 33);
	assert( list3.getSize() == 4 );
	cout << " 4 " << flush;

	// test removal of last element of list with multiple items
	List<double> list4;
	list4.append(11);
	list4.append(22);
	list4.append(33);
	list4.append(44);
	list4.append(55);
	assert(list4.remove(4) == 55);
	assert( list4.getSize() == 4 );
	cout << " 5 " << flush;

	cout << "Passed!" << endl;

}

void ListTester::testSort()
{
	cout << "Testing sort(list)..." << flush;
	//test on empty list
	List<double> list1;
	sort(list1);
	assert ( list1.myFirst == NULL );
	assert ( list1.myLast == NULL );
	assert ( list1.getSize() == 0 );
	cout << " 1 " << flush;

	//test on list containing one item
	list1.append(11);
	sort(list1);
	assert ( list1.myFirst == list1.myLast );
	assert ( list1.myFirst != NULL );
	assert ( list1.getFirst() == 11 );
	assert ( list1.getSize() == 1 );
	cout << " 2 " << flush;

	//test on list containing multiple items
	list1.prepend(22);
	list1.prepend(44);
	list1.prepend(55);
	list1.prepend(33);
	sort(list1);
	assert ( list1.getFirst() == 11 );
	assert ( list1.getLast() == 55 );
	assert ( list1.myFirst->myNext->myItem == 22 );
	assert ( list1.myFirst->myNext->myNext->myItem == 33 );
	assert ( list1.myFirst->myNext->myNext->myNext->myItem == 44 );
	assert ( list1.getSize() == 5 );
	cout << " 3 " << flush;

	//test on list that is already in order
	sort(list1);
	assert ( list1.getFirst() == 11 );
	assert ( list1.getLast() == 55 );
	assert ( list1.myFirst->myNext->myItem == 22 );
	assert ( list1.myFirst->myNext->myNext->myItem == 33 );
	assert ( list1.myFirst->myNext->myNext->myNext->myItem == 44 );
	assert ( list1.getSize() == 5 );
	cout << " 4 " << flush;

	//test on list in reverse order
	List<double> list2;
	list2.prepend(11);
	list2.prepend(22);
	list2.prepend(33);
	list2.prepend(44);
	sort(list2);
	assert ( list2.getFirst() == 11 );
	assert ( list2.getLast() == 44 );
	assert ( list2.myFirst->myNext->myItem == 22 );
	assert ( list2.myFirst->myNext->myNext->myItem == 33 );
	assert ( list2.getSize() == 4 );
	cout << " 5 " << flush;

	//test on list containing two items
	List<double> list3;
	list3.prepend(11);
	list3.prepend(22);
	sort(list3);
	assert ( list3.getFirst() == 11 );
	assert ( list3.getLast() == 22 );
	cout << " 6 " << flush;

	//test on list containing two of the same item
	list3.prepend(22);
	sort(list3);
	assert ( list3.getFirst() == 11 );
	assert ( list3.myFirst->myNext->myItem == 22 );
	assert ( list3.getLast() == 22 );
	assert ( list3.myFirst->myNext != list3.myLast );
	cout << " 7 " << flush;

	cout << "Passed!" << endl;
}
