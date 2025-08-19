
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Progression { 				// a generic progression
public:
	Progression(long f = 0) 		// constructor
	: first(f), cur(f) { }
	virtual ~Progression() { };		// destructor
	void printProgression(int n); 	// print the first n values
	long getNthValue(int n); 		// print the nth value
protected:
	virtual long firstValue(); 		// reset
	virtual long nextValue(); 		// advance
protected:
	long first; 					// first value
	long cur; 						// current value
};

class ArithProgression : public Progression { 	// arithmetic progression
public:
	ArithProgression(long i = 1); 				// constructor
protected:
	virtual long nextValue(); 					// advance
protected:
	long inc; 									// increment
};

class GeomProgression : public Progression { 	// geometric progression
public:
	GeomProgression(long b = 2); 				// constructor
protected:
	virtual long nextValue(); 					// advance
protected:
	long base; 									// base value
};

class FibonacciProgression : public Progression {	// Fibonacci progression
public:
	FibonacciProgression(long f = 0, long s = 1); 	// constructor
protected:
	virtual long firstValue(); 						// reset
	virtual long nextValue(); 						// advance
protected:
	long second; 									// second value
	long prev; 										// previous value
};

class AbsValProgression : public Progression {		// Absolute Value Progression
public :											// ( difference between previous two numbers )
	AbsValProgression(long f = 1, long s = 100)		// constructor
	: Progression(f), second(s) {}
	virtual ~AbsValProgression() {}
protected :
	virtual long firstValue();						// reset
	virtual long nextValue();						// advance
protected :
	long second;									// second value
	long prev;										// previous value

};

class SquareRootProgression : public Progression {	// Sqaure Root Progression
public :
	SquareRootProgression(long f = 65536)			// constructor
	: Progression(f) {}
	virtual ~SquareRootProgression() {}
protected :
	virtual long nextValue();						// advance
};

void Progression::printProgression(int n) { 		// print n values
	cout << firstValue(); 							// print the first
	for (int i = 2; i <= n; i++) 					// print 2 through n
		cout << ' ' << nextValue();
	cout << endl;
}

long Progression::getNthValue(int n) { 				// retrieve nth value
	long f = firstValue();
	if (n == 1) return f;
	for (int i = 2; i < n; i++) 					// skip 1 through n-1
		nextValue();
	return nextValue();								// return nth value
}

long Progression::firstValue() { 					// reset
	cur = first;
	return cur;
}

long Progression::nextValue() {						// advance
	return ++cur;
}

ArithProgression::ArithProgression(long i) 			// constructor (Arithmetic Progression)
	: Progression(), inc(i) { }

long ArithProgression::nextValue() { 				// advance by adding
		cur += inc;
		return cur;
}

GeomProgression::GeomProgression(long b) 			// constructor (Geometric Progression)
	: Progression(1), base(b) { }

long GeomProgression::nextValue() { 				// advance by multiplying
		cur *= base;
		return cur;
}

FibonacciProgression::FibonacciProgression(long f, long s)
	: Progression(f), second(s), prev(second - first) { }

long FibonacciProgression::firstValue() { 				// reset
	cur = first;
	prev = second - first; 								// create fictitious prev
	return cur;
}

long FibonacciProgression::nextValue() { 				// advance
	long temp = prev;
	prev = cur;
	cur += temp;
	return cur;
}

long AbsValProgression::firstValue() { 				// reset
	cur = first;
	prev = first + second; 							// create prev
	return cur;
}

long AbsValProgression::nextValue() { 				// advance
	long temp = cur;
	if ( prev > cur )	cur = prev - cur;
	else				cur -= prev;
	prev = temp;
	return cur;
}

long SquareRootProgression::nextValue() {			// advance
	cur = sqrt(cur);
	return cur;
}

/** Test program for the progression classes */
int main() {

	Progression* prog;
								// test ArithProgression
	cout << "Arithmetic progression with default increment:\n";
	prog = new ArithProgression();
	prog->printProgression(10);
	cout << "Arithmetic progression with increment 5:\n";
	prog = new ArithProgression(5);
	prog->printProgression(10);
								// test GeomProgression
	cout << "Geometric progression with default base:\n";
	prog = new GeomProgression();
	prog->printProgression(10);
	cout << "Geometric progression with base 3:\n";
	prog = new GeomProgression(3);
	prog->printProgression(10);
							// test FibonacciProgression
	cout << "Fibonacci progression with default start values:\n";
	prog = new FibonacciProgression();
	prog->printProgression(10);
	cout << "Fibonacci progression with start values 4 and 6:\n";
	prog = new FibonacciProgression(4, 6);
	prog->printProgression(10);

	cout << "Fibonacci progression with start values 3 and 4:\n";
	prog = new FibonacciProgression(3, 4);
	prog->printProgression(7);
	cout << "7th value of Fibonacci progression : " << prog->getNthValue(7) << endl;

	Progression* p;
	p = new GeomProgression();
	cout << "The first value of pointer p : " << p->getNthValue(1) << endl;
	p->printProgression(10);

							// test AbsValProgression
	cout << "Absolute Value progression with default start values:\n";
	prog = new AbsValProgression();
	prog->printProgression(10);
	cout << "Absolute Value progression with start values 2 and 200:\n";
	prog = new AbsValProgression(2, 200);
	prog->printProgression(10);

	try {
							// test SqaureRoot Progression
	cout << "SqaureRoot progression with default start values:\n";
	prog = new SquareRootProgression();
	prog->printProgression(10);
	cout << "SqaureRoot progression with start value 65536:\n";
	prog = new SquareRootProgression(10000);
	prog->printProgression(10);
	}
	catch (const exception &e){
		cerr << "Error: " << e.what() << endl;
	}

	return EXIT_SUCCESS; // successful execution
}
