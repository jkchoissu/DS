
#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>
#include "DequeException.h"
#include "LinkedDeque.h"

using namespace std;

typedef string Elem;				// element type
class DequeStack {					// stack as a deque
public:
    DequeStack();					// constructor
    int size() const;				// number of elements
    bool empty() const;				// is the stack empty?
    const Elem& top() const throw(StackEmpty);	// the top element
    void push(const Elem& e);			// push element onto stack
    void pop() throw(StackEmpty);		// pop the stack
    void display();
private:
    LinkedDeque D;					// deque of elements
};

DequeStack::DequeStack()			// constructor
    : D() { }
  									// number of elements
int DequeStack::size() const
    { return D.size(); }
  									// is the stack empty?
bool DequeStack::empty() const
    { return D.empty(); }
  									// the top element
const Elem& DequeStack::top() const throw(StackEmpty) {
    if (empty())
      throw StackEmpty("top of empty stack");
    return D.front();
}
  									// push element onto stack
void DequeStack::push(const Elem& e)
    { D.insertFront(e); }
  									// pop the stack
void DequeStack::pop() throw(StackEmpty)
{
    if (empty())
      throw StackEmpty("pop of empty stack");
    D.removeFront();
}

void DequeStack::display() {
	D.print();
}

#endif /* DEQUE_H_ */
