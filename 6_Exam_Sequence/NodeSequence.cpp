
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

NodeList::NodeList() {				// constructor
    n = 0;							// initially empty
    header = new Node;				// create sentinels
    trailer = new Node;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
}

int NodeList::size() const 			// list size
    { return n; }

bool NodeList::empty() const 				// is the list empty?
    { return (n == 0); }

NodeList::Iterator NodeList::begin() const	// begin position is first item
    { return Iterator(header->next); }

NodeList::Iterator NodeList::end() const	// end position is just beyond last
    { return Iterator(trailer); }

void NodeList::insert(const NodeList::Iterator& p, const Elem& e) {
  Node* w = p.v;						// p's node
  Node* u = w->prev;					// p's predecessor
  Node* v = new Node;					// new node to insert
  v->elem = e;
  v->next = w;  w->prev = v;			// link in v before w
  v->prev = u;  u->next = v;			// link in v after u
  n++;
}

void NodeList::insertFront(const Elem& e)	// insert at front
  { insert(begin(), e); }

void NodeList::insertBack(const Elem& e)	// insert at rear
  { insert(end(), e); }

void NodeList::erase(const Iterator& p) {	// remove p
  Node* v = p.v;							// node to remove
  Node* w = v->next;						// successor
  Node* u = v->prev;						// predecessor
  u->next = w;  w->prev = u;				// unlink p
  delete v;									// delete this node
  n--;										// one fewer element
}

void NodeList::eraseFront()			// remove first
  { erase(begin()); }

void NodeList::eraseBack()			// remove last
  { erase(--end()); }

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
    Iterator q = end();
    int n = size();
    int f, r;	--q;
    for (f = 0, r = (n-1); (f < i) && (r > i); f++, r--) {
    	++p; --q;
    }
//    cout << " atIndex [" << *p << "," << *q << "]" << endl;
    if (f >= i)	return p;
    else		return q;
}
  						// get index from position
int NodeSequence::indexOf(const Iterator& p) const {
    Iterator qf = begin();
    Iterator qr = end();
    int n = size();
    int f = 0,	r = (n-1);	--qr;
    while ((qf != p) && (qr != p)) {			// until finding p
      ++qf; --qr; ++f; --r; 					// advance and count hops
    }
//    cout << " indexOf [" << f << "," << r << "]" << endl;
    if (qf == p)	return f;
    else			return r;
}

void NodeSequence::insertAtRank(int ix, Elem& e) {
	Iterator p = this->atIndex(ix);
	insert(p, e);
}

void bubbleSort1(NodeSequence& S) {			// bubble-sort by indices
  int n = S.size();
  for (int i = 0; i < n; i++) {			// i-th pass
    for (int j = 1; j < n-i; j++) {
      NodeSequence::Iterator prec = S.atIndex(j-1);	// predecessor
      NodeSequence::Iterator succ = S.atIndex(j);		// successor
      if (*prec > *succ) {				// swap if out of order
        int tmp = *prec; *prec = *succ; *succ = tmp;
      }
    }
  }
}

void bubbleSort2(NodeSequence& S) {			// bubble-sort by positions
  int n = S.size();
  for (int i = 0; i < n; i++) {			// i-th pass
    NodeSequence::Iterator prec = S.begin();		// predecessor
    for (int j = 1; j < n-i; j++) {
      NodeSequence::Iterator succ = prec;
      ++succ;						// successor
      if (*prec > *succ) {				// swap if out of order
        int tmp = *prec; *prec = *succ; *succ = tmp;
      }
      ++prec;						// advance predecessor
    }
  }
}

void Sequence_Exam_C_6_10() {
	//	C-6.10 Consider the following fragment of C++ code,
	//	assuming that the constructor Sequence creates an empty sequence of integer objects.
	//	Recall that division between integers performs truncation (for example, 7/2 = 3).
	//	Sequence<int> seq;
	//	for (int i = 0; i < n; i++)
	//		seq.insertAtRank(i/2, i);
	//	a. Assume that the for loop is executed 10 times, that is, n = 10,
	//	   and show the sequence after each iteration of the loop.
	//	b. Draw a schematic illustration of the sequence at the end of the for loop,
	//	   for a generic number n of iterations.

	cout << " <<< Sequence Exam C-6.10 : seq.insertAtRank(i/2, i) " << endl;
	NodeSequence seq;

	int n = 10;
	for (int i = 0; i < n; i++) {
		seq.insertAtRank(i/2, i);
		seq.display();
	}
	cout << endl;
}

void Sequence_Exam_R_6_14() {
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


	bubbleSort2(v);
	v.display();
	cout << endl;

//	R-6.14 In our implementation of the atRank(i) function in Code Fragment 6.18
//	for class NodeSequence, we walked from the front of the list.
//	Present a more efficient implementation,
//	which walks from whichever end of the list is closer to index i.
	cout << " <<< Sequence Exam R-6.14 : update atIndex, IndexOf " << endl;
	cout << "*(v.atIndex(2)) = " << *(v.atIndex(2)) << endl;
	cout << "*(v.atIndex(7)) = " << *(v.atIndex(7)) << endl;

	p = v.begin(); q = v.end();
	++p; ++p;
	cout << "v.indexOf(p) = " << v.indexOf(p) << endl;
	--q; --q;
	cout << "v.indexOf(q) = " << v.indexOf(q) << endl;
	cout << endl;
}

int main() {

	Sequence_Exam_C_6_10();
	Sequence_Exam_R_6_14();

	return EXIT_SUCCESS;
}
