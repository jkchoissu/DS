/*
 * ListMergeSort.cpp
 *
 *  Created on: 2025. 5. 15.
 *      Author: alber
 */

#include <iostream>
#include <list>
#include "MergeSort.h"

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

int main() {

	list<int>	L = {85, 24, 63, 45, 17, 31, 96, 50};
	Compare 	c;

	mergeSort(L, c);

	return EXIT_SUCCESS;
}


