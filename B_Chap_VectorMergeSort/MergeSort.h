
#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <iostream>
#include <vector>

using namespace std;

template <typename E>						// display element
void display(vector<E>& S) {
  int n = S.size();
  cout << "{ ";
  for (int m = 0; m < n; m++)
	  cout << S[m] << " ";					// display element
  cout << "}" << endl;
}

template <typename E, typename C>			// merge-sort S
void mergeSort(vector<E>& S, const C& less) {
  typedef vector<E> vect;
  int n = S.size();
  vect v1(S);  vect* in = &v1;				// initial input vector
  vect v2(n);  vect* out = &v2;				// initial output vector
  for (int m = 1; m < n; m *= 2) {			// list sizes doubling
    for (int b = 0; b < n; b += 2*m) {		// beginning of list
    	merge(*in, *out, less, b, m);		// merge sublists
    }
    std::swap(in, out);						// swap input with output
  }
  S = *in;									// copy sorted array to S
}

								// merge in[b..b+m-1] and in[b+m..b+2*m-1]
template <typename E, typename C>
void merge(vector<E>& in, vector<E>& out, const C& less, int b, int m) {
  int i = b;						// index into run #1
  int j = b + m;					// index into run #2
  int n = in.size();
  int e1 = std::min(b + m, n);		// end of run #1
  int e2 = std::min(b + 2*m, n);	// end of run #2
  int k = b;

  cout << "Vin = "; display(in);

  while ((i < e1) && (j < e2)) {
    if(!less(in[j], in[i]))			// append smaller to S
      out[k++] = in[i++];
    else
      out[k++] = in[j++];
  }
  while (i < e1)					// copy rest of run 1 to S
    out[k++] = in[i++];
  while (j < e2)					// copy rest of run 2 to S
    out[k++] = in[j++];

  cout << "Vout = "; display(out);
}


#endif /* MERGESORT_H_ */
