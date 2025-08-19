/*
 * LinkedListStack.cpp
 *
 *  Created on: 2025. 2. 25.
 *      Author: USER
 */
#include <iostream>
#include "LinkedListStack.h"

using namespace std;


LinkedStack::LinkedStack()
    : S(), n(0) { }					// constructor

int LinkedStack::size() const
    { return n; }					// number of items in the stack

bool LinkedStack::empty() const
    { return n == 0; }				// is the stack empty?

									// get the top element
const Elem& LinkedStack::top() const throw(StackEmpty) {
    if (empty()) throw StackEmpty("Top of empty stack");
    return S.front();
}

void LinkedStack::push(const Elem& e) {	// push element onto stack
    ++n;
    S.addFront(e);
}
						// pop the stack
void LinkedStack::pop() throw(StackEmpty) {
    if (empty()) throw StackEmpty("Pop from empty stack");
    --n;
    S.removeFront();
}

void LinkedStack::print() const {
	S.display();
};

