#include "Span.hpp"
#include <exception>
#include <algorithm>

Span::Span(unsigned int n) : _maxSize(n) {
}

Span::Span(const Span &other) : _arr(other._arr), _maxSize(other._maxSize) {
}

Span &Span::operator=(const Span &other){
	if (this != &other){
		this->_arr = other._arr;
		this->_maxSize = other._maxSize;
	}
	return (*this);
}

Span::~Span(){
}


void	Span::addNumber(int numb){
	if (this->_arr.size() >= this->_maxSize){
		throw std::exception();
	}
	this->_arr.push_back(numb);
}

int	Span::shortestSpan() const{
	if (this->_arr.size() <= 1){
		throw std::exception();
	}

	std::vector<int> temp = this->_arr;
	std::sort(temp.begin(), temp.end());

	int	minDiff = temp.back() - temp.front();

	for (size_t i = 0; i + 1 < temp.size(); i++){
		int diff = temp[i + 1] - temp[i];
		if (diff < minDiff){
			minDiff = diff;
		}
	}
	return (minDiff);
}

int	Span::longestSpan() const{
	if (this->_arr.size() <= 1){
		throw std::exception();
	}

	int min = *std::min_element(this->_arr.begin(), this->_arr.end());
	int max = *std::max_element(this->_arr.begin(), this->_arr.end());

	return (max - min);
}
