
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A simple C++ function that sums the entries of an STL vector
int vectorSum1(const vector<int>& V) {
  int sum = 0;
  for (int i = 0; i < V.size(); i++)
    sum += V[i];
  return sum;
}

// Using an iterator to sum the elements of an STL vector
int vectorSum2(vector<int> V) {
  typedef vector<int>::iterator Iterator;		// iterator type
  int sum = 0;
  for (Iterator p = V.begin(); p != V.end(); ++p) {
	*p += 1;
    sum += *p;
  }
  return sum;
}

// Using a constant iterator to sum the elements of a vector
int vectorSum3(const vector<int>& V) {
  typedef vector<int>::const_iterator ConstIterator; 	// iterator type
  int sum = 0;
  for (ConstIterator p = V.begin(); p != V.end(); ++p) {
//	  *p += 1;
	  sum += *p;
  }
  return sum;
}

template <typename E>
void vectordisplay(vector<E>& V) {

	cout << " Vector : ";
	for (int i = 0; i < V.size(); i++)
	    cout << V[i] << " ";
	cout << endl;

}

int main() {


	//
	vector<int> V = {4, 5, 6, 9, 22, 15, 32, 28, 77};

	cout << "vectorSum1 = " << vectorSum1(V) << endl;

	vectordisplay<int>(V);

	cout << "vectorSum2 = " << vectorSum2(V) << endl;
	cout << "vectorSum3 = " << vectorSum3(V) << endl;

	int a[ ] = {17, 12, 33, 15, 62, 45};
	vector<int> v(a, a + 6); 	vectordisplay<int>(v);		// v: 17 12 33 15 62 45
	cout << v.size() << endl; 								// outputs: 6
	v.pop_back(); 				vectordisplay<int>(v);		// v: 17 12 33 15 62
	cout << v.size() << endl; 								// outputs: 5
	v.push_back(19); 			vectordisplay<int>(v);		// v: 17 12 33 15 62 19
	cout << v.front() << " " << v.back() << endl; 			// outputs: 17 19
	sort(v.begin(), v.begin() + 4); vectordisplay<int>(v);	// v: (12 15 17 33) 62 19
	v.erase(v.end() - 4, v.end() - 2); vectordisplay<int>(v);// v: 12 15 62 19
	cout << v.size() << endl; 								// outputs: 4
	char b[] = {'b', 'r', 'a', 'v', 'o'};
	vector<char> w(b, b + 5); 	vectordisplay<char>(w);			// w: b r a v o
	random_shuffle(w.begin(), w.end()); vectordisplay<char>(w);	// w: o v r a b
	w.insert(w.begin(), 's'); 	vectordisplay<char>(w);			// w: s o v r a b
	for (vector<char>::iterator p = w.begin(); p != w.end(); ++p)
	cout << *p << " "; 											// outputs: s o v r a b
	cout << endl;

	vector<int> v2(v.begin(), v.begin() + 3);
	v2.insert(v2.begin(),5);
	v2.erase(v2.end() - 1);
	vectordisplay<int>(v2);

	return EXIT_SUCCESS;
}




