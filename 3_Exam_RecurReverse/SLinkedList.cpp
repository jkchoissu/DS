
#include <iostream>
#include <string>

using namespace std;

template <typename E>
struct SNode {						// singly linked list node
    E elem;							// linked list element value
    SNode<E>* next;					// next item in the list
};

template <typename E>
class SLinkedList {					// a singly linked list
public:
    SLinkedList();					// empty list constructor
    ~SLinkedList();					// destructor
    bool empty() const;				// is list empty?
    const E& front() const;			// return front element
    void addFront(const E& e);		// add to front of list
    void removeFront();				// remove front item list
    void reverseList();
    void display() const;
private:
    SNode<E>* head;					// head of the list
  };

template <typename E>
SLinkedList<E>::SLinkedList()				// constructor
    : head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const			// is list empty?
    { return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const		// return front element
    { return head->elem; }

template <typename E>
SLinkedList<E>::~SLinkedList()				// destructor
    { while (!empty()) removeFront(); }

template <typename E>
void SLinkedList<E>::addFront(const E& e) {	// add to front of list
    SNode<E>* v = new SNode<E>;				// create new node
    v->elem = e;							// store data
    v->next = head;							// head now follows v
    head = v;								// v is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() {		// remove front item
    SNode<E>* old = head;					// save current head
    head = old->next;						// skip over old head
    delete old;								// delete the old head
}

template <typename E>
SNode<E>* reverseRecursive(SNode<E>* v) {
    // Base case: if the list is empty or has only one node
    if (v == NULL || v->next == NULL) {
        return v;
    }

    // Recursive case: reverse the rest of the list
    SNode<E>* newHead = reverseRecursive(v->next);

    // Adjust the pointers to reverse the current link
    v->next->next = v;
    v->next = NULL;

    return newHead; // Return the new head of the reversed list
}

template <typename E>
void SLinkedList<E>::reverseList() {
	SNode<E>* s = head;

	head = reverseRecursive(s);
}

template <typename E>
void SLinkedList<E>::display() const {
        SNode<E>* temp = head;
        while (temp != NULL) {
            cout << temp->elem << " ";
            temp = temp->next;
        }
        cout << endl;
};

// Example usage
int main() {
    SLinkedList<int> a;
    a.addFront(3);
    a.addFront(4);
    a.addFront(5);
    a.addFront(6);
    a.addFront(7);
    a.addFront(8);
    a.addFront(9);
    a.removeFront();
    a.display(); 			// integer linked list display

    a.reverseList();
    a.display();

    SLinkedList<string> b;
    b.addFront("Seoul");
    b.addFront("Busan");
    b.addFront("Incheon");
    b.addFront("Daejeon");
    b.removeFront();
    b.addFront("Suwon");
    b.display();			// string linked list display

    b.reverseList();
    b.display();

    return 0;
}
