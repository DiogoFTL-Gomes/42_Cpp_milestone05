#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <climits>
#include <sstream>


PMergeMe::PMergeMe(char **lines){
	importValues(lines);

	this->_deq = std::deque<int>(this->_vec.begin(), this->_vec.end());
	std::cout << "Before: ";
	printVec();
	std::cout << std::endl;
	printDeq();
	std::cout << std::endl;

	sortVec(this->_vec);
	sortDeq(this->_deq);

	std::cout << "After: ";
	std::cout << std::endl;

}

PMergeMe::PMergeMe(const PMergeMe &other) : _vec(other._vec), _deq(other._deq) {
}

PMergeMe &	PMergeMe::operator=(const PMergeMe &other){
	if (this != &other){
		this->_vec = other._vec;
		this->_deq = other._deq;
	}
	return (*this);
}

PMergeMe::~PMergeMe(){
	std::cout << "Bye Bye" << std::endl;
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

void	PMergeMe::sortVec(std::vector<int> &mainChain){
	if (mainChain.size() < 2){
		return;
	}
	int	leftOver;
	std::vector<int>	stayV;
	std::vector<int>	mainV;
	for (size_t i = 0; i < mainChain.size();){
		if (i + 1 == mainChain.size()){
			leftOver = mainChain[i];
			break;
		}
		compareSendValues(stayV, mainV, mainChain[i], mainChain[i + 1]);
		i += 2;
	}

	if (mainV.size() > 1){
		sortVec(mainV);
	}

	std::vector<size_t> jacobsthal = generateJacobsthalOrder(stayV.size());

	for (size_t k = 0; k < jacobsthal.size(); ++k){
		size_t idx = jacobsthal[k];
		int value = stayV[idx];

		size_t pos = binarySearch(mainV, value);
		mainV.insert(mainV.begin() + pos, value);
	}
}

size_t	PMergeMe::binarySearch(std::vector<int>	&mainV, int value){
	size_t	left = 0;
	size_t	right = mainV.size();
	while (left < right){
		size_t	mid = left + (right - left) / 2;

		if (value > mainV[mid]){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return (left);
}

std::vector<size_t>	PMergeMe::generateJacobsthalOrder(size_t size){
	std::vector<size_t>	jacobsthal;

	size_t	prev2 = 0;
	size_t	prev1 = 1;
	while (true){
		size_t	current = prev1 + 2 * prev2;
		bool	isBigger = false;

		if (current > size){
			current = size;
			isBigger = true;
		}

		for (size_t i = current; i > prev1; --i){
			jacobsthal.push_back(i - 1);
		}

		if (isBigger == true){
			break;
		}
		prev2 = prev1;
		prev1 = current;
	}

	return (jacobsthal);
}

void	PMergeMe::compareSendValues(std::vector<int> &stayV, std::vector<int> &mainV, int a, int b){
	if (a < b){
		stayV.push_back(a);
		mainV.push_back(b);
	}
	else{
		stayV.push_back(b);
		mainV.push_back(a);
	}
}

void	PMergeMe::printVec(){
	for (size_t i = 0; i < this->_vec.size(); ++i){
		std::cout << this->_vec[i] << " ";
	}
}

void	PMergeMe::printDeq(){
	for (size_t i = 0; i < this->_deq.size(); ++i){
		std::cout << this->_deq[i] << " ";
	}
}
