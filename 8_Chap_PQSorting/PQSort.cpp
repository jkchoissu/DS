
#include <iostream>
#include <list>
#include "ListPQ.h"
#include "HeapPQ.h"

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};

template <typename T>
void Lprint(list<T>& L) {
    cout << "List L : ";
    for (int e : L) cout << e << " ";
    cout << endl;
}

void PQ_example_8_4() {

    ListPriorityQueue<int, Compare> Lpq;
    Lpq.insert(5); Lpq.display();
    Lpq.insert(9); Lpq.display();
    Lpq.insert(2); Lpq.display();
    Lpq.insert(7); Lpq.display();

    cout << "RemoveMin output : " << Lpq.min() << endl;
    Lpq.removeMin();
    Lpq.display();

    cout << "size of pq: " << Lpq.size() << endl; Lpq.display();

    cout << "RemoveMin output : " << Lpq.min() << endl;
    Lpq.removeMin();
    Lpq.display();

    Lpq.removeMin();
    Lpq.display();

    Lpq.removeMin();
    Lpq.display();

    cout << "Empty: " << ( Lpq.empty() ? "true" : "false") << endl; Lpq.display();
}

// Function to perform insertion-sort using a priority queue
template <typename T>
void PQ_insertionSort(list<T>& L) {
    // Define a min-heap using a priority queue
	ListPriorityQueue<int, Compare> P;

    Lprint<T>(L);
    P.display();

    // Step 1: Insert all elements from the list into the priority queue
    while (!L.empty()) {
        T e = L.front();   	// Get the first element
        L.pop_front();     	// Remove it from the list
        P.insert(e);        // Insert into the priority queue

        Lprint<T>(L);
        P.display();
    }
    cout << endl;
    // Step 2: Extract elements from the priority queue and insert them back into the list
    while (!P.empty()) {
        L.push_back(P.min()); 	// Get the smallest element and add it into the list
        P.removeMin();     		// Remove it from the queue

        Lprint<T>(L);
        P.display();
    }
}

// Function to perform selection-sort using a priority queue
template <typename T>
void PQ_selectionSort(list<T>& L) {
    // Define a min-heap using a priority queue
	ListPriorityQueue<int, Compare> P;

    Lprint<T>(L);
    P.display();

    // Step 1: Insert all elements into the priority queue
    while (!L.empty()) {
        T e = L.front();   		// Get the first element
        L.pop_front();     		// Remove it from the list
        P.insert_unsorted(e);   // Insert into the priority queue

        Lprint<T>(L);
        P.display();
    }
    cout << endl;
    // Step 2: Extract elements from the priority queue in sorted order and add them back to the list
    while (!P.empty()) {
        L.push_back(P.min_unsorted()); 	// Get the smallest element and add it into the list
        P.removeMin_unsorted();         // Remove it from the queue

        Lprint<T>(L);
        P.display();
    }
}

// Function to perform selection-sort using a priority queue
template <typename T>
void PQ_heapSort(list<T>& L) {
    // Define a min-heap using a priority queue
	HeapPriorityQueue<int, Compare> P;

    Lprint<T>(L);
    P.display();

    // Step 1: Insert all elements into the priority queue
    while (!L.empty()) {
        T e = L.front();   // Get the first element
        L.pop_front();     // Remove it from the list
        P.insert(e);       // Insert into the priority queue

        Lprint<T>(L);
        P.display();
    }
    cout << endl;
    // Step 2: Extract elements from the priority queue in sorted order and add them back to the list
    while (!P.empty()) {
        L.push_back(P.min()); 		// Get the smallest element and add it into the list
        P.removeMin();              // Remove it from the queue

        Lprint<T>(L);
        P.display();
    }
}


int main() {

	PQ_example_8_4();

    // Priority Queue Selection-Sort
    list<int> L1  = {9, 3, 7, 1, 4};

    cout << endl << "Selection-Sort" << endl;
    PQ_selectionSort(L1);

    // Priority Queue Insertion Sorting
    list<int> L2 = {7, 4, 8, 2, 5, 3, 9};

    cout << endl << "Insertion-Sort" << endl;
    PQ_insertionSort(L2);

    // Priority Queue Heap Sorting
    list<int> L3 = {7, 4, 8, 2, 5, 3, 9, 1, 10};

    cout << endl << "Heap-Sort" << endl;
    PQ_heapSort(L3);


	return EXIT_SUCCESS;
}



