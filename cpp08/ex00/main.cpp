#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

template <typename T>
void	testTContainer(const T &container, int find){
	typename T::const_iterator	it = easyfind(container, find);

	if (it != container.end()){
		std::cout << "found " << *it << " in position " << std::distance(container.begin(), it) << std::endl;
	}
	else{
		std::cout << "Value " << find << " not found." << std::endl;
	}
}

int	main(void){
	std::cout << "\n===Testing VECTOR===" << std::endl;
	std::vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(42);
	v.push_back(8);

	testTContainer(v, 42);
	testTContainer(v, 24);
	
	std::cout << "\n===Testing LIST===" << std::endl;
	std::vector<int> l;
	l.push_back(62);
	l.push_back(42);
	l.push_back(51);
	l.push_back(45);
	l.push_back(38);

	testTContainer(l, 42);
	testTContainer(l, 24);

	std::cout << "\n===Testing DEQUE===" << std::endl;
	std::deque<int> d;
	d.push_back(162);
	d.push_back(251);
	d.push_back(345);
	d.push_back(438);
	d.push_back(42);

	testTContainer(d, 42);
	testTContainer(d, 24);

	return (0);
}