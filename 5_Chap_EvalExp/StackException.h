/*
 * StackException.h
 *
 *  Created on: 2025. 2. 25.
 *      Author: USER
 */

#ifndef STACKEXCEPTION_H_
#define STACKEXCEPTION_H_

#include <iostream>

using namespace std;

class RuntimeException {
private :
	string errorMsg;
public :
	RuntimeException(const string& err) {errorMsg = err;}
	string getMessage() const { return errorMsg; }
};

// Exception thrown on performing top or pop of an empty stack.
class StackEmpty : public RuntimeException {
public:
    StackEmpty(const string& err) : RuntimeException(err) {}
};

// Exception thrown on performing push of an full stack.
class StackFull : public RuntimeException {
public:
    StackFull(const string& err) : RuntimeException(err) {}
};

#endif /* STACKEXCEPTION_H_ */
