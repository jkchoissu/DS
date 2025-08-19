
#include <iostream>
#include "Entry.h"
#include "SearchTree.h"

using namespace std;

int main() {

    SearchTree<Entry<int, string>> bst;

    // Insert elements into the BST
    bst.insert(44, "A");
    bst.insert(17, "B");
    bst.insert(88, "C");
    bst.insert(32, "D");
    bst.insert(65, "E");
    bst.insert(97, "F");
    bst.insert(28, "G");
    bst.insert(54, "H");
    bst.insert(82, "I");
    bst.insert(29, "J");
    bst.insert(76, "K");
    bst.insert(80, "L");

    // Find an element
    auto it = bst.find(76);
    if (it != bst.end()) {
        cout << "Found key 76: " << (*it).value() << endl;
    } else {
        cout << "Key 76 not found!" << endl;
    }

    auto it2 = bst.find(25);
    if (it2 != bst.end()) {
        cout << "Found key 25: " << (*it2).value() << endl;
    } else {
        cout << "Key 25 not found!" << endl;
    }

    // Insert an element
    bst.insert(78, "M");

    // Display all elements using iterator
    cout << "BST elements (in order) after insertion (78, \"M\") :";
    for (SearchTree<Entry<int, string>>::Iterator itr = bst.begin(); itr != bst.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).value() << ") ";
    }
    cout << endl;

    // Erase an element
    bst.erase(32);
    cout << "Key 32 erased from BST." << endl;

    // Display all elements using iterator
    cout << "BST elements (in order) after erase(32):";
    for (SearchTree<Entry<int, string>>::Iterator itr = bst.begin(); itr != bst.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).value() << ") ";
    }
    cout << endl;

    // Erase an element
    bst.erase(65);
    cout << "Key 65 erased from BST." << endl;

    // Display all elements using iterator
    cout << "BST elements (in order) after erase(65):";
    for (SearchTree<Entry<int, string>>::Iterator itr = bst.begin(); itr != bst.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).value() << ") ";
    }
    cout << endl;

	return EXIT_SUCCESS;
}


