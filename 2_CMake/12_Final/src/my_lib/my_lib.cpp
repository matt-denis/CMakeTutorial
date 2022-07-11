#include <iostream>
#include "my_lib.h"

void print_hello_world()
{
    std::cout << "Hello World!" << std::endl;
}

unsigned int Factorial( unsigned int number )
{
    return number <= 1 ? 1 : Factorial(number-1)*number;
}
