/*
 * TwoFourTree.cpp
 *
 *  Created on: 2025. 5. 9.
 *      Author: alber
 */

#include <iostream>
#include <vector>

class Node {
public:
    std::vector<int> keys;
    std::vector<Node*> children;
    bool isLeaf;

    Node(bool leaf) : isLeaf(leaf) {}

    void insertNonFull(int key);
    void splitChild(int i, Node* y);
};

class TwoFourTree {
public:
    Node* root;

    TwoFourTree() {
        root = new Node(true);
    }

    void insert(int key);
    void traverse(Node* node);
    void traverse() { traverse(root); }
};

// Inserts a key into the tree
void Node::insertNonFull(int key) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.push_back(0);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key) i--;
        if (children[i + 1]->keys.size() == 3) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key) i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

// Splits a full child node
void Node::splitChild(int i, Node* y) {
    Node* z = new Node(y->isLeaf);
    z->keys.assign(y->keys.begin() + 2, y->keys.end());
    y->keys.resize(1);

    if (!y->isLeaf) {
        z->children.assign(y->children.begin() + 2, y->children.end());
        y->children.resize(2);
    }

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[1]);
}

// Inserts a key into the (2,4) tree
void TwoFourTree::insert(int key) {
    if (root->keys.size() == 3) {
        Node* s = new Node(false);
        s->children.push_back(root);
        s->splitChild(0, root);
        root = s;
    }
    root->insertNonFull(key);
}

// Traverses and prints the tree
void TwoFourTree::traverse(Node* node) {
    int i;

	std::cout << "{ ";
    for (i = 0; i < node->keys.size(); i++) {
        if (!node->isLeaf)
            traverse(node->children[i]);
        std::cout << node->keys[i] << " ";
    }
    std::cout << "} ";
    if (!node->isLeaf)
        traverse(node->children[i]);
}

int main() {
    TwoFourTree tree;
    tree.insert(4);
    tree.insert(6);
    tree.insert(12);
    tree.insert(15);
    tree.insert(3);
    tree.insert(5);
    tree.insert(10);
    tree.insert(8);

    std::cout << "Traversal of the tree: ";
    tree.traverse();
    std::cout << std::endl;

    return EXIT_SUCCESS;
}


