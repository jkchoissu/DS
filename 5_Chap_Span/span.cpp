
#include <iostream>
#include <vector>
//#include <stack>
#include "StackException.h"
#include "ArrayStack.h"
using namespace std;

// Function to calculate spans using Quadratic Algorithm
vector<int> spans1(const vector<int>& X) {
    int n = X.size(); 		// Size of the array
    vector<int> S(n); 		// Array to store the spans

    for (int i = 0; i < n; ++i) {
        int s = 1; 			// Initial span value
        while (s <= i && X[i - s] <= X[i]) {
            s++; 			// Increase span if preceding elements are less or equal
        }
        S[i] = s; 			// Store the span for the current element
    }

    return S; 				// Return the span array
}

// Function to calculate spans using the Linear Algorithm with stack
vector<int> spans2(const vector<int>& X) {
    int n = X.size(); 		// Size of the array
    vector<int> S(n); 		// Array to store spans
    ArrayStack<int> A; 		// Stack to store indices

    for (int i = 0; i < n; ++i) {
        // Pop indices from the stack where X[A.top()] <= X[i]
        while (!A.empty() && X[A.top()] <= X[i]) {
        	A.pop();
        }

        // Calculate the span based on the stack's state
        if (A.empty()) {
            S[i] = i + 1; 		// Entire range up to the current element
        } else {
            S[i] = i - A.top(); // Distance from the nearest greater element
        }

        // Push the current index onto the stack
        A.push(i);
    }

    return S; // Return the span array
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> X(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> X[i];
    }

    // Calculate spans using spans1
    vector<int> S1 = spans1(X);

    // Display spans
    cout << "Spans1 of the array: ";
    for (int i = 0; i < n; ++i) {
        cout << S1[i] << " ";
    }
    cout << endl;

    // Calculate spans using spans2
    vector<int> S2 = spans2(X);

    // Display spans
    cout << "Spans2 of the array: ";
    for (int i = 0; i < n; ++i) {
        cout << S2[i] << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}



