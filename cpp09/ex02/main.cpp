#include <iostream>
#include <stdexcept>
#include <string>

int	main(int argc, char **argv){
	if (argc < 2){
		std::cout << "Error" << std::endl;
		return (1);
	}

	std::string param = "";
	for (int i = 1; argv[i]; ++i){
		param = param + " " + argv[i];
	}

	std::cout << param << std::endl;
	return (0);
}