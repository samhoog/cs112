/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: Sam Hoogewind (sth6)
 * Date: April 13, 2021
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>
using namespace std;

typedef int Item;

template<class Item>
class ArrayQueue {
public:

ArrayQueue(unsigned capacity);
	ArrayQueue(const ArrayQueue& original);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	Item remove();
	void setCapacity(unsigned newCapacity);
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of items

protected:
	virtual void makeCopyOf(const ArrayQueue& original);
private:

	friend class ArrayQueueTester;
};

template<class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
	if (capacity < 1) {
		throw QueueException("ArrayQueue(capacity)", "capacity must be positive!");
	} else {
		myCapacity = capacity;
		mySize = myFirstIndex = 0;
		myLastIndex = capacity - 1;
		myArrayPtr = new Item[capacity];
	}
}

/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = nullptr;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

/* accessor for first item in the queue
 * @return the first item
 */
template<class Item>
Item ArrayQueue<Item>::getFirst() const {
	if (isEmpty()) {
		throw EmptyQueueException("ArrayQueue(getFirst)");
	} else {
		return myArrayPtr[myFirstIndex];
	}
}

/* accessor for last item in the queue
 * @return the last item
 */
template<class Item>
Item ArrayQueue<Item>::getLast() const {
	if (isEmpty()) {
		throw EmptyQueueException("ArrayQueue(getLast)");
	} else {
		return myArrayPtr[myLastIndex];
	}
}

/* append method
 * @param: it, an Item
 * @return: nothing
 * Postcondition: the queue isn't full
 */
template<class Item>
void ArrayQueue<Item>::append(const Item& it) {
	if (isFull()) {
		throw FullQueueException("ArrayQueue(append)");
	} else {
		myLastIndex = (myLastIndex + 1) % myCapacity;
		myArrayPtr[myLastIndex] = it;
		mySize ++;
	}
}

/* remove method
 * @param: none
 * @return: result, an Item
 * Postcondition: the queue isn't empty
 */
template<class Item>
Item ArrayQueue<Item>::remove() {
	if (isEmpty()) {
		throw EmptyQueueException("ArrayQueue(remove)");
	} else {
		Item result = myArrayPtr[myFirstIndex];
		myFirstIndex = (myFirstIndex + 1) % myCapacity;
		mySize --;
		return result;
	}
}

template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity == 0 || newCapacity < mySize) {
		throw QueueException("ArrayQueue(setCapactiy)", "newCapacity is smaller than size");
	} else {
		Item* newArrayPtr = new Item[newCapacity];
		for (unsigned i = 0; i < mySize; i++) {
			newArrayPtr[i] = myArrayPtr[(myFirstIndex + i) % myCapacity];
		}
		delete [] myArrayPtr;
		myArrayPtr = newArrayPtr;
		myCapacity = newCapacity;
		myFirstIndex = 0;
		myLastIndex = mySize - 1;
	}
}

#endif /*ARRAY_QUEUE_H_*/
