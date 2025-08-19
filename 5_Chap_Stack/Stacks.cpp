
#include <iostream>
#include "StackException.h"
#include "ArrayStack.h"
#include "LinkedListStack.h"
#include "reverse.h"

using namespace std;

vector<string> getHtmlTags();
bool isHtmlMatched(const vector<string>& tags);

void Stack_Exam1() {

	 ArrayStack<int> C(10);				// C = [], size = 0

	 C.push(5);	C.print();				// C = [5*], size = 1
	 C.push(3);	C.print();				// C = [5, 3*], size = 2
	 C.pop();	C.print();				// C = [5*], size = 1
	 C.push(7);	C.print();				// C = [5, 7*], size = 2
	 C.pop();	C.print();				// C = [5*], size = 1
	 cout << C.top() << endl;
	 C.pop();	C.print();				// C = [], size = 0
	 try {
		 C.pop(); C.print();
	 } catch (StackEmpty &e) {
		 cout << "Exception catch : " << e.getMessage() << endl;
	 }
	 try {
		 cout << C.top() << endl;
	 } catch (StackEmpty &e) {
		 cout << "Exception catch : " << e.getMessage() << endl;
	 }
	 cout << boolalpha << C.empty() << endl;
	 C.push(9);	C.print();				// C = [9*], size = 1
	 C.push(7);	C.print();				// C = [9, 7*], size = 2
	 C.push(3);	C.print();				// C = [9, 7, 3*], size = 3
	 C.push(5);	C.print();				// C = [9, 7, 3, 5*], size = 4
	 cout << C.size() << endl;
	 C.pop();	C.print();				// C = [9, 7, 3*], size = 3
	 C.push(8);	C.print();				// C = [9, 7, 3, 8*], size = 4
	 C.pop();	C.print();				// C = [9, 7, 3*], size = 3
	 try {
		 cout << C.top() << endl;
	 } catch (StackEmpty &e) {
		 cout << "Exception catch : " << e.getMessage() << endl;
	 }
}

void Stack_Exam2() {

	 ArrayStack<int> A;						// A = [], size = 0
	 A.push(7);	A.print();					// A = [7*], size = 1
	 A.push(13); A.print();					// A = [7, 13*], size = 2
	 cout << "Output : " << A.top() << endl;
	 A.pop(); A.print();					// A = [7*], outputs: 13
	 A.push(9); A.print();					// A = [7, 9*], size = 2
	 cout << "Output : " << A.top() << endl;	// A = [7, 9*], outputs: 9
	 cout << "Output : " << A.top() << endl;
	 A.pop(); A.print();					// A = [7*], outputs: 9

}

void Stack_Exam3() {

	 ArrayStack<string> B(10);		// B = [], size = 0

	 try {
	 B.push("Bob");	B.print();		// B = [Bob*], size = 1
	 B.push("Alice"); B.print();	// B = [Bob, Alice*], size = 2
	 cout << B.top() << endl;
	 B.pop(); B.print();			// B = [Bob*], outputs: Alice
	 B.push("Eve");	 B.print();		// B = [Bob, Eve*], size = 2
	 B.push("Eve3"); B.print();		// B = [Bob,...,Eve3*], size = 3
	 B.push("Eve4"); B.print();		// B = [Bob,...,Eve4*], size = 4
	 B.push("Eve5"); B.print();		// B = [Bob,...,Eve5*], size = 5
	 B.push("Eve6"); B.print();		// B = [Bob,...,Eve6*], size = 6
	 B.push("Eve7"); B.print();		// B = [Bob,...,Eve7*], size = 7
	 B.push("Eve8"); B.print();		// B = [Bob,...,Eve8*], size = 8
	 B.push("Eve9"); B.print();		// B = [Bob,...,Eve9*], size = 9
	 B.push("Eve10");B.print();		// B = [Bob,...,Eve10*], size = 10
	 B.push("Eve11");B.print();		// B = [Bob,...,Eve11*], size = 11
	 } catch (StackFull &e) {
		 cout << "Exception catch : " <<e.getMessage() << endl;
	 } catch (...) {
		 cerr << "Unknown exception error " << endl;
	 }
}

void Stack_Exam4() {
	 LinkedStack D;

	 D.push("Jack"); D.print();
	 D.push("Kate"); D.print();
	 cout << D.top() << endl;
	 D.push("Hurley"); D.print();
	 D.push("Jin");	   D.print();
	 D.push("Michael"); D.print();
	 cout << D.top() << endl;
}

void Stack_Reverse() {

	 vector<string> R = {"Jack", "Kate", "Herley", "Jin", "Michael"};
	 reverse(R);
}

void Stack_Html() {						// main HTML tester
   if (isHtmlMatched(getHtmlTags()))		// get tags and test them
     cout << "The input file is a matched HTML document." << endl;
   else
     cout << "The input file is not a matched HTML document." << endl;
}

int main() {

	 Stack_Exam1();
	 Stack_Exam2();
	 Stack_Exam3();
	 Stack_Exam4();
	 Stack_Reverse();
	 Stack_Html();

	 return EXIT_SUCCESS;
 }
