
#ifndef HEAPPQ_H_
#define HEAPPQ_H_

#include <iostream>
#include "VectorComplete.h"

template <typename E, typename C>
class HeapPriorityQueue {
private :
    typedef typename VectorCompleteTree<E>::Position Position;
public:
    int size() const;					// number of elements
    bool empty() const;					// is the queue empty?
    const E& min();						// minimum element
    Position insert(const E& e);		// insert element
    void removeMin();					// remove minimum
    void remove(Position& p);		// remove at position p
    Position replace(Position& p, const E& e); // replace at position p
    void heaporder(Position& v);		// preorder traversal for HeapPQ display
    void display();
private:
    VectorCompleteTree<E> T;		// priority queue contents
    C isLess;						// less-than comparator
    								// shortcut for tree position
};

template <typename E, typename C>	// number of elements
int HeapPriorityQueue<E,C>::size() const
    { return T.size(); }

template <typename E, typename C>	// is the queue empty?
bool HeapPriorityQueue<E,C>::empty() const
    { return size() == 0; }

template <typename E, typename C>	// minimum element
const E& HeapPriorityQueue<E,C>::min()
    { return *(T.root()); }			// return reference to root element

template <typename E, typename C>	// insert element
typename VectorCompleteTree<E>::Position HeapPriorityQueue<E,C>::insert(const E& e) {
    T.addLast(e);					// add e to heap
    Position v = T.last();			// e's position
    while (!T.isRoot(v)) {			// up-heap bubbling
      Position u = T.parent(v);
      if (!isLess(*v, *u)) break;	// if v in order, we're done
      T.swap(v, u);					// ...else swap with parent
      v = u;
    }

    return v;
}

template <typename E, typename C>	// remove minimum
void HeapPriorityQueue<E,C>::removeMin() {
    if (size() == 1)				// only one node?
      T.removeLast();				// ...remove it
    else {
      Position u = T.root();		// root position
      T.swap(u, T.last());			// swap last with root
      T.removeLast();				// ...and remove last
      while (T.hasLeft(u)) { 		// down-heap bubbling
        Position v = T.left(u);
        if (T.hasRight(u) && isLess(*(T.right(u)), *v))
          v = T.right(u);			// v is u's smaller child
        if (isLess(*v, *u)) {		// is u out of order?
          T.swap(u, v);				// ...then swap
          u = v;
        }
        else break;					// else we're done
      }
    }
}

template <typename E, typename C>	// remove minimum
void HeapPriorityQueue<E,C>::remove(Position& p) {
      T.swap(p, T.last());			// swap last with root
      T.removeLast();				// ...and remove last
      while (T.hasLeft(p)) { 		// down-heap bubbling
        Position v = T.left(p);
        if (T.hasRight(p) && isLess(*(T.right(p)), *v))
          v = T.right(p);			// v is u's smaller child
        if (isLess(*v, *p)) {		// is u out of order?
          T.swap(p, v);				// ...then swap
          p = v;
        }
        else break;					// else we're done
      }
}

template <typename E, typename C>			// replace at position p
typename VectorCompleteTree<E>::Position HeapPriorityQueue<E,C>::replace(Position& p, const E& e) {
  remove(p);								// remove the old entry
  return insert(e);							// insert replacement
}

template <typename E, typename C>
void HeapPriorityQueue<E,C>::heaporder(Position& v) {  // preorder traversal for display
	Position u;

	std::cout << *v << " ";
	if (T.hasLeft(v)) 	{ u = T.left(v);	heaporder(u); };
	if (T.hasRight(v)) 	{ u = T.right(v); 	heaporder(u); };
}

template <typename E, typename C>						// display heap PQ
void HeapPriorityQueue<E,C>::display() {
	Position u = T.root();		// root position

	std::cout << "Heap PQ { ";
	if (T.size() != 0)	heaporder(u);
	std::cout << "}" << std::endl;
}

#endif /* HEAPPQ_H_ */
