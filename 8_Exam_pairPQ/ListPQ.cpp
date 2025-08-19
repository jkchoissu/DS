
#include <iostream>
#include "ListPQ.h"

using namespace std;

struct Compare {
    bool operator()(const pair<int,char>& a, const pair<int,char>& b) const {
        return a.first < b.first;
    }
};

void PQ_R_8_6() {

    ListPriorityQueue<pair<int,char>, Compare> pq;
    pair<int,char> e;

    pq.insert({5,'a'}); pq.display();
    pq.insert({4,'b'}); pq.display();
    pq.insert({7,'i'}); pq.display();
    pq.insert({1,'d'}); pq.display();


    e = pq.min();
    cout << "RemoveMin output : " << "(" << e.first << "," << e.second << ")" << endl;
    pq.removeMin();
    pq.display();

    pq.insert({3,'j'}); pq.display();
    pq.insert({6,'c'}); pq.display();

    e = pq.min();
    cout << "RemoveMin output : " << "(" << e.first << "," << e.second << ")" << endl;
    pq.removeMin();
    pq.display();

    e = pq.min();
    cout << "RemoveMin output : " << "(" << e.first << "," << e.second << ")" << endl;
    pq.removeMin();
    pq.display();

    pq.insert({8,'g'}); pq.display();

    e = pq.min();
    cout << "RemoveMin output : " << "(" << e.first << "," << e.second << ")" << endl;
    pq.removeMin();
    pq.display();

    pq.insert({2,'h'}); pq.display();

    e = pq.min();
    cout << "RemoveMin output : " << "(" << e.first << "," << e.second << ")" << endl;
    pq.removeMin();
    pq.display();

    e = pq.min();
    cout << "RemoveMin output : " << "(" << e.first << "," << e.second << ")" << endl;
    pq.removeMin();
    pq.display();

}

int main() {

	PQ_R_8_6();

	return EXIT_SUCCESS;
}



