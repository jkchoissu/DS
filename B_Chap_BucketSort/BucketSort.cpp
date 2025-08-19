#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Function to perform bucket sort
void bucketSort(list<pair<int, char>>& S, int N) {
    vector<list<pair<int, char>>> B(N); // Array of N empty sequences (buckets)

    // Distribute entries into buckets
    while (!S.empty()) {
        pair<int, char> entry = S.front();
        S.pop_front();
        B[entry.first].push_back(entry);
    }

    // Gather sorted entries back into S
    for (int i = 0; i < N; ++i) {
        while (!B[i].empty()) {
            pair<int, char> entry = B[i].front();
            B[i].pop_front();
            S.push_back(entry);
        }
    }
}

int main() {
    list<pair<int, char>> S = {{7, 'd'}, {1, 'c'}, {3, 'a'}, {7, 'g'}, {3, 'b'}, {7, 'b'}};
    int N = 8; // Maximum key value + 1

    cout << "Original Sequence:\n";
    for (const auto& e : S) {
        cout << "(" << e.first << "," << e.second << ") ";
    }
    cout << endl;

    bucketSort(S, N);

    cout << "Sorted Sequence:\n";
    for (const auto& e : S) {
        cout << "(" << e.first << "," << e.second << ") ";
    }
    cout << endl;

    return 0;
}


