
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

    // R-8.9 Priority Queue Selection-Sort
    list<int> L1  = {22, 15, 36, 44, 10, 3, 9, 13, 29, 25};

    cout << endl << "Selection-Sort" << endl;
    PQ_selectionSort(L1);

    // R-8.10 Priority Queue Insertion Sorting
    list<int> L2 = {22, 15, 36, 44, 10, 3, 9, 13, 29, 25};

    cout << endl << "Insertion-Sort" << endl;
    PQ_insertionSort(L2);

    // R-8.14 Priority Queue Heap Sorting
    list<int> L3 = {2,5,16,4,10,23,39,18,26,15};

    cout << endl << "Heap-Sort" << endl;
    PQ_heapSort(L3);


	return EXIT_SUCCESS;
}



