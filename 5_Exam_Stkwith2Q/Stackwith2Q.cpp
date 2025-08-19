
#include <iostream>
#include "Stackwith2Q.h"

using namespace std;

void Stack_Exam_C_5_5() {

	Stackwith2Q<int>	S2Q;

	S2Q.push(1);	S2Q.print();
	S2Q.push(2);	S2Q.print();
	S2Q.push(3);	S2Q.print();
	cout << S2Q.size() << endl;
	cout << "top = " << S2Q.top() << endl;
	S2Q.pop();		S2Q.print();
	cout << "top = " << S2Q.top() << endl;

}


int main() {

	 Stack_Exam_C_5_5();

	 return EXIT_SUCCESS;
 }
