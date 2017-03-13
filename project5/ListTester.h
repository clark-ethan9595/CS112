/* ListTester.h declares the test-class for class List.
 * Student One: Ethan Clark (elc3)
 * Student Two: Elizabeth Crow (emc37)
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testReadFromStream();
	void testWriteToFile();
	void testPrepend();
	void testInsert();
	void testInequality();
	void testWriteToStream();
	void testReadFromString();
	void testGetIndexOf();
	void testRemove();
};

#endif /*LISTTESTER_H_*/
