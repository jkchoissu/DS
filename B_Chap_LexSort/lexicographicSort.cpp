
#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform lexicographic sorting
void lexicographicSort(std::vector<std::vector<int>>& S, int d) {
    // Sorting by each column from d-th to the first in a stable manner
    for (int i = d - 1; i >= 0; --i) {
        std::stable_sort(S.begin(), S.end(), [i](const std::vector<int>& a, const std::vector<int>& b) {
            return a[i] < b[i];
        });
    }
}

int main() {
    // Example input: list of d-tuples
    std::vector<std::vector<int>> S = {
    	{7, 4, 6},
		{5, 1, 5},
		{2, 4, 6},
		{2, 1, 4},
		{3, 2, 4}
    };

    int d = S[0].size(); // Get dimension of tuples

    // Inut sequence
    std::cout << "Original sequence:\n";
    for (const auto& tuple : S) {
    	std::cout << "(";
        for (size_t i = 0; i < tuple.size(); i++) {
            std::cout << tuple[i];
            if ( i != (tuple.size()-1))	std::cout << ",";
        }
        std::cout << ") ";
    }
    std::cout << std::endl;

    lexicographicSort(S, d);

    // Output sorted sequence
    std::cout << "Sorted sequence:\n";
    for (const auto& tuple : S) {
    	std::cout << "(";
        for (size_t i = 0; i < tuple.size(); i++) {
            std::cout << tuple[i];
            if ( i != (tuple.size()-1))	std::cout << ",";
        }
        std::cout << ") ";
    }
    std::cout << std::endl;
    return 0;
}


