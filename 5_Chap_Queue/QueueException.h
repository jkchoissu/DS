
#ifndef QUEUEEXCEPTION_H_
#define QUEUEEXCEPTION_H_

#include <iostream>

using namespace std;

class RuntimeException {
private :
	string errorMsg;
public :
	RuntimeException(const string& err) {errorMsg = err;}
	string getMessage() const { return errorMsg; }
};

// Exception thrown on performing top or pop of an empty queue.
class QueueEmpty : public RuntimeException {
public:
    QueueEmpty(const string& err) : RuntimeException(err) {}
};

// Exception thrown on performing push of an full queue.
class QueueFull : public RuntimeException {
public:
    QueueFull(const string& err) : RuntimeException(err) {}
};



#endif /* QUEUEEXCEPTION_H_ */
