
#ifndef LISTPQ_H_
#define LISTPQ_H_

#include <iostream>
#include <list>

template <typename E, typename C>
class ListPriorityQueue {
public:
  int size() const;				// number of elements
  bool empty() const;			// is the queue empty?
  void insert(const E& e);		// insert element
  const E& min() const;			// minimum element
  void removeMin();				// remove minimum
  void insert_unsorted(const E& e);		// insert element into sorted list
  const E& min_unsorted() const;		// find minimum element in sorted list
  void removeMin_unsorted();			// remove minimum in sorted list
  void display();				// display element
private:
  std::list<E> L;				// priority queue contents
  C isLess;						// less-than comparator
};

template <typename E, typename C>				// number of elements
int ListPriorityQueue<E,C>::size() const
  { return L.size(); }

template <typename E, typename C>				// is the queue empty?
bool ListPriorityQueue<E,C>::empty() const
  { return L.empty(); }

template <typename E, typename C>				// insert element into sorted list
void ListPriorityQueue<E,C>::insert(const E& e) {
  typename std::list<E>::iterator p;
  p = L.begin();
  while (p != L.end() && !isLess(e, *p)) ++p;	// find larger element
  L.insert(p, e);								// insert e before p
}

template <typename E, typename C>				// minimum element in the sorted list
const E& ListPriorityQueue<E,C>::min() const
  { return L.front(); }							// minimum is at the front

template <typename E, typename C>				// remove minimum in the sorted list
void ListPriorityQueue<E,C>::removeMin()
  { L.pop_front(); }

template <typename E, typename C>				// insert element
void ListPriorityQueue<E,C>::insert_unsorted(const E& e) {
  typename std::list<E>::iterator p;
  p = L.end();
  L.insert(p, e);								// insert e at the end of p
}

template <typename E, typename C>				// minimum element
const E& ListPriorityQueue<E,C>::min_unsorted() const {
	typename std::list<E>::const_iterator p, sp;
	for ( p = L.begin(), sp = p; p != L.end(); ++p) {
		if (isLess(*p,*sp))  sp = p; 			// find the smallest element
	}
	return *sp;
}

template <typename E, typename C>				// remove minimum
void ListPriorityQueue<E,C>::removeMin_unsorted() {
	typename std::list<E>::const_iterator p, ep;
	E e;
	for ( p = L.begin(), e = *p, ep = p; p != L.end(); ++p) {
		if (!isLess(e,*p)) { e = *p; ep = p; }		// find the smallest element
	}
	L.erase(ep);									// remove minimum in the list
}

template <typename E, typename C>				// display element
void ListPriorityQueue<E,C>::display() {
  typename std::list<E>::iterator p;
  std::cout << "PQ { ";
  for (p = L.begin(); p !=  L.end(); ++p)
	  std::cout << *p << " ";					// display element
  std::cout << "}" << std::endl;
}

#endif /* LISTPQ_H_ */
