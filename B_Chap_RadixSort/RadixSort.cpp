/*
 * RadixSort.cpp
 *
 *  Created on: 2025. 5. 15.
 *      Author: USER
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform counting sort based on the specified digit index
void countingSort(vector<pair<int, int>>& S, int digitIndex) {
    const int RANGE = 10; // Assuming keys are in the range [0,9] for simplicity
    vector<vector<pair<int, int>>> buckets(RANGE);

    // Place entries into buckets based on the current digit
    for (const auto& e : S) {
        int key = (digitIndex == 0) ? e.second : e.first; // Select sorting digit
        buckets[key].push_back(e);
    }

    // Collect sorted values back into S
    S.clear();
    for (const auto& bucket : buckets) {
        for (const auto& entry : bucket) {
            S.push_back(entry);
        }
    }

    cout << "[processing...]";
    for (const auto& e : S) {
        cout << "(" << e.first << "," << e.second << ") ";
    }
    cout << endl;
}

// Radix Sort function
void radixSort(vector<pair<int, int>>& S) {
    // First sort by the second value (least significant key)
    countingSort(S, 0);

    // Then sort by the first value (most significant key)
    countingSort(S, 1);
}

int main() {
    vector<pair<int, int>> S = {{3,3}, {1,5}, {2,5}, {1,2}, {2,3}, {1,7}, {3,2}, {2,2}};

    cout << "Original Sequence:\n";
    for (const auto& e : S) {
        cout << "(" << e.first << "," << e.second << ") ";
    }
    cout << endl;

    radixSort(S);

    cout << "Sorted Sequence:\n";
    for (const auto& e : S) {
        cout << "(" << e.first << "," << e.second << ") ";
    }
    cout << endl;

    return 0;
}


