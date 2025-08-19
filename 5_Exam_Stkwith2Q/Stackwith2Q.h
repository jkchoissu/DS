
#ifndef STACKWITH2Q_H_
#define STACKWITH2Q_H_

#include "ArrayQueue.h"

template <typename E>
//typedef int Elem;					// element type
class Stackwith2Q {					// stack using 2 Queues
public:
    Stackwith2Q();					// constructor
    int size() const;				// number of elements
    bool empty() const;				// is the stack empty?
    const E top() throw(StackEmpty);	// the top element
    void push(const E& e);			// push element onto stack
    void pop() throw(StackEmpty);	// pop the stack
    void print();
private:
    ArrayQueue<E> Q1;				// Array Queue 1 of elements
    ArrayQueue<E> Q2;				// Array Queue 2 of elements
};

template <typename E>
Stackwith2Q<E>::Stackwith2Q()		// constructor
    : Q1(), Q2() { }
template <typename E>
int Stackwith2Q<E>::size() const	// number of elements
    { return Q1.size(); }

template <typename E>
bool Stackwith2Q<E>::empty() const	// is the stack empty?
    { return Q1.empty(); }

template <typename E>
const E Stackwith2Q<E>::top() throw(StackEmpty) {	// the top element
	E e;
    if (empty())
      throw StackEmpty("top of empty stack");
   	e = Q1.front();
    return e;
}

template <typename E>
void Stackwith2Q<E>::push(const E& e) {			// push element onto stack
	Q2.enqueue(e);
	while (!Q1.empty()) {
		Q2.enqueue(Q1.front());
		Q1.dequeue();
	}
	while (!Q2.empty()) {
		Q1.enqueue(Q2.front());
		Q2.dequeue();
	}
}

template <typename E>
void Stackwith2Q<E>::pop() throw(StackEmpty)	// pop the stack
{
    if (empty())
    	throw StackEmpty("pop of empty stack");
    Q1.dequeue();
}

template <typename E>
void Stackwith2Q<E>::print()
{
	cout << "StackArray [Top][ ";
	for (int i=0; i<this->size(); i++) {
			E e = Q1.front();
			cout << e << " ";
			Q1.dequeue();
			Q1.enqueue(e);
	}
	cout << "][Bottom]" << endl;
}

#endif /* STACKWITH2Q_H_ */
