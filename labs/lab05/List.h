/* List.h provides a class for manipulating lists.
 * Student Name: Sam Hoogewind (sth6)
 * Date: March 9, 2021
 */

#ifndef LIST_H_
#define LIST_H_
#include <fstream>
using namespace std;

typedef double Item;

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

#endif /* LIST_H_ */
