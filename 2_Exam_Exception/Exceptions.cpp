
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// 2.4 Exceptions

class MathException { 						// generic math exception
public:
	MathException(const string& err) 		// constructor
		: errMsg(err) { }
	string getError() { return errMsg; } 	// access error message
private:
	string errMsg; 							// error message
};

class ZeroDivide : public MathException {
public:
	ZeroDivide(const string& err) 			// divide by zero
		: MathException(err) { }
};

class NegativeRoot : public MathException {
public:
	NegativeRoot(const string& err) 		// negative square root
		: MathException(err) { }
};

class ArrayIndexBounds {					// out of bounds exception
public :
	ArrayIndexBounds(int index) : badIndexValue(index) {}
	int badIndex() const { return badIndexValue; }
private :
	int badIndexValue;
};

int main() {

	double result = 0.0;
	double dividend, divisor;

	cout << "Enter two numbers (dividend, divisor) : ";
	cin >> dividend >> divisor;
	result = dividend + divisor;
	cout << "Sum = " << result << endl;

	try {
		if ( divisor == 0 )		// attempt to divide by 0?
			throw ZeroDivide("Divide by Zero in main routine");
		result = dividend / divisor;
		cout << "Division result = " << result << endl;
	} catch (ZeroDivide &e) {	// handle division by zero
		cerr << "Exception caught : " << e.getError() << endl;
	} catch (...) {				// handle any math exception other than division by zero
		cerr << "Unknown exception error " << endl;
	}

	vector<int> array = {1, 2, 3, 4, 5};
	unsigned int i = 7;

	try {
		if ( i >= array.size()) throw ArrayIndexBounds(i);
		cout << array[i] << endl;
	} catch (ArrayIndexBounds& e) {
		cerr << "Array Index " << e.badIndex() << " is a out of bounds" << endl;
	}

	return EXIT_SUCCESS;
}


