
#include <iostream>
#include "QueueException.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"

using namespace std;


void ArrayQ() {
	ArrayQueue<int>	AQ(10);

	cout << "Array List Queue" << endl;

	AQ.enqueue(5);	AQ.print();
	AQ.enqueue(3);	AQ.print();
	cout << AQ.front() << " ";	AQ.print();
	cout << AQ.size() << " ";	AQ.print();
	AQ.dequeue();	AQ.print();
	AQ.enqueue(7);	AQ.print();
	AQ.dequeue();	AQ.print();
	cout << AQ.front() << " ";	AQ.print();
	AQ.dequeue();	AQ.print();
	try {
		AQ.dequeue();
	} catch (QueueEmpty &e) {
		cout << "Exception catch : " << e.getMessage() << endl;
	}
	cout << boolalpha << AQ.empty() << endl;
	cout << endl;

}

void LinkedListQ() {

	LinkedQueue Q;

	cout << "Linked List Queue " << endl;

	Q.enqueue("LAX");	Q.display();
	Q.enqueue("MSP");	Q.display();
	Q.enqueue("ATL");	Q.display();
	Q.enqueue("BOS");	Q.display();


	Q.dequeue();		Q.display();
	Q.dequeue();		Q.display();
	Q.dequeue();		Q.display();
	Q.dequeue();
}

int main() {

	ArrayQ();
	LinkedListQ();

	return EXIT_SUCCESS;
}


