/* array.cpp defines "C style" array operations
 * Name: Sam Hoogewind (sth6)
 * Date: February 16, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
 
#include "array.h"

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
	float sum;
	for (unsigned i = 0; i < size; ++i) {
			sum = sum + *a;
			a++;
		}
	return sum / size;
}
