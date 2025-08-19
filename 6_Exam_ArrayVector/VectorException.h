
#ifndef VECTOREXCEPTION_H_
#define VECTOREXCEPTION_H_

#include <iostream>

using namespace std;

class RuntimeException {
private :
	string errorMsg;
public :
	RuntimeException(const string& err) {errorMsg = err;}
	string getMessage() const { return errorMsg; }
};

// Exception thrown IndexOutOfBounds.
class IndexOutOfBounds : public RuntimeException {
public:
    IndexOutOfBounds(const string& err) : RuntimeException(err) {}
};

#endif /* VECTOREXCEPTION_H_ */
