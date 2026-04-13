#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <ctime>
#include <iomanip>

PMergeMe::PMergeMe(char **lines){
	this->importValues(lines);
	this->_deq = std::deque<int>(this->_vec.begin(), this->_vec.end());

	std::cout << "Before: ";
	this->printPMergeMe(this->_vec);
	std::cout << std::endl;


	clock_t start = std::clock();
	this->sortPMergeMe(this->_vec);
	clock_t end = std::clock();
	this->_vecTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

	start = std::clock();
	this->sortPMergeMe(this->_deq);
	end = std::clock();
	this->_deqTime = (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "\nAfter: ";
	printPMergeMe(this->_deq);
	std::cout << std::endl;

	std::cout << "\nTime to process a range of "
		  << _vec.size()
		  << " elements with std::vector : "
		  << this->_vecTime << " us"
		  << std::endl;
	std::cout << "\nTime to process a range of "
		  << _deq.size()
		  << " elements with std::deque : "
		  << this->_deqTime << " us"
		  << std::endl;
}

PMergeMe::PMergeMe(const PMergeMe &other) : _vec(other._vec), _deq(other._deq) {
}

PMergeMe	&PMergeMe::operator=(const PMergeMe &other){
	if (this != &other){
		this->_vec = other._vec;
		this->_deq = other._deq;
	}
	return (*this);
}

PMergeMe::~PMergeMe(){
}

void	PMergeMe::importValues(char **lines){
	for (int i = 1; lines[i]; ++i)
	{
		std::istringstream iss(lines[i]);
		std::string token;

		while (iss >> token)
		{
			char* end;
			long val = std::strtol(token.c_str(), &end, 10);

			if (*end != '\0'){
				throw std::runtime_error("Error: invalid char");
			}
			if (val < 0 ){
				throw std::runtime_error("Error: negative value");
			}
			if (val > INT_MAX){
				throw std::runtime_error("Error: value too big");
			}

			_vec.push_back(static_cast<int>(val));
		}
	}
}

void	PMergeMe::sortPMergeMe(std::vector<int> &mainChain){
	if (mainChain.size() < 2){
		return;
	}
	int	leftOver = -1;
	std::vector<int>	lesserV;
	std::vector<int>	biggerV;
	for (size_t i = 0; i < mainChain.size();){
		if (i + 1 == mainChain.size()){
			leftOver = mainChain[i];
			break;
		}
		compareSendValues(lesserV, biggerV, mainChain[i], mainChain[i + 1]);
		i += 2;
	}

	if (biggerV.size() > 1){
		sortPMergeMe(biggerV);
	}

	std::vector<size_t> jacobsthal = generateJacobsthalOrder(lesserV.size());

	for (size_t k = 0; k < jacobsthal.size(); ++k){
		size_t idx = jacobsthal[k];
		int value = lesserV[idx];

		size_t pos = binarySearch(biggerV, value);
		biggerV.insert(biggerV.begin() + pos, value);
	}
	if (leftOver != -1){
		size_t pos = binarySearch(biggerV, leftOver);
		biggerV.insert(biggerV.begin() + pos, leftOver);
	}
	mainChain = biggerV;
}

void	PMergeMe::sortPMergeMe(std::deque<int> &mainChain){
	if (mainChain.size() < 2){
		return;
	}
	int	leftOver = -1;
	std::deque<int>	lesserV;
	std::deque<int>	biggerV;
	for (size_t i = 0; i < mainChain.size();){
		if (i + 1 == mainChain.size()){
			leftOver = mainChain[i];
			break;
		}
		compareSendValues(lesserV, biggerV, mainChain[i], mainChain[i + 1]);
		i += 2;
	}

	if (biggerV.size() > 1){
		sortPMergeMe(biggerV);
	}

	std::vector<size_t> jacobsthal = generateJacobsthalOrder(lesserV.size());

	for (size_t k = 0; k < jacobsthal.size(); ++k){
		size_t idx = jacobsthal[k];
		int value = lesserV[idx];

		size_t pos = binarySearch(biggerV, value);
		biggerV.insert(biggerV.begin() + pos, value);
	}
	if (leftOver != -1){
		size_t pos = binarySearch(biggerV, leftOver);
		biggerV.insert(biggerV.begin() + pos, leftOver);
	}
	mainChain = biggerV;
}

size_t	PMergeMe::binarySearch(std::vector<int>	&biggerV, int value){
	size_t	left = 0;
	size_t	right = biggerV.size();
	while (left < right){
		size_t	mid = left + (right - left) / 2;

		if (value > biggerV[mid]){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return (left);
}

size_t	PMergeMe::binarySearch(std::deque<int>	&biggerV, int value){
	size_t	left = 0;
	size_t	right = biggerV.size();
	while (left < right){
		size_t	mid = left + (right - left) / 2;

		if (value > biggerV[mid]){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return (left);
}

std::vector<size_t> PMergeMe::generateJacobsthalOrder(size_t size){
	std::vector<size_t> order;

	if (size == 0)
		return order;

	order.push_back(0);

	size_t prev2 = 0;
	size_t prev1 = 1;

	while (true)
	{
		size_t current = prev1 + 2 * prev2;

		if (current > size){
			current = size;
		}

		for (size_t i = current; i > prev1; --i){
			order.push_back(i - 1);
		}

		if (current == size)
			break;

		prev2 = prev1;
		prev1 = current;
	}

	return order;
}

void	PMergeMe::compareSendValues(std::vector<int> &lesserV, std::vector<int> &biggerV, int a, int b){
	if (a < b){
		lesserV.push_back(a);
		biggerV.push_back(b);
	}
	else{
		lesserV.push_back(b);
		biggerV.push_back(a);
	}
}

void	PMergeMe::compareSendValues(std::deque<int> &lesserV, std::deque<int> &biggerV, int a, int b){
	if (a < b){
		lesserV.push_back(a);
		biggerV.push_back(b);
	}
	else{
		lesserV.push_back(b);
		biggerV.push_back(a);
	}
}

void	PMergeMe::printPMergeMe(std::vector<int> &vecMain){
	for (size_t i = 0; i < vecMain.size(); ++i){
		std::cout << vecMain[i] << " ";
	}
}

void	PMergeMe::printPMergeMe(std::deque<int> &vecMain){
	for (size_t i = 0; i < vecMain.size(); ++i){
		std::cout << vecMain[i] << " ";
	}
}
