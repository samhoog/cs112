/* ReversePoem.cpp defines ReversePoem class methods.
 * Student Name: Sam Hoogewind (sth6)
 * Date: April 2, 2021
 */

#include "ReversePoem.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <stdexcept>
#include <string>

ReversePoem::ReversePoem(const string& filename) {
	Stack<string> myPoem(1);
	string line;

	ifstream fin(filename.c_str());
	assert(fin.is_open());

	getline(fin, myTitle);
	getline(fin, myAuthor);
	getline(fin, line);

	while (getline(fin, line)) {
		myBody += line + "\n";
		try {
			myPoem.push(line);
		} catch (const StackException& se) {
			myPoem.setCapacity(myPoem.getCapacity() * 2);
			myPoem.push(line);
		}
	}
	while (!myPoem.isEmpty()) {
		myBodyReversed += myPoem.pop() + "\n";
	}
	fin.close();

}

ReversePoem::~ReversePoem() {
	// TODO Auto-generated destructor stub
}

string ReversePoem::getTitle() const {
	return myTitle;
}

string ReversePoem::getAuthor() const {
	return myAuthor;
}

string ReversePoem::getBody() const {
	return myBody;
}

string ReversePoem::getBodyReversed() const {
	return myBodyReversed;
}
