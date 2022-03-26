/* main.cpp tests the classes in our project.
* Sam Hoogewind (sth6)
* Date: February 9, 2021
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#include "SongTester.h"
#include "PlayListTester.h"
#include "Application.h"

int main() {
	SongTester sTester;
	sTester.runTests();
	PlayListTester plTester;
	plTester.runTests();
	Application();
}
