#include <iostream>
#include "iter.hpp"

// modifica
void inc(int &x) {
	x++;
}

// só lê
void printConst(const int &x) {
	std::cout << x << " ";
}

// lê (sem const)
void print(int &x) {
	std::cout << x << " ";
}

// versão template
template <typename T>
void printT(T &x) {
	std::cout << x << " ";
}

template <typename T>
void printConstT(const T &x) {
	std::cout << x << " ";
}

int main() {
	int a[] = {1, 2, 3};
	const int b[] = {4, 5, 6};

	std::cout << "print() addr:	";
	iter(a, 3, print);
	std::cout << "inc() addr:	";
	iter(a, 3, inc);
	std::cout << "printConst() addr:	";
	iter(a, 3, printConst);
	std::cout << "printT() addr:	";
	iter(a, 3, printT);
	std::cout << "printConstT() addr:	";
	iter(a, 3, printConstT);

	std::cout << "printConst() addr:	";
	iter(b, 3, printConst);
	std::cout << "printT() addr:	";
	iter(b, 3, printT);
	std::cout << "printConstT() addr:	";
	iter(b, 3, printConstT);
	return 0;
}
