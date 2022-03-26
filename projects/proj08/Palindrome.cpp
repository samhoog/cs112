/* Queue.cpp defines the methods for class Palindrome.
 * Student Name: Sam Hoogewind (sth6)
 * Date: April 17, 2021
 */

#include "Palindrome.h"
#include "ArrayQueue.h"
#include "Stack.h"
#include "StackException.h"
#include <iostream>
#include <cassert>
#include <fstream>

Palindrome::Palindrome(const string& input, const string& output) {
	inputFile = input;
	outputFile = output;
}

void Palindrome::detectPalindrome() {
	string line;

	ifstream fin(inputFile);
	ofstream fout(outputFile);
	assert(fin.is_open());
	assert(fout.is_open());
	while (getline(fin, line)) {
		if (line == "") {
			fout << "\n";
		}
		else if (isPalindrome(line)) {
			fout << line << " *** \n";
		} else {
			fout << line << "\n";
		}
	}
	fin.close();
	fout.close();
}

bool Palindrome::isPalindrome(string str) {
	ArrayQueue<char> q(1);
	Stack<char> s(1);
	for (char c_original : str) {             // for each character in the string
		if (isalpha(c_original)) {           // makes sure the characters are in the alphabet
			char c = tolower(c_original);
			try {
				s.push(c);
				q.append(c);
			} catch (const StackException& se) {
				s.setCapacity(s.getCapacity() * 2);
				q.setCapacity(q.getCapacity() * 2);
				s.push(c);
				q.append(c);
			} catch (const FullQueueException& fqe) {
				s.setCapacity(s.getCapacity() * 2);
				q.setCapacity(q.getCapacity() * 2);
				s.push(c);
				q.append(c);
			}
		}
	}
	while (!s.isEmpty() and !q.isEmpty()) {
		char ch1 = s.pop();
		char ch2 = q.remove();
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}
