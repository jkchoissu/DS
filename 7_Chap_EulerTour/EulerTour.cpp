
#include <iostream>
#include <list>
#include "EulerTour.h"

int main() {
    BinaryTree<int> tree;

    tree.root = new BinaryTree<int>::Position(1);
    tree.root->leftChild = new BinaryTree<int>::Position(2);
    tree.root->rightChild = new BinaryTree<int>::Position(3);
    tree.root->leftChild->leftChild = new BinaryTree<int>::Position(4);
    tree.root->leftChild->rightChild = new BinaryTree<int>::Position(5);
    tree.root->rightChild->leftChild = new BinaryTree<int>::Position(6);
    tree.root->rightChild->rightChild = new BinaryTree<int>::Position(7);
    tree.root->leftChild->leftChild->leftChild = new BinaryTree<int>::Position(8);
    tree.root->leftChild->leftChild->rightChild = new BinaryTree<int>::Position(9);
    tree.root->leftChild->rightChild->leftChild = new BinaryTree<int>::Position(10);
    tree.root->leftChild->rightChild->rightChild = new BinaryTree<int>::Position(11);
    tree.root->rightChild->leftChild->leftChild = new BinaryTree<int>::Position(12);
    tree.root->rightChild->leftChild->rightChild = new BinaryTree<int>::Position(13);
    tree.root->rightChild->rightChild->leftChild = new BinaryTree<int>::Position(14);
    tree.root->rightChild->rightChild->rightChild = new BinaryTree<int>::Position(15);

    EvaluateExpressionTour<int, int> evalTour;
    evalTour.execute(tree);

    PrintExpressionTour<int, int> printTour;
    printTour.execute(tree);

	return EXIT_SUCCESS;
}

