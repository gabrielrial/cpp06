#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *Base::generate(void)
{
	std::srand(std::time(NULL));
	int r = std::rand() % 3;

	switch (r)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void Base::identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &)
	{
	}

	std::cout << "Unknown" << std::endl;
}