#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <ctime>

BitcoinExchange::BitcoinExchange(){
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()){
		std::cerr << "Error: Could not open file: \"data.csv\"" << std::endl;
		exit (1);
	}
	std::string	dataString;
	std::getline(dataFile, dataString);
	if (dataString != "date,exchange_rate"){
		throw std::runtime_error("Error: File: \"data.csv\" has incorrect header");
	}
	while (std::getline(dataFile, dataString)){
		size_t	pos = dataString.find(',');
		if (pos == std::string::npos){
			throw std::runtime_error("Error: File: \"data.csv\" has missing/unformatted data: " + dataString);
		}
		std::string date = dataString.substr(0, pos);
		float value = std::atof((dataString.substr(pos + 1)).c_str());
		_baseData[date] = value;
	}
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

void	BitcoinExchange::processInput(const std::string &input) const{
	std::ifstream inputFile(input.c_str());
	if (!inputFile.is_open()){
		std::cerr << "Error: Could not open file: \"" << input << "\"" << std::endl;
		exit (1);
	}
	std::string	inputString;
	std::getline(inputFile, inputString);
	if (inputString != "date | value"){
		throw std::runtime_error("Error: File: \"" + input + "\" has incorrect header");
	}
}
