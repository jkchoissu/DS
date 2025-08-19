
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// 2.3 Templates

template <typename T>
T genericMin(T a, T b) {
	return (a < b ? a : b);
}

template <typename T>
class BasicVector {					// a simple vector class
public :
	BasicVector(int capac = 10);	// constructor
	T& operator[](int i)			// access element at index i
	{return a[i];}
	//...other public members omitted
private :
	T* a;							// array storing the elements
	int capacity;					// length of array a
};

template <typename T>				// constructor
BasicVector<T>::BasicVector(int capac) {
	capacity = capac;
	a = new T[capac];				// allocate array storage
}

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

int main() {

	cout << genericMin(3,4) << ' '
		<< genericMin(1.1, 3.1) << ' '
		<< genericMin('t', 'g') << endl;


	BasicVector<int>	iv(5);		// vector of 5 integers
	BasicVector<double>	dv(20);		// vector of 20 doubles
	BasicVector<string>	sv(10);		// vector of 10 strings

	iv[3] = 8;
	dv[14] = 2.5;
	sv[7] = "hello";

	cout << iv[3] << " " << dv[14] << " " << sv[7] << endl;

	BasicVector<BasicVector<int> > xv(5);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 10; j++)
			xv[i][j] = i*10 + (j+1);

	cout << "Vector of vectors : " << endl;;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++)
			cout << xv[i][j] << " ";
		cout << endl;
	}
	cout << endl;

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

	return EXIT_SUCCESS;
}


