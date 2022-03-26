/* List.cpp defines List class methods.
 * Student Name: Sam Hoogewind (sth6)
 * Date: March 9, 2021
 */

#include "List.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

// Default Constructor
List::List() {
	mySize = 0;
	myFirst = nullptr;
	myLast = nullptr;
}

// Deconstructor
List::~List() {
      delete myFirst;             // delete first node, invoking ~Node()
                                  //  (does nothing if myFirst == nullptr)
      myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
      mySize = 0;                 // clear mySize (optional)
}

/*
 * Returns mySize
 */
Item List::getSize() const {
	return mySize;
}

/*
 * Throws error if List is empty, otherwise returns the first item
 */
Item List::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("List is empty");
	} else {
		return myFirst->myItem;
	}
}

/*
 * Throws error if List is empty, otherwise returns the last item
 */
Item List::getLast() const {
	if (mySize == 0) {
		throw underflow_error("List is empty");
	} else {
		return myLast->myItem;
	}
}

/*
 * Appends Item& it to List, increments the size
 */
void List::append(const Item& it) {
	Node* nodePtr = new Node(it, nullptr);
	if (mySize == 0) {
		myFirst = nodePtr;
	} else {
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize += 1;
}

List::List(const List& original) {
	myFirst = myLast = nullptr;     //  set pointers
	mySize = 0;                     //   and size to 'empty' values
	Node* oPtr = original.myFirst;  //  start at original's first node
	while (oPtr != nullptr) {       //  while there are nodes to copy:
		append(oPtr->myItem);       //   append the item in that node
		oPtr = oPtr->myNext;        //   advance to next node
	}
}

List& List::operator=(const List& rhs) { // rhs == right hand side
	if (this != &rhs) {
		delete myFirst;
		myFirst = myLast = nullptr;
		mySize = 0;
		Node* nPtr = rhs.myFirst;
		while (nPtr != nullptr) {
			append(nPtr->myItem);
			nPtr = nPtr->myNext;
		}
	}
	return *this;
}

/* Operator !=() method
 * By: Samuel Hoogewind
 * @param: list2, a List
 * Return: true, if the values of myList are not equal to list2; and false if otherwise
 */
bool List::operator!=(const List& list2) const {

	if (mySize != list2.mySize) {
		return true;
	} else {
		Node * nPtr = myFirst;
		Node * nPtr2 = list2.myFirst;
		while (nPtr != nullptr) {
			if (nPtr->myItem != nPtr2->myItem) {
				return true;
			}
		}
	}
}

/* readFrom(string)
 * by: Samuel Hoogewind
 * @param: filename, string
 * Precondition: a valid file has been given
 */
void List::readFrom(const string& filename) {
	ifstream fin(filename);

	//empty the list if it's not already
	if (myFirst != nullptr || myLast != nullptr) {
		delete myFirst;
		myFirst = myLast = nullptr;
		mySize = 0;
	}

	//create Item and fill from file
	Item values;
	fin >> values;

	//append values to the list
	while (fin) {
		append(values);
		fin >> values;
	}
	fin.close();
}

/* writeTo(ostream)
 * @param: out, ostream
 * Precondition: an ostream has been given
 */
void List::writeTo(ostream& out, const string& separator) const {
	//create a new node
	Node* nPtr = myFirst;

	//while the node is not NULL, write to the ostream
	while (nPtr) {
		out << separator << nPtr->myItem;

		//update the pointer
		nPtr = nPtr->myNext;
	}
}

/*getIndexOf()
 * By: Samuel Hoogewind
 * @param: Item, an item
 */
unsigned List::getIndexOf(unsigned Item) {
	//create a new node
	Node* nPtr = myFirst;

	unsigned index = 0;
	//loop through the list until you find the item and return the index
	for (unsigned i = 0; i < mySize; i++) {
		if (nPtr->myItem == Item) {
			return index;
		} else {
			nPtr = nPtr->myNext;
			index += 1;
		}
	}
}

/*remove()
 * By: Samuel Hoogewind
 * @param: index, an unsigned int
 */
Item List::remove(unsigned index) {
	//create a new node
	Node* nPtr = myFirst;
	Item item = 0;

	//if the index is <= 0, return and delete the first item
	if (index <= 0) {
		item = nPtr->myItem;
		mySize -= 1;
		return item;
		delete nPtr;

	//if the index is < the total size, return and delete that index
	} else if (index < mySize) {
		for (unsigned i = 0; i < index; i++) {
			nPtr = nPtr->myNext;
		}
		item = nPtr->myItem;
		mySize -= 1;
		return item;
		delete nPtr;

	//if the index is >= the total size, return and delete the last item
	} else if (index >= mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			nPtr = nPtr->myNext;
		}
		item = nPtr->myItem;
		mySize -= 1;
		myLast = nullptr;
		return item;
	    }
}

/* Operator==() method
 * BY: Samuel Haileselassie
 * @param: list2, a List
 * Return: true, if the values of myList are equal to list2;
 *            false, if otherwise
 */
bool List::operator==(const List &list1) const {



    if (mySize != list1.getSize()) {
        return false;
    }
    Node *thisptr = this->myFirst;
    Node *listptr = list1.myFirst;



    while (thisptr) {   //thisptr != NULL
        if (thisptr->myItem != listptr->myItem) {
            return false;
        }
        thisptr = thisptr->myNext;
        listptr = listptr->myNext;
    }
    return true;
}

/* readfrom(cin)...
 * By: Samuel Haileselassie
 * @param: cin, istream
 * Precondition: an istream has been given
 * Postcondition: list has been read from file
 */
void List::readFrom(istream &cin) {
    //make list empty
    delete myFirst;
    mySize = 0;
    myFirst = myLast = nullptr;



    //create Item and fill from cin
    Item values;
    cin >> values;



    //append values to the list
    while (cin) {
        append(values);



        //break if newline character is peeked
        if (cin.peek() == '\n') {
            break;
        }
        cin >> values;
    }
}

/* writeTo(fileName)...
 * By: Samuel Haileselassie
 * @param: fileName, string
 * Precondition: a filename has been given
 * Postcondition: list has been written to the file
 */
void List::writeTo(const string &filename, string separator) const{
    separator = "\n";



    //open ofstream
    ofstream fout(filename);
    assert(fout.is_open());



    //create a new node
    Node *listptr = myFirst;



    //while listptr is not NULL, write to a file with the separator
    while (listptr) {
        if (listptr->myNext != NULL) {
            fout << listptr->myItem << separator;
        }



        //update the pointer to the next
        listptr = listptr->myNext;
    }
}

/* prepend()...
 * By: Samuel Haileselassie
 * @param: it , an Item
 * postcondition: an item has been added to the beginning of a list
 */
void List::prepend(Item it) {
    //create a new pointer with it and myFirst
    Node *listptr = new Node(it, myFirst);



    //if list is empty, point myLast to new node
    if (mySize == 0) {
        myLast = listptr;
    }



    //point myFirst to new node and increment size
    myFirst = listptr;
    mySize++;
}

/* insert()...
 * By: Samuel Haileselassie
 * @param: Item, an item
 * @param: index, an int
 * postcondition: an item has been added to the list at the index
 */
void List::insert(Item it, int index) {
    //if index is negative or zero, prepend it
    if (index <= 0) {
        this->prepend(it);
    } else {
        int size = mySize;
        //if index is greater than the size, append it
        if (index >= size) {
            this->append(it);
        } else {
            List list1;
            for (int i = 0; i < index; i++) {
                list1.append(myFirst->myItem);
                myFirst = myFirst->myNext;
            }
            list1.append(it);
            for (int i = index + 1; i < size + 1; i++){
                list1.append(myFirst->myItem);
                myFirst = myFirst->myNext;
            }
            *this = list1;
        }
    }
}
// Default Constructor
List::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

/*
 * Explicit Constructor
 * Sets myItem to Item& it, and next to a Node pointer
 */
List::Node::Node(const Item& it, Node* next) {
	myItem = it;
	myNext = next;
}

// Deconstructor
List::Node::~Node() {
      delete myNext;       // delete the next node, invoking ~Node() in it
                           // (does nothing if myNext == nullptr)
}
