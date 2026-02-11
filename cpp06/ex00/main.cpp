#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, const char *argv[]){
	if (argc == 1){
		std::cout << "convert needs 1 valid parameter" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}