
#include <iostream>
#include "Entry.h"
#include "RBTree.h"  // Include your Red-Black Tree header file

using namespace std;

int main() {

    RBTree<Entry<int,int>> rbt; // Initialize Red-Black tree for integer keys and colors

    cout << "Red-Black Tree display...started " << endl;

    rbt.insert(4, 4);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(7, 7);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(12, 12);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(15, 15);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(3, 3);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(5, 5);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(14, 14);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(18, 18);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(16, 16);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.insert(17, 17);
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;

    // Erase an element
    rbt.erase(3);
    cout << "Key 3 erased from rbt." << endl;
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.erase(12);
    cout << "Key 12 erased from rbt." << endl;
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.erase(17);
    cout << "Key 17 erased from rbt." << endl;
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.erase(18);
    cout << "Key 18 erased from rbt." << endl;
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.erase(15);
    cout << "Key 15 erased from rbt." << endl;
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;
    rbt.erase(16);
    cout << "Key 16 erased from rbt." << endl;
    for (RBTree<Entry<int,int>>::Iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).color() << ") ";
    }
    cout << endl;

    cout << "Red-Black Tree display...end " << endl;

	return EXIT_SUCCESS;
}


