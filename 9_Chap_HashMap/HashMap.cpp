
#include <iostream>
#include "HashMap.h"

using namespace std;

int main() {
    HashMap<string, int, hash<string>> map;

    map.put("A", 25);
    map.put("B", 30);
    map.put("C", 35);
    map.put("D", 30);

    cout << "HashMap display : ";
    for (HashMap<string,int,hash<string>>::Iterator it = map.begin(); it != map.end(); ++it) {
        cout << "(" << (*it).key() << ": " << (*it).value() << ") ";
    }
    cout << endl;

    try {
    	cout << "HashMap erase(\"A\") " << endl;
        map.erase("A");
        map.erase("Nonexistent"); // This will throw an exception
    } catch (const NonexistentElement& e) {
        cerr << e.what() << endl;
    }

    cout << "HashMap display after erase(\"A\") : ";
    for (HashMap<string,int,hash<string>>::Iterator it = map.begin(); it != map.end(); ++it) {
    	cout << "(" << (*it).key() << ": " << (*it).value() << ") ";
    }
    cout << endl;

	return EXIT_SUCCESS;
}


