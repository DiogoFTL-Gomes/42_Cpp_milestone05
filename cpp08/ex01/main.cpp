#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

int main() {

	std::cout << "=== TEST 1: ===" << std::endl;
	try {
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: addNumber(int) Overflow ===" << std::endl;
	try {
		Span sp(2);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception &e) {
		std::cout << "Span too small exception" << std::endl;
	}

	std::cout << "\n=== TEST 3: addNumber(range) Overflow ===" << std::endl;
	try {
		Span sp(3);
		std::vector<int> v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);

		sp.addNumber(v.begin(), v.end());
	}
	catch (std::exception &e) {
		std::cout << "Span too small exception" << std::endl;
	}

	std::cout << "\n=== TEST 4: shortestSpan / longestSpan with few elements ===" << std::endl;
	try {
		Span sp(1);
		sp.addNumber(42);

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Span too small exception" << std::endl;
	}

	std::cout << "\n=== TEST 5: addNumber with range ===" << std::endl;
	try {
		Span sp(6);

		int arr[] = {5, 1, 9};
		std::list<int> lst;

		lst.push_back(20);
		lst.push_back(25);
		lst.push_back(30);

		sp.addNumber(arr, arr + 3);
		sp.addNumber(lst.begin(), lst.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: 10000 number test ===" << std::endl;
	try {
		const int SIZE = 10000;
		Span sp(SIZE);

		std::srand(std::time(NULL));
		for (int i = 0; i < SIZE; ++i)
			sp.addNumber(std::rand());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Tests complete ===" << std::endl;
	return 0;
}
