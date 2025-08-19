/*
 * MultipleRecursion.cpp
 *
 *  Created on: 2025. 3. 11.
 *      Author: albert
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::cout;
using std::string;
using std::unordered_set;

int letterToDigit[256]; // Array to map letters to digits
unordered_set<int> usedDigits; // Keeps track of digits already assigned

int wordToNum(const string &str)
{
    int result = 0;
    for (char ch : str) {
        result = result * 10 + letterToDigit[ch];
    }
    return result;
}

bool checkSum(const string &addend1, const string &addend2, const string &sum)
{
    int a1 = wordToNum(addend1);
    int a2 = wordToNum(addend2);
    int s = wordToNum(sum);
    return a1 + a2 == s;
}

bool solveRecursively(const string &letters, const string &addend1, const string &addend2, const string &sum, size_t index, int& counter)
{
    if (index == letters.size()) {
        // All letters have been assigned digits, check the equation
        return checkSum(addend1, addend2, sum);
    }

    char currentLetter = letters[index];
    for (int digit = 0; digit <= 9; ++digit) {
        if (usedDigits.find(digit) == usedDigits.end()) { // If the digit is not already used
            letterToDigit[currentLetter] = digit;
            usedDigits.insert(digit);

            if (solveRecursively(letters, addend1, addend2, sum, index + 1, counter)) {
            	cout << wordToNum(addend1) << " + " << wordToNum(addend2) << " = " << wordToNum(sum) << '\n';
            	counter++;
//                return true; // Solution found
            }

            // Backtrack
            usedDigits.erase(digit);
        }
    }
    return false; // No valid digit found for this letter
}

int main()
{
    string lettersInPuzzle = "dogcatpi"; // All unique letters in the puzzle
    string addend1 = "dog";
    string addend2 = "cat";
    string sum = "pig";
    int counter = 0;

    solveRecursively(lettersInPuzzle, addend1, addend2, sum, 0, counter);
//    if (solveRecursively(lettersInPuzzle, addend1, addend2, sum, 0)) {
//        cout << wordToNum(addend1) << " + " << wordToNum(addend2) << " = " << wordToNum(sum) << '\n';
//        return 0; // Success
//    }

//    cout << "No solution found\n";
      cout << counter << " Solutions are found !" << '\n';

    return 1; // Failure
}


