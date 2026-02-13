#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv){

	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	try	{
		BitcoinExchange bitcoinData;
		bitcoinData.processInput(argv[1]);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}