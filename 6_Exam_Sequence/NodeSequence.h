
#ifndef NODESEQUENCE_H_
#define NODESEQUENCE_H_

#include <iostream>
#include "NodeList.h"

using namespace std;

class NodeSequence : public NodeList {
public:
    Iterator atIndex(int i) const;			// get position from index
    int indexOf(const Iterator& p) const;	// get index from position
    void insertAtRank(int ix, Elem& e);		// insert an element in front of index
};

#endif /* NODESEQUENCE_H_ */
