
#include "BST_Tester.h"
#include "Experiment.h"

int main() {
//	BST_Tester bstt;
//	bstt.runTests();
	Experiment e("randomInts01.txt");
	cout << "Text file 1: " << endl;
	e.getResults();

	Experiment e2("randomInts02.txt");
	cout << "Text file 2: " << endl;
	e2.getResults();

	Experiment e3("randomInts03.txt");
	cout << "Text file 3: " << endl;
	e3.getResults();

	Experiment e4("randomInts04.txt");
	cout << "Text file 4: " << endl;
	e4.getResults();

	Experiment e5("randomInts05.txt");
	cout << "Text file 5: " << endl;
	e5.getResults();

	Experiment e6("randomInts06.txt");
	cout << "Text file 6: " << endl;
	e6.getResults();

	Experiment e7("randomInts07.txt");
	cout << "Text file 7: " << endl;
	e7.getResults();

	Experiment e8("randomInts08.txt");
	cout << "Text file 8: " << endl;
	e8.getResults();

	Experiment e9("randomInts09.txt");
	cout << "Text file 9: " << endl;
	e9.getResults();

	Experiment e10("randomInts10.txt");
	cout << "Text file 10: " << endl;
	e10.getResults();
}
