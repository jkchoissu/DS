
#include <iostream>
#include "HeapPQ.h"

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

void HeapPQ_example() {
    HeapPriorityQueue<int, Compare> pq;
    pq.insert(5);
    pq.insert(9);
    pq.insert(2);
    pq.insert(7);

    std::cout << "Minimum: " << pq.min() << std::endl;

    std::cout << "Minimum after removal: " << pq.min() << std::endl;
    pq.removeMin();

    std::cout << "size of PQ: " << pq.size() << std::endl;
    std::cout << "Minimum: " << pq.min() << std::endl;

    std::cout << "Minimum after removal: " << pq.min() << std::endl;
    pq.removeMin();

    std::cout << "Minimum after removal: " << pq.min() << std::endl;
    pq.removeMin();

    std::cout << "Minimum after removal: " << pq.min() << std::endl;
    pq.removeMin();

    std::cout << "Empty: " << ( pq.empty() ? "true" : "false") << std::endl;
}

int main() {

	HeapPQ_example();

	return EXIT_SUCCESS;
}


