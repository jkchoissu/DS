/*
 * permutation.cpp
 *
 *  Created on: 2025. 3. 19.
 *      Author: alber
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

ostream& operator<<(ostream& out, const list<char>& L) {
    list<char>::const_iterator p = L.begin();
    while (p != L.end()) { out << *p; p++; }
    return out;
}

void permute(list<char>& bag, list<char>& permutation) {
    if (bag.empty())
       cout << permutation << endl;
    else {
       list<char>::iterator p = bag.begin();
       while (p != bag.end()) {
           list<char>::iterator n = p; n++;
           char c = *p;
           bag.erase(p);
           permutation.push_back(c);
           permute(bag, permutation);
           permutation.pop_back();
           bag.insert(n,c);
           p++;
       }
    }
}

void printPermutations(list<char>& elements) {
    list<char> bag = elements;
    list<char> permutation;
    permute(bag, permutation);
}

int main() {
    const char elts[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    list<char> elements;
    for (int i = 0; i < 6; i++) elements.push_back(elts[i]);
    printPermutations(elements);
    return EXIT_SUCCESS;
}



