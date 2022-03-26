/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:
 * Date:
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == nullptr ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

typedef int Item;

template<class Item>
class BST {
public:

	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	void insert(const Item& item);
	bool contains(const Item& item) const;
	int getHeight();

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            void insert(const Item& item);
            bool contains(const Item& item) const;
            int getHeight(Node* myRoot) const;
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

template<class Item>
BST<Item>::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}

template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

template<class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = nullptr;
   myRight = nullptr;
}

template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template<class Item>
void BST<Item>::insert(const Item& item) {
	if (isEmpty()) {
		myRoot = new Node(item);
	} else {
		try {
			myRoot->insert(item);
		} catch (...){
			throw Exception("BST(insert)", "Item already in the BST");
		}
	}
	myNumItems += 1;
}

template<class Item>
bool BST<Item>::contains(const Item& item) const {
	if (isEmpty()) {
		return false;
	} else {
		return myRoot->contains(item);
	}
}

template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template<class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

template<class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

template<class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != nullptr) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != nullptr) {
		myRight->traverseInorder();
	}
}

template<class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != nullptr) {
		myLeft->traversePostorder();
	}
	if (myRight != nullptr) {
		myRight->traversePostorder();
	}
	processItem();
}

template<class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

template<class Item>
void BST<Item>::Node::insert(const Item& item) {
	if (item < myItem) {
		if (myLeft == nullptr) {
			myLeft = new Node(item);
		} else {
			myLeft->insert(item);
		}
	} else if (item > myItem) {
		if (myRight == nullptr) {
			myRight = new Node(item);
		} else {
			myRight->insert(item);
		}
	} else {
		throw Exception("Node::insert", "Item already in the BST");
	}
}

template<class Item>
bool BST<Item>::Node::contains(const Item& item) const {
	if (item < myItem) {
		if (myLeft == nullptr) {
			return false;
		} else {
			return myLeft->contains(item);
		}
	} else if (item > myItem ) {
		if (myRight == nullptr) {
			return false;
		} else {
			return myRight->contains(item);
		}
	} else {
		return true;
	}
}

template<class Item>
int BST<Item>::getHeight() {
	return myRoot->getHeight(myRoot);
}

template<class Item>
int BST<Item>::Node::getHeight(Node* myRoot) const {
	if (myRoot == nullptr) {
		return 0;
	} else {
		int leftHeight = getHeight(myRoot->myLeft);
		int rightHeight = getHeight(myRoot->myRight);
		if (leftHeight > rightHeight) {
			return (leftHeight + 1);
		} else {
			return (rightHeight + 1);
		}
	}
}

#endif /*BST_H_*/

