/* List.h provides a class for manipulating lists.
 * Student Name: Sam Hoogewind (sth6)
 * Date: March 20, 2021
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

typedef double Item;

template<class Item>
class List {
	friend class ListTester;
public:
	List();
	virtual ~List();
	Item getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& rhs);
	bool operator!=(const List& list1) const;
	void readFrom(const string& filename);
	void writeTo(ostream& out, const string& separator = "\t") const;
	unsigned getIndexOf(unsigned it);
	Item remove(unsigned index);
	bool operator==(const List &list1) const;
	void readFrom(istream &cin);
	void writeTo(const string &filename, string separator) const;
	void prepend(Item it);
	void insert(Item it, int index);
	bool insertAfter(string otherPersonsName, string yourName);
	bool insertBefore(string otherPersonsName, string yourName);

private:
	struct Node {
		Node();
		~Node();
		Node(const Item& it, Node* next);
		Item myItem;
		Node* myNext;
		};
	unsigned mySize;
	Node* myFirst;
	Node* myLast;
};

// Default Constructor
template<class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = nullptr;
	myLast = nullptr;
}

// Deconstructor
template<class Item>
List<Item>::~List() {
      delete myFirst;             // delete first node, invoking ~Node()
                                  //  (does nothing if myFirst == nullptr)
      myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
      mySize = 0;                 // clear mySize (optional)
}

/*
 * Returns mySize
 */
template<class Item>
Item List<Item>::getSize() const {
	return mySize;
}

/*
 * Throws error if List is empty, otherwise returns the first item
 */
template<class Item>
Item List<Item>::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("List is empty");
	} else {
		return myFirst->myItem;
	}
}

/*
 * Throws error if List is empty, otherwise returns the last item
 */
template<class Item>
Item List<Item>::getLast() const {
	if (mySize == 0) {
		throw underflow_error("List is empty");
	} else {
		return myLast->myItem;
	}
}

/*
 * Appends Item& it to List, increments the size
 */
template<class Item>
void List<Item>::append(const Item& it) {
	Node* nodePtr = new Node(it, nullptr);
	if (mySize == 0) {
		myFirst = nodePtr;
	} else {
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize += 1;
}

template<class Item>
List<Item>::List(const List<Item>& original) {
	myFirst = myLast = nullptr;     //  set pointers
	mySize = 0;                     //   and size to 'empty' values
	Node* oPtr = original.myFirst;  //  start at original's first node
	while (oPtr != nullptr) {       //  while there are nodes to copy:
		append(oPtr->myItem);       //   append the item in that node
		oPtr = oPtr->myNext;        //   advance to next node
	}
}

template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& rhs) { // rhs == right hand side
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
template<class Item>
bool List<Item>::operator!=(const List<Item>& list2) const {

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
template<class Item>
void List<Item>::readFrom(const string& filename) {
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
template<class Item>
void List<Item>::writeTo(ostream& out, const string& separator) const {
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
template<class Item>
unsigned List<Item>::getIndexOf(unsigned it) {
	//create a new node
	Node* nPtr = myFirst;

	unsigned index = 0;
	//loop through the list until you find the item and return the index
	for (unsigned i = 0; i < mySize; i++) {
		if (nPtr->myItem == it) {
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
template<class Item>
Item List<Item>::remove(unsigned index) {
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
template<class Item>
bool List<Item>::operator==(const List<Item> &list1) const {



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
template<class Item>
void List<Item>::readFrom(istream &cin) {
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
template<class Item>
void List<Item>::writeTo(const string &filename, string separator) const{
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
template<class Item>
void List<Item>::prepend(Item it) {
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
template<class Item>
void List<Item>::insert(Item it, int index) {
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

/* insertAfter()...
 * By: Samuel Hoogewind
 * @param: otherPersonsName, a string
 * @param: yourName, a string
 * Postcondition: a string yourName has been added to the list after the string
 * otherPersonsName
 */
template<class Item>
bool List<Item>::insertAfter(string otherPersonsName, string yourName) {
	Node* nPtr = myFirst;
	unsigned count = 0;

	for (unsigned i = 0; i < mySize; i++) {
		if (nPtr->myItem == otherPersonsName) {
			insert(yourName, count + 1);
			//insert name
			return true;
		} else {
			count += 1;
			nPtr = nPtr->myNext;
		}
	}

	if (count == mySize) {
		return false;
	}
}

/* insertAfter()...
 * By: Samuel Hoogewind
 * @param: otherPersonsName, a string
 * @param: yourName, a string
 * Postcondition: a string yourName has been added to the list before the string
 * otherPersonsName
 */
template<class Item>
bool List<Item>::insertBefore(string otherPersonsName, string yourName) {
	Node* nPtr = myFirst;
	unsigned count = 0;

	for (unsigned i = 0; i < mySize; i++) {
		if (nPtr->myItem == otherPersonsName) {
			insert(yourName, count);
			//insert name
			return true;
		} else {
			count += 1;
			nPtr = nPtr->myNext;
		}
	}

	if (count == mySize) {
		return false;
	}
}

/* Operator<< method
 * By: Samuel Hoogewind
 * @param: out, an ostream
 * @param: aList, a List
 * Postcondition: outputs the list seperated by '=' to the ostream
 */
template<class Item>
ostream& operator<<(ostream& out, const List<Item>& aList) {
	aList.writeTo(out, "=");
	return out;
}

// Default Constructor
template<class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

/*
 * Explicit Constructor
 * Sets myItem to Item& it, and next to a Node pointer
 */
template<class Item>
List<Item>::Node::Node(const Item& it, Node* next) {
	myItem = it;
	myNext = next;
}

// Deconstructor
template<class Item>
List<Item>::Node::~Node() {
      delete myNext;       // delete the next node, invoking ~Node() in it
                           // (does nothing if myNext == nullptr)
}

#endif /* LIST_H_ */
