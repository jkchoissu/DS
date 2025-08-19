
#include <iostream>
#include <list>
#include "Merge.h"

// Test function to print list elements
template <typename E>
void printList(const std::list<E>& lst, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Initialize test lists
	typedef std::list<int> List;
	List A = {1, 2, 3, 4, 5};
	List B = {3, 4, 5, 6, 7};
	List C;

    // Union test
    UnionMerge<int> unionMerge;
    unionMerge.merge(A, B, C);
    printList(C, "Union");

    // Intersection test
    C.clear();
    IntersectMerge<int> intersectMerge;
    intersectMerge.merge(A, B, C);
    printList(C, "Intersection");

    // Subtraction test
    C.clear();
    SubtractMerge<int> subtractMerge;
    subtractMerge.merge(A, B, C);
    printList(C, "Subtraction");

    return 0;
}


