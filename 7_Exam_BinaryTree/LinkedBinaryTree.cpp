
#include <iostream>
#include <list>
#include "LinkedBinaryTree.h"

using namespace std;


int main() {
    // Create a sample tree
    LinkedBinaryTree<int> tree;

    auto rootPos = tree.addRoot(1);
    auto child02 = tree.addLeftChild(rootPos,2);
    auto child03 = tree.addRightChild(rootPos,3);
    auto child04 = tree.addLeftChild(child02,4);
    auto child05 = tree.addRightChild(child02,5);
    auto child06 = tree.addLeftChild(child03,6);
    auto child07 = tree.addRightChild(child03,7);
    tree.addLeftChild(child04,8);
    tree.addRightChild(child04,9);
    tree.addLeftChild(child05,10);
    tree.addRightChild(child05,11);
    tree.addLeftChild(child06,12);
    tree.addRightChild(child06,13);
    tree.addLeftChild(child07,14);
    tree.addRightChild(child07,15);

    cout << "Preorder Tree Print : ";
    LinkedBinaryTree<int>::BinaryPreorderPrint(tree, rootPos);
    cout << endl;

    cout << "Postorder Tree Print : ";
    LinkedBinaryTree<int>::BinaryPostorderPrint(tree, rootPos);
    cout << endl;

    cout << "Inorder Tree Print : ";
    LinkedBinaryTree<int>::BinaryInorderPrint(tree, rootPos);
    cout << endl;

//  R-7.1 Describe an algorithm for counting the number of left external nodes
//	in a binary tree, using the Binary tree ADT.
    // Count left external nodes
    int count = 0;
    LinkedBinaryTree<int>::countLeftExternalNodes(tree, rootPos, count);
    cout << "Number of left external nodes: " << count << endl;

    LinkedBinaryTree<string> T1;

    auto RrootExp = T1.addRoot("*");
    auto RchildE00 = T1.addLeftChild(RrootExp,"/");
    T1.addRightChild(RrootExp,"8");
    auto RchildE01 = T1.addLeftChild(RchildE00,"*");
    auto RchildE05 = T1.addRightChild(RchildE00,"+");
    auto RchildE03 = T1.addLeftChild(RchildE01,"+");
    auto RchildE04 = T1.addRightChild(RchildE01,"-");

    T1.addLeftChild(RchildE03,"5");
    T1.addRightChild(RchildE03,"2");
    T1.addLeftChild(RchildE04,"2");
    T1.addRightChild(RchildE04,"1");
    auto RchildE11 = T1.addLeftChild(RchildE05,"+");
    auto RchildE12 = T1.addRightChild(RchildE05,"-");
    T1.addLeftChild(RchildE11,"2");
    T1.addRightChild(RchildE11,"9");
    auto RchildE15 = T1.addLeftChild(RchildE12,"-");
    T1.addRightChild(RchildE12,"1");
    T1.addLeftChild(RchildE15,"7");
    T1.addRightChild(RchildE15,"2");

    cout << "Preorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryPreorderPrint(T1, RrootExp);
    cout << endl;

    cout << "Postorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryPostorderPrint(T1, RrootExp);
    cout << endl;

    cout << "Inorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryInorderPrint(T1, RrootExp);
    cout << endl;

    cout << "Parenthetic Expression Print : ";
    LinkedBinaryTree<string>::BinaryParenPrint(T1, RrootExp);
    cout << endl;

    LinkedBinaryTree<string> T2;

    auto rootExp = T2.addRoot("+");
    auto childE01 = T2.addLeftChild(rootExp,"+");
    T2.addRightChild(rootExp,"4");
    auto childE03 = T2.addLeftChild(childE01,"-");
    auto childE04 = T2.addRightChild(childE01,"/");
    T2.addLeftChild(childE03,"7");
    auto childE08 = T2.addRightChild(childE03,"*");
    T2.addLeftChild(childE08,"3");
    T2.addRightChild(childE08,"2");
    T2.addLeftChild(childE04,"6");
    T2.addRightChild(childE04,"2");

    cout << "Preorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryPreorderPrint(T2, rootExp);
    cout << endl;

    cout << "Postorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryPostorderPrint(T2, rootExp);
    cout << endl;

    cout << "Inorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryInorderPrint(T2, rootExp);
    cout << endl;

    cout << "Parenthetic Expression Print : ";
    LinkedBinaryTree<string>::BinaryParenPrint(T2, rootExp);
    cout << endl;

    LinkedBinaryTree<string> T3;

    auto rootChar = T3.addRoot("C");
    T3.addLeftChild(rootChar,"O");
    auto childC02 = T3.addRightChild(rootChar,"M");
    T3.addLeftChild(childC02,"P");
    auto childC04 = T3.addRightChild(childC02,"U");
    T3.addLeftChild(childC04,"T");
    auto childC06 = T3.addRightChild(childC04,"E");
    T3.addLeftChild(childC06,"R");
    T3.addRightChild(childC06,"S");

    cout << "Preorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryPreorderPrint(T3, rootChar);
    cout << endl;

    cout << "Postorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryPostorderPrint(T3, rootChar);
    cout << endl;

    cout << "Inorder Tree Print : ";
    LinkedBinaryTree<string>::BinaryInorderPrint(T3, rootChar);
    cout << endl;


	return EXIT_SUCCESS;
}
