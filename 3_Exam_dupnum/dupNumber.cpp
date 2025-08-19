/*
 * dupNumber.cpp
 *
 *  Created on: 2025. 3. 23.
 *      Author: alber
 */

#include <iostream>
#include <vector>

using namespace std;

int findDuplicateUsingSum(const vector<int>& A) { // Summation Method
    int n = A.size();
    int expectedSum = (n - 1) * n / 2; // Sum of integers from 1 to n-1
    int actualSum = 0;

    for (int num : A) {
        actualSum += num;
    }

    return actualSum - expectedSum; // The repeated number
}
									// Cycle Detection (Tortoise and hare algorithm)
int findDuplicateUsingCycleDetection(const vector<int>& A) {
    int tortoise = A[0];
    int hare = A[0];

    // Phase 1: Find intersection point in the cycle
    do {
        tortoise = A[tortoise];
        hare = A[A[hare]];
    } while (tortoise != hare);

    // Phase 2: Find the entrance to the cycle
    tortoise = A[0];
    while (tortoise != hare) {
        tortoise = A[tortoise];
        hare = A[hare];
    }

    return hare; // The repeated number
}

int main() {
    vector<int> A = {1, 3, 2, 4, 2};
    cout << "Repeated Number: " << findDuplicateUsingSum(A) << endl;

    vector<int> B = {3, 1, 3, 4, 2};
    cout << "Repeated Number: " << findDuplicateUsingCycleDetection(B) << endl;

    return EXIT_SUCCESS;

}


