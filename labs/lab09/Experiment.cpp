/* ReversePoem.cpp defines ReversePoem class methods.
 * Student Name: Sam Hoogewind (sth6)
 * Date: April 24, 2021
 */

#include "Experiment.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

Experiment::Experiment(const string& filename) {
	BST<long> bst;
	long value;
	ifstream fin(filename.c_str());
	assert(fin.is_open());

	while (fin >> value) {
		try {
			bst.insert(value);
		} catch (Exception &e) {
			duplicates ++;
		}
	}
	fin.close();
	height = bst.getHeight();
}

void Experiment::getResults() {
	cout << "Height: " << height << endl;
	cout << "Duplicates: " << duplicates << endl;
}
