#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange(const std::string &file){
	std::ifstream dataFile(file);
	if (!dataFile.is_open())
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _baseData(other._baseData) {
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other){
		this->_baseData = other._baseData;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
}

