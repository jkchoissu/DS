
#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename E>						// display element
void ldisplay(list<E>& S) {
  typename list<E>::iterator p;
  cout << "{ ";
  for (p = S.begin(); p != S.end(); ++p)
	  cout << *p << " ";					// display element
  cout << "}" << endl;
}

template <typename E>						// display element
void vdisplay(vector<E>& S, int a, int b) {
  cout << "{ ";
  for (int m = a; m <= b; m++)
	  cout << S[m] << " ";					// display element
  cout << "}" << endl;
}

template <typename E>
void QuickSortStep(list<E>& S) {
  	  	  	  	  	  	  	  		// Choosing the pivot (last element)
  int p = S.back();
  list<E> L, Q, G;
  	  	  	  	  	  	  	  	  	// Partition the list into L, E, and G
  while (!S.empty()) {
      int elem = S.back();
      S.pop_back();
      if (elem < p)			L.push_back(elem);
      else if (elem == p)	Q.push_back(elem);
      else					G.push_back(elem);
  }
  	  	  	  	  	  	  	  	  	  // Recursively sort L and G
  if (!L.empty())	QuickSortStep(L);
  if (!G.empty())	QuickSortStep(G);

  // Merge sorted lists back into S
  while (!L.empty()) {
      S.push_back(L.front());
      L.pop_front();
  }
  while (!Q.empty()) {
      S.push_back(Q.front());
      Q.pop_front();
  }
  while (!G.empty()) {
      S.push_back(G.front());
      G.pop_front();
  }
}

template <typename E, typename C>
void quickSortStep(vector<E>& S, int a, int b, const C& less) {

  vdisplay(S, a, b);

  if (a >= b) return;				// 0 or 1 left? done
  E pivot = S[b];					// select last as pivot
  int l = a; 						// left edge
  int r = b - 1;					// right edge
  while (l <= r) {
    while (l <= r && !less(pivot, S[l])) l++;		// scan right till larger
    while (r >= l && !less(S[r], pivot)) r--;		// scan left till smaller
    if (l < r)					// both elements found
      swap(S[l], S[r]);
  }								// until indices cross
  swap(S[l], S[b]);					// store pivot at l
  quickSortStep(S, a, l-1, less);	// recur on both sides
  quickSortStep(S, l+1, b, less);
}

template <typename E>						// quick-sort S
void QuickSort(list<E>& S) {

  cout << "Before QuickSort : "; ldisplay(S);

  if (S.size() <= 1) return;				// already sorted

  QuickSortStep(S);							// call sort utility

  cout << "After QuickSort : "; ldisplay(S);
}

template <typename E, typename C>			// quick-sort S
void quickSort(vector<E>& S, const C& less) {

  cout << "Before quickSort : "; vdisplay(S, 0, S.size()-1);

  if (S.size() <= 1) return;				// already sorted

  quickSortStep(S, 0, S.size()-1, less);	// call sort utility

  cout << "After quickSort : "; vdisplay(S, 0, S.size()-1);
}

#endif /* QUICKSORT_H_ */
