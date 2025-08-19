
#include <iostream>
#include "HashDict.h"

using namespace std;

int main() {
    HashDict<int,char,hash<int>> myMap;

    cout << "Dictionary example ... start \n";

    if (myMap.empty()) 	cout << "true" << endl;
    else				cout << "false" << endl;

    myMap.insert(5,'A');
    HashDict<int,char,hash<int>>::Iterator p2 = myMap.insert(7,'B');
    HashDict<int,char,hash<int>>::Iterator p3 = myMap.insert(2,'C');
    HashDict<int,char,hash<int>>::Iterator p4 = myMap.insert(8,'D');
    cout << "{ ";
    for (HashDict<int,char,hash<int>>::Iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "(" << (*it).key() << "," << (*it).value() << ") ";
    }
    cout << " }" << endl;

    HashDict<int,char,hash<int>>::Iterator p5 = myMap.insert(2,'E');
    cout << "Dictionary display after myMap.insert(2,'E') " << endl;
    cout << "{ ";
    for (HashDict<int,char,hash<int>>::Iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "(" << (*it).key() << "," << (*it).value() << ") ";
    }
    cout << " }" << endl;

    p2 = myMap.find(7);
    if ( p2 == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p2).key() << "," << (*p2).value() << ")" << endl;

    HashDict<int,char,hash<int>>::Iterator p = myMap.find(4);
    if ( p == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p).key() << "," << (*p).value() << ")" << endl;

    p3 = myMap.find(2);
    if ( p3 == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p3).key() << "," << (*p3).value() << ")" << endl;

    HashDict<int,char,hash<int>>::Range r = myMap.findAll(2);
    for (HashDict<int,char,hash<int>>::Iterator it = r.begin(); it != r.end(); ++it) {
        cout << "(" << (*it).key() << "," << (*it).value() << ") ";
    }
    cout << endl;

    cout << "size = " << myMap.size() << endl;

    myMap.erase(5);
    myMap.erase(p3);

    cout << "Dictionary display after myMap.erase(5); myMap.erase(p3= myMap.find(2)) " << endl;

    p3 = myMap.find(2);
    if ( p3 == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p3).key() << "," << (*p3).value() << ")" << endl;

    cout << "{ ";
    for (HashDict<int,char,hash<int>>::Iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "(" << (*it).key() << "," << (*it).value() << ") ";
    }
    cout << " }" << endl;

    cout << "Dictionary example ...end \n";

	return EXIT_SUCCESS;
}




