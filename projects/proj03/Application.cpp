/* Application.cpp defines the Application test-methods.
* Sam Hoogewind (sth6)
* Date: February 28, 2021
*/

#include "Application.h"
#include "Vec.h"
#include <iostream>
using namespace std;

Application::Application() {
	cout << "Welcome to the Dimension Manager!"
			"\n\nPlease enter the number of dimensions: " << endl;
	int N;
	cin >> N;

	Vec sum;
	Vec increment_position;
	Vec final_position;
	cout << "Please enter a starting position: " << endl;
	for (unsigned int i = 0; i < N; ++i) {
			cin >> sum.myArray[i];
			}

	string response;
	response = "yes";
	unsigned x;
	x = 9999;
	while (response == "yes") {
		cout << "Would you like to add another position? 'Yes' or 'No'" << endl;
		cin >> response;
		if (response == "no") {
			break;
		}

		cout << "Enter a position to add: " << endl;
		for (unsigned i = 0; i < x; i++) {
			cin >> increment_position.myArray[i];
			final_position[i] = final_position[i] + increment_position[i];
		}

		cout << "{";
		for (unsigned i = 0; i < x; i++) {
			if (i < x - 1) {
				cout << increment_position.myArray[i] << ",";
			} else {
				cout << increment_position.myArray[i];
			}
		} cout << "}" << endl;
	}

	cout << "\n Starting Position:" << endl << "{";
	for (unsigned i = 0; i < x; i++) {
		if (i < x - 1) {
			cout << sum.myArray[i] << ",";
		} else {
			cout << sum.myArray[i];
		}
	} cout << "}" << endl;
	cout << "Ending Position:" << endl << "{";
	for (unsigned i = 0; i < x; i++) {
		if (i < x - 1) {
			cout << final_position.myArray[i] << ",";
		} else {
			cout << final_position.myArray[i];
		}
	}
}
