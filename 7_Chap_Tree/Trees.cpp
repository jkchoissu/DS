
#include <iostream>
#include "Trees.h"

using namespace std;

struct Node;

int main() {

    // Create a sample tree
    Tree<string> tree;

    auto rootPos = tree.addRoot("/user/rt/courses");
    auto child01 = tree.addChild(rootPos, "cs016/");
    auto child02 = tree.addChild(rootPos, "cs252/");
    tree.addChild(child01, "grades");
    auto child012 = tree.addChild(child01, "homeworks/");
    auto child013 = tree.addChild(child01, "programs/");
    tree.addChild(child012, "hw1");
    tree.addChild(child012, "hw2");
    tree.addChild(child012, "hw3");
    tree.addChild(child013, "pr1");
    tree.addChild(child013, "pr2");
    tree.addChild(child013, "pr3");
    auto child021 = tree.addChild(child02, "projects/");
    tree.addChild(child02, "grades");
    auto child0211 = tree.addChild(child021, "papers/");
    auto child0212 = tree.addChild(child021, "demos/");
    tree.addChild(child0211, "buylow");
    tree.addChild(child0211, "sellhigh");
    tree.addChild(child0212, "market");

//        auto rootPos = tree.addRoot("0");
//        auto child01 = tree.addChild(rootPos, "01");
//        auto child02 = tree.addChild(rootPos, "02");
//        tree.addChild(child01, "011");
//        auto child012 = tree.addChild(child01, "012");
//        auto child013 = tree.addChild(child01, "013");
//        tree.addChild(child012, "0121");
//        tree.addChild(child012, "0122");
//        tree.addChild(child012, "0123");
//        tree.addChild(child013, "0131");
//        tree.addChild(child013, "0132");
//        tree.addChild(child013, "0133");
//        auto child021 = tree.addChild(child02, "021");
//        tree.addChild(child02, "022");
//        auto child0211 = tree.addChild(child021, "0211");
//        auto child0212 = tree.addChild(child021, "0212");
//        tree.addChild(child0211, "02111");
//        tree.addChild(child0211, "02112");
//        tree.addChild(child0212, "02121");

    // Print the elements in the tree
    for (const auto& pos : tree.positions().getPositions()) {
        cout << *pos << " ";
    }
    cout << endl;

    // Compute and print the depth of some nodes
    cout << "Depth of node : " << Tree<string>::depth(tree, child0211) << endl;

    // Compute and print the height1 of some nodes
    cout << "Height1 of node : " << Tree<string>::height1(tree) << endl;

    // Compute and print the height2 of some nodes
    cout << "Height2 of node : " << Tree<string>::height2(tree, child021) << endl;

    cout << "Preorder : ";
    Tree<string>::preorderPrint(tree, tree.root());
    cout << endl;

    cout << "Postorder : ";
    Tree<string>::postorderPrint(tree, tree.root());
    cout << endl;

    cout << "Parenthetic : ";
    Tree<string>::parenPrint(tree, tree.root());
    cout << endl;


       Tree<string> tree2;

       auto TrootPos = tree2.addRoot("A");
       auto Tchild02 = tree2.addChild(TrootPos,"B");
       auto Tchild03 = tree2.addChild(TrootPos,"G");
       tree2.addChild(Tchild02,"C");
       auto Tchild05 = tree2.addChild(Tchild02,"D");
       tree2.addChild(Tchild03,"H");
       tree2.addChild(Tchild03,"I");
       tree2.addChild(Tchild05,"E");
       tree2.addChild(Tchild05,"F");

       cout << "Preorder : ";
       Tree<string>::preorderPrint(tree2, tree2.root());
       cout << endl;

       cout << "Postorder : ";
       Tree<string>::postorderPrint(tree2, tree2.root());
       cout << endl;

       cout << "Parenthetic : ";
       Tree<string>::parenPrint(tree2, tree2.root());
       cout << endl;

	return EXIT_SUCCESS;
}
