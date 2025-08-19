
#include <iostream>
#include "StackQueueException.h"
#include "Qwith2Stk.h"

using namespace std;

int main() {
	Queuewith2Stk<int>	AQ(10);

	cout << "Array List Queue" << endl;

	AQ.enqueue(5);	AQ.print();
	AQ.enqueue(3);	AQ.print();
	cout << AQ.front() << " "; 	AQ.print();
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

	return EXIT_SUCCESS;
}



