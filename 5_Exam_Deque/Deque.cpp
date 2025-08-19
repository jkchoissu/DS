
#include <iostream>
#include "DequeQueue.h"
#include "DequeStack.h"

using namespace std;

void Deque_Exam_R_5_5() {

	 DequeStack DS;				// C = [], size = 0

	 cout << "Deque Stack : ";
	 DS.push(5);
	 DS.push(3);
	 cout << DS.top() << " "; DS.pop();
	 DS.push(2);
	 DS.push(8);
	 cout << DS.top() << " "; DS.pop();
	 cout << DS.top() << " "; DS.pop();
	 DS.push(9);
	 DS.push(1);
	 cout << DS.top() << " "; DS.pop();
	 DS.push(7);
	 DS.push(6);
	 cout << DS.top() << " "; DS.pop();
	 cout << DS.top() << " "; DS.pop();
	 DS.push(4);
	 cout << DS.top() << " "; DS.pop();
	 cout << DS.top() << " "; DS.pop();

	 DS.display();

	 cout << endl;

}

void Deque_Exam_R_5_9() {

	DequeQueue DQ;

	cout << "Deque Queue : ";

	DQ.enqueue(5);
	DQ.enqueue(3);
	cout << DQ.front() << " "; DQ.dequeue();
	DQ.enqueue(2);
	DQ.enqueue(8);
	cout << DQ.front() << " "; DQ.dequeue();
	cout << DQ.front() << " "; DQ.dequeue();
	DQ.enqueue(9);
	DQ.enqueue(1);
	cout << DQ.front() << " "; DQ.dequeue();
	DQ.enqueue(7);
	DQ.enqueue(6);
	cout << DQ.front() << " "; DQ.dequeue();
	cout << DQ.front() << " "; DQ.dequeue();
	DQ.enqueue(4);
	cout << DQ.front() << " "; DQ.dequeue();
	cout << DQ.front() << " "; DQ.dequeue();

	DQ.display();

	cout << endl;
}

void Deque_Exam_R_5_10() {

	LinkedDeque	LDQ;

	cout << "Output : ";

	LDQ.insertFront(3);
	LDQ.insertBack(8);
	LDQ.insertBack(9);
	LDQ.insertFront(5);
	cout << LDQ.front() << " "; LDQ.removeFront();
	cout << LDQ.back() << " "; LDQ.eraseBack();
	cout << LDQ.first() << " ";
	LDQ.insertBack(7);
	cout << LDQ.front() << " "; LDQ.removeFront();
	cout << LDQ.last() << " ";
	cout << LDQ.back() << " "; LDQ.eraseBack();

	LDQ.print();

	cout << endl;
}

void Deque_Exam_R_5_11() {

	LinkedDeque D;
	DequeQueue	Q;

	D.insertBack(1);
	D.insertBack(2);
	D.insertBack(3);
	D.insertBack(4);
	D.insertBack(5);
	D.insertBack(6);
	D.insertBack(7);
	D.insertBack(8);
	D.print();

	D.insertBack(D.front()); D.eraseFront();
	D.insertBack(D.front()); D.eraseFront();
	D.insertBack(D.front()); D.eraseFront();
	Q.enqueue(D.front()); 	 D.eraseFront();
	Q.enqueue(D.front()); 	 D.eraseFront();
	D.insertFront(Q.front());	Q.dequeue();
	D.insertFront(Q.front());	Q.dequeue();
	D.insertFront(D.back()); D.eraseBack();
	D.insertFront(D.back()); D.eraseBack();
	D.insertFront(D.back()); D.eraseBack();
	D.print();

}

void Deque_Exam_R_5_12() {

	LinkedDeque D;
	DequeStack	S;

	D.insertBack(1);
	D.insertBack(2);
	D.insertBack(3);
	D.insertBack(4);
	D.insertBack(5);
	D.insertBack(6);
	D.insertBack(7);
	D.insertBack(8);
	D.print();

	D.insertBack(D.front()); D.eraseFront();
	D.insertBack(D.front()); D.eraseFront();
	D.insertBack(D.front()); D.eraseFront();
	S.push(D.front());		 D.eraseFront();
	S.push(D.front());		 D.eraseFront();
	D.insertBack(S.top());	 S.pop();
	D.insertBack(S.top());	 S.pop();
	D.insertFront(D.back()); D.eraseBack();
	D.insertFront(D.back()); D.eraseBack();
	D.insertFront(D.back()); D.eraseBack();
	D.insertFront(D.back()); D.eraseBack();
	D.insertFront(D.back()); D.eraseBack();
	D.print();

}

int main() {

	Deque_Exam_R_5_5();
	Deque_Exam_R_5_9();
	Deque_Exam_R_5_10();
	Deque_Exam_R_5_11();
	Deque_Exam_R_5_12();

	return EXIT_SUCCESS;
}


