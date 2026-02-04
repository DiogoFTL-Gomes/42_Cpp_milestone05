#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

void	ScalarConverter::convert(const std::string &literal){
	if (isPseudoLiteral(literal)){
		outputPseudoLiteral(literal);
	}
	else if (isChar(literal)){
		outputChar(literal);
	}
	else if (isNumber(literal)){
		outputNumbers(literal);
	}
	else {
		std::cout << "char:	impossible\n";
		std::cout << "int:	impossible\n";
		std::cout << "float:	impossible\n";
		std::cout << "double:	impossible" << std::endl;
	}
}

bool	ScalarConverter::isPseudoLiteral(const std::string &literal){
	if (literal == "nan" || literal == "nanf" 
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
	size_t	i = 0;
	bool	dot = false;
	bool	digit_before = false;
	bool	digit_after = false;

	if (literal.empty()){
		return (false);
	}
	size_t	size = literal.length();

	if  (literal[i] == '+' || literal[i] == '-'){
		i++;
	}

	for (; i < size; i++){
		unsigned char	c = static_cast<unsigned char>(literal[i]);

		if (c == '.'){
			if (dot || !digit_before){
				return (false);
			}
			dot = true;
			continue;
		}

		if (i == size - 1 && dot && digit_after && c == 'f'){
			return (true);
		}

		if (!std::isdigit(c)){
			return (false);
		}
		
		if (!dot){
			digit_before = true;
		}
		else{
			digit_after = true;
		}
	}
	if (dot)
		return (digit_before && digit_after);
	return (digit_before);
}


void	ScalarConverter::outputPseudoLiteral(const std::string &literal){
	float	f;
	double	d;

	std::cout << "char:	impossible\n";
	std::cout << "int:	impossible\n";
	if  (literal[0] == 'n'){
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
	}
	else{
		f = std::numeric_limits<float>::infinity();
		d = std::numeric_limits<double>::infinity();
		if (literal[0] == '-'){
			f = -f;
			d = -d;
		}
	}
	std::cout << "float:	" << f << "f\n";
	std::cout << "double:	" << d  << std::endl;
}

void	ScalarConverter::outputChar(const std::string &literal){
	char	c = literal[0];
	if (std::isprint(static_cast<unsigned char>(c))){
		std::cout << "char:	" << c << "\n";
	}
	else{
		std::cout << "char:	Non displayable\n";
	}

	std::cout << "int:	" << static_cast<int>(c) << "\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float:	" << static_cast<float>(c) << "f\n";
	std::cout << "double:	" << static_cast<double>(c) << "\n";
}

void	ScalarConverter::outputNumbers(const std::string &literal){
	char	c;
	int		i;
	float	f;
	double	d;

	d = std::strtod(literal.c_str(), NULL);
	f = static_cast<float>(d);
	if (d == static_cast<long>(d) && d >= std::numeric_limits<unsigned char>::min() && d <= std::numeric_limits<char>::max()){
		c = static_cast<char>(d);
		if (std::isprint(static_cast<unsigned char>(c))){
			std::cout << "char:	" << c << "\n";
		}
		else{
			std::cout << "char:	Non displayable\n";
		}
	}
	else{
		std::cout << "char:	impossible\n";
	}

	if (d == static_cast<long>(d) && d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()){
		i = static_cast<int>(d);
		std::cout << "int:	" << i << "\n";
	}
	else{
		std::cout << "int:	impossible\n";
	}
	
	if (d == static_cast<long>(d)){
		std::cout << std::fixed << std::setprecision(1);
	}
	std::cout << "float:	" << f << "f\n";
	std::cout << "double:	" << d << std::endl;
}