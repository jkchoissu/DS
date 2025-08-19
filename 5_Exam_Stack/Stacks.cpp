/*
 * Stacks.cpp
 *
 *  Created on: 2025. 2. 25.
 *      Author: USER
 */

#include <iostream>
#include "StackException.h"
#include "ArrayStack.h"
#include "LinkedListStack.h"

using namespace std;

void Stack_Exam_R_5_5() {

	 ArrayStack<int> C(10);				// C = [], size = 0

	 cout << "Output : ";
	 C.push(5);
	 C.push(3);
	 cout << C.top() << " "; C.pop();
	 C.push(2);
	 C.push(8);
	 cout << C.top() << " "; C.pop();
	 cout << C.top() << " "; C.pop();
	 C.push(9);
	 C.push(1);
	 cout << C.top() << " "; C.pop();
	 C.push(7);
	 C.push(6);
	 cout << C.top() << " "; C.pop();
	 cout << C.top() << " "; C.pop();
	 C.push(4);
	 cout << C.top() << " "; C.pop();
	 cout << C.top() << " "; C.pop();

	 cout << endl;

	 C.print();

}


int main() {

	 Stack_Exam_R_5_5();

	 return EXIT_SUCCESS;
 }
