/*
 * HashMap.cpp
 *
 *  Created on: 2025. 3. 1.
 *      Author: alber
 */

#include <iostream>
#include "HashMap.h"

using namespace std;

int main() {
    HashMap<std::string, int, std::hash<std::string>> map;

    map.put("Alice", 25);
    map.put("Bob", 30);
    map.put("Charlie", 35);

    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << (*it).key() << ": " << (*it).value() << std::endl;
    }

    try {
        map.erase("Bob");
        map.erase("Nonexistent"); // This will throw an exception
    } catch (const NonexistentElement& e) {
        std::cerr << e.what() << std::endl;
    }

    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << (*it).key() << ": " << (*it).value() << std::endl;
    }

	return EXIT_SUCCESS;
}


