
#include <iostream>
#include "Trees.h"

using namespace std;

struct Node;

int main() {

    // Create a sample tree
    Tree<string> T;

    auto rootPos = T.addRoot("/user/rt/courses");
    auto child01 = T.addChild(rootPos, "cs016/");
    auto child02 = T.addChild(rootPos, "cs252/");
    T.addChild(child01, "grades");
    auto child012 = T.addChild(child01, "homeworks/");
    auto child013 = T.addChild(child01, "programs/");
    T.addChild(child012, "hw1");
    T.addChild(child012, "hw2");
    T.addChild(child012, "hw3");
    T.addChild(child013, "pr1");
    T.addChild(child013, "pr2");
    T.addChild(child013, "pr3");
    auto child021 = T.addChild(child02, "projects/");
    T.addChild(child02, "grades");
    auto child0211 = T.addChild(child021, "papers/");
    auto child0212 = T.addChild(child021, "demos/");
    T.addChild(child0211, "buylow");
    T.addChild(child0211, "sellhigh");
    T.addChild(child0212, "market");

    for (const auto& pos : T.positions().getPositions()) {
        cout << *pos << " ";
    }
    cout << endl;

    // Compute and print the depth of some nodes
     cout << "Depth of node : " << Tree<string>::depth(T, child0211) << endl; // Output: 0

     // Compute and print the height1 of some nodes
      cout << "Height1 of node : " << Tree<string>::height1(T) << endl; // Output: 0

      // Compute and print the height2 of some nodes
       cout << "Height2 of node : " << Tree<string>::height2(T, child0211) << endl; // Output: 0


//       R-7.9 Let T be the T of Figure 7.3.
//       a. Give the output of preorderPrint(T,T.root()) (Code Fragment 7.10).
//       b. Give the output of parenPrint(T,T.root())(Code Fragment cod:paren:Print).

       cout << "Preorder : ";
       Tree<string>::preorderPrint(T, T.root());
       cout << endl;

       cout << "Postorder : ";
       Tree<string>::postorderPrint(T, T.root());
       cout << endl;

       cout << "Parenthetic : ";
       Tree<string>::parenPrint(T, T.root());
       cout << endl;


	return EXIT_SUCCESS;
}
