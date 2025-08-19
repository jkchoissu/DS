
#ifndef NODELIST_H_
#define NODELIST_H_

#include <iostream>

using namespace std;

template <typename E>
//typedef int Elem;				// list base element type
class NodeList {				// node-based list
private:
    // insert Node declaration here...
	struct Node {				// a node of the list
	  E elem;				// element value
	  Node* prev;				// previous in list
	  Node* next;				// next in list
	};
public:
    // insert Iterator declaration here...
	class Iterator {				// an iterator for the list
	public:
	  E& operator*();			// reference to the element
	  bool operator==(const Iterator& p) const;	// compare positions
	  bool operator!=(const Iterator& p) const;
	  Iterator& operator++();			// move to next position
	  Iterator& operator--();			// move to previous position
	  Iterator operator++(int);			// move to next position
	  Iterator operator--(int);			// move to previous position
	  friend class NodeList;			// give NodeList access
	private:
	  Node* v;						// pointer to the node
	  Iterator(Node* u);			// create from node
	};
public:
    NodeList();									// default constructor
    NodeList(const NodeList& node);				// copy constructor
    NodeList& operator=(const NodeList& node);	// assignment constructor
    ~NodeList();					// destructor
    int size() const;				// list size
    bool empty() const;				// is the list empty?
    Iterator begin() const;			// beginning position
    Iterator end() const;			// (just beyond) last position
    void insertFront(const E& e);		// insert at front
    void insertBack(const E& e);		// insert at rear
    void insert(const Iterator& p, const E& e); // insert e before p
    void eraseFront();				// remove first
    void eraseBack();				// remove last
    void erase(const Iterator& p);		// remove p
    void display() const;
    // housekeeping functions omitted...
private:					// data members
    int     n;					// number of items
    Node*   header;				// head-of-list sentinel
    Node*   trailer;				// tail-of-list sentinel
};


#endif /* NODELIST_H_ */
