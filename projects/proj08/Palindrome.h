/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: Sam Hoogewind (sth6)
 * Date: April 17, 2021
 */
#ifndef PALINDROME_H_
#define PALINDROME_H_
using namespace std;
#include <string>

class Palindrome {
public:
	Palindrome(const string& input, const string& output);
	void detectPalindrome();
	bool isPalindrome(string str);
	string inputFile;
	string outputFile;
};

#endif /* PALINDROME_H_ */
