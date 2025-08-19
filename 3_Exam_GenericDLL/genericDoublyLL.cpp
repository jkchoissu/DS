
#include <iostream>

using namespace std;

template <typename E>
class DLinkedList;

// Node structure
template <typename E>
struct DNode {
    E elem;
    DNode<E>* prev;
    DNode<E>* next;
    friend class DLinkedList<E>;
};

// Doubly Linked List class
template <typename E>
class DLinkedList {						// doubly linked list
public:
        DLinkedList();					// constructor
        ~DLinkedList();					// destructor
        bool empty() const;				// is list empty?
        const E& front() const;			// get front element
        const E& back() const;			// get back element
        void addFront(const E& e);		// add to front of list
        void addBack(const E& e);		// add to back of list
        void removeFront();				// remove from front
        void removeBack();				// remove from back
        void display() const;
private:								// local type definitions
        DNode<E>* header;				// list sentinels
        DNode<E>* trailer;
protected:								// local utilities
        void add(DNode<E>* v, const E& e);	// insert new node before v
        void remove(DNode<E>* v);			// remove node v
};

template <typename E>
DLinkedList<E>::DLinkedList() {			// constructor
        header = new DNode<E>;			// create sentinels
        trailer = new DNode<E>;
        header->next = trailer;			// have them point to each other
        trailer->prev = header;
}

template <typename E>
DLinkedList<E>::~DLinkedList() {			// destructor
        while (!empty()) removeFront();		// remove all but sentinels
        delete header;						// remove the sentinels
        delete trailer;
}

template <typename E>
bool DLinkedList<E>::empty() const			// is list empty?
        { return (header->next == trailer); }

template <typename E>
const E& DLinkedList<E>::front() const		// get front element
        { return header->next->elem; }

template <typename E>
const E& DLinkedList<E>::back() const		// get back element
        { return trailer->prev->elem; }

template <typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e) {
        DNode<E>* u = new DNode<E>;  u->elem = e;	// create a new node for e
        u->next = v;						// link u in between v
        u->prev = v->prev;					// ...and v->prev
        v->prev->next = v->prev = u;
}

template <typename E>
void DLinkedList<E>::addFront(const E& e)	// add to front of list
        { add(header->next, e); }

template <typename E>
void DLinkedList<E>::addBack(const E& e)	// add to back of list
        { add(trailer, e); }

template <typename E>
void DLinkedList<E>::remove(DNode<E>* v) {		// remove node v
        DNode<E>* u = v->prev;					// predecessor
        DNode<E>* w = v->next;					// successor
        u->next = w;							// unlink v from list
        w->prev = u;
        delete v;
}

template <typename E>
void DLinkedList<E>::removeFront()				// remove from font
        { remove(header->next); }

template <typename E>
void DLinkedList<E>::removeBack()				// remove from back
        { remove(trailer->prev); }

template <typename E>
void DLinkedList<E>::display() const {
        DNode<E>* v = header;
        cout << "Output : ";
        while (v->next != trailer) {
          v = v->next;
       	  cout << v->elem << " ";
        }
        cout << endl;
};

template <typename E>
void listReverse(DLinkedList<E>& L) {		// reverse a list
	  DLinkedList<E> T;						// temporary list
	  while (!L.empty()) {					// reverse L into T
		  string s = L.front();
		  L.removeFront();
		  T.addFront(s);
	  }
	  while (!T.empty()) {					// copy T back to L
		  string s = T.front();
		  T.removeFront();
		  L.addBack(s);
	  }
}

// Example usage
int main() {

	DLinkedList<string> a;

    a.addFront("Korea");
    a.display(); // Output:
    a.addBack("Japan");
    a.display(); // Output:
    a.addBack("China");
    a.display(); // Output:
    a.addFront("UK");
    a.display(); // Output:
    a.addFront("France");
    a.display(); // Output:
    a.addFront("Spain");
    a.display(); // Output:
    a.removeBack();
    a.display(); // Output:
    a.removeFront();
    a.display(); // Output:

    listReverse(a);

    a.display(); // Output:

    return EXIT_SUCCESS;
}




