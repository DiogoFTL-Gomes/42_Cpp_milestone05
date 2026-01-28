#ifndef ITER_H
# define ITER_H

#include <cstdlib>
#include <iostream>

template <typename T>
void	iter(T *ptr, const size_t len, void (*f)(T &)){
	std::cout << reinterpret_cast<void*>(f) << std::endl;
	for (size_t i = 0; i < len; i++){
		f(ptr[i]);
	}
	std::cout << std::endl;
}

template <typename T>
void	iter(const T *ptr, const size_t len, void (*f)(const T &)){
	std::cout << reinterpret_cast<void*>(f) << std::endl;
	for (size_t i = 0; i < len; i++){
		f(ptr[i]);
	}
	std::cout << std::endl;
}

#endif