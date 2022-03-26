/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Sam Hoogewind (sth6)
 *
 * operator[] (write version), operator!=(), readFrom(), and operator+()
 * done by Sam Hoogewind
 *
 * operator[] (read version), writeTo(), operator-(), and operator*()
 * done by Ryan Bouman
 *
 * Date: February 28, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */
 
#include "Vec.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Default Constructor
Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

// Deconstructor
Vec::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}

/*
 * Explicit Constructor
 * Takes in size value and creates Vec object of size "size"
 */
Vec::Vec(unsigned size) {
	mySize = size;
	if (size > 0) {
		myArray = new Item[size];
		for (unsigned int i = 0; i < size; ++i) {
			myArray[i] = 0;
		}
	} else {
		myArray = nullptr;
	}
}

/*
 * Takes in Vec object
 * Copies Vec object
 */
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[mySize];
		for (unsigned int i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

/*
 * Structure: Vec = Vec
 * Takes in Vec object
 * Takes Vec on left side of assignment and copies into Vec on right side of assignment
 * Returns copied Vec
 */
Vec& Vec::operator=(const Vec& original) {
    if (&original != this) {
    	if (mySize != original.mySize) {
    		if (mySize > 0) {
    			delete [] myArray ;
    			myArray = nullptr;
    		}
    	}
    	if (original.mySize > 0) {
    		myArray = new Item[original.mySize];
    	}

    	mySize = original.mySize;

    	for (unsigned int i = 0; i < mySize; ++i) {
    		myArray[i] = original.myArray[i];
    	}
    }
	return *this;
 }

//Gets array size
unsigned Vec::getSize() const {
	return mySize;
   }

/*
 * Takes in index and value
 * If allowable, Vec array value at index "index" is replaced or set to value "it"
 */
void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize) {
		throw range_error("This index is out of range");
	} else {
		myArray[index] = it;
	}
}

/*
 * Takes in index
 * If allowable, returns Vec array value at index "index"
 */
Item Vec::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("This index is out of range");
	} else {
		return myArray[index];
	}
}

/*
 * Takes in size value
 * Sets array size to new size
 * New size > array size: array is copied to new array and empty positions are set to 0
 * New size < array size: array is copied to new array until full
 */
void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete [] myArray;
			myArray = nullptr;
			mySize = 0;
		} else {
			Item * newArray = new Item[newSize];
			if (mySize < newSize) {
				for (unsigned int i = 0; i < mySize; ++i) {
					newArray[i] = myArray[i];
		    		}
				for (unsigned int i = mySize; i < newSize; i++) {
					newArray[i] = 0;
					}
			} else {
				for (unsigned int i = 0; i < newSize; i++) {
					newArray [i] = myArray[i];
				}
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}
	}
}

/*
 * Structure: Vec == Vec
 * Takes in Vec
 * Test whether Vec on left side of operator is equal to Vec on right side of operator
 * returns true if equal, otherwise returns false
 */
bool Vec::operator==(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned int i = 0; i < mySize; i++) {
		if (myArray [i] != v2.myArray[i]) {
			return false;
		}
	}
	return true;
}

/*
 * Takes in stream to text file
 * Writes values of Vec to text file
 */
void Vec::writeTo(ostream& out) const {
	for (unsigned int i = 0; i < mySize; i++) {
		out << myArray[i] << " ";
	}
}

/*
 * Takes in stream to text file
 * Writes values in text file to Vec object
 */
void Vec::readFrom(istream& in) {
	for (unsigned int i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

/*
 * Takes in Vec object
 * Checks whether two Vec object are different. Returns true if so
 */
bool Vec::operator!=(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return true;
	}
	for (unsigned int i = 0; i < mySize; i++) {
		if (myArray [i] != v2.myArray[i]) {
			return true;
		}
	}
	return false;
}

/*
 * Takes in Vec object
 * Adds two Vec objects together
 * returns Vec
 */
Vec Vec::operator+(Vec& v2) const {
	if (mySize == v2.mySize) {
		Vec v3(mySize);
		for (unsigned int i = 0; i < mySize; i++) {
			v3.myArray[i] = myArray[i] + v2.myArray[i];
			}
		return v3;
	} else {
		throw invalid_argument("The matrixes are different sizes");
	}
}

/*
 * Takes in Vec object
 * Subtracts two Vec objects
 * Returns Vec
 */
Vec Vec::operator-(Vec& v2) const {
	if (mySize == v2.mySize) {
		Vec v3(mySize);
		for (unsigned int i = 0; i < mySize; i++) {
			v3.myArray[i] = myArray[i] - v2.myArray[i];
			}
		return v3;
	} else {
		throw invalid_argument("The matrixes are different sizes");
	}
}

/*
 * Takes in file name
 * Puts values in file into Vec object
 */
void Vec::readFrom(const string& filename) {
	ifstream fin(filename);
	fin >> mySize;

	delete [] myArray;
	myArray = new Item[mySize];

	for (unsigned i = 0; i < mySize; i++) {
		fin >> myArray[i];
	}
	fin.close();
}

/*
 * Takes in file name
 * Puts integers in file into Vec object
 */
void Vec::writeTo(const string& filename) {
	ofstream fout(filename);
    fout << mySize << "\n";

    for (unsigned i = 0; i < mySize; i++) {
    	fout << myArray[i] << "\n";
    }
	fout.close();
}

/*
 * Takes in Vec object
 * performs dot product and returns value
 */
Item Vec::operator*(Vec& v2) const {
	if (mySize == v2.mySize) {
		Item dotProduct = 0;
		for (unsigned int i = 0; i < mySize; i++) {
			dotProduct += myArray[i] * v2.myArray[i];
			}
		return dotProduct;
	} else {
		throw invalid_argument("The matrixes are different sizes");
	}
}

/*
 * Structure: v[i] = it
 * Receives index value
 * Returns value at index value
 */
Item& Vec::operator[](unsigned index) const {

	if (mySize == 0 || index < 0 || index > mySize) {
		throw range_error("Index outside of Vec range");
	}
	return myArray[index];
}

