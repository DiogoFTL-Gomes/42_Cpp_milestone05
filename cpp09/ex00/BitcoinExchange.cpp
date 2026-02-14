#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>

BitcoinExchange::BitcoinExchange(){
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()){
		throw std::runtime_error("Error: Could not open file: \"data.csv\"");
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
		_baseData.insert(std::make_pair(date, value));
	}
	dataFile.close();
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

//Process the input file and outputs the results
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

	while (std::getline(inputFile, inputString)){
		size_t pos = inputString.find(" | ");
		if (pos == std::string::npos){
			std::cout << "Error: Bad format => " << inputString << std::endl;
			continue;
		}
		std::string	date = inputString.substr(0, pos);
		if (!this->validateDate(date)){
			continue;
		}
		std::string	value = inputString.substr(pos + 3);
		if (!this->validateValue(value)){
			continue;
		}
		float	val = std::atof(value.c_str());
		Const_MapIter it = _baseData.lower_bound(date);
		if (it == _baseData.end()){
			--it;
		}
		else if (it->first != date){
			if (it == _baseData.begin()){
				std::cout << "Error: No data for this date => " << date << std::endl;
				continue;
			}
			--it;
		}
		std::cout << date << " => " << val << " = " << val * it->second << std::endl;
	}
	inputFile.close();
}

//Checks if the date is valid
bool	BitcoinExchange::validateDate(const std::string &date) const{
	if (date.size() != 10){
		std::cout << "Error: Invalid date size => " << date << std::endl;
		return false;
	}

	if (date[4] != '-' || date[7] != '-'){
		std::cout << "Error: Invalid date format => " << date << std::endl;
		return false;
	}

	for (int i = 0; i < 10; ++i){
		if (i == 4 || i == 7){
			continue;
		}
		if (!std::isdigit(date[i])){
			std::cout << "Error: Date must be digits => " << date << std::endl;
			return false;
		}
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12){
		std::cout << "Error: Invalid month value => " << date << std::endl;
		return false;
	}

	int	daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	bool	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (leap){
		daysInMonth[1] = 29;
	}

	if (day > daysInMonth[month - 1] || day < 1){
		std::cout << "Error: Day is invalid => " << date << std::endl;
		return false;
	}

	return true;
}

//Checks if the value is valid
bool	BitcoinExchange::validateValue(const std::string &value) const{
	bool	dotFound = false;
	bool	digitFound = false;
	size_t i = 0;

	if (value.empty())
	{
		std::cout << "Error: Invalid value => " << value << std::endl;
		return false;
	}

	if (value[i] == '-'){
		std::cout << "Error: Not a positive number => " << value << std::endl;
		return false;
	}
	if (value[i] == '+'){
		++i;
	}
	for (; i < value.size(); ++i){
		if (value[i] == '.'){
			if (dotFound){
				std::cout << "Error: Invalid value => " << value << std::endl;
				return false;
			}
			else{
				dotFound = true;
				continue;
			}
		}

		if (!std::isdigit(static_cast<unsigned char>(value[i]))){
			std::cout << "Error: Invalid value => " << value << std::endl;
			return false;
		}

		digitFound = true;
	}

	if (!digitFound){
		std::cout << "Error: Invalid value => " << value << std::endl;
		return false;
	}
	float	val = std::atof(value.c_str());
	if (val > 1000.0f){
		std::cout << "Error: Too large a number => " << val << std::endl;
		return false;
	}

	return true;
}
