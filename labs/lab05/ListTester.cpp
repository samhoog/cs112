/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin University.
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
#include <fstream>
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
	testInequality();
//	testReadFromFile();
	testWriteToStream();
	testSearching();
//	testDeletion();
	testEquality();
	testReadFromStream();
	testWriteToString();
	testPrepend();
	testInsert();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List::Node aNode;
	assert( aNode.myItem == Item() );
	assert( aNode.myNext == nullptr );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List::Node n1(11, nullptr );
	assert( n1.myItem == 11 );
	assert( n1.myNext == nullptr );
	cout << " 1 " << flush;

	List::Node *n3 = new List::Node(33, nullptr);
	List::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
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
	assert( aList.myFirst != nullptr );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == nullptr );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != nullptr );
	assert( aList.myLast != nullptr );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != nullptr );
	assert( aList.myLast->myNext == nullptr );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != nullptr );
	assert( aList.myLast != nullptr );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == nullptr );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == nullptr );
	assert( aList.myLast == nullptr );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List list1;
	List list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == nullptr );
	assert( list2.myLast == nullptr );
	cout << " 1 " << flush;

	// copy nonempty list
	List list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List list4(list3);
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
	List list1;
	List list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == nullptr );
	assert( list2.myLast == nullptr );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == nullptr );
	assert( list6.myLast == nullptr );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List list11;
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

void ListTester::testInequality() {
	cout << "Testing !=... " << flush;

	// empty
	List list1;
	List list2;
	assert( !(list1 != list2) );
	cout << " 0 " << flush;

	// nonempty, same size
	List list3;
	list3.append(11);
	List list4;
	list4.append(22);
	List list5;
	list5.append(33);

	assert( list3 != list4 );
	assert( list4 != list5 );
	assert( list3 != list5 );
	cout << " 1 " << flush;

	// different sizes
	List list6;
	list6.append(11);
	list6.append(22);
	List list7;
	list7.append(11);

	assert( list6 != list7);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testReadFromFile() {
	cout << "Testing readFrom(string)... " << flush;

	//read from file
	List list;
	list.readFrom("ListTest1.txt");

	//check list size
	assert( list.getSize() == 3 );
	cout << " 1 " << flush;

	//check list
	assert( list.getFirst() == 11 );
	assert( list.getLast() == 33 );
	assert( list.myFirst->myNext->myItem == 22 );

	cout << "Passed!" << endl;
}

void ListTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)... " << flush;

	//create list
	List list;
	list.append(11);
	list.append(22);
	list.append(33);
	list.append(44);
	list.append(55);

	//check if written to ostream
	ofstream fout("ListTest1.txt");
	assert( fout.is_open() );
	list.writeTo(fout);
	fout.close();

	cout << "Passed!" << endl;
}

void ListTester::testSearching() {
	cout << "Testing searching... " << flush;

	//create list
	List list;
	list.append(11);
	list.append(22);
	list.append(33);

	//test indexs
	assert( list.getIndexOf(11) == 0);
	cout << " 1 " << flush;
	assert( list.getIndexOf(22) == 1);
	cout << " 2 " << flush;
	assert( list.getIndexOf(33) == 2);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

//void ListTester::testDeletion() {
//	cout << "Testing deletion... " << flush;
//
//	//create lists
//	List list;
//	list.append(11);
//	list.append(22);
//	list.append(33);
//
//	List list2;
//	list2.append(44);
//	list2.append(55);
//	list2.append(66);
//
//	List list3;
//	list3.append(77);
//	list3.append(88);
//	list3.append(99);

	//check value returned and new list value
//	assert( list.remove(0) == 11 );
//	cout << "Size: " << list.getSize() << endl;
//	cout << "First: " << list.getFirst() << endl;
//	cout << "Last: " << list.getLast() << endl;
//	assert( list.getFirst() == 22 );
//	assert( list.getLast() == 33 );
//	cout << " 1 " << flush;
//
//
//
//	assert( list2.remove(1) == 55 );
//	assert( list2.getFirst() == 44 );
//	assert( list2.getLast() == 66 );
//	cout << " 2 " << flush;
//
//
//	assert( list3.remove(2) == 99);
//	cout << "Size: " << list3.getSize() << endl;
//	cout << "First: " << list3.getFirst() << endl;
//	cout << "Last: " << list3.getLast() << endl;
//	assert( list3.getFirst() == 77 );
//	assert( list3.getLast() == 88 );
//	cout << " 3 " << flush;
//}

void ListTester::testEquality() {
    cout << "Testing equality==... " << flush;



    List list1;
    List list2;
    //empty case
    assert (list1 == list2);
    cout << " 1 " << flush;



    //non-empty case 1
    list1.append(11);
    list1.append(22);
    list2.append(11);
    list2.append(22);
    assert( list1 == list2 );
    cout << " 2 " << flush;



    //non-empty case 2
    list1.append(55);
    assert ( !(list1 == list2));
    cout << " 3 " << flush;



    cout << "Passed!" << endl;
}



void ListTester::testReadFromStream() {
    cout << "Testing readfrom... " << flush;



    ifstream cin("ListTest2.txt");
    assert( cin.is_open() );



    //checking size of list
    List list1;
    assert( list1.getSize() == 0);
    list1.readFrom(cin);
    assert ( list1.getSize() == 6);
    cout << " 1 " << flush;



    //checking specific values
    assert (list1.myFirst->myItem == 11);
    assert (list1.myFirst->myNext->myItem == 22);
    cout << " 2 " << flush;



    //checking all values
    for (unsigned i; i < list1.getSize(); i++) {
        assert ( list1.myFirst->myItem == i+10) ;
    }
    cin.close();
    cout << " 3 " << flush;



    cout << "Passed!" << endl;
}




void ListTester::testWriteToString() {
    cout << "Testing writetostring... " << flush;



    ifstream fin("ListTest2.txt");
    assert( fin.is_open() );
    List list1;
    list1.readFrom(fin);
    fin.close();



    //write to a new file
    list1.writeTo("ListTest3.txt", " ");
    cout << " 1 " << flush;



    //read from new file into another list
    List list2;
    list2.readFrom("listTest2.txt");



    //checks if the values are the same
    assert (list1 == list2);
    assert ( !(list1.myFirst == list2.myFirst));
    assert ( !(list1.myLast == list2.myLast));
    cout << " 2 " << flush;
    cout << "Passed!" << endl;



}



void ListTester::testPrepend() {
    cout << "Testing prepend()... " << flush;



    //create empty list
    List list1;
    assert ( list1.mySize == 0);
    assert ( list1.myFirst == NULL);
    list1.prepend(-1);
    assert ( list1.mySize == 1 );
    assert ( list1.myFirst != NULL );
    assert (list1.myFirst->myItem == -1);
    cout << " 1 " << flush;



    //non-empty case 1
    list1.prepend(5);
    assert ( list1.mySize == 2 );
    assert (list1.myFirst->myItem == 5);
    assert (list1.myFirst->myNext->myItem == -1);
    cout << " 2 " << flush;



    //non-empty case 2
    list1.prepend(10);
    assert ( list1.mySize == 3 );
    assert (list1.myFirst->myItem == 10);
    assert (list1.myFirst->myNext->myItem == 5);
    assert (list1.myFirst->myNext->myNext->myItem == -1);
    cout << " 3 " << flush;



    cout << "Passed!" << endl;
}



void ListTester::testInsert() {
    cout << "Testing insert()... " << flush;



    // create and insert to an empty list
    List list11;
    assert( list11.getSize() == 0 );
    assert( list11.myFirst == NULL );
    assert( list11.myLast == NULL );
    // Insert into list
    list11.insert(5, 0);
    assert( list11.getSize() == 1 );
    assert( list11.myFirst != NULL );
    assert( list11.myLast == list11.myFirst );
    assert( list11.getFirst() == 5 );
    assert( list11.getLast() == 5 );
    assert( list11.myFirst->myNext == NULL );
    cout << " 1 " << flush;



    // INSERT AT THE BEGINNING OF LIST
    // Index = 0
    list11.insert(10, 0);
    assert( list11.getSize() == 2 );
    assert( list11.myFirst != list11.myLast );
    assert( list11.getFirst() == 10 );
    assert( list11.getLast() == 5 );
    assert( list11.myFirst->myNext != NULL );
    assert( list11.myLast->myNext == NULL );
    cout << " 2 " << flush;
    // Index > 0
    list11.insert(20, -1);
    assert( list11.getSize() == 3 );
    assert( list11.getFirst() == 20 );
    assert( list11.getLast() == 5 );
    assert( list11.myLast->myNext == NULL );
    cout << " 3 " << flush;



    cout << "Passed!" << endl;
}
