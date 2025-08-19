
#ifndef REVERSE_H_
#define REVERSE_H_

#include <iostream>
#include <vector>

using namespace std;

template <typename E>
void reverse(vector<E>& V) {						// reverse a vector
    ArrayStack<E> S(V.size());
    cout << "Original Stack : ";
    for (unsigned int i = 0; i < V.size(); i++) {	// push elements onto stack
      S.push(V[i]);
      cout << S.top() << " ";
    }
    cout << endl;

    for (unsigned int i = 0; i < V.size(); i++) {	// pop them in reverse order
      V[i] = S.top();  S.pop();
    }

    cout << "Reverse Array : ";
    for (unsigned int i = 0; i < V.size(); i++) {
    	cout << V[i] << " ";
    }
	cout << endl;
}


#endif /* REVERSE_H_ */
