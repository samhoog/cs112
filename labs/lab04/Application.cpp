/* Application.cpp defines the Application test-methods.
* Sam Hoogewind (sth6)
* Date: March 8, 2021
*/

#include "Application.h"
#include "Vec.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

Application::Application() {
	cout << "Welcome to the Matrix Manager!"
			"\n\nPlease Enter:\n   1 - to add two matrices\n"
			"   2 - to subtract two matrices\n"
			"   3 - to transpose a matrix\n"
			"   0 - to quit\n" << flush;
	int input;
	cin >> input;

	if (input == 1) {
		matrixAddition();

	} else if (input == 2) {
		matrixSubtraction();

	} else if (input == 3) {
		matrixTranspose();

	} else if (input == 0) {
		void exit (int status);

	} else {
		cout << "That is not a valid command." << flush;
	}
}

void Application::matrixAddition() {
	cout << "Please enter the filename for the first matrix:\n" << flush;
	string filename;
	cin >> filename;
	cout << "Please enter the filename for the second matrix:\n" << flush;
	string filename2;
	cin >> filename2;
	Matrix m1;
	m1.readFrom(filename);
	Matrix m2;
	m2.readFrom(filename2);
	Matrix m3;
	m3 = m1 + m2;
	for (unsigned i = 0; i < m3.myRows; i++) {
		cout << "\n";
		for (unsigned j = 0; j < m3.myColumns; j++) {
			cout << m3.myVec[i][j] << "	";
		}
	}

}

void Application::matrixSubtraction() {
	cout << "Please enter the filename for the first matrix:\n" << flush;
	string filename;
	cin >> filename;
	cout << "Please enter the filename for the second matrix:\n" << flush;
	string filename2;
	cin >> filename2;
	Matrix m1;
	m1.readFrom(filename);
	Matrix m2;
	m2.readFrom(filename2);
	Matrix m3;
	m3 = m1 - m2;
	for (unsigned i = 0; i < m3.myRows; i++) {
		cout << "\n";
		for (unsigned j = 0; j < m3.myColumns; j++) {
			cout << m3.myVec[i][j] << "	";
		}
	}
}

void Application::matrixTranspose() {
	cout << "Please enter the filename for the matrix:\n" << flush;
	string filename;
	cin >> filename;
	Matrix m1;
	m1.readFrom(filename);
	Matrix mTransposed(m1.myColumns, m1.myRows);
	for (unsigned i = 0; i < m1.myRows; i++) {
		for (unsigned j = 0; j < m1.myColumns; j++) {
			mTransposed[j][i] = m1.myVec[i][j];
		}
	}
	for (unsigned i = 0; i < mTransposed.myRows; i++) {
		cout << "\n";
		for (unsigned j = 0; j < mTransposed.myColumns; j++) {
			cout << mTransposed.myVec[i][j] << "	";
		}
	}

}
