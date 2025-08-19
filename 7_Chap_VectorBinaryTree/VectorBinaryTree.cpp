
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Node structure
struct Node {
    string value;
    int left;  // Index of left child in the vector
    int right; // Index of right child in the vector

    Node(string v, int l = -1, int r = -1) : value(v), left(l), right(r) {}
};

// Binary Tree class
class BinaryTree {
private:
    vector<Node> nodes;

public:
    // Add a new node to the tree
    int addNode(string value, int left = -1, int right = -1) {
        nodes.push_back(Node(value, left, right));
        return nodes.size() - 1; // Return the index of the new node
    }

    // Add this method inside the BinaryTree class
    void setChild(int parentIndex, int leftChildIndex, int rightChildIndex) {
        nodes[parentIndex].left = leftChildIndex;
        nodes[parentIndex].right = rightChildIndex;
    }

    // Display the tree in preorder traversal
    void preorderTraversal(int index) {
        if (index == -1) return; // Base case
        cout << nodes[index].value << " ";
        preorderTraversal(nodes[index].left);
        preorderTraversal(nodes[index].right);
    }

    // Display the tree in postorder traversal
    void postorderTraversal(int index) {
        if (index == -1) return; // Base case
        postorderTraversal(nodes[index].left);
        postorderTraversal(nodes[index].right);
        cout << nodes[index].value << " ";
    }

    // Display the tree in inorder traversal
    void inorderTraversal(int index) {
        if (index == -1) return; // Base case
        inorderTraversal(nodes[index].left);
        cout << nodes[index].value << " ";
        inorderTraversal(nodes[index].right);
    }
};

int main() {
    BinaryTree tree;


//    auto rootPos = tree.addRoot(1);
//    auto child02 = tree.addLeftChild(rootPos,2);
//    auto child03 = tree.addRightChild(rootPos,3);
//    auto child04 = tree.addLeftChild(child02,4);
//    auto child05 = tree.addRightChild(child02,5);
//    auto child06 = tree.addLeftChild(child03,6);
//    auto child07 = tree.addRightChild(child03,7);
//    tree.addLeftChild(child04,8);
//    tree.addRightChild(child04,9);
//    tree.addLeftChild(child05,10);
//    tree.addRightChild(child05,11);
//    tree.addLeftChild(child06,12);
//    tree.addRightChild(child06,13);
//    tree.addLeftChild(child07,14);
//    tree.addRightChild(child07,15);

    // Creating nodes
    int root = tree.addNode("A");
    int leftChild = tree.addNode("B");
    int rightChild = tree.addNode("C");
    int leftGrandchild = tree.addNode("D");
    int rightGrandchild = tree.addNode("E");

    // Defining relationships
    tree.setChild(root, leftChild, rightChild);
    tree.setChild(leftChild, leftGrandchild, rightGrandchild);

    // Traversals
    cout << "Preorder Traversal: ";
    tree.preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(root);
    cout << endl;

    return 0;
}


