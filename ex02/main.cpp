#include "Base.hpp"

int main(void)
{
	Base *ptr = Base::generate();
	
	std::cout << "Identify with pointer: ";
	Base::identify(ptr);

	std::cout << "Identify with reference: ";
	Base::identify(*ptr);

	delete ptr;
	return 0;
}
