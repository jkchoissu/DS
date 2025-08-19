
#ifndef ARRAYVECTOR_H_
#define ARRAYVECTOR_H_

#include <iostream>
#include "VectorException.h"

using namespace std;

typedef int Elem;								// base element type
class ArrayVector {
public:
    ArrayVector();								// constructor
    int size() const;							// number of elements
    bool empty() const;							// is vector empty?
    Elem& operator[](int i);					// element at index
    Elem& at(int i) throw(IndexOutOfBounds);	// element at index
    void erase(int i);							// remove element at index
    void insert(int i, const Elem& e);			// insert element at index
    void set(int i, const Elem& e) throw(IndexOutOfBounds);			// replace element at index
    void reserve(int N);						// reserve at least N spots
    // ... (housekeeping functions omitted)
    void display() const;
private:
    int capacity;								// current array size
    int n;										// number of elements in vector
    Elem* A;									// array storing the elements
};

#endif /* ARRAYVECTOR_H_ */
