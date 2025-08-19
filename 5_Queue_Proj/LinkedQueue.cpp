
#include <iostream>
#include "QueueException.h"
#include "LinkedQueue.h"

using namespace std;

LinkedQueue::LinkedQueue()				// constructor
    : C(), n(0) { }

int LinkedQueue::size() const			// number of items in the queue
    { return n; }

bool LinkedQueue::empty() const			// is the queue empty?
    { return n == 0; }
						// get the front element
const Elem& LinkedQueue::front() const throw(QueueEmpty) {
    if (empty())
      throw QueueEmpty("front of empty queue");
    return C.front();					// list front is queue front
}

void LinkedQueue::enqueue(const Elem& e) {
    C.add(e);							// insert after cursor
    C.advance();						// ...and advance
    n++;
}
  										// dequeue element at front
void LinkedQueue::dequeue() throw(QueueEmpty) {
    if (empty())
      throw QueueEmpty("dequeue of empty queue");
    C.remove();							// remove from list front
    n--;
}

void LinkedQueue::display() throw(QueueEmpty) {
	if (empty())
			throw QueueEmpty("dequeue of empty queue");
	else 	C.display();
}
