
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
    tree.BinaryPreorderPrint(tree, rootPos);
    cout << endl;
    cout << "Postorder Tree Print : ";
    tree.BinaryPostorderPrint(tree, rootPos);
    cout << endl;
    cout << "Inorder Tree Print : ";
    tree.BinaryInorderPrint(tree, rootPos);
    cout << endl;

    LinkedBinaryTree<string> tree2;

    auto TrootPos = tree2.addRoot("A");
    auto Tchild02 = tree2.addLeftChild(TrootPos,"B");
    auto Tchild03 = tree2.addRightChild(TrootPos,"G");
    tree2.addLeftChild(Tchild02,"C");
    auto Tchild05 = tree2.addRightChild(Tchild02,"D");
    tree2.addLeftChild(Tchild03,"H");
    auto Tchild07 = tree2.addRightChild(Tchild03,"I");
    tree2.addLeftChild(Tchild05,"E");
    auto Tchild09 = tree2.addRightChild(Tchild05,"F");

    cout << "Preorder Tree Print : ";
    tree2.BinaryPreorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Postorder Tree Print : ";
    tree2.BinaryPostorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Inorder Tree Print : ";
    tree2.BinaryInorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Parenthetic Expression Print : ";
    tree2.BinaryParenPrint(tree2, TrootPos);
    cout << endl;


    tree2.expandExternal(Tchild07, "J","K");	// add two external nodes

    cout << "Preorder Tree Print : ";
    tree2.BinaryPreorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Postorder Tree Print : ";
    tree2.BinaryPostorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Inorder Tree Print : ";
    tree2.BinaryInorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Parenthetic Expression Print : ";
    tree2.BinaryParenPrint(tree2, TrootPos);
    cout << endl;

    tree2.removeAboveExternal(Tchild09);		// remove an external node

    cout << "Preorder Tree Print : ";
    tree2.BinaryPreorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Postorder Tree Print : ";
    tree2.BinaryPostorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Inorder Tree Print : ";
    tree2.BinaryInorderPrint(tree2, TrootPos);
    cout << endl;
    cout << "Parenthetic Expression Print : ";
    tree2.BinaryParenPrint(tree2, TrootPos);
    cout << endl;

    LinkedBinaryTree<string> T2;

    auto rootExp = T2.addRoot("+");
    auto childE01 = T2.addLeftChild(rootExp,"*");
    auto childE02 = T2.addRightChild(rootExp,"*");
    T2.addLeftChild(childE01,"2");
    auto childE04 = T2.addRightChild(childE01,"-");
    T2.addLeftChild(childE02,"3");
    T2.addRightChild(childE02,"b");
    T2.addLeftChild(childE04,"a");
    T2.addRightChild(childE04,"1");

    cout << "Preorder Tree Print : ";
    T2.BinaryPreorderPrint(T2, rootExp);
    cout << endl;
    cout << "Postorder Tree Print : ";
    T2.BinaryPostorderPrint(T2, rootExp);
    cout << endl;
    cout << "Inorder Tree Print : ";
    T2.BinaryInorderPrint(T2, rootExp);
    cout << endl;
    cout << "Parenthetic Expression Print : ";
    T2.BinaryParenPrint(T2, rootExp);
    cout << endl;

	return EXIT_SUCCESS;
}
