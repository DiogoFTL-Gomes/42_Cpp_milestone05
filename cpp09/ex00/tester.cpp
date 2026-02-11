#include <string>
#include <iostream>
#include <fstream>
#include <map>

int	main(void){
	std::map<std::string, int> test;

	test.insert(std::make_pair("2014-09-24", 2026-2014));
	test.insert(std::make_pair("1981-06-21", 2026-1981));
	test.insert(std::make_pair("1977-07-05", 2026-1977));

	typedef std::map<std::string, int>::iterator ItMapStrInt;

	ItMapStrInt it = test.begin();

	for (; it != test.end(); it++){
		std::cout << it->first << " => " << it->second << std::endl;
	}

	std::cout << test.size() << std::endl;

	it = test.find("1977-07-05");
	if (it != test.end()){
		std::cout << it->first << " => " << it->second << std::endl;
	}
	else{
		std::cout << "Unable to find entry" << std::endl;
	}

	return (0);
}