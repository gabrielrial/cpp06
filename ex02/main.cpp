#include "Identify.hpp"

int main(void)
{
	Base *ptr = generate();
	
	std::cout << "Identify with pointer: ";
	identify(ptr);

	std::cout << "Identify with reference: ";
	identify(*ptr);

	delete ptr;
	return 0;
}
