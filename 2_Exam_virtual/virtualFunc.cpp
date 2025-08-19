/*
 * virtualFunc.cpp
 *
 *  Created on: 2025. 4. 13.
 *      Author: alber
 */

#include <iostream>

using namespace std;

class Earth
	{ public: virtual void print() { cout << "Earth \n"; } };
class Continent : public Earth
	{ public: void print() { cout << "Asia \n"; } };
class Nation : public Continent
	{ public: void print() { cout << "Korea \n"; } };
class City : public Nation
	{ public: void print() { cout << "Seoul \n"; } };

int main() {
	Earth* earth = new Earth;
	Earth* asia = new Continent;
	Continent* korea = new Nation;
	Nation* seoul = new City;

	earth->print();
	asia->print();
	korea->print();
	seoul->print();

	return EXIT_SUCCESS;
}


