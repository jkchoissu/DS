/*
 * DLLSentinel.cpp
 *
 *  Created on: 2025. 3. 22.
 *      Author: alber
 */

#include <iostream>

// Node definition without dummy header/trailer sentinels
typedef int Elem;						// list element type

struct DNode {					// doubly linked list node
    Elem elem;
    DNode* prev;
    DNode* next;

    DNode(Elem value) : elem(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    // Constructor initializes an empty list.
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Append: add a node with given value at the end of the list.
    void append(Elem value) {
        DNode* newNode = new DNode(value);
        if (!head) { // List is empty.
            head = tail = newNode;
        } else { // Link new node after tail.
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Prepend: add a node with given value at the beginning of the list.
    void prepend(Elem value) {
        DNode* newNode = new DNode(value);
        if (!head) { // List is empty.
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Remove: delete the first node containing the specified value.
    // Returns true if a node was removed, false otherwise.
    bool remove(Elem value) {
        DNode* current = head;
        while (current) {
            if (current->elem == value) {
                // If there is a previous node, link it to current's next.
                if (current->prev)
                    current->prev->next = current->next;
                // If there is a next node, link it back to current's prev.
                if (current->next)
                    current->next->prev = current->prev;
                // Update head and tail if necessary.
                if (current == head)
                    head = current->next;
                if (current == tail)
                    tail = current->prev;
                delete current;
                return true;
            }
            current = current->next;
        }
        return false; // Value not found.
    }

    // Display: prints the content of the list from head to tail.
    void display() const {
        DNode* current = head;
        while (current) {
            std::cout << current->elem << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor releases all allocated nodes.
    ~DoublyLinkedList() {
        DNode* current = head;
        while (current) {
            DNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    // Append and prepend nodes to the list.
    dll.append(10);
    dll.append(20);
    dll.prepend(5);

    // Display list: Expected output "5 10 20"
    std::cout << "Current List     : ";
    dll.display();

    // Remove a node and display updated list.
    if (dll.remove(10))
        std::cout << "After removing 10: ";
    else
        std::cout << "10 not found!";
    dll.display();

    return 0;
}




