
#include <iostream>
#include <vector>
#include <utility>
#include "HashMap.h"

//class HashTable {
//public:
//    HashTable(int size) : size(size), table(size, NULL) {}
//
//    int hashFunction(int key) {
//        return key % size;
//    }
//
//    void insert(int key, int value) {
//        int idx = hashFunction(key);
//        while (table[idx] != NULL && table[idx]->first != key) {
//            idx = (idx + 1) % size;
//        }
//        table[idx] = new std::pair<int, int>(key, value);
//    }
//
//    int find(int key) {
//        int idx = hashFunction(key);
//        int startIdx = idx;
//        while (table[idx] != NULL) {
//            if (table[idx]->first == key) {
//                return idx;
//            }
//            idx = (idx + 1) % size;
//            if (idx == startIdx) {
//                break;
//            }
//        }
//        return -1;
//    }
//
//    void remove(int key) {
//        int idx = find(key);
//        if (idx == -1) {
//            return; // Key not found
//        }
//
//        delete table[idx];
//        table[idx] = NULL;
//
//        idx = (idx + 1) % size;
//        while (table[idx] != NULL) {
//            auto item = table[idx];
//            table[idx] = NULL;
//            reinsert(item);
//            idx = (idx + 1) % size;
//        }
//    }
//
//    void display() {
//        for (int i = 0; i < size; ++i) {
//            if (table[i] != NULL) {
//                std::cout << "[" << i << "] -> (" << table[i]->first << ", " << table[i]->second << ")\n";
//            } else {
//                std::cout << "[" << i << "] -> NULL\n";
//            }
//        }
//    }
//
//private:
//    void reinsert(std::pair<int, int>* item) {
//        int idx = hashFunction(item->first);
//        while (table[idx] != NULL) {
//            idx = (idx + 1) % size;
//        }
//        table[idx] = item;
//    }
//
//    int size;
//    std::vector<std::pair<int, int>*> table;
//};

int main() {
	LinearProbHT<int, std::string> ht;

    ht.put(12, "A");
    ht.put(44, "B");
    ht.put(13, "C");
    ht.put(88, "D");
    ht.put(23, "E");
    ht.put(94, "F");
    ht.put(11, "G");
    ht.put(39, "H");
    ht.put(20, "I");
    ht.put(16, "J");
    ht.put(5, "K");

    std::cout << "Before removal:\n";
    ht.display();

    ht.erase(44);

    std::cout << "After removal of 44:\n";
    ht.display();

    return EXIT_SUCCESS;
}





