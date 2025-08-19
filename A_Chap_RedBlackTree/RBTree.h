
#ifndef RBTREE_H_
#define RBTREE_H_

#include <iostream>
#include <list>
#include <vector>
#include "Entry.h"
#include "BinaryTree.h"
#include "Exception.h"

template <typename E>
class RBTree {					// a binary search tree
public: 							// public types
    typedef typename E::Key K;			// a key
    typedef typename E::Value V;		// a value
    class Iterator;						// an iterator/position
public:						// public functions
    RBTree();							// constructor
    int size() const; 					// number of entries
    bool empty() const;					// is the tree empty?
    Iterator find(const K& k);			// find entry with key k
    Iterator insert(const K& k, const V& x);			// insert (k,x)
    void erase(const K& k) throw(NonexistentElement);	// remove key k entry
    void erase(const Iterator& p);		// remove entry at p
    Iterator begin();					// iterator to first entry
    Iterator end();						// iterator to end entry
protected:								// local utilities
    typedef BinaryTree<E> BinaryTree;			// linked binary tree
    typedef typename BinaryTree::Position TPos;	// position in the tree

    TPos root() const;							// get virtual root
    TPos sibling(const TPos& v) const;			// get sibling node
    TPos finder(const K& k, const TPos& v);		// find utility
    TPos inserter(const K& k, const V& x);		// insert utility
    TPos eraser(TPos& v);						// erase utility
    TPos restructure(const TPos& v) 			// restructure
      	throw(BoundaryViolation);
    void remedyDoubleRed(const TPos& z);		// fix double-red z
    void remedyDoubleBlack(const TPos& r);		// fix double-black r
    void setRed(const TPos& v);
    void setBlack(const TPos& v);
    void setColor(const TPos& v, Color c);
    bool wasParentRed(const TPos& v);
    void RBInorderPrint(const RBTree& T, TPos& p, int first);
    void RBPreorderPrint(const RBTree& , TPos& p, int first);
    void RBPostorderPrint(const RBTree& T, TPos& p, int first);

private: 						// member data
    BinaryTree T;				// the binary tree
    int n;						// number of entries
public:
    // ...insert Iterator class declaration here
    class Iterator {	                     	// an iterator/position
    private:
      TPos v;									// which entry
    public:
      Iterator(const TPos& vv) : v(vv) { }		// constructor
      const E& operator*() const { return *v; }	// get entry (read only)
      E& operator*() { return *v; }				// get entry (read/write)
      bool operator==(const Iterator& p) const	// are iterators equal?
        { return v == p.v; }
      bool operator!=(const Iterator& p) const	// are iterators not equal?
        { return v != p.v; }
      Iterator& operator++();					// inorder successor
      TPos& position() { return v; }
      friend class RBTree;						// give search tree access
    };
};


template <typename E>						// constructor
RBTree<E>::RBTree() : T(), n(0)
    { T.addRoot(); T.expandExternal(T.root()); }	// create the super root

template <typename E>						// get virtual root
typename RBTree<E>::TPos RBTree<E>::root() const
    { return T.root().left(); }				// left child of super root

template <typename E>						// get sibling node
typename RBTree<E>::TPos RBTree<E>::sibling(const TPos& v) const {
	if (v == root()) return NULL;
	TPos pnode = v.parent();
	if (pnode.left() == v)	return pnode.right();
	else					return pnode.left();
}

template <typename E>						// iterator to first entry
typename RBTree<E>::Iterator RBTree<E>::begin() {
    TPos v = root();						// start at virtual root
    while (v.isInternal()) v = v.left();	// find leftmost node
    return Iterator(v.parent());
}

template <typename E>						// iterator to end entry
typename RBTree<E>::Iterator RBTree<E>::end()
    { return Iterator(T.root()); }			// return the super root

template <typename E>						// find utility
typename RBTree<E>::TPos RBTree<E>::finder(const K& k, const TPos& v) {
  if (v.isExternal()) return v; 					// key not found
  if (k < (*v).key()) return finder(k, v.left());	// search left subtree
  else if ((*v).key() < k) return finder(k, v.right());	// search right subtree
  else return v;							// found it here
}

template <typename E>						// find entry with key k
typename RBTree<E>::Iterator RBTree<E>::find(const K& k) {
  TPos v = finder(k, root());				// search from virtual root

  if (v.isInternal()) return Iterator(v);		// found it
  else return end();						// didn't find it
}

template <typename E>						// insert utility
typename RBTree<E>::TPos RBTree<E>::inserter(const K& k, const V& x) {
  TPos v = finder(k, root());				// search from virtual root
  while (v.isInternal())					// key already exists?
    v = finder(k, v.right());				// look further
  T.expandExternal(v);						// add new internal node
  (*v).setKey(k); (*v).setValue(x);			// set entry
  n++;										// one more entry
  return v;									// return insert position
}

template <typename E>					// insert (k,x)
typename RBTree<E>::Iterator RBTree<E>::insert(const K& k, const V& x) {
  TPos v = inserter(k, x);				// insert in base tree
  if (v == root())
    setBlack(v);					// root is always black
  else {
    setRed(v);
    remedyDoubleRed(v);				// rebalance if needed
  }
  return Iterator(v);
}

template <typename E>					// remove utility
typename RBTree<E>::TPos RBTree<E>::eraser(TPos& v) {
  TPos w;
  if (v.left().isExternal()) w = v.left();			// remove from left
  else if (v.right().isExternal()) w = v.right();	// remove from right
  else {											// both internal?
    w = v.right();									// go to right subtree
    do { w = w.left(); } while (w.isInternal());	// get leftmost node
    TPos u = w.parent();
    (*v).setKey((*u).key()); (*v).setValue((*u).value());	// copy w's parent to v
  }
  n--;						// one less entry

  return T.removeAboveExternal(w);		// remove w and parent
}

template <typename E>					// remove key k entry
void RBTree<E>::erase(const K& k) throw(NonexistentElement) {
  TPos u = finder(k, root());			// find the node
  if (Iterator(u) == end())
    throw NonexistentElement("Erase of nonexistent");
  TPos r = eraser(u);					// remove u
  if (r == root() || (*r).isRed() || wasParentRed(r))
    setBlack(r);						// fix by color change
  else 									// r, parent both black
    remedyDoubleBlack(r);				// fix double-black r
}

template <typename E>					// erase entry at p
void RBTree<E>::erase(const Iterator& p)
  { eraser(p.v); }

template <typename E>
typename RBTree<E>::TPos RBTree<E>::restructure(const TPos& v) throw(BoundaryViolation) {
	TPos x = v;
    TPos y = x.parent();
    TPos z = y.parent();

//    std::cout << " x, y, z = " << (*x).key() << " " << (*y).key() << " " << (*z).key() << " " << std::endl;

    // Step 1: Get nodes in inorder sequence
    // Step 2: Get subtrees
    TPos a, b, c;
    TPos T0, T1, T2, T3;
    if (x == y.left() && y == z.left()) { 			// Left-Left (Single Rotation)
    	T0 = x.left(); T1 = x.right(); T2 = y.right(); T3 = z.right();
        a = x; b = y; c = z;
    } else if (x == y.right() && y == z.right()) { 	// Right-Right (Single Rotation)
    	T0 = z.left(); T1 = y.left(); T2 = x.left(); T3 = x.right();
        a = z; b = y; c = x;
    } else if (x == y.right() && y == z.left()) { 	// Left-Right (Double Rotation)
    	T0 = y.left(); T1 = x.left(); T2 = x.right(); T3 = z.right();
        a = y; b = x; c = z;
    } else { 										// Right-Left (Double Rotation)
    	T0 = z.left(); T1 = x.left(); T2 = x.right(); T3 = y.right();
        a = z; b = x; c = y;
    }

//    std::cout << " a, b, c = " << (*a).key() << " " << (*b).key() << " " << (*c).key() << " " << std::endl;

    // Step 3: Replace subtree rooted at z with one rooted at b
    if (z == root()) {
        T.setRoot(b);
    } else {
        TPos p = z.parent();
        if (z == p.left()) p.setLeft(b);
        else p.setRight(b);
    }

    // Step 4: Assign new children
    b.setLeft(a);
    a.setLeft(T0);
    a.setRight(T1);

    b.setRight(c);
    c.setLeft(T2);
    c.setRight(T3);

    return b; // Return the new root after restructuring
}

template <typename E>					// inorder successor
typename RBTree<E>::Iterator& RBTree<E>::Iterator::operator++() {
  TPos w = v.right();
  if (w.isInternal()) {					// have right subtree?

    do { v = w; w = w.left();}			// move down left chain
    while (w.isInternal());
  }
  else {
    w = v.parent();						// get parent
    while (v == w.right())				// move up right chain
      { v = w; w = w.parent();}
    v = w;								// and first link to left
  }
  return *this;
}

template <typename E>					// fix double-red z
void RBTree<E>::remedyDoubleRed(const TPos& z) {
  TPos v = z.parent();					// v is z's parent
//  std::cout << "remedyDoubleRed "<< (*z).key() << "," << (*v).key() << endl;
  if (v == root() || (*v).isBlack()) return;	// v is black, all ok
  							// z, v are double-red
  if ((*sibling(v)).isBlack())  {		// Case 1: restructuring
    v = restructure(z);
    setBlack(v);							// top vertex now black
    setRed(v.left()); setRed(v.right());	// set children red
  }
  else  {								// Case 2: recoloring
    setBlack(v); setBlack(sibling(v));		// set v and sibling black
    TPos u = v.parent();					// u is v's parent
    if (u == root()) return;
    setRed(u);								// make u red
    remedyDoubleRed(u);						// may need to fix u now
  }
}

template <typename E>					// fix double-black r
void RBTree<E>::remedyDoubleBlack(const TPos& r) {
  TPos x = r.parent();				// r's parent
  TPos y = sibling(r);				// r's sibling
//  std::cout << "remedyDoubleBlack " << (*r).key() << "," << (*x).key() << endl;
  if ((*y).isBlack())  {
	TPos yl = y.left();
	TPos yr = y.right();
    if ( ((yl != NULL) && (*yl).isRed()) || ((yr != NULL) && (*yr).isRed()) ) {	// Case 1: restructuring
							// z is y's red child
	  TPos z = ((*yl).isRed() ? y.left() : y.right());
      Color topColor = (*x).color();		// save top vertex color
      z = restructure(z);					// restructure x,y,z
	  setColor(z, topColor);				// give z saved color
      setBlack(r);							// set r black
      setBlack(z.left()); setBlack(z.right());	// set z's children black
    }
    else {						// Case 2: recoloring
      setBlack(r); setRed(y);				// r=black, y=red
      if ((*x).isBlack() && !(x == root()))
    	  remedyDoubleBlack(x);				// fix double-black x
      setBlack(x);
    }
  }
  else {						// Case 3: adjustment
    TPos z = (y == x.right() ? y.right() : y.left());	// grandchild on y's side
    restructure(z);						// restructure x,y,z
    setBlack(y); setRed(x);				// y=black, x=red
    remedyDoubleBlack(r);				// fix r by Case 1 or 2
  }
}

template <typename E>					// set RED color
void RBTree<E>::setRed(const TPos& v) {
	(*v).setColor(RED);
}

template <typename E>					// set BLACK color
void RBTree<E>::setBlack(const TPos& v) {
	(*v).setColor(BLACK);
}

template <typename E>					// set RED or BLACK color
void RBTree<E>::setColor(const TPos& v, Color c) {
	(*v).setColor(c);
}

template <typename E>					// check if parent node is red before deletion
bool RBTree<E>::wasParentRed(const TPos& v) {
	TPos w = v.parent();
	return !(*w).isRed();
}

#endif /* RBTREE_H_ */
