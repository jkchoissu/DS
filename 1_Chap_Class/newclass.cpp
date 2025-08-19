
#include <iostream>

using namespace std;

class Vect { 			// a vector class
public:
	Vect();				// default constructor
	Vect(int n);		// constructor, given size
	Vect(const Vect& v);							// copy constructor   --- added
	~Vect(); 			// destructor
	// . . . other public members omitted
	int operator[](int i) const { return data[i]; }	//
	Vect& operator=(const Vect& v);					// assignment(=) operator overloading --- added
	void setValue(int pos, int value) const;		// modify the value of "pos" position --- added
	int getSize() const { return size; }			// read the number of arrary entries --- added
private:
	int* data; 			// an array holding the vector
	int size; 			// number of array entries
};

Vect::Vect() {			// default constructor (size 10)   --- added
	size = 10;
	data = new int[size];
}

Vect::Vect(int n) { 	// constructor
	size = n;
	data = new int[n]; 	// allocate array
}

Vect::~Vect() { 		// destructor
	delete [ ] data; 	// free the allocated array
}


Vect::Vect(const Vect& a) { 			// copy constructor from a
	size = a.size; 						// copy sizes
	data = new int[size];			 	// allocate new array
	for (int i = 0; i < size; i++) { 	// copy the vector contents
		data[i] = a.data[i];
	}
}

Vect& Vect::operator=(const Vect& a) { 	// assignment operator from a
	if (this != &a) { 					// avoid self-assignment
		delete [ ] data; 				// delete old array
		size = a.size; 					// set new size
		data = new int[size]; 			// allocate new array
		for (int i=0; i < size; i++) { 	// copy the vector contents
			data[i] = a.data[i];
		}
	}
	return *this;
}


void Vect::setValue(int pos, int value) const { // modify function
	data[pos] = value;
}

main() {

	Vect a(100); 	// a is a vector of size 100

	for (int i = 0; i < 100; i++)
		a.setValue(i, i);

	Vect b = a;  	// initialize b from a (DANGER!)
//	Vect b(a);		// same as "b = a"
	Vect c; 		// c is a vector (default size 10)
	c = a; 			// assign a to c (DANGER!)

	cout << " size of a : " << a.getSize() << endl;
	cout << " size of b : " << b.getSize() << endl;
	cout << " size of c : " << c.getSize() << endl;

	for (int i = 0; i < 100; i++)
		a.setValue(i, i+100);

	cout << "vector b[5] : " << b[5] << endl;
	cout << "vector c[9] : " << c[9] << endl;

	return EXIT_SUCCESS;
}


