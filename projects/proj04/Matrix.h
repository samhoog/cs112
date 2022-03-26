/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Sam Hoogewind (sth6)
 * Date: March 2, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {
	friend class MatrixTester;
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	Item getRows() const;
	Item getColumns() const;
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator==(const Matrix& m2) const;
	bool operator!=(const Matrix& m2) const;
	Matrix operator-(Matrix& m2) const;
	Matrix operator+(const Matrix& m2) const;
	Matrix getTranspose();
	void writeTo(ostream& out) const;
	void writeTo(const string& filename);
	void readFrom(const string& filename);
	void readFrom(istream& cin);
	Vec< Vec<Item> > myVec;
	unsigned         myRows;
	unsigned         myColumns;

private:

};

#endif
