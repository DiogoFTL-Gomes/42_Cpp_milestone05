#include "Base.hpp"
#include "identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; i++)
    {
        Base *p = generate();

        std::cout << "Pointer identify: ";
        identify(p);

        std::cout << "Reference identify: ";
        identify(*p);

        delete p;
        std::cout << "-----" << std::endl;
    }

    return 0;
}