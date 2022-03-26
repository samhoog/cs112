/* Matrix.cpp defines Matrix class methods.
 * Student Name: Sam Hoogewind (sth6)
 *
 * writeTo(ostream), readFrom(string), operator-(), getTranspose()
 * done by Sam Hoogewind
 *
 * operator!=(), readFrom(istream), writeTo(string), operator+()
 * done by Alexandra Prasser
 *
 * Date: March 2, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Matrix.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <stdexcept>

// Default Constructor
Matrix::Matrix() {
	myRows = myColumns = 0;
    }

/*
 * Explicit Constructor
 * Takes in size value and creates Matrix object of size "rows" and "columns"
 */
Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

/*
 * Returns number of rows
 */
Item Matrix::getRows() const {
	return myRows;
}

/*
 * Returns number of columns
 */
Item Matrix::getColumns() const {
	return myColumns;
}

/*
 * Returns index
 */
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (index >= myRows) {
		throw range_error("Index outside of Matrix range");
	} else {
		return myVec[index];
	}
}

/*
 * Returns index
 */
Vec<Item>& Matrix::operator[](unsigned index) {
	if (index >= myRows){
		throw range_error("Index outside of Matrix range");
	} else {
		return myVec[index];
	}
}

/*
 * Structure: Matrix = Matrix
 * Takes in two Matrix objects
 * Takes Matrix on left side of assignment and compares to Matrix on right side of assignment
 * Returns bool true or false
 */
bool Matrix::operator==(const Matrix& m2) const {
      if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
           return false;
      } else {
           return myVec == m2.myVec;
      }
}

/*
*  inequality operator (agp27)
*  determines if two matrix are not equal
*  @param: const Matrix&
*  @return: return true or return myVec != m2
*/
bool Matrix::operator!=(const Matrix& m2) const {
	if( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return true;
	} else {
		return myVec != m2.myVec;
	}
}

/*
 * Takes in Matrix object
 * Subtracts two Matrix objects
 * Returns Matrix
 */
Matrix Matrix::operator-(Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		throw invalid_argument("The matrixes are different sizes");
	} else {
		Matrix m3(myRows, myColumns);
		for (unsigned i = 0; i < myRows; i++) {
			for (unsigned j = 0; j < myColumns; j++) {
				m3[i][j] = myVec[i][j] - m2[i][j];
			}
		}
		return m3;
	}
}

/*
 * Takes in Matrix object
 * Adds two Matrix objects
 * Returns Matrix
 */
Matrix Matrix::operator+(const Matrix& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		throw std::invalid_argument("Invalid Argument");
	}
	else {
		Matrix m3(myRows, myColumns);
		for (unsigned i = 0; i < myRows; ++i) {
			for (unsigned j = 0; j < myColumns; j++) {
				m3[i][j] = myVec[i][j] + m2[i][j];
			}
		}
	return m3;
	}
}

/*
 * Takes Matrix object and flips it's columns and rows
 */
Matrix Matrix::getTranspose() {
	Matrix mTransposed(myColumns, myRows);
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			mTransposed[j][i] = myVec[i][j];
		}
	}
	return mTransposed;
}

/*
 * Takes in ostream
 * Puts integers in Matrix object into file
 */
void Matrix::writeTo(ostream& out) const {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] << "	";
		}
	}
}

/*
*  Write to file
*  writes the values in a matrix to a file
*  @param: filename
*  @return: none
*/
void Matrix::writeTo(const string& filename) {
	ofstream fout(filename);
	assert( fout.is_open());
	fout << myRows << "\t" << myColumns << endl;
	for (unsigned i = 0; i < myRows; ++i) {
		for (unsigned j = 0; j < myColumns; j++) {
			fout << myVec[i][j] << " ";
		}
	}
	fout.close();
}

/*
*  Read from istream
*  Read the values from an istream to a matrix
*  @param: istream
*  @return: none
*/
void Matrix::readFrom(istream& cin) {
    while (cin) {
		for (unsigned i = 0; i < myRows; ++i) {
			for (unsigned j = 0; j < myColumns; j++) {
				cin >> myVec[i][j];
			}
		}
	}
}

/*
 * Takes in file name
 * Puts values in file into Matrix object
 */
void Matrix::readFrom(const string& filename) {
	ifstream fin(filename);
	fin >> myRows;
	fin >> myColumns;

	myVec.setSize(myRows);
	for (unsigned i = 0; i < myRows; i++) {
			myVec[i].setSize(myColumns);
	}

	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			fin >> myVec[i][j];
		}
	}
	fin.close();
}
