
#include <iostream>

using namespace std;

class StringNode {					// a node in a list of strings
private:
    string elem;					// element value
    StringNode* next;				// next item in the list

    friend class StringLinkedList;	// provide StringLinkedList access
};

class StringLinkedList {			// a linked list of strings
public:
    StringLinkedList();				// empty list constructor
    ~StringLinkedList();			// destructor
    bool empty() const;				// is list empty?
    const string& front() const;	// get front element
    void addFront(const string& e);	// add to front of list
    void removeFront();				// remove front item list
    void addNthNode(int n, const string& e); // add to front of nth node
    void removeNthNode(int n);		// remove nth node
    void removeBack();				// remove back node
    void display() const;
private:
    StringNode* head;				// pointer to the head of list
};

StringLinkedList::StringLinkedList()					// constructor
    : head(NULL) { }

StringLinkedList::~StringLinkedList()					// destructor
    { while (!empty()) removeFront(); }

bool StringLinkedList::empty() const					// is list empty?
    { return head == NULL; }

const string& StringLinkedList::front() const			// get front element
    { return head->elem; }


void StringLinkedList::addFront(const string& e) {		// add to front of list
    StringNode* v = new StringNode;						// create new node
    v->elem = e;										// store data
    v->next = head;										// head now follows v
    head = v;											// v is now the head
}

void StringLinkedList::removeFront() {					// remove front item
    StringNode* old = head;								// save current head
    head = old->next;									// skip over old head
    delete old;											// delete the old head
}

void StringLinkedList::addNthNode(int n, const string& e) {

	if ( (n <= 0) || (head == NULL) ) return;			// ignore if n is not positive and no elements

	StringNode* v = new StringNode;
	v->elem = e;

	if ( n == 1 ) {										// add to front of head node
		v->next = head;
		head = v;
	}
	else {												// add to front of i-th node
		StringNode* curr = head->next;
		StringNode* prev = head;

		for (int i = 2; i < n; i++) {
			if ( curr != NULL ) {
				prev = curr;
				curr = curr->next;
			}
		}
		v->next = curr;
		prev->next = v;
	}
}

void StringLinkedList::removeNthNode(int n) {

	if ( (n <= 0) || (head == NULL) ) return;			// ignore if n is not positive and no elements

	if ( n == 1 ) {										// remove head node
		StringNode* old = head;
		head = old->next;
		delete old;
	}
	else {												// remove i-th node
		StringNode* curr = head->next;
		StringNode* prev = head;

		for (int i = 2; i < n; i++) {
			if ( curr != NULL ) {
				prev = curr;
				curr = curr->next;
			}
			else return;
		}
		prev->next = curr->next;
		delete curr;
	}
}

void StringLinkedList::removeBack() {

	if ( head->next == NULL ) {							// remove head node
		StringNode* old = head;
		head = NULL;
		delete old;
	}
	else {												// remove tail node
		StringNode* curr = head->next;
		StringNode* prev = head;

		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		delete curr;
	}
}
void StringLinkedList::display() const {
          StringNode* v = head;
          cout << "Output : ";
          while ( v != NULL ) {
              cout << v->elem << " ";
              v = v->next;
          }
          cout << endl;
};

  // Example usage
int main() {
      StringLinkedList a;

      a.addFront("Korea");
      a.display(); // Output:
      a.addFront("Japan");
      a.display(); // Output:
      a.addFront("China");
      a.display(); // Output:
      a.addFront("UK");
      a.display(); // Output:
      a.addFront("France");
      a.display(); // Output:
      a.addFront("Spain");
      a.display(); // Output:
      a.addNthNode(2, "Norway");
      a.display(); // Output:
//    a.removeFront();
      a.removeNthNode(3);
      a.display(); // Output:
      a.removeFront();
      a.display(); // Output:
      a.removeBack();
      a.display(); // Output:

      return 0;
}

