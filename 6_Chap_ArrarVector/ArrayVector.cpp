
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

int main() {

	 ArrayVector v;

	 v.insert(0, 7); v.display();
	 v.insert(0, 4); v.display();
	 cout << v.at(1) << endl;
	 v.insert(2,2);  v.display();
	 try {
		 v.at(3);
	 } catch (IndexOutOfBounds& e) {
		 cout << "Exception catch : " << e.getMessage() << endl;
	 }
//	 cout << v.at(3) << endl;
	 v.erase(1);     v.display();
	 v.insert(1,5);  v.display();
	 v.insert(1,3);  v.display();
	 v.insert(4,9);  v.display();
	 cout << v.at(2) << endl;
	 v.set(3,8);     v.display();

	 return EXIT_SUCCESS;
}
