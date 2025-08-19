
#include <iostream>
#include <vector>
#include "QuickSort.h"

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

int main() {

	list<int>	S1 = {85, 24, 63, 45, 17, 31, 96, 50};
	QuickSort(S1);

	vector<int>	S2 = {85, 24, 63, 45, 17, 31, 96, 50};
	Compare 	c;
	quickSort(S2, c);

	return EXIT_SUCCESS;
}





