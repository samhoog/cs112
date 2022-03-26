/* array.h declares "C style" array operations.
 * Name: Sam Hoogewind (sth6)
 * Date: February 20, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include <iostream>
#include <cassert>
using namespace std;

void initialize(double *a, unsigned size);

void print(double *a, unsigned size);

double average(double *a, unsigned size);

double sum(double *a, unsigned size);

// void read(istream& in, double *a, unsigned size);
