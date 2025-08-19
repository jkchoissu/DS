
#include <iostream>

using namespace std;

template <typename E>
class CircleList;

template <typename E>
struct CNode {						// circularly linked list node
private:
    E elem;							// linked list element value
    CNode<E>* next;					// next item in the list

    friend class CircleList<E>;		// provide CircleList access
};

template <typename E>
class CircleList {					// a circularly linked list
public:
    CircleList();					// constructor
    ~CircleList();					// destructor
    bool empty() const;				// is list empty?
    const E& front() const;		// element at cursor
    const E& back() const;		// element following cursor
    void advance();					// advance cursor
    void add(const E& e);		// add after cursor
    void remove();					// remove node after cursor
    void display() const;
private:
    CNode<E>* cursor;					// the cursor
};

template <typename E>
CircleList<E>::CircleList()					// constructor
    : cursor(NULL) { }

template <typename E>
CircleList<E>::~CircleList()					// destructor
    { while (!empty()) remove(); }

template <typename E>
bool CircleList<E>::empty() const				// is list empty?
    { return cursor == NULL; }

template <typename E>
const E& CircleList<E>::back() const		// element at cursor
    { return cursor->elem; }

template <typename E>
const E& CircleList<E>::front() const		// element following cursor
    { return cursor->next->elem; }

template <typename E>
void CircleList<E>::advance()					// advance cursor
    { cursor = cursor->next; }

template <typename E>
void CircleList<E>::add(const E& e) {		// add after cursor
    CNode<E>* v = new CNode<E>;					// create a new node
    v->elem = e;
    if (cursor == NULL) {					// list is empty?
      v->next = v;							// v points to itself
      cursor = v;							// cursor points to v
    }
    else {									// list is nonempty?
      v->next = cursor->next;				// link in v after cursor
      cursor->next = v;
// 	  cursor = cursor->next;  				// add a statement *** important

    }
}

template <typename E>
void CircleList<E>::remove() {					// remove node after cursor
    CNode<E>* old = cursor->next;				// the node being removed
    if (old == cursor) 						// removing the only node?
      cursor = NULL;						// list is now empty
    else
      cursor->next = old->next;				// link out the old node
    delete old;								// delete the old node
}

template <typename E>
void CircleList<E>::display() const {
          CNode<E>* v = cursor->next;

          cout << "Output : " << "(" << cursor->elem << ") ";
          while ( v != NULL ) {
        	  cout << v->elem << " ";
              if (v == cursor) break;
              v = v->next;
          }
          cout << endl;
};

// Example usage
int main() {
      CircleList<string> a;

      a.add("Korea");
      a.display();
      a.add("Japan");
      a.display();
      a.add("USA");
      a.display();
      a.add("Austrailia");
      a.display();
      a.add("German");
      a.display();
      a.add("Norway");
      a.display();
      a.advance();
      a.display();
      a.advance();
      a.display();
      a.remove();
      a.display();
      a.remove();
      a.display();

      return EXIT_SUCCESS;
}


