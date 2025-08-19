
#ifndef LINKEDBINARYTREE_H_
#define LINKEDBINARYTREE_H_

#include <iostream>

using namespace std;

template <typename E>
//typedef int Elem;					// base element type
class LinkedBinaryTree {
protected:
  // insert Node declaration here...
    struct Node {					// a node of the tree
      E    	  elt;					// element value
      Node*   par;					// parent
      Node*   left;					// left child
      Node*   right;				// right child
      Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
    };
public:
  // insert Position declaration here...
    class Position {							// position in the tree
    private:
      Node* v;									// pointer to the node
    public:
      Position(Node* _v = NULL) : v(_v) { }		// constructor
      E& operator*()	const					// get element
        { return v->elt; }
      Position left() const						// get left child
        { return Position(v->left); }
      Position right() const					// get right child
        { return Position(v->right); }
      Position parent() const					// get parent
        { return Position(v->par); }
      bool isRoot() const						// root of the tree?
        { return v->par == NULL; }
      bool isExternal() const					// an external node?
        { return v->left == NULL && v->right == NULL; }
      bool noLeft() const
        { return v->left == NULL; }
      bool noRight() const
        { return v->right == NULL; }
      friend class LinkedBinaryTree;			// give tree access
    };
    typedef std::list<Position> PositionList;	// list of positions

public:
//  LinkedBinaryTree();					// constructor
//  int size() const;					// number of nodes
//  bool empty() const;					// is tree empty?
//  Position root() const;				// get the root
//  PositionList positions() const;  	// list of nodes
//  void addRoot();						// add root to empty tree
//  Position addRoot(const E& element);				// add root with element
//  Position addLeftChild(const Position& p, const E& element);	// add a left child node
//  Position addRightChild(const Position& p, const E& element);	// add a right child node
//  void expandExternal(const Position& p);				// expand external node
//  Position removeAboveExternal(const Position& p);	// remove p and parent
  // housekeeping functions omitted...

  LinkedBinaryTree()					// constructor
    : _root(NULL), n(0) { }

  int size() const						// number of nodes
    { return n; }

  bool empty() const					// is tree empty?
    { return size() == 0; }

  Position root() const 				// get the root
    { return Position(_root); }

  void addRoot() {						// add root to empty tree
	  _root = new Node;
	  n = 1;
  }
  Position addRoot(const E& element)	{		// add root with element
     _root = new Node;
     _root->elt = element;
     n = 1;
     return Position(_root);
  }

  Position addLeftChild(const Position& p, const E& element) {	// add a left child node
      auto node = p.v;
      auto leftchildNode = new Node;

      leftchildNode->elt = element;
      leftchildNode->par = node;
      p.v->left = leftchildNode;
      n++;
      return Position(leftchildNode);
  }

  Position addRightChild(const Position& p, const E& element) {	// add a right child node
      auto node = p.v;
      auto rightchildNode = new Node;

      rightchildNode->elt = element;
      rightchildNode->par = node;
      p.v->right = rightchildNode;
      n++;
      return Position(rightchildNode);
  }

  void expandExternal(const Position& p) {							// expand external node
  Node* v = p.v;					// p's node
  v->left = new Node;				// add a new left child
  v->left->par = v;					// v is its parent
  v->right = new Node;				// and a new right child
  v->right->par = v;				// v is its parent
  n += 2;							// two more nodes
  }

  Position removeAboveExternal(const Position& p) {					// remove p and parent
    Node* w = p.v;  Node* v = w->par;			// get p's node and parent
    Node* sib = (w == v->left ?  v->right : v->left);
    if (v == _root) {							// child of root?
      _root = sib;								// ...make sibling root
      sib->par = NULL;
    }
    else {
      Node* gpar = v->par;						// w's grandparent
      if (v == gpar->left) gpar->left = sib; 	// replace parent by sib
      else gpar->right = sib;
      sib->par = gpar;
    }
    delete w; delete v;							// delete removed nodes
    n -= 2;										// two fewer nodes
    return Position(sib);
  }

  // list of all nodes
  PositionList positions() const {
	  PositionList pl;
	  preorder(_root, pl);						// preorder traversal
	  return PositionList(pl);					// return resulting list
  }


  static void BinaryPreorderPrint(const LinkedBinaryTree& T, const Position& p) {
  	cout << *p << " ";
  	if (!p.noLeft())							// traverse left subtree
  		BinaryPreorderPrint(T, p.left());
  	if (!p.noRight())							// traverse right subtree
  		BinaryPreorderPrint(T, p.right());
  }

  static void BinaryPostorderPrint(const LinkedBinaryTree& T, const Position& p) {
  	if (!p.noLeft())							// traverse left subtree
  		BinaryPostorderPrint(T, p.left());
  	if (!p.noRight())							// traverse right subtree
  		BinaryPostorderPrint(T, p.right());
  	cout << *p << " ";
  }

  static void BinaryInorderPrint(const LinkedBinaryTree& T, const Position& p) {

  	if (!p.noLeft())							// traverse left subtree
  		BinaryInorderPrint(T, p.left());
  	cout << *p << " ";
  	if (!p.noRight())							// traverse right subtree
  		BinaryInorderPrint(T, p.right());
  }

  static void BinaryParenPrint(const LinkedBinaryTree& T, const Position& p) {

  	if (!p.isExternal()) {							// traverse left subtree
  		cout << "( ";
  		BinaryParenPrint(T, p.left());
  	}
  	cout << *p << " ";
  	if (!p.isExternal()) {							// traverse right subtree
  		BinaryParenPrint(T, p.right());
  		cout << ")";
  	}
  }

  // Helper function to count left external nodes
  static void countLeftExternalNodes(const LinkedBinaryTree& T, const Position& p, int& countLeft) {
	if (!p.noLeft()) {
		if (p.left().isExternal())	++countLeft;		// if left node is external node
		countLeftExternalNodes(T, p.left(), countLeft);
	}
	if (!p.noRight()) {
		countLeftExternalNodes(T, p.right(), countLeft);
	}
  }

protected: 								// local utilities
  // preorder traversal
  void preorder(Node* v, PositionList& pl) const {	// preorder utility
	  pl.push_back(Position(v));				// add this node
	  if (v->left != NULL)						// traverse left subtree
		  preorder(v->left, pl);
	  if (v->right != NULL)						// traverse right subtree
		  preorder(v->right, pl);
  }
private:
  Node* _root;					// pointer to the root
  int n;						// number of nodes
};


#endif /* LINKEDBINARYTREE_H_ */
