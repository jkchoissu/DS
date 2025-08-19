
#include <iostream>
#include <cmath>

using namespace std;

							// Factorial Function
int recursiveFactorial(int n) { 				// recursive factorial function
	if (n == 0) return 1; 						// basis case
	else return n * recursiveFactorial(n-1); 	// recursive case
}
							// Linear Summation Function
int LinearSum(int* A, int n) {					// recursive linear summation function

	if (n == 1)	{								// base case
		cout << "( " << n << "," << A[0] << " )" << endl;
		return A[0];
	}
	else {										// recursive case
		int result = LinearSum(A, n-1) + A[n-1];
		cout << "( " << n << "," << result << " )" << endl;
		return result;
	}
}

void swapArray(int* A, int i, int j) {				// swap A[i] and A]j]
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
							// Reverse Array Function using recursive call
void ReverseArray(int* A, int i, int j) {
	if (i < j)	{
		swapArray(A, i, j);
		ReverseArray(A, i+1, j-1);
	}
}
							// Reverse Array Function using no recursive call
void IterativeReverseArray(int* A, int i, int j) {
	while (i < j) {
		swapArray(A, i, j);
		i = i + 1;
		j = j - 1;
	}
}

void displayArray(int* A, int n) {
	cout << " Array : ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

							// Binary Summation Function
int BinarySum(int* A, int i, int n) {
	if (n == 1) {							// base case
		return A[i];
	}
	else {									// recursive case
		cout << "( " << i << "," << ceil(n/2) << " )" <<
				"( " << i+ceil(n/2) << "," << n-ceil(n/2) << " )" << endl;
		return BinarySum(A, i, ceil(n/2)) + BinarySum(A, i+ceil(n/2), n-ceil(n/2));
	}
}

							// Fibonacci number computing by binary recursion
int BinaryFib(int k) {
	if (k <= 1) {							// base case
		return k;
	}
	else {									// recursive case
		return BinaryFib(k-1) + BinaryFib(k-2);
	}
}

							// Fibonacci number computing by linear recursion
pair<int,int> LinearFibonacci(int k) {
	if (k <= 1) {							// base case
		return {k, 0};
	}
	else {									// recursive case
		pair<int, int> pFib = LinearFibonacci(k-1);
		return {pFib.first + pFib.second, pFib.first};
	}
}

int main() {

	int n = 0;
							// Factorial Recursion Test
	cout << ">>> Factorial Recursion Test " << endl;
	cout << "Enter a number : ";
	cin >> n;
	cout << n << "! = " << recursiveFactorial(n) << endl;

							// Linear Summation Recursion Test
	int arr1[] = {4, 3, 6, 2, 5};

	cout << ">>> LinearSum Recursion Test " << endl;
	cout << "Linear Sum = " << LinearSum(arr1,5) << endl;

							 // Reverse Array Recursion Test
	int arr2[20];

	cout << ">>> ReverseArray Recursion Test " << endl;
	for (int i = 0; i < 20; i++)
		arr2[i] = i + 1;

	displayArray(arr2, 20);
	ReverseArray(arr2, 0, 19);
	displayArray(arr2, 20);
							// Reverse Array Test using no recursion
	int arr3[20];

	cout << ">>> IterativeReverseArray (NOT use recursive call) Test " << endl;
	for (int i = 0; i < 20; i++)
		arr3[i] = i + 1;
	displayArray(arr3, 20);
	IterativeReverseArray(arr3, 0, 19);
	displayArray(arr3, 20);

							// BinarySum Test
	int arr4[] = {4, 3, 6, 2, 5};

	cout << ">>> BinarySum Recursion Test " << endl;
	cout << "Binary Sum = " << BinarySum(arr4,0,5) << endl;

							// Fibonacci Number Computing by Binary Recursion
	cout << ">>> BinaryFib Test " << endl;
	cout << "Enter a number : ";
	cin >> n;
	cout << n << "th Fibnacci number = " << BinaryFib(n) << endl;

							// Fibonacci Number Computing by Linear Recursion

	cout << ">>> LinearFibonacci Test " << endl;
	cout << "Enter a number : ";
	cin >> n;
	pair<int, int> fib = LinearFibonacci(n);
	cout << n << "th Fibnacci number = " << fib.first << endl;

	return EXIT_SUCCESS;
}



