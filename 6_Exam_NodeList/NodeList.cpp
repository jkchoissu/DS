
#include <iostream>
#include "NodeList.h"

using namespace std;

template <typename E>
NodeList<E>::Iterator::Iterator(Node* u)		// default constructor from Node*
  { v = u; }

template <typename E>
E& NodeList<E>::Iterator::operator*()			// reference to the element
  { return v->elem; }

template <typename E>							// compare positions
bool NodeList<E>::Iterator::operator==(const Iterator& p) const
  { return v == p.v; }

template <typename E>
bool NodeList<E>::Iterator::operator!=(const Iterator& p) const
  { return v != p.v; }

template <typename E>							// move to next position
typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator++()
  { v = v->next; return *this; }

template <typename E>							// move to previous position
typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator--()
  { v = v->prev; return *this; }

template <typename E>							// move to next position
typename NodeList<E>::Iterator NodeList<E>::Iterator::operator++(int)
{
	Iterator t = v;
	++(*this);
	return t;
}

template <typename E>							// move to previous position
typename NodeList<E>::Iterator NodeList<E>::Iterator::operator--(int)
{ 	Iterator t = v;
	--(*this);
	return t;
}

template <typename E>
NodeList<E>::NodeList() {					// constructor
    n = 0;									// initially empty
    header = new Node;						// create sentinels
    trailer = new Node;
    header->next = trailer;					// have them point to each other
    trailer->prev = header;
}

template <typename E>
int NodeList<E>::size() const 				// list size
    { return n; }

template <typename E>
bool NodeList<E>::empty() const 			// is the list empty?
    { return (n == 0); }

template <typename E>
typename NodeList<E>::Iterator NodeList<E>::begin() const	// begin position is first item
    { return Iterator(header->next); }

template <typename E>
typename NodeList<E>::Iterator NodeList<E>::end() const	// end position is just beyond last
    { return Iterator(trailer); }

template <typename E>
void NodeList<E>::insert(const NodeList<E>::Iterator& p, const E& e) {
  Node* w = p.v;							// p's node
  Node* u = w->prev;						// p's predecessor
  Node* v = new Node;						// new node to insert
  v->elem = e;
  v->next = w;  w->prev = v;				// link in v before w
  v->prev = u;  u->next = v;				// link in v after u
  n++;
}

template <typename E>
void NodeList<E>::insertFront(const E& e)	// insert at front
  { insert(begin(), e); }

template <typename E>
void NodeList<E>::insertBack(const E& e)	// insert at rear
  { insert(end(), e); }

template <typename E>
void NodeList<E>::erase(const Iterator& p) {	// remove p
  Node* v = p.v;							// node to remove
  Node* w = v->next;						// successor
  Node* u = v->prev;						// predecessor
  u->next = w;  w->prev = u;				// unlink p
  delete v;									// delete this node
  n--;										// one fewer element
}

template <typename E>
void NodeList<E>::eraseFront()				// remove first
  { erase(begin()); }

template <typename E>
void NodeList<E>::eraseBack()				// remove last
  { erase(--end()); }

template <typename E>
NodeList<E>::NodeList(const NodeList<E>& node) : NodeList() {	// copy constructor

	for (Iterator t=node.begin(); t!=node.end(); ++t) {
		insertBack(*t);
	}
}

template <typename E>
NodeList<E>& NodeList<E>::operator=(const NodeList<E>& node) {	// assignment constructor
	if (this != &node) {
		while (!empty()) eraseBack();			// remove all nodes

		for (Iterator t=node.begin(); t!=node.end(); ++t) {
			insertBack(*t);
		}
	}
	return *this;
}

template <typename E>
NodeList<E>::~NodeList() {					// destructor
	while (!empty()) eraseBack();			// remove all nodes

	delete header;							// delete sentinels
	delete trailer;

}

template <typename E>
void NodeList<E>::display() const {			// display node list
	Iterator t = begin();

	cout << " Node List : ";
	while ( t != end() ) {
		cout << *t << " ";
		++t;
	}
	cout << endl;
}

void List_Exam_R_6_12(NodeList<int>& v) {

	//	R-6.12 Provide the missing housekeeping functions
	//	(copy constructor, assignment operator, and destructor)
	//	for the class NodeList, which was presented in Code Fragment 6.9.
	cout << " >>> List Exam R-6.12 : Copy/Assignment Constructor ...." << endl;
	cout << "Copy Constructor" << endl;
	NodeList<int>	v2(v);
	v2.insertFront(15);
	v2.insertBack(16);
	v2.display();
	cout << endl;

	cout << "Assignment Constructor" << endl;
	NodeList<int>	v3 = v2;
	v3.eraseFront();
	v3.insertFront(25);
	v3.insertBack(26);
	v3.display();
	cout << endl;

}

void List_Exam_R_6_13(NodeList<int>& v) {
	//	R-6.13 In our implementation of an iterator for class NodeList in Code Fragment 6.7,
	//	we defined only the preincrement operator.
	//	Provide a definition for a postincrement operator.
	cout << " >>> List Exam R-6.13 : Post-increment/post-decrement operator (*p++, *p--)" << endl;
	NodeList<int>	v4(v);
	NodeList<int>::Iterator p4 = v4.begin();
	NodeList<int>::Iterator q4 = v4.end();

	v4.insertFront(15);
	v4.insertBack(16);
	v4.eraseFront();
	v4.insertFront(25);
	v4.insertBack(26);
	v4.display();

	p4 = v4.begin();
	v4.insertFront(38);						v4.display();
	p4 = v4.begin();
	cout << " p = " << *p4++ << ", "; 		v4.display();
	cout << " p = " << *p4 << ", "; 		v4.display();
	cout << " p = " << *(++p4) << ", "; 	v4.display();
	q4 = v4.end();
	*q4--;
	cout << " q = " << *q4-- << ", "; 		v4.display();
	cout << " q = " << *q4 << ", "; 		v4.display();
	cout << " q = " << *(--q4) << ", "; 	v4.display();
}

int main() {

	NodeList<int> v;
	NodeList<int>::Iterator p = v.begin();
	NodeList<int>::Iterator q = v.end();

	v.insertFront(8);				v.display();
	p = v.begin();
	cout << " p = " << *p << ", "; 	v.display();
	v.insertBack(5);				v.display();
	q = p; ++q;
	cout << " q = " << *q << ", ";	v.display();
	cout << " " << boolalpha << (p == v.begin()) << ", "; v.display();
	v.insert(q,3);					v.display();
    *q = 7;							v.display();
	v.insertFront(9);				v.display();
//	v.eraseBack();					v.display();
//	v.erase(p);						v.display();
//	v.eraseFront();					v.display();
	cout << endl;

	List_Exam_R_6_12(v);
	List_Exam_R_6_13(v);

	return EXIT_SUCCESS;
}
