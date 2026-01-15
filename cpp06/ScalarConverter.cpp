#include "ScalarConverter.hpp"
#include <cctype>

void	ScalarConverter::convert(const std::string &literal){
	if (isPseudoNumb(literal)){

	}
	else if (isChar(literal)){

	}
	else if (isNumber(literal)){

	}
	else {

	}
}

bool	ScalarConverter::isPseudoNumb(const std::string &literal){
	if (literal == "nan" || literal == "nan" 
		|| literal == "inf" || literal == "+inf" || literal == "-inf" 
		|| literal == "inff" || literal == "+inff" || literal == "-inff"){
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isChar(const std::string &literal){
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0]))){
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isNumber(const std::string &literal){
	size_t	size = literal.length();
	size_t	i = 0;
	bool	dot = false;
	bool	digit = false;

	if (literal.empty()){
		return (false);
	}

	if  (literal[i] == '+' || literal[i] == '-'){
		i++;
	}

	for (; i < size; i++){
		unsigned char c = static_cast<unsigned char>(literal[i]);

		if (c == '.'){
			if (dot){
				return (false);
			}
			dot = true;
			continue;
		}
		if (!std::isdigit(c))
			return (false);
		digit = true;
	}
	return (true);
}