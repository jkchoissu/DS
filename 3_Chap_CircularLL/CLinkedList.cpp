
#include <iostream>

using namespace std;

typedef string Elem;				// element type
class CNode {						// circularly linked list node
private:
    Elem elem;						// linked list element value
    CNode* next;					// next item in the list

    friend class CircleList;		// provide CircleList access
};

class CircleList {					// a circularly linked list
public:
    CircleList();					// constructor
    ~CircleList();					// destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;		// element at cursor
    const Elem& back() const;		// element following cursor
    void advance();					// advance cursor
    void add(const Elem& e);		// add after cursor
    void remove();					// remove node after cursor
    void display() const;
private:
    CNode* cursor;					// the cursor
};

CircleList::CircleList()					// constructor
    : cursor(NULL) { }

CircleList::~CircleList()					// destructor
    { while (!empty()) remove(); }

bool CircleList::empty() const				// is list empty?
    { return cursor == NULL; }

const Elem& CircleList::back() const		// element at cursor
    { return cursor->elem; }

const Elem& CircleList::front() const		// element following cursor
    { return cursor->next->elem; }

void CircleList::advance()					// advance cursor
    { cursor = cursor->next; }

void CircleList::add(const Elem& e) {		// add after cursor
    CNode* v = new CNode;					// create a new node
    v->elem = e;
    if (cursor == NULL) {					// list is empty?
      v->next = v;							// v points to itself
      cursor = v;							// cursor points to v
    }
    else {									// list is nonempty?
      v->next = cursor->next;				// link in v after cursor
      cursor->next = v;
    }
}

void CircleList::remove() {					// remove node after cursor
	if ( cursor == NULL)
		return;

    CNode* old = cursor->next;				// the node being removed
    if (old == cursor) 						// removing the only node?
      cursor = NULL;						// list is now empty
    else
      cursor->next = old->next;				// link out the old node
    delete old;								// delete the old node
}

void CircleList::display() const {
          CNode* v = cursor->next;

          cout << "Output : [";
          while ( v != NULL ) {
        	  cout << v->elem;
              if (v == cursor) break;
              cout << ", ";
              v = v->next;
          }
          cout << "*]" << endl;
};

// Example usage
int main() {
	  CircleList playList;				// []

	  playList.remove();				// []

	  playList.add("Stayin Alive");		//[Stayin Alive*]
	  playList.display();
	  playList.add("Le Freak");			//[Le Freak, Stayin Alive*]
	  playList.display();
	  playList.add("Jive Talkin");		//[Jive Talkin, Le Freak, Stayin Alive*]
	  playList.display();

	  playList.advance();				//[Le Freak, Stayin Alive, Jive Talkin*]
	  playList.display();
	  playList.advance();				//[Stayin Alive, Jive Talkin, Le Freak*]
	  playList.display();
	  playList.remove();				//[Jive Talkin, Le Freak*]
	  playList.display();
	  playList.add("Disco Inferno");	//[Disco Inferno, Jive Talkin, Le Freak*]
	  playList.display();

      CircleList a;

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


