
#ifndef TREES_H_
#define TREES_H_

#include <iostream>
#include <list>

using namespace std;

template <typename E>			// base element type
class Tree {
protected :
    // insert Node declaration here...
	struct Node {
		E element;
		Node* parent;
		list<Node*> children;
		Node(const E& e) : element(e), parent(NULL) {}
	};
public:							// public types
	class PositionList;			// forward declaration
    class Position {			// a node position
    public :
    	Position(Node* n = NULL) : node(n) {}	// constructor

        E& operator*() const {					// get element
            return node->element;
        }

        Position parent() const {				// get parent
            return Position(node->parent);
        }

        PositionList children() const {        // get node's children
            PositionList positions;
            for (typename list<Node*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
                positions.addPosition(Position(*it));
            }
            return positions;
        }

        bool isRoot() const {					// root node ?
            return node->parent == NULL;
        }

        bool isExternal() const {				// external node ?
            return node->children.empty();
        }

    private:
        Node* node;
        friend class Tree<E>;  	// Allow Tree to access private members of Position
    }; 							// end of class Position

    class PositionList {		// a list of positions
    public:
        // Nested Iterator class
        class Iterator {
        public:
            // Constructor for const iterator
            Iterator(typename list<Position>::const_iterator it)
                : iter(it) {}

            // Dereference operator (const version)
            const Position& operator*() const {
                return *iter;
            }

            // Prefix increment operator to move to the next position
            Iterator& operator++() {
                ++iter;
                return *this;
            }
            // Equality comparison operator
            bool operator==(const Iterator& other) const { return iter == other.iter; }

            // Inequality comparison operator
            bool operator!=(const Iterator& other) const { return iter != other.iter; }

        private:
            typename list<Position>::const_iterator iter;           // For const access
        };															// end of class Iterator

    public:
        void addPosition(const Position& p) {
            positions.push_back(p);
        }

        list<Position> getPositions() const {
            return positions;
        }

        // Begin method to return an iterator pointing to the start of the list
        Iterator begin() const {
        	return Iterator(positions.begin());
        }

        // End method to return an iterator pointing to the end of the list
        Iterator end() const {
        	return Iterator(positions.end());
        }

    private:
        list<Position> positions;
    };															// end of PostionList


public:
    // Tree public functions
    Tree() : rootNode(NULL), n(0) {}		// constructor

    ~Tree() {
        deleteTree(rootNode);				// destructor
    }

    int size() const {						// number of nodes
        return n;
    }

    bool empty() const {					// is tree empty ?
        return n == 0;
    }

    Position root() const {					// get the root
        return Position(rootNode);
    }

    PositionList positions() const {		// get positions of all nodes
        PositionList plist;
        preorder(rootNode, plist);
        return plist;
    }

    // Method to add root
    Position addRoot(const E& element) {
        if (rootNode != NULL) throw std::runtime_error("Root already exists");
        rootNode = new Node(element);
        n = 1;
        return Position(rootNode);
    }

    // Method to add a child node
    Position addChild(const Position& p, const E& element) {
        auto node = p.node;
        auto childNode = new Node(element);
        childNode->parent = node;
        node->children.push_back(childNode);
        n++;
        return Position(childNode);
    }

    static int depth(const Tree<E>& T, const Position& p) {
      if (p.isRoot())
        return 0;								// root has depth 0
      else
        return 1 + depth(T, p.parent());		// 1 + (depth of parent)
    }

    static int height1(const Tree<E>& T) {
      int h = 0;
      PositionList nodes = T.positions();		// list of all nodes
   	  for (typename PositionList::Iterator q = nodes.begin(); q != nodes.end(); ++q) {
        if ((*q).isExternal())
      	      h = max(h, depth(T, *q));			// get max depth among leaves
      }
      return h;
    }

    static int height2(const Tree<E>& T, const Position& p) {
      if (p.isExternal()) return 0;				// leaf has height 0
      int h = 0;
      PositionList ch = p.children();			// list of children
      for (typename PositionList::Iterator q = ch.begin(); q != ch.end(); ++q)
        h = max(h, height2(T, *q));
      return 1 + h;								// 1 + max height of children
    }

    static void preorderPrint(const Tree& T, const Position& p) {
      cout << *p;								// print element
      PositionList ch = p.children();			// list of children
      for (typename PositionList::Iterator q = ch.begin(); q != ch.end(); ++q) {
        cout << " ";
        preorderPrint(T, *q);
      }
    }

    static void postorderPrint(const Tree& T, const Position& p) {
      PositionList ch = p.children();			// list of children
      for (typename PositionList::Iterator q = ch.begin(); q != ch.end(); ++q) {
        postorderPrint(T, *q);
        cout << " ";
      }
      cout << *p;								// print element
    }

    static void parenPrint(const Tree& T, const Position& p) {
      cout << *p;								// print node's element
      if (!p.isExternal()) {
    	PositionList ch = p.children();			// list of children
        cout << "( ";							// open
        for (typename PositionList::Iterator q = ch.begin(); q != ch.end(); ++q) {
        	if ( q != ch.begin()) cout << " ";	// print separator
        	parenPrint(T, *q);					// visit the next child
        }
        cout << " )";							// close
      }
    }

//    static int diskSpace(const Tree& T, const Position& p) {
//      int s = size(p);							// start with size of p
//      if (!p.isExternal()) {					// if p is external
//    	PositionList ch = p.children();			// list of children
//        for (typename PositionList::Iterator q = ch.begin(); q != ch.end(); ++q)
//        	s += diskSpace(T, *q);
//        cout << name(p) << ": " << s << endl;	// sum the space of subtrees
//      }
//      return s;
//    }

protected:
    void preorder(Node* v, PositionList& plist) const {
        if (v != NULL) {
            plist.addPosition(Position(v));
            list<Node*> ch = v->children;
            for (typename list<Node*>::iterator q = ch.begin(); q != ch.end(); ++q) {
                preorder(*q, plist);
            }
        }
    }

    void deleteTree(Node* v) {
        if (v != NULL) {
        	list<Node*> ch = v->children;
        	for (typename list<Node*>::iterator q = ch.begin(); q != ch.end(); ++q) {
                deleteTree(*q);
            }
            delete v;
        }
    }

private:
    Node* rootNode;
    int n;
};


#endif /* TREES_H_ */
