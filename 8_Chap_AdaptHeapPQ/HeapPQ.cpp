
#include <iostream>
#include "VectorComplete.h"
#include "HeapPQ.h"

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

void HeapPQ_example() {
    HeapPriorityQueue<int, Compare> pq;
    VectorCompleteTree<int>::Position p;

    pq.insert(5); pq.display();
    pq.insert(9); pq.display();
    pq.insert(2); pq.display();
    p = pq.insert(7); pq.display();

    pq.replace(p,10); pq.display();

    cout << "Minimum: " << pq.min() << endl; pq.display();

    pq.removeMin();
    cout << "Minimum after removal: " << pq.min() << endl;
    pq.display();

    cout << "size of PQ: " << pq.size() << endl; pq.display();
    cout << "Minimum: " << pq.min() << endl; pq.display();

    pq.removeMin();
    cout << "Minimum after removal: " << pq.min() << endl;
    pq.display();

    pq.removeMin();
    cout << "Minimum after removal: " << pq.min() << endl;
    pq.display();

    pq.removeMin();
    cout << "Minimum after removal: " << pq.min() << endl;
    pq.display();

    cout << "Empty: " << ( pq.empty() ? "true" : "false") << endl; pq.display();
}

int main() {

	HeapPQ_example();

	return EXIT_SUCCESS;
}


