
#include <iostream>
#include "OrderedMap.h"

using namespace std;

void Map_Exam_R_9_5() {

	OrderedMap<int,string> map;

    map.put(12, "A");
    map.put(44, "B");
    map.put(13, "C");
    map.put(88, "D");
    map.put(23, "E");
    map.put(94, "F");
    map.put(11, "G");
    map.put(39, "H");
    map.put(20, "I");
    map.put(16, "J");
    map.put(5, "K");

    map.display();

    cout << "Search 39: " << map.find(39) << endl;

    cout << "Erase 20: " << map.find(20) << endl;
    map.erase(20);
    map.display();
}

int main() {

	Map_Exam_R_9_5();

    return EXIT_SUCCESS;
}

