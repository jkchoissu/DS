
#ifndef QWITH2STK_H_
#define QWITH2STK_H_

#include <iostream>
//#include <exception>
#include "StackQueueException.h"
#include "ArrayStack.h"

using namespace std;

template <typename E>
class Queuewith2Stk {
    enum { DEF_CAPACITY = 100 };			// default queue capacity
public:
    Queuewith2Stk(int cap = DEF_CAPACITY); 	// constructor from capacity
    int size() const;						// number of items in the queue
    bool empty() const;						// is the queue empty?
    E front() throw(QueueEmpty);			// get the front element
    void enqueue(const E& e) throw(QueueFull);	// add an element onto queue
    void dequeue() throw(QueueEmpty);			// remove an element in the queue
    void print();							// adding print function
    // ...housekeeping functions omitted
private:                                	// member data
    ArrayStack<E> S1;
    ArrayStack<E> S2;
    int capacity;
};

template <typename E> Queuewith2Stk<E>::Queuewith2Stk(int cap)
    : S1(cap), S2(cap), capacity(cap) { }					// constructor from capacity

template <typename E> int Queuewith2Stk<E>::size() const
    { return S1.size(); }									// number of items in the stack

template <typename E> bool Queuewith2Stk<E>::empty() const
    { return S1.empty(); }									// is the queue empty?

template <typename E>										// return front of queue
E Queuewith2Stk<E>::front() throw(QueueEmpty) {
    if (empty()) throw QueueEmpty("Front of empty queue");

    E e1, e2;
    while (!S1.empty()) {
    	e1 = S1.top(); S2.push(e1); S1.pop();
    }
    e1 = S2.top();
    while (!S2.empty())	{
    	e2 = S2.top(); S1.push(e2); S2.pop();
    }

    return e1;
}

template <typename E>							// add an element into the queue
void Queuewith2Stk<E>::enqueue(const E& e) throw(QueueFull) {
    if (size() == capacity) throw QueueFull("Enqueue to full Queue");
    S1.push(e);
}

template <typename E>							// remove an element in the queue
void Queuewith2Stk<E>::dequeue() throw(QueueEmpty) {
    if (empty()) throw QueueEmpty("Dequeue from empty Queue");

    E e1, e2;
    while (!S1.empty()) {
    	e1 = S1.top(); S2.push(e1); S1.pop();
    }
    e1 = S2.top(); S2.pop();
    while (!S2.empty())	{
    	e2 = S2.top(); S1.push(e2); S2.pop();
    }
}

template <typename E>							// print the queue
void Queuewith2Stk<E>::print() {
	E e;

	cout << "QueueArray [ ";
	if (!this->empty()) {
	    while (!S1.empty()) {
	    	e = S1.top(); S2.push(e); S1.pop();
	    }
	    while (!S2.empty())	{
	    	cout << (e = S2.top()) << " ";
	    	S1.push(e); S2.pop();
	    }
	}
	cout << "]" << endl;
}

#endif /* QWITH2STK_H_ */
