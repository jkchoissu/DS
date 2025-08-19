/*
 * STLmap.cpp
 *
 *  Created on: 2025. 4. 30.
 *      Author: alber
 */

#include <iostream>
#include <map>

using namespace std;

int main() {

	map<string, int> myMap; 			// a (string,int) map
	map<string, int>::iterator p; 		// an iterator to the map

	myMap.insert(pair<string, int>("Rob", 28)); // insert (“Rob”,28)
	myMap["Joe"] = 38;	 						// insert(“Joe”,38)
	myMap["Joe"] = 50; 							// change to (“Joe”,50)
	myMap["Sue"] = 75; 							// insert(“Sue”,75)
	cout << endl;
	for (p = myMap.begin(); p != myMap.end(); ++p) { 	// print all entries
		cout << "(" << p->first << "," << p->second << ")\n";
	}

	cout << endl;
	p = myMap.find("Joe"); 						// *p = (“Joe”,50)
	cout << "(" << p->first << "," << p->second << ")\n";

	cout << endl;
	myMap.erase(p); 							// remove (“Joe”,50)
	cout << " map display after myMap.erase(p=myMap.find(\"Joe\")) " << endl;
	for (p = myMap.begin(); p != myMap.end(); ++p) { 	// print all entries
		cout << "(" << p->first << "," << p->second << ")\n";
	}
	cout << endl;

	myMap.erase("Sue"); 						// remove (“Sue”,75)
	cout << " map display after myMap.erase(\"Sue\") " << endl;
	p = myMap.find("Joe");
	if (p == myMap.end()) cout << "nonexistent\n"; 		// outputs: “nonexistent”
	for (p = myMap.begin(); p != myMap.end(); ++p) { 	// print all entries
		cout << "(" << p->first << "," << p->second << ")\n";
	}

	return EXIT_SUCCESS;
}

