/*
 * puzzlesolve.cpp
 *
 *  Created on: 2025. 3. 16.
 *      Author: alber
 */


#include <iostream>
#include <vector>
#include <set>

void PuzzleSolve(int k, std::vector<char>& S, std::set<char>& U) {
    // Loop through each element in U
    for (auto it = U.begin(); it != U.end();) {
        char e = *it;          // Select an element
        it = U.erase(it);      // Remove e from U
        S.push_back(e);        // Add e to the sequence S

        std::cout << "Configuration (T): " << k << " " << e << " ";
        for (char elem : S) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
        for (char elem : U) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        if (k == 1) {
            // If a full sequence is created, print the solution
            std::cout << "Configuration: " << k << " " << e << " ";
            for (char elem : S) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
            for (char elem : U) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } else {
            // Recursive call to build the next part of the sequence
            PuzzleSolve(k - 1, S, U);
        }

        // Backtrack: undo the changes to S and U
        U.insert(e);
        S.pop_back();
        std::cout << "Configuration (B): " << k << " " << e << " ";
        for (char elem : S) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
        for (char elem : U) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int k = 3; // Length of the configurations
    std::vector<char> S; // Sequence being generated
    std::set<char> U = {'a', 'b', 'c'}; // Elements available for use

    PuzzleSolve(k, S, U);

    return 0;
}


