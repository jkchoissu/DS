
#include <iostream>
#include "NodeList.h"
#include "NodeSequence.h"

using namespace std;


NodeList::Iterator::Iterator(Node* u)		// constructor from Node*
  { v = u; }

Elem& NodeList::Iterator::operator*()		// reference to the element
  { return v->elem; }
									// compare positions
bool NodeList::Iterator::operator==(const Iterator& p) const
  { return v == p.v; }

bool NodeList::Iterator::operator!=(const Iterator& p) const
  { return v != p.v; }
									// move to next position
NodeList::Iterator& NodeList::Iterator::operator++()
  { v = v->next; return *this; }
									// move to previous position
NodeList::Iterator& NodeList::Iterator::operator--()
  { v = v->prev; return *this; }

NodeList::NodeList() {				// default constructor
    n = 0;							// initially empty
    header = new Node;				// create sentinels
    trailer = new Node;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
}



int NodeList::size() const 			// list size
    { return n; }

bool NodeList::empty() const 		// is the list empty?
    { return (n == 0); }

NodeList::Iterator NodeList::begin() const	// begin position is first item
    { return Iterator(header->next); }

NodeList::Iterator NodeList::end() const	// end position is just beyond last
    { return Iterator(trailer); }

void NodeList::insert(const NodeList::Iterator& p, const Elem& e) {
  Node* w = p.v;					// p's node
  Node* u = w->prev;				// p's predecessor
  Node* v = new Node;				// new node to insert
  v->elem = e;
  v->next = w;  w->prev = v;		// link in v before w
  v->prev = u;  u->next = v;		// link in v after u
  n++;
}

void NodeList::insertFront(const Elem& e)	// insert at front
  { insert(begin(), e); }

void NodeList::insertBack(const Elem& e)	// insert at rear
  { insert(end(), e); }

void NodeList::erase(const Iterator& p) {	// remove p
  Node* v = p.v;					// node to remove
  Node* w = v->next;				// successor
  Node* u = v->prev;				// predecessor
  u->next = w;  w->prev = u;		// unlink p
  delete v;							// delete this node
  n--;								// one fewer element
}

void NodeList::eraseFront()			// remove first
  { erase(begin()); }

void NodeList::eraseBack()			// remove last
  { erase(--end()); }

NodeList::NodeList(NodeList& node) {// copy constructor
    n = 0;							// initially empty
    header = new Node;				// create sentinels
    trailer = new Node;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;

	for (Iterator t=node.begin(); t!=node.end(); ++t) {
		insertBack(*t);
	}
}

void NodeList::display() const {
	Iterator t = begin();

	cout << " Node List : ";
	while ( t != end() ) {
		cout << *t << " ";
		++t;
	}
	cout << endl;
}
  						// get position from index
NodeSequence::Iterator NodeSequence::atIndex(int i) const {
    Iterator p = begin();
    for (int j = 0; j < i; j++) ++p;
    return p;
}
  						// get index from position
int NodeSequence::indexOf(const Iterator& p) const {
    Iterator q = begin();
    int j = 0;
    while (q != p) {				// until finding p
      ++q; ++j;						// advance and count hops
    }
    return j;
}

void bubbleSort1(NodeSequence& S) {						// bubble-sort by indices
  int n = S.size();
  for (int i = 0; i < n; i++) {							// i-th pass
    for (int j = 1; j < n-i; j++) {
      NodeSequence::Iterator prec = S.atIndex(j-1);		// predecessor
      NodeSequence::Iterator succ = S.atIndex(j);		// successor
      if (*prec > *succ) {								// swap if out of order
        int tmp = *prec; *prec = *succ; *succ = tmp;
      }
    }
    S.display();
  }
}

void bubbleSort2(NodeSequence& S) {						// bubble-sort by positions
  int n = S.size();
  for (int i = 0; i < n; i++) {							// i-th pass
    NodeSequence::Iterator prec = S.begin();			// predecessor
    for (int j = 1; j < n-i; j++) {
      NodeSequence::Iterator succ = prec;
      ++succ;											// successor
      if (*prec > *succ) {								// swap if out of order
        int tmp = *prec; *prec = *succ; *succ = tmp;
      }
      ++prec;											// advance predecessor
    }
  }
}

int main() {

	NodeSequence v;
	NodeList::Iterator p = v.begin();
	NodeList::Iterator q = v.end();

	v.insertFront(8);	v.display();
	p = v.begin();
	cout << " p = " << *p << endl;
	v.insertBack(5);	v.display();
	q = p; ++q;
	cout << " q = " << *q << endl;
	if ( p == v.begin())
			cout << " true" << endl;
	else	cout << " false" << endl;
	v.display();
	v.insert(q,3);	v.display();
    *q = 7;				v.display();
	v.insertFront(9);	v.display();
	v.eraseBack();	v.display();
	v.erase(p);	v.display();
	v.eraseFront();	v.display();


	v.insertFront(9);	v.display();
	v.insertFront(7);	v.display();
	v.insertFront(15);	v.display();
	v.insertFront(22);	v.display();
	v.insertFront(33);	v.display();
	v.insertFront(5);	v.display();
	v.insertFront(11);	v.display();
	v.insertFront(89);	v.display();
	cout << endl;

	NodeSequence v1 = v;
	NodeSequence v2 = v;


	cout << "Bubble Sort Algorithm 1" << endl;
	v1.display();
	bubbleSort1(v1);
	v1.display();
	cout << endl;

	cout << "Bubble Sort Algorithm 2" << endl;
	v2.display();
	bubbleSort2(v2);
	v2.display();
	cout << endl;

	NodeSequence v4;
	v4.insertBack(8);
	v4.insertBack(7);
	v4.insertBack(4);
	v4.insertBack(5);
	v4.insertBack(3);
	v4.insertBack(1);

	cout << "Bubble Sort Algorithm 1" << endl;
	v4.display();
	bubbleSort1(v4);
	v4.display();
	cout << endl;



	return EXIT_SUCCESS;
}
