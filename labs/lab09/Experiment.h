/*
 * Experiment.h
 *
 *  Created on: Apr 26, 2021
 *      Author: Sam
 */

#ifndef EXPERIMENT_H_
#define EXPERIMENT_H_

#include "BST.h"

typedef int Item;

class Experiment {
public:
	Experiment(const string& filename);
	void getResults();

	unsigned height;
	unsigned duplicates;
};

#endif /* EXPERIMENT_H_ */
