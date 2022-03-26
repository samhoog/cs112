/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
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
	void testInequality();
	void testReadFromFile();
	void testWriteToStream();
	void testSearching();
	void testDeletion();
	void testEquality();
	void testReadFromStream();
	void testWriteToString();
	void testPrepend();
	void testInsert();
};

#endif /*LISTTESTER_H_*/
