/* array.cpp defines "C style" array operations
 * Name: Sam Hoogewind (sth6)
 * Date: February 16, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "array.h"
#include <iostream>
#include <fstream>

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; ++i) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		cout << *a << '\t';
		a++;
	}
}

double average(double *a, unsigned size) {
	float total;
	total = 0;
	for (unsigned i = 0; i < size; ++i) {
			total = total + *a;
			a++;
		}
	return total / size;
}

double sum(double *a, unsigned size) {
	unsigned sum;
	sum = 0;
	for (unsigned i = 0; i < size; ++i) {
			sum = sum + *a;
			a++;
		}
	return sum;
}

void read(istream& in, double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		in >> a[i];
		}
}

void fill(const string& fileName, double *&a, unsigned &numValues) {
	ifstream is(fileName);
	is >> numValues;
	double * b;
	b = new double[numValues]();
	for (unsigned i = 0; i < numValues; i++) {
		is >> b[i];
		}

	is.close();
	delete [] a;
	a = b;
}

void resize(double *&a, unsigned oldSize, unsigned newSize) {
	double * b;
	b = new double[newSize]();
	if (newSize > oldSize) {
		for (unsigned i = 0; i < oldSize; i++) {
			b[i] = a[i];
		}
		for (unsigned i = oldSize; i < newSize; i++) {
			b[i] = 0;
		}
	} else {
		for (unsigned i = 0; i < newSize; i++) {
			b[i] = a[i];
		}
	}
	delete [] a;
	a = b;
}

void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3) {
	size3 = size1 + size2;
	a3 = new double[size3]();
	for (unsigned i = 0; i < size1; i++) {
		a3[i] = a1[i];
	}
	for (unsigned i = size1; i < size3; i++) {
		a3[i] = a2[i-size1];
	}
}

