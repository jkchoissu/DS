
#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

#include <iostream>
//#include <exception>
#include "QueueException.h"

using namespace std;

template <typename E>
class ArrayQueue {
    enum { DEF_CAPACITY = 100 };			// default queue capacity
public:
    ArrayQueue(int cap = DEF_CAPACITY);		// constructor from capacity
    int size() const;						// number of items in the queue
    bool empty() const;						// is the queue empty?
    const E& front() const throw(QueueEmpty);	// get the front element
    void enqueue(const E& e) throw(QueueFull);	// add an element onto queue
    void dequeue() throw(QueueEmpty);			// remove an element in the queue
    void print() const;						// adding print function
    // ...housekeeping functions omitted
private:                                	// member data
    E* Q;									// array of queue elements
    int capacity;							// queue capacity
    int n;									// size of the queue
    int f;									// index of front node
    int r;									// index of rear node
};

template <typename E> ArrayQueue<E>::ArrayQueue(int cap)
    : Q(new E[cap]), capacity(cap), n(0), f(0), r(0) { }	// constructor from capacity

template <typename E> int ArrayQueue<E>::size() const
    { return n; }											// number of items in the queue

template <typename E> bool ArrayQueue<E>::empty() const
    { return (n == 0); }									// is the queue empty?

template <typename E>										// return front of queue
const E& ArrayQueue<E>::front() const throw(QueueEmpty) {
    if (empty()) throw QueueEmpty("Front of empty queue");
    return Q[f];
}

template <typename E>							// push element onto the stack
void ArrayQueue<E>::enqueue(const E& e) throw(QueueFull) {
    if (size() == capacity) throw QueueFull("Enqueue to full Queue");
    Q[r] = e;
    r = (r + 1) % capacity;
    n = n + 1;
}

template <typename E>							// pop the stack
void ArrayQueue<E>::dequeue() throw(QueueEmpty) {
    if (empty()) throw QueueEmpty("Dequeue from empty Queue");
    f = (f + 1) % capacity;
    n = n - 1;
}

template <typename E>							// print the Queue
void ArrayQueue<E>::print() const {
	cout << "QueueArray [ ";
	if (!this->empty()) {
		for (int i=0; i<this->size(); i++) {
			int ix = (f + i) % capacity;
			cout << Q[ix] << " ";
		}
	}
	cout << "]" << endl;
}

#endif /* ARRAYQUEUE_H_ */
