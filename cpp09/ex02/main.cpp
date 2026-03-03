#include <iostream>
#include <stdexcept>
#include <string>
#include "PmergeMe.hpp"

int	main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try{
		PMergeMe test(argv);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	return (0);
}