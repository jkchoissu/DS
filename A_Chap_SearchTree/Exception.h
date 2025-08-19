
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>

using namespace std;

class RuntimeException {
private :
	string errorMsg;
public :
	RuntimeException(const string& err) {errorMsg = err;}
	string getMessage() const { return errorMsg; }
};

// Exception thrown NonexistentElement.
class NonexistentElement : public RuntimeException {
public:
	NonexistentElement(const string& err) : RuntimeException(err) {}
};

// Exception thrown BoundaryViolation.
class BoundaryViolation : public RuntimeException {
public:
	BoundaryViolation(const string& err) : RuntimeException(err) {}
};

#endif /* EXCEPTION_H_ */
