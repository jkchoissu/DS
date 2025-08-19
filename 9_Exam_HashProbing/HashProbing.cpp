
#include <iostream>
#include <vector>
#include "HashMap.h"

using namespace std;

void Hashing_Chaining() {
    ChainingHT<int,string> ht;

    ht.put(11, "A");
    ht.put(43, "B");
    ht.put(12, "C");
    ht.put(87, "D");
    ht.put(22, "E");
    ht.put(93, "F");
    ht.put(10, "G");
    ht.put(38, "H");
    ht.put(19, "I");
    ht.put(15, "J");
    ht.put(4, "K");

    std::cout << "Hash Table Before Deletion:\n";
    ht.display();

    ht.erase(10);
    ht.erase(15);

    cout << "\nHash Table After Deletion: erase(10), erase(15) \n";
    ht.display();

    ht.put(10, "NEW_G");  // Reinserting a deleted item
    cout << "\nHash Table After Reinserting (10, \"NEW_G\"):\n";
    ht.display();
}

void Hashing_LinearProbing() {
    LinearProbHT<int,string> ht;

    ht.put(11, "A");
    ht.put(43, "B");
    ht.put(12, "C");
    ht.put(87, "D");
    ht.put(22, "E");
    ht.put(93, "F");
    ht.put(10, "G");
    ht.put(38, "H");
    ht.put(19, "I");
    ht.put(15, "J");
    ht.put(4, "K");

    std::cout << "Hash Table Before Deletion:\n";
    ht.display();

    ht.erase(10);
    ht.erase(15);

    cout << "\nHash Table After Deletion: erase(10), erase(15) \n";
    ht.display();

    ht.put(10, "NEW_G");  // Reinserting a deleted item
    cout << "\nHash Table After Reinserting (10, \"NEW_G\"):\n";
    ht.display();
}

void Hashing_QuadraticProbing() {
    QuadraticProbHT<int,string> ht;

    ht.put(11, "A");
    ht.put(43, "B");
    ht.put(12, "C");
    ht.put(87, "D");
    ht.put(22, "E");
    ht.put(93, "F");
    ht.put(10, "G");
    ht.put(38, "H");
    ht.put(19, "I");
    ht.put(15, "J");
    ht.put(4, "K");

    std::cout << "Hash Table Before Deletion:\n";
    ht.display();

    ht.erase(10);
    ht.erase(15);

    cout << "\nHash Table After Deletion: erase(10), erase(15) \n";
    ht.display();

    ht.put(10, "NEW_G");  // Reinserting a deleted item
    cout << "\nHash Table After Reinserting (10, \"NEW_G\"):\n";
    ht.display();
}

void Hashing_Double() {
    DoubleHT<int,string> ht;

    ht.put(11, "A");
    ht.put(43, "B");
    ht.put(12, "C");
    ht.put(87, "D");
    ht.put(22, "E");
    ht.put(93, "F");
    ht.put(10, "G");
    ht.put(38, "H");
    ht.put(19, "I");
    ht.put(15, "J");
    ht.put(4, "K");

    std::cout << "Hash Table Before Deletion:\n";
    ht.display();

    ht.erase(10);
    ht.erase(87);

    cout << "\nHash Table After Deletion: erase(10), erase(87) \n";
    ht.display();

    ht.put(10, "NEW_G");  // Reinserting a deleted item
    cout << "\nHash Table After Reinserting (10, \"NEW_G\"):\n";
    ht.display();
}

int main() {

	cout << " [R-9.7] Hash Table : Separate Chaining......" << endl;
	Hashing_Chaining();
	cout << "\n\n [R-9.8] Hash Table : Linear Probing........." << endl;
	Hashing_LinearProbing();
	cout << "\n\n [R-9.9] Hash Table : Quadratic Probing......" << endl;
	Hashing_QuadraticProbing();
	cout << "\n\n [R-9.10] Hash Table : Double Hashing........." << endl;
	Hashing_Double();

    return EXIT_SUCCESS;
}


