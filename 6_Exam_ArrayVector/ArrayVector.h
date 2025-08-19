
#ifndef ARRAYVECTOR_H_
#define ARRAYVECTOR_H_

#include <iostream>
#include "VectorException.h"
#include "StackException.h"

using namespace std;

template <typename E>
//typedef int Elem;								// base element type
class ArrayVector {
public:
    // insert Iterator declaration here...
	class Iterator {				// an iterator for the array vector
	public:
	  Iterator(int i, ArrayVector* vec);		// constructor
	  E& operator*();					// reference to the element
	  bool operator==(const Iterator& it) const;	// compare positions
	  bool operator!=(const Iterator& it) const;	// compare positions
	  Iterator& operator++();						// move to next position
	  Iterator& operator--();						// move to previous position
	  friend class ArrayVector;						// give NodeList access
	private:
	  int			index;							// current index in the array
	  ArrayVector* 	vec;							// pointer to the array vector
	};
public:
    ArrayVector();								// default constructor
    ArrayVector(ArrayVector& av);				// copy constructor
    ArrayVector& operator=(const ArrayVector& av);	// assignment constructor
    ~ArrayVector();								// destructor
    int size() const;							// number of elements
    bool empty() const;							// is vector empty?
    E& operator[](int i);						// element at index
    E& at(int i) throw(IndexOutOfBounds);		// element at index
    void erase(int i);							// remove element at index
    void insert(int i, const E& e);				// insert element at index
    void set(int i, const E& e) throw(IndexOutOfBounds);			// replace element at index
    void reserve(int N);						// reserve at least N spots
    void insertFront(const E& e);				// insert element at front
    void insertBack(const E& e);				// insert element at back
    void removeFront();							// remove element at front
    void removeBack();							// remove element at back
    Iterator begin();							// beginning position
    Iterator end();								// (just beyond) last position
    // ... (housekeeping functions omitted)
    void display() const;
private:
    int capacity;								// current array size
    int n;										// number of elements in vector
    E* A;										// array storing the elements
};

template <typename E>
class VectorStack {
public:
    VectorStack(ArrayVector<E>& av);		// constructor from capacity
    int size() const;						// number of items in the stack
    bool empty() const;						// is the stack empty?
    const E& top() const throw(StackEmpty);	// get the top element
    void push(const E& e);					// push element onto stack
    void pop() throw(StackEmpty);			// pop the stack
    void print();
    friend class ArrayVector<E>;
    // ...housekeeping functions omitted
private:                                	// member data
    ArrayVector<E> V;							// array vector of stack elements
};

#endif /* ARRAYVECTOR_H_ */
