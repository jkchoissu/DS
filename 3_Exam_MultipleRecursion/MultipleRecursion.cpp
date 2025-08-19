/*
 * MultipleRecursion.cpp
 *
 *  Created on: 2025. 3. 18.
 *      Author: albert
 */

#include <iostream>
void fun(int n) {
	if (n > 3) {
		fun(n-1);
		fun(n-2);
		fun(n-3);
	}
	std::cout << n << " ";
}

void morefun(int n) {
	std::cout << n << " ";
	if (n > 3) {
		morefun(n-1);
		morefun(n-2);
		morefun(n-3);
	}
}

int main() {
	std::cout << "fun(6)" << std::endl;
	fun(6);
	std::cout << std::endl;
	std::cout << "morefun(6)" << std::endl;
	morefun(6);

	return 0;
}
