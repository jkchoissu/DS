
#ifndef EULERTOUR_H_
#define EULERTOUR_H_

#include <iostream>

using namespace std;

template <typename E>
class BinaryTree {
public:
    class Position {
    public:
        E data;
        Position* leftChild;
        Position* rightChild;
        Position(E value) : data(value), leftChild(NULL), rightChild(NULL) {}
        bool isExternal() const { return leftChild == NULL && rightChild == NULL; }
        Position* left() const { return leftChild; }
        Position* right() const { return rightChild; }
        E value() const { return data; }
        void print() const { std::cout << data << " "; } // Example print function
        E operation(const E& left, const E& right) const { return left + right; } // Example operation
    };

    Position* root;
    BinaryTree() : root(NULL) {}
    Position* rootNode() const { return root; }
};

template <typename E, typename R> 	// element and result types
class EulerTour { 					// a template for Euler tour
protected:
    struct Result { 				// stores tour results
        R leftResult; 				// result from left subtree
        R rightResult; 				// result from right subtree
        R finalResult; 				// combined result
    };
    typedef BinaryTree<E> BinaryTree; 	// the tree
    typedef typename BinaryTree::Position Position; 	// a position in the tree
protected: 							// data member
    const BinaryTree* tree; 				// pointer to the tree
public:
    void initialize(const BinaryTree& T) { 			// initialize
        tree = &T;
    }
protected: // local utilities
    int eulerTour(const Position& p) const; 	// perform the Euler tour
    virtual void visitExternal(const Position& p, Result& r) const {}
    virtual void visitLeft(const Position& p, Result& r) const {}
    virtual void visitBelow(const Position& p, Result& r) const {}
    virtual void visitRight(const Position& p, Result& r) const {}
    Result initResult() const { return Result(); }
    int result(const Result& r) const { return r.finalResult; }
};

template <typename E, typename R> 				// do the tour
int EulerTour<E, R>::eulerTour(const Position& p) const {
    Result r = initResult();
    if (p.isExternal()) { 						// external node
        visitExternal(p, r);
    } else { 									// internal node
        visitLeft(p, r);
        r.leftResult = eulerTour(*p.left());
        visitBelow(p, r);
        r.rightResult = eulerTour(*p.right());
        visitRight(p, r);
    }
    return result(r);
}

template <typename E, typename R>
class EvaluateExpressionTour : public EulerTour<E, R> {
protected: 										// Shortcut type names
    typedef typename EulerTour<E, R>::BinaryTree BinaryTree;
    typedef typename EulerTour<E, R>::Position Position;
    typedef typename EulerTour<E, R>::Result Result;
public:
    void execute(const BinaryTree& T) { 		// Execute the tour
        this->initialize(T);
        std::cout << "The value is: " << this->eulerTour(*T.rootNode()) << "\n";
    }
protected: 										// Leaf: return value
    virtual void visitExternal(const Position& p, Result& r) const override {
        r.finalResult = p.value();
    }
    											// Internal: do operation
    virtual void visitRight(const Position& p, Result& r) const override {
        r.finalResult = p.operation(r.leftResult, r.rightResult);
//      cout << r.finalResult << " ";
    }
};

template <typename E, typename R>
class PrintExpressionTour : public EulerTour<E, R> {
protected: 										// Shortcut type names
    typedef typename EulerTour<E, R>::BinaryTree BinaryTree;
    typedef typename EulerTour<E, R>::Position Position;
    typedef typename EulerTour<E, R>::Result Result;
public:
    void execute(const BinaryTree& T) { 		// execute the tour
        this->initialize(T);
        std::cout << "Expression: "; this->eulerTour(*T.rootNode()); std::cout << std::endl;
    }
protected:
    // leaf: print value
    virtual void visitExternal(const Position& p, Result& r) const override {
        p.print();
    }
    // left: open new expression
    virtual void visitLeft(const Position& p, Result& r) const override {
        std::cout << "(";
    }
    // below: print operator
    virtual void visitBelow(const Position& p, Result& r) const override {
        p.print();
    }
    // right: close expression
    virtual void visitRight(const Position& p, Result& r) const override {
        std::cout << ")";
    }
};

#endif /* EULERTOUR_H_ */
