/*
 * VectorSum.cpp
 *
 *  Created on: 2025. 4. 5.
 *      Author: albert
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// Using an iterator to sum the elements of an STL vector
template <typename E>
E vectorSum(vector<E>& V) {
  E sum = E();									// Initialize sum to the default value of the numeric type (e.g., 0)
  typename vector<E>::iterator Iterator;		// iterator type
  for (Iterator = V.begin(); Iterator != V.end(); ++Iterator)
    sum += *Iterator;
  return sum;
}

int main() {
    // Example usage with a vector of integers
    vector<int> intVector = {1, 2, 3, 4, 5};
    cout << "Sum of integers: " << vectorSum(intVector) << endl;

    // Example usage with a vector of doubles
    vector<double> doubleVector = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "Sum of doubles: " << vectorSum(doubleVector) << endl;

    return 0;
}


