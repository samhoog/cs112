/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: Sam Hoogewind (sth6)
 * Date: April 13, 2021
 */

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = myLastPtr = nullptr;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = nullptr;
	} else {
		myFirstPtr = new Node(original.getFirst(), nullptr);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != nullptr) {
			temp1->myNextPtr = new Node(temp0->myItem, nullptr);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = nullptr;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

/* accessor for first item in the queue
 * @return the first item
 */
Item LinkedQueue::getFirst() const {
	if (isEmpty()) {
		throw EmptyQueueException("LinkedQueue(getFirst)");
	} else {
		return myFirstPtr->myItem;
	}
}

/* accessor for last item in the queue
 * @return the last item
 */
Item LinkedQueue::getLast() const {
	if (isEmpty()) {
		throw EmptyQueueException("LinkedQueue(getLast)");
	} else {
		return myLastPtr->myItem;
	}
}

void LinkedQueue::append(const Item& it) {
	try {
		Node* nPtr = new Node(it, nullptr);
		if (isEmpty()) {
			myFirstPtr = nPtr;
		} else {
			myLastPtr->myNextPtr = nPtr;
	    }
	    myLastPtr = nPtr;
	    mySize ++;
	} catch(std::bad_alloc) {
		throw FullQueueException("LinkedQueue(append)");
    }
}

Item LinkedQueue::remove() {
	if (isEmpty()) {
		throw EmptyQueueException("LinkedQueue(remove)");
	} else {
		Item result = myFirstPtr->myItem;
		Node* nPtr = myFirstPtr;
		myFirstPtr = myFirstPtr->myNextPtr;
		nPtr->myNextPtr = nullptr;
		delete nPtr;
		mySize -= 1;
		if (mySize == 0) {
			myLastPtr = nullptr;
		}
		return result;
	}
}
