
#include <iostream>
#include "VectorException.h"
#include "ArrayVector.h"

using namespace std;

ArrayVector::ArrayVector()				// constructor
    : capacity(0), n(0), A(NULL) { }

int ArrayVector::size() const			// number of elements
    { return n; }

bool ArrayVector::empty() const			// is vector empty?
    { return size() == 0; }

Elem& ArrayVector::operator[](int i)	// element at index
    { return A[i]; }
  										// element at index (safe)
Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) {
    if (i < 0 || i >= n)
      throw IndexOutOfBounds("illegal index in function at()");
    return A[i];
}

void ArrayVector::reserve(int N) {		// reserve at least N spots
    if (capacity >= N) return;			// already big enough
    Elem* B = new Elem[N];				// allocate bigger array
    for (int j = 0; j < n; j++)			// copy contents to new array
      B[j] = A[j];
    if (A != NULL) delete [] A;			// discard old array
    A = B;								// make B the new array
    capacity = N;						// set new capacity
}

void ArrayVector::insert(int i, const Elem& e) {
    if (n >= capacity) {				// overflow?
        cout << "increased by double (" << n << ") : " << capacity << " -> " << 2*capacity << endl;
    	reserve(max(1, 2 * capacity));	// double array size
    }
    for (int j = n - 1; j >= i; j--)	// shift elements up
      A[j+1] = A[j];
    A[i] = e;							// put in empty slot
    n++;								// one more element
}

void ArrayVector::set(int i, const Elem& e) throw(IndexOutOfBounds) {
	if (i < 0 || i >= n)
	      throw IndexOutOfBounds("illegal index in function at()");
    A[i] = e;							// put in empty slot

}

void ArrayVector::erase(int i) {		// remove element at index
    for (int j = i+1; j < n; j++)		// shift elements down
      A[j - 1] = A[j];
    n--;								// one fewer element
}

void ArrayVector::display() const {
	  cout << "Array Vector : ";
	  for (int i = 0; i < n; i++)
		  cout << A[i] << " ";
	  cout << endl;
}

void Vector_Exam_R_6_4() {

//	R-6.4 Draw a representation of an initially empty vector A
//	after performing the following sequence of operations:
//	insert(0,4), insert(0,3), insert(0,2), insert(2,1), insert(1,5),
//	insert(1,6), insert(3,7), insert(0,8).

	ArrayVector A;

	A.insert(0,4);	A.display();
	A.insert(0,3);	A.display();
	A.insert(0,2);	A.display();
	A.insert(2,1);	A.display();
	A.insert(1,5);	A.display();
	A.insert(1,6);	A.display();
	A.insert(3,7);	A.display();
	A.insert(0,8);	A.display();

}

int main() {

	Vector_Exam_R_6_4();

	return EXIT_SUCCESS;
}
