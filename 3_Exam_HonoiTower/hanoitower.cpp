/*
 * hanoitower.cpp
 *
 *  Created on: 2025. 3. 16.
 *      Author: alber
 */

#include <iostream>
using namespace std;

// Function to solve the Towers of Hanoi puzzle
void towersOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) { // Base case: Move a single disk
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    // Step 1: Move top n-1 disks from source to auxiliary
    towersOfHanoi(n - 1, source, auxiliary, target);

    // Step 2: Move the nth disk from source to target
    cout << "Move disk " << n << " from " << source << " to " << target << endl;

    // Step 3: Move n-1 disks from auxiliary to target
    towersOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;
    // Solve the Towers of Hanoi puzzle
    towersOfHanoi(n, 'a', 'c', 'b'); // Source peg: a, Target peg: c, Auxiliary peg: b
    return 0;
}



