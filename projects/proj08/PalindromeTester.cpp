/* PalindromeTester.cpp defines the test-methods for class Palindrome.
 * Student Name: Sam Hoogewind (sth6)
 * Date: April 17, 2021
 */

#include "PalindromeTester.h"
#include <iostream>
#include <cstdlib>          // exit()
#include <cassert>
#include <fstream>
using namespace std;

void PalindromeTester::runTests() {
	cout << "Testing class Palindrome..." << endl;
	testPalindrome();
	cout << "All tests passed!\n" << endl;
}

void PalindromeTester::testPalindrome() {
	// test 1st palindrome
	Palindrome p("palindromeTest1.txt", "pTest1.txt");
	p.detectPalindrome();
	ifstream fin("pTest1.txt");
	string line;
	getline(fin, line);
	assert( line == "Madam, I'm Adam. *** ");
	getline(fin, line);
	assert( line == "A man, a plan, a canal, Panama! *** " );
	cout << " 1 " << flush;
	fin.close();

	// test 2nd palindrome
	Palindrome p2("palindromeTest2.txt", "pTest2.txt");
	p2.detectPalindrome();
	ifstream fin2("pTest2.txt");
	string line2;
	getline(fin2, line2);
	assert( line2 == "Sore was I ere I saw Eros. *** ");
	getline(fin2, line2);
	assert( line2 == "My name is Sam" );
	getline(fin2, line2);
	assert( line2 == "A man, a plan, a canal -- Panama *** ");
	cout << " 2 " << flush;

	// test blank line
	getline(fin2, line2);
	assert( line2 == "");
	fin2.close();

	cout << "Passed!" << endl;
}

