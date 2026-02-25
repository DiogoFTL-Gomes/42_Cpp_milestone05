#include <iostream>
#include <stdexcept>
#include "RPN.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Error" << std::endl;
		return (1);
	}

	RPN	solve;

	try{
		solve.thinkMath(argv[1]);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}