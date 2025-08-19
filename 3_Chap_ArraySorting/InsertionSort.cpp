
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void display(T* A, int n);

template <typename T>
void insertionSort(T* A, int n) { 			// sort an array of n elements
    for (int i = 1; i < n; i++) {			// insertion loop
      T cur = A[i];							// current character to insert
      int j = i - 1;						// start at previous character
      while ((j >= 0) && (A[j] > cur)) {	// while A[j] is out of order
    	  A[j + 1] = A[j];					// move A[j] right
    	  j--;								// decrement j
      }
      A[j + 1] = cur;						// this is the proper place for cur
      display(A,n);
    }
}

template <typename T>
void display(T* A, int n) {				// display an array of n elements
	cout << " Array : ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main() {

	char arr1[] = {'B','C','D','A','E','H','G','F'};	// character array
	int arr2[] = { 8, 2, 5, 1, 4};						// integer array
	int arr3[] = { 8, 7, 4, 5, 3, 1};						// integer array

	display(arr1,8);							// before sorting the array
	insertionSort(arr1,8);
	display(arr1,8);							// after sorting the array

	display(arr2,5);							// before sorting the array
	insertionSort(arr2,5);
	display(arr2,5);							// after sorting the array

	display(arr3,6);							// before sorting the array
	insertionSort(arr3,6);
	display(arr3,6);							// after sorting the array

	return EXIT_SUCCESS;
}
