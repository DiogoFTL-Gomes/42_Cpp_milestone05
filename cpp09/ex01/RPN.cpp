#include "RPN.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>



RPN::RPN(){
}

RPN::RPN(const RPN &other) : _operands(other._operands) {
}

RPN	&RPN::operator=(const RPN &other){
	if (this != &other){
		this->_operands = other._operands;
	}
	return (*this);
}

RPN::~RPN(){
}

void	RPN::thinkMath(const std::string &line) {
	validateLine(line);

	std::string operators = "/+-*";
	for (size_t i = 0; i < line.size(); ++i){
		unsigned char c = static_cast<unsigned char>(line[i]);
		if (std::isdigit(c)){
			this->_operands.push(std::atoi(line.substr(i, 1).c_str()));
			continue;
		}
		if (operators.find(c) != std::string::npos){
			if (this->_operands.size() < 2){
				throw std::runtime_error("Error");
			}
			RPN::doMath(c);
			continue;
		}
		if (c == ' '){
			continue;
		}
	}
	if (this->_operands.size() != 1){
		throw std::runtime_error("Error");
	}
	std::cout << this->_operands.top() << std::endl;
}

void	RPN::doMath(const unsigned char c){
	int	b = this->_operands.top();
	this->_operands.pop();
	int a = this->_operands.top();
	this->_operands.pop();
	if (c == '/'){
		if (b == 0){
			throw std::runtime_error("Error");
		}
		this->_operands.push(a / b);
	}
	if (c == '*'){
		this->_operands.push(a * b);
	}
	if (c == '-'){
		this->_operands.push(a - b);
	}
	if (c == '+'){
		this->_operands.push(a + b);
	}
}

void	RPN::validateLine(const std::string &line) const {
	if (line.empty())
		throw std::runtime_error("Error");

	std::istringstream iss(line);
	std::string token;

	while (iss >> token)
	{
		if (token.length() != 1)
			throw std::runtime_error("Error");

		char c = token[0];

		if (std::isdigit(c))
			continue;

		if (std::string("+-*/").find(c) != std::string::npos)
			continue;

		throw std::runtime_error("Error");
	}
}