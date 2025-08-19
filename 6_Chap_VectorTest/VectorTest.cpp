/*
 * VectorTest.cpp
 *
 *  Created on: 2025. 4. 3.
 *      Author: alber
 */

#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int main() {

	vector<int>	v;

	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[0] << endl;

	v.push_back(1);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[0] << endl;
	cout << "vector address : " << &v[1] << endl;

	v.push_back(2);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[1] << endl;
	cout << "vector address : " << &v[2] << endl;

	v.push_back(3);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[2] << endl;
	cout << "vector address : " << &v[3] << endl;

	v.push_back(4);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[3] << endl;
	cout << "vector address : " << &v[4] << endl;

	v.push_back(5);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[4] << endl;
	cout << "vector address : " << &v[5] << endl;

	v.push_back(6);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[5] << endl;
	cout << "vector address : " << &v[6] << endl;

	v.push_back(7);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[6] << endl;
	cout << "vector address : " << &v[7] << endl;

	v.push_back(8);
	cout << "vector capacity : " << v.capacity() << endl;
	cout << "vector address : " << &v[7] << endl;
	cout << "vector address : " << &v[8] << endl;


	return EXIT_SUCCESS;
}


