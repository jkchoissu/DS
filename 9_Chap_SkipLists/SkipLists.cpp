
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Maximum level for the skip list
const int MAX_LEVEL = 16;

// Node structure
struct Node {
    int key;
    string value;
    Node **forward; // Array of pointers to next nodes at different levels

    Node(int k, string v, int level) {
        key = k;
        value = v;
        forward = new Node*[level+1];
        for (int i = 0; i <= level; i++) forward[i] = NULL;
    }
};

// SkipList class
class SkipList {
private:
    int level; // Current level
    Node *header; // Header node

    // Random level generator
    int randomLevel() {
        int lvl = 0;
        while ((rand() % 2) && (lvl < MAX_LEVEL)) lvl++;
        return lvl;
    }

public:
    SkipList() {
        level = 0;
        header = new Node(-1, "", MAX_LEVEL); // Create header node with min key
    }

    // Algorithm: SkipSearch(k)
    Node* SkipSearch(int k) {
        Node *p = header;
        for (int i = level; i >= 0; i--) {
            while (p->forward[i] && p->forward[i]->key < k) {
                p = p->forward[i]; // Scan forward
            }
        }
        return p->forward[0]; // Returns position with key ≤ k
    }

    // Algorithm: SkipInsert(k, v)
    void SkipInsert(int k, string v) {
        Node *update[MAX_LEVEL+1]; // Track path
        Node *p = header;

        for (int i = level; i >= 0; i--) {
            while (p->forward[i] && p->forward[i]->key < k) {
                p = p->forward[i]; // Scan forward
            }
            update[i] = p;
        }

        // Generate random level
        int newLevel = randomLevel();
        if (newLevel > level) {
            for (int i = level+1; i <= newLevel; i++) {
                update[i] = header;
            }
            level = newLevel;
        }

        // Create new node
        Node *q = new Node(k, v, newLevel);
        for (int i = 0; i <= newLevel; i++) {
            q->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = q;
        }
    }

    // Algorithm: Erase(k)
    void Erase(int k) {
        Node *update[MAX_LEVEL+1];
        Node *p = header;

        for (int i = level; i >= 0; i--) {
            while (p->forward[i] && p->forward[i]->key < k) {
                p = p->forward[i]; // Scan forward
            }
            update[i] = p;
        }

        Node *q = p->forward[0]; // Get target node
        if (q && q->key == k) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != q) break;
                update[i]->forward[i] = q->forward[i];
            }
            delete q;

            // Adjust levels
            while (level > 0 && header->forward[level] == NULL) {
                level--;
            }
        }
    }

    // Display the skip list
    void display() {
        for (int i = level; i >= 0; i--) {
            Node *p = header->forward[i];
            cout << "Level " << i << ": ";
            while (p) {
                cout << "(" << p->key << ", " << p->value << ") -> ";
                p = p->forward[i];
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    srand(time(0)); // Seed random number generator

    SkipList sl;

    sl.SkipInsert(12, "A");
    sl.SkipInsert(17, "B");
    sl.SkipInsert(20, "C");
    sl.SkipInsert(25, "D");
    sl.SkipInsert(31, "E");
    sl.SkipInsert(38, "F");
    sl.SkipInsert(39, "H");
    sl.SkipInsert(44, "J");
    sl.SkipInsert(50, "K");
    sl.SkipInsert(55, "L");


    cout << "Skip List After Insertions:\n";
    sl.display();

    cout << "\nSearching for key 50:\n";
    Node *result = sl.SkipSearch(50);
    if (result) cout << "Found: (" << result->key << ", " << result->value << ")\n";
    else cout << "Not Found\n";

    cout << "Skip List After Insertion for key 42 (42,\"I\") :\n";
    sl.SkipInsert(42, "I");
    sl.display();

    cout << "\nRemoving key 25:\n";
    sl.Erase(25);
    sl.display();

    return EXIT_SUCCESS;
}
