
#include <iostream>
//#include <map>
#include "Map.h"

using namespace std;

int main() {
    Map<int, char> myMap;

    cout << "map example ... start \n";

    if (myMap.empty()) 	cout << "true" << endl;
    else				cout << "false" << endl;

    myMap.put(5,'A');
    Map<int,char>::Iterator p2 = myMap.put(7,'B');
    Map<int,char>::Iterator p3 = myMap.put(2,'C');
    cout << "map display : ";
    for (Map<int,char>::Iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "(" << (*it).key() << "," << (*it).value() << ") ";
    }
    cout << endl;

    p3 = myMap.put(2,'E');
    cout << "map display after myMap.put(2,'E') : ";
    for (Map<int,char>::Iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout << "(" << (*it).key() << "," << (*it).value() << ") ";
    }
    cout << endl;

    p2 = myMap.find(7);
    if ( p2 == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p2).key() << "," << (*p2).value() << ")" << endl;

    Map<int,char>::Iterator p = myMap.find(4);
    if ( p == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p).key() << "," << (*p).value() << ")" << endl;

    p3 = myMap.find(2);
    if ( p3 == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p3).key() << "," << (*p3).value() << ")" << endl;

    cout << "size = " << myMap.size() << endl;

    myMap.erase(5);
    myMap.erase(p3);

    cout << "map display after myMap.erase(5); myMap.erase(p3= myMap.find(2)) :  " << endl;

    p3 = myMap.find(2);
    if ( p3 == myMap.end())	cout << "end" << endl;
    else	cout << "(" << (*p3).key() << "," << (*p3).value() << ")" << endl;


    cout << "map example ...end \n";

	return EXIT_SUCCESS;
}


