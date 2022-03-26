/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Sam Hoogewind (sth6)
 * Date: March 30, 2021
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

typedef int Item;

template<class Item>
class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty() const;
	void push(const Item& it);
	Item peekTop() const;
	bool isFull() const;
	Item pop();
	unsigned getSize () const;
	unsigned getCapacity() const;
	void setCapacity(unsigned newCapacity);
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	
protected:
	void makeCopyOf(const Stack& original);
	
private:
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned capacity) {
	if ( capacity < 1 ) {
		throw StackException("Stack(capacity)", "capacity must be positive!");
	}
	mySize = 0;
    myCapacity = capacity;
    myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template<class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; ++i) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
template<class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = nullptr;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/* isEmpty method
 * returns true if the stack is empty, false if not.
 */
template<class Item>
bool Stack<Item>::isEmpty() const {
	if (mySize == 0) {
		return true;
	} else {
		return false;
	}
}

/* push method
 * pushes parameter it onto end of stack, unless stack is at capacity.
 */
template<class Item>
void Stack<Item>::push(const Item& it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full");
	}
	myArray[mySize] = it;
	mySize += 1;
}

/* peekTop method
 * returns the last item in the stack unless the stack is empty
 */
template<class Item>
Item Stack<Item>::peekTop() const {
	if ( isEmpty() ) {
		throw StackException("peekTop()", "stack is empty");
	}
	return myArray[mySize - 1];
}

/* isFull method
 * returns if the stack has reach max capacity
 */
template<class Item>
bool Stack<Item>::isFull() const {
	return mySize == myCapacity;
}

/* pop method
 * removes and returns the top value from the stack
 */
template<class Item>
Item Stack<Item>::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty");
	}
	mySize -= 1;
	return myArray[mySize];
}

/* getSize method
 * returns the stacks current size
 */
template<class Item>
unsigned Stack<Item>::getSize() const {
	return mySize;
}

/* getCapactiy method
 * returns the stacks capacity
 */
template<class Item>
unsigned Stack<Item>::getCapacity() const {
	return myCapacity;
}

template<class Item>
void Stack<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity == 0 or newCapacity < mySize) {
		throw StackException("setCapactiy()", "new capacity is smaller than size");
	} else if (newCapacity == myCapacity) {
		return;
	} else {
		Item* newArray = new Item[newCapacity];
		for (unsigned i = 0; i < mySize; ++i) {
			newArray[i] = myArray[i];
		}
		myCapacity = newCapacity;
		delete [] myArray;
		myArray = newArray;
	}
}
#endif

