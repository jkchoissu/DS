
#include <iostream>
#include <vector>
#include "MergeSort.h"

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

int main() {

	vector<int>	L = {85, 24, 63, 45, 17, 31, 96, 50};
	Compare 	c;

	mergeSort(L, c);

	return EXIT_SUCCESS;
}



