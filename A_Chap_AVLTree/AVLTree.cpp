#include <iostream>
#include "Entry.h"
#include "AVLTree.h"

using namespace std;

int main() {

    AVLTree<Entry<int,int>> avlt; // Initialize AVL tree for integer keys and values

    cout << "AVL Tree display...started " << endl;

    avlt.insert(44, 44);
    avlt.insert(17, 17);
    avlt.insert(78, 78);
    avlt.insert(32, 32);
    avlt.insert(50, 50);
    avlt.insert(88, 88);
    avlt.insert(48, 48);
    avlt.insert(62, 62);

    cout << "avlt elements (in order) before insertion (54, 54) :";
    for (AVLTree<Entry<int,int>>::Iterator itr = avlt.begin(); itr != avlt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).value() << ") ";
    }
    cout << endl;

    // Insert an element
    avlt.insert(54, 54);

    // Display all elements using iterator
    cout << "avlt elements (in order) after insertion (54, 54) :";
    for (AVLTree<Entry<int,int>>::Iterator itr = avlt.begin(); itr != avlt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).value() << ") ";
    }
    cout << endl;

    // Erase an element
    avlt.erase(32);

    // Display all elements using iterator
    cout << "avlt elements (in order) after erase(32):";
    for (AVLTree<Entry<int,int>>::Iterator itr = avlt.begin(); itr != avlt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).value() << ") ";
    }
    cout << endl;

    // Insert an element
    avlt.insert(49, 49);

    // Display all elements using iterator
    cout << "avlt elements (in order) after insertion (49, 49) :";
    for (AVLTree<Entry<int,int>>::Iterator itr = avlt.begin(); itr != avlt.end(); ++itr) {
        cout << "(" << (*itr).key() << "," << (*itr).value() << ") ";
    }
    cout << endl;

    cout << "AVL Tree display...end " << endl;

	return EXIT_SUCCESS;
}






