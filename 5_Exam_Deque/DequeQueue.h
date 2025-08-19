
#ifndef DEQUEQUEUE_H_
#define DEQUEQUEUE_H_

#include <iostream>
#include "DequeException.h"
#include "LinkedDeque.h"

using namespace std;

typedef int Elem;						// element type
class DequeQueue {						// queue as a deque
public:
    DequeQueue();						// constructor
    int size() const;					// number of elements
    bool empty() const;					// is the queue empty?
    const Elem& front() const throw(QueueEmpty);	// the first element
    const Elem& back() const throw(QueueEmpty);		// the last element
    void enqueue(const Elem& e);		// add an element onto queue
    void dequeue() throw(QueueEmpty);	// remove an element in the queue
    void display();
private:
    LinkedDeque D;						// deque of elements
};

DequeQueue::DequeQueue()				// constructor
    : D() { }
  										// number of elements
int DequeQueue::size() const
    { return D.size(); }
  										// is the queue empty?
bool DequeQueue::empty() const
    { return D.empty(); }
  										// the first element
const Elem& DequeQueue::front() const throw(QueueEmpty) {
    if (empty())
      throw QueueEmpty("front of empty queue");
    return D.front();
}
										// the last element
const Elem& DequeQueue::back() const throw(QueueEmpty) {
    if (empty())
      throw QueueEmpty("back of empty queue");
    return D.back();
}
  										// add an element onto queue
void DequeQueue::enqueue(const Elem& e)
    { D.insertBack(e); }
  										// remove the element in the queue
void DequeQueue::dequeue() throw(QueueEmpty)
{
    if (empty())
      throw QueueEmpty("dequeue of empty queue");
    D.removeFront();
}

void DequeQueue::display() {
	D.print();
}

#endif /* DEQUEQUEUE_H_ */
