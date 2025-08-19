
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// 2.3 Templates

template <typename T>
T genericMin(T a, T b) {
	return (a < b ? a : b);
}

template <typename T>
class BasicVector {					// a simple vector class
public :
	BasicVector(int capac = 10);	// constructor
	T& operator[](int i)			// access element at index i
	{return a[i];}
	//...other public members omitted
private :
	T* a;							// array storing the elements
	int capacity;					// length of array a
};

template <typename T>				// constructor
BasicVector<T>::BasicVector(int capac) {
	capacity = capac;
	a = new T[capac];				// allocate array storage
}

template <typename T1, typename T2>
class Pair {						// pair class with two different types
private :
	T1 first;
	T2 second;
public :
	Pair(T1 f, T2 s) : first(f), second(s) {}
	void print() {
		cout << " ( " << first << " , " << second << " )" << endl;
	}
};

int main() {

	cout << genericMin(3,4) << ' '
		<< genericMin(1.1, 3.1) << ' '
		<< genericMin('t', 'g') << endl;


	BasicVector<int>	iv(5);		// vector of 5 integers
	BasicVector<double>	dv(20);		// vector of 20 doubles
	BasicVector<string>	sv(10);		// vector of 10 strings

	iv[3] = 8;
	dv[14] = 2.5;
	sv[7] = "hello";

	cout << iv[3] << " " << dv[14] << " " << sv[7] << endl;

    // Creating and printing pairs of different types
    Pair<int, string> pair1(1, "One");
    pair1.print();
    Pair<float, long> pair2(3.14f, 100000L);
    pair2.print();
    Pair<char, double> pair3('A', 2.718);
    pair3.print();
    Pair<string, bool> pair4("Hello", true);
    cout << boolalpha;
    pair4.print();
    Pair<int, int> pair5(10, 20);
    pair5.print();

	return EXIT_SUCCESS;
}


