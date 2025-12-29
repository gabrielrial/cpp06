#include "Serializer.hpp"

int main()
{
	Data data;
	data.name = "Gabriel";
	data.age = 31;

	std::cout << "Original Data:" << std::endl;
	std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

	std::cout << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << std::endl;

	uintptr_t address = Serializer::serialize(&data);

	std::cout << "Memory addres of data: \n"
			  << &data << std::endl;
	std::cout << "Value of addres: \n"
			  << address << std::endl;

	std::cout << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << std::endl;

	Data *ptr = Serializer::deserialize(address);

	std::cout << "Memory addres of data: \n"
			  << ptr << std::endl;

	std::cout << std::endl;
	std::cout << "=====================================================" << std::endl;
	std::cout << std::endl;

	std::cout << "After deserialization:" << std::endl;
	std::cout << "Name: " << ptr->name << ", Age: " << ptr->age << std::endl;

	return 0;
}
