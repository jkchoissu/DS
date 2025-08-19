/*
 * LinkedQueue.h
 *
 *  Created on: 2025. 2. 25.
 *      Author: USER
 */

#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_

#include <iostream>
#include <string>
#include "QueueException.h"
#include "CircleList.h"

using namespace std;

typedef string Elem;					// queue element type
class LinkedQueue {						// queue as doubly linked list
public:
    LinkedQueue();						// constructor
    int size() const;					// number of items in the queue
    bool empty() const;					// is the queue empty?
    const Elem& front() const throw(QueueEmpty); // the front element
    void enqueue(const Elem& e);		// enqueue element at rear
    void dequeue() throw(QueueEmpty);	// dequeue element at front
    void display() throw(QueueEmpty);
private:					// member data
    CircleList C;			// circular list of elements
    int n;					// number of elements
};

#endif /* LINKEDQUEUE_H_ */
