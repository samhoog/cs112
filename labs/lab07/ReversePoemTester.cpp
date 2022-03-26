/* ReversePoemTester.cpp defines test-methods for class ReversePoem.
 * Student Name: Sam Hoogewind (sth6)
 * Date: April 2, 2021
 */

#include "ReversePoemTester.h"
#include "ReversePoem.h"
#include <iostream>  // cout, cerr, ...
#include <cassert>   // assert()
#include <cstdlib>   // exit()
using namespace std;

void ReversePoemTester::runTests() {
	cout << "Testing ReversePoem class..." << endl;
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << "All tests passed!" << endl;
}

void ReversePoemTester::testGetTitle() {
	cout << "- Testing getTitle()... " << flush;

	// test titles for different poems
	ReversePoem r1("love.txt");
	assert( r1.getTitle() == "Love?");
	cout << " 1 " << flush;

	ReversePoem r2("anorexia.txt");
	assert( r2.getTitle() == "Anorexia");
	cout << " 2 " << flush;

	ReversePoem r3("theKiss.txt");
	assert( r3.getTitle() == "The Kiss");
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetAuthor() {
	cout << "- Testing getAuthor()... " << flush;

	// test authors for different poems
	ReversePoem r1("love.txt");
	assert( r1.getAuthor() == "Anonymous");
	cout << " 1 " << flush;

	ReversePoem r2("anorexia.txt");
	assert( r2.getAuthor() == "Anonymous");
	cout << " 2 " << flush;

	ReversePoem r3("theKiss.txt");
	assert( r3.getAuthor() == "R. Lamoureux");
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBody() {
	cout << "- Testing getBody()... " << flush;

	// test body for different poems
	ReversePoem r1("love.txt");
//	assert( r1.getBody() == "");
	cout << " 1 " << flush;

	ReversePoem r2("anorexia.txt");
//	assert( r2.getBody == "Anorexia");
	cout << " 2 " << flush;

	ReversePoem r3("theKiss.txt");
//	assert( r3.getBody == "The Kiss");
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBodyReversed() {
	cout << "- Testing getBodyReversed()... " << flush;

	// test reversed body for different poems
	ReversePoem r1("love.txt");
//	assert( r1.getBodyReversed == "Love?");
	cout << " 1 " << flush;

	ReversePoem r2("anorexia.txt");
//	assert( r2.getBodyReversed == "Anorexia");
	cout << " 2 " << flush;

	ReversePoem r3("theKiss.txt");
//	assert( r3.getBodyReversed == "The Kiss");
	cout << " 3 " << flush;

	cout << " Passed!" << endl;
}

