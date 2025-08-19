
#include <iostream>

using namespace std;

class Progression { 				// a generic progression
public:
	Progression(long f = 0) 		// constructor
	: first(f), cur(f) { }
	virtual ~Progression() { };		// destructor
	void printProgression(int n); 	// print the first n values
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

void Progression::printProgression(int n) { 		// print n values
	cout << firstValue(); 							// print the first
	for (int i = 2; i <= n; i++) 					// print 2 through n
		cout << ' ' << nextValue();
	cout << endl;
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

	return EXIT_SUCCESS; // successful execution
}
