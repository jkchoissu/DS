
#include <iostream>
#include "VectorException.h"
#include "ArrayVector.h"

using namespace std;

template <typename E>
ArrayVector<E>::Iterator::Iterator(int i, ArrayVector* vec)				// constructor
	: index(i), vec(vec) { }

template <typename E>
E& ArrayVector<E>::Iterator::operator*()								// reference to the element
	{	return vec->at(index); }

template <typename E>
bool ArrayVector<E>::Iterator::operator==(const Iterator& it) const		// equality test
	{	return index == it.index; }

template <typename E>
bool ArrayVector<E>::Iterator::operator!=(const Iterator& it) const		// inequality test
	{	return index != it.index; }

template <typename E>
typename ArrayVector<E>::Iterator& ArrayVector<E>::Iterator::operator++()		// move to next position
	{	++index; return *this; }

template <typename E>
typename ArrayVector<E>::Iterator& ArrayVector<E>::Iterator::operator--()		// move to previous position
	{   --index; return *this; }

template <typename E>
ArrayVector<E>::ArrayVector()					// default constructor
    : capacity(0), n(0), A(NULL) { }

template <typename E>
ArrayVector<E>::ArrayVector(ArrayVector& av)	// copy constructor
{
	capacity = av.capacity;						// copy the capacity
	n = av.n;									// copy the number of elements
	A = new E[capacity];						// allocate new array vector
	for (int i = 0; i < n; i++) {
		A[i] = av.A[i];							// copy the vector contents
	}
}

template <typename E>
ArrayVector<E>& ArrayVector<E>::operator=(const ArrayVector<E>& av)	// assignment constructor
{
	if (this != &av) {							// avoid self-assignment
		delete [] A;							// delete old array
		n = av.n;								// copy the number of elements
		A = new E[capacity];					// allocate new array vector
		for (int i = 0; i < n; i++) {
			A[i] = av.A[i];						// copy the vector contents
		}
	}
	return *this;								// return the current object
}


template <typename E>
ArrayVector<E>::~ArrayVector()					// destructor
	{ delete [] A; }

template <typename E>
int ArrayVector<E>::size() const				// number of elements
    { return n; }

template <typename E>
bool ArrayVector<E>::empty() const				// is vector empty?
    { return size() == 0; }

template <typename E>
E& ArrayVector<E>::operator[](int i)			// element at index
    { return A[i]; }

template <typename E>							// element at index (safe)
E& ArrayVector<E>::at(int i) throw(IndexOutOfBounds) {
    if (i < 0 || i >= n)
      throw IndexOutOfBounds("illegal index in function at()");
    return A[i];
}

template <typename E>
void ArrayVector<E>::reserve(int N) {	// reserve at least N spots
    if (capacity >= N) return;			// already big enough
    E* B = new E[N];					// allocate bigger array
    for (int j = 0; j < n; j++)			// copy contents to new array
      B[j] = A[j];
    if (A != NULL) delete [] A;			// discard old array
    A = B;								// make B the new array
    capacity = N;						// set new capacity
}

template <typename E>
void ArrayVector<E>::insert(int i, const E& e) {
    if (n >= capacity) {				// overflow?
        cout << "increased by double (" << n << ") : " << capacity << " -> " << 2*capacity << endl;
    	reserve(max(1, 2 * capacity));	// double array size
    }
    for (int j = n - 1; j >= i; j--)	// shift elements up
      A[j+1] = A[j];
    A[i] = e;							// put in empty slot
    n++;								// one more element
}

template <typename E>
void ArrayVector<E>::set(int i, const E& e) throw(IndexOutOfBounds) {
	if (i < 0 || i >= n)
	      throw IndexOutOfBounds("illegal index in function at()");
    A[i] = e;							// put in empty slot

}

template <typename E>
void ArrayVector<E>::erase(int i) {		// remove element at index
    for (int j = i+1; j < n; j++)		// shift elements down
      A[j - 1] = A[j];
    n--;								// one fewer element
}

template <typename E>
void ArrayVector<E>::insertFront(const E& e) {
	insert(0,e);
}

template <typename E>
void ArrayVector<E>::insertBack(const E& e) {
	insert(n,e);
}

template <typename E>
void ArrayVector<E>::removeFront() {
	erase(0);
}

template <typename E>
void ArrayVector<E>::removeBack() {
	erase(n-1);
}

template <typename E>
void ArrayVector<E>::display() const {
	  cout << "Array Vector : ";
	  for (int i = 0; i < n; i++)
		  cout << A[i] << " ";
	  cout << endl;
}

template <typename E>
typename ArrayVector<E>::Iterator ArrayVector<E>::begin()	// beginning position
	{	return Iterator(0, this); }

template <typename E>
typename ArrayVector<E>::Iterator ArrayVector<E>::end()		// (just beyond) last position
	{	return Iterator(n, this); }

template <typename E>
VectorStack<E>::VectorStack(ArrayVector<E>& av)
	: V(av) { }												// constructor from capacity

template <typename E>
int VectorStack<E>::size() const
    { return V.size(); }									// number of items in the stack

template <typename E>
bool VectorStack<E>::empty() const
    { return V.empty(); }									// is the stack empty?

template <typename E>										// return top of stack
const E& VectorStack<E>::top() const throw(StackEmpty) {
    if (V.empty()) throw StackEmpty("Top of empty stack");
    return V[V.size()-1];
}

template <typename E>										// push element onto the stack
void VectorStack<E>::push(const E& e) {
	V.insert(V.size(),e);
}

template <typename E>										// pop the stack
void VectorStack<E>::pop() throw(StackEmpty) {
	if (V.empty()) throw StackEmpty("Pop of empty stack");
    V.erase(V.size()-1);
}

template <typename E>										// print the stack
void VectorStack<E>::print() {
	cout << "StackArray [bottom][ ";
	for (int i=0; i<V.size(); i++) {
		cout << V[i] << " ";
	}
	cout << "][top]" << endl;
}

void Vector_Exam_R_6_4() {

//	R-6.4 Draw a representation of an initially empty vector A
//	after performing the following sequence of operations:
//	insert(0,4), insert(0,3), insert(0,2), insert(2,1), insert(1,5),
//	insert(1,6), insert(3,7), insert(0,8).

	ArrayVector<int> A;

	cout << " >>> Vector Exam. R-6.4 " << endl;
	A.insert(0,4);	A.display();
	A.insert(0,3);	A.display();
	A.insert(0,2);	A.display();
	A.insert(2,1);	A.display();
	A.insert(1,5);	A.display();
	A.insert(1,6);	A.display();
	A.insert(3,7);	A.display();
	A.insert(0,8);	A.display();

	cout << endl;

}

void Vector_Exam_R_6_5() {

//	 R-6.5 Give an adapter class to support the Stack interface
//	 using the functions of the vector ADT.
	 ArrayVector<int> v6;
	 VectorStack<int> S(v6);

	 cout << " >>> Vector Exam R-6.5 : Stack Implementation using ArrayVector " << endl;
	 S.push(1);
	 S.push(2);
	 S.push(3);
	 S.push(4);
	 S.push(5);
	 S.push(6);
	 S.print();

	 S.pop();
	 S.pop();
	 S.print();

	 S.push(7);
	 S.push(8);
	 S.print();

	 cout << endl;
}

void Make_ArrayVector(ArrayVector<int>& v) {

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
	cout << endl;
}

void Vector_Exam_R_6_6(ArrayVector<int>& v) {

//	 R-6.6 Provide the missing housekeeping functions
//	 (copy constructor, assignment operator, and destructor)
//	 for the class ArrayVector of Code Fragment 6.2.

	 cout << " >>> Vector Exam R-6.6 : Copy/Assignment Constructor ...." << endl;
	 cout << "Copy Constructor " << endl;
	 ArrayVector<int> v1(v);
	 v1.display();
	 v1.insert(1,10);
	 v1.insert(2,15);
	 v1.display();

	 cout << endl;
	 cout << "Assignment Constructor " << endl;
	 ArrayVector<int> v2 = v1;
	 v2.display();
	 v2.erase(1);
	 v2.display();

	 cout << endl;
	 ArrayVector<string> v3;
	 cout << "String Array Vector" << endl;
	 v3.insert(0, "Seoul"); v3.display();
	 v3.insert(0, "Busan"); v3.display();
	 cout << v.at(1) << endl;
	 v3.insert(2,"Incheon");  v3.display();
	 try {
		 v3.at(3);
	 } catch (IndexOutOfBounds& e) {
		 cout << "Exception catch : " << e.getMessage() << endl;
	 }
//	 cout << v.at(3) << endl;
	 v3.erase(1);     v3.display();
	 v3.insert(1,"Suwon");  v3.display();
	 v3.insert(1,"Daejeon");  v3.display();
	 v3.insert(4,"Daegu");  v3.display();
	 cout << v.at(2) << endl;
	 v3.set(3,"Kwangju");     v3.display();
	 cout << endl;

	 cout << "insertFront, insertBack" << endl;
	 ArrayVector<int> v4;
	 v4.insert(0,1);
	 v4.insert(1,2);
	 v4.insert(2,3);
	 v4.insertFront(10);
	 v4.insertBack(20);
	 v4.display();

	 cout << endl;
}

void Vector_Exam_R_6_20() {

//	 R-6.20 Describe how to implement an iterator
//	 for the class ArrayVector of Code Fragment 6.2,
//	 based on an integer index.
//	 Include pseudo-code fragments describing the dereferencing operator (“*”),
//	 equality test (“==”), and increment and decrement (“++” and “––”).

	 ArrayVector<int> v5;
	 v5.insert(0,1);
	 v5.insert(1,2);
	 v5.insert(2,3);
	 v5.insert(2,4);
	 v5.insert(2,5);
	 v5.insert(2,6);
	 v5.display();

	 cout << " >>> Vector Exam R-6.20 : Additional operations ( *, ==, ++, --) " << endl;
	 for (ArrayVector<int>::Iterator t = v5.begin(); t != v5.end(); ++t)
		 cout << *t << " ";
	 cout << endl;

	 ArrayVector<int>::Iterator t1 = v5.begin();
	 ArrayVector<int>::Iterator t2 = v5.end();
	 if ( t1 == t2)
		 	cout << "true" << endl;
	 else	cout << "false" << endl;
}

int main() {

	Vector_Exam_R_6_4();
	Vector_Exam_R_6_5();

	ArrayVector<int> v;
	Make_ArrayVector(v);
	Vector_Exam_R_6_6(v);

	Vector_Exam_R_6_20();

	return EXIT_SUCCESS;
}
