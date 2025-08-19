/*
 * Deque.cpp
 *
 *  Created on: 2025. 2. 25.
 *      Author: USER
 */

#include <iostream>
#include "Deque.h"

using namespace std;


int main() {

	DequeStack DQ;

	cout << "Deque Stack : ";

	DQ.push("A");
	DQ.push("B");
	DQ.push("C");
	DQ.push("D");

	cout << DQ.top() << endl;
	DQ.pop();
	cout << DQ.top() << endl;
	DQ.pop();
	cout << DQ.top() << endl;
	DQ.pop();
	cout << DQ.top() << endl;
	DQ.pop();


	return EXIT_SUCCESS;
}


