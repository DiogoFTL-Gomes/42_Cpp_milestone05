#include <iostream>
#include <cstdlib> // added
#include <ctime> //added
#include "Array.hpp"

#define MAX_VAL 10 //750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 256;//smaller numbers
		numbers[i] = value;
		mirror[i] = value;
		std::cout << numbers[i] << " -- " << mirror[i] << std::endl;//visualize
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++){//vizualize
			std::cout << tmp[i] << " -- " << test[i] << std::endl;//vizualize
		}//vizualize
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << " in pos:" << i << " is now ";//vizualize
		numbers[i] = rand() % 256;//smaller numbers
		std::cout << numbers[i] << std::endl;//vizualize
	}
	delete [] mirror;//
	return 0;
}