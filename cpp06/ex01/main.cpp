#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void){
	Data test;

	uintptr_t raw = Serializer::serialize(&test);
	Data	*ptr = Serializer::deserialize(raw);

	std::cout << "Data addr:	" << &test 
	<< "\nPointer addr:	" << ptr << std::endl;
	if (&test == ptr){
		std::cout << "** Values are equal **" << std::endl;
		std::cout << "test id:	" << test.id << "\nptr id:		" << ptr->id << std::endl;
		std::cout << "test value:	" << test.value << "\nptr value:	" << ptr->value << std::endl;
	}
	else{
		std::cout << "** Values are different **" << std::endl;
	}

	return (0);
}