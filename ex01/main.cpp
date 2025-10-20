#include "Serializer.hpp"

int main()
{
	Data data;
	data.name = "Gabriel";
	data.age = 31;
	Data &ptr_data = data;

	std::cout << "Original Data:" << std::endl;
	std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

	std::cout << std::endl;

	std::cout << "Memory addres data: \n" << &data << std::endl;
	std::cout << "Memory addres ptr_data: \n" << &ptr_data << std::endl;

	std::cout << std::endl;

	uintptr_t address = Serializer::serialize(&data);
	std::cout << "Memory addres ptr_address: \n" << &address << std::endl;
	std::cout << "Memory addres ptr_address: \n" << address << std::endl;

	std::cout << std::endl;
	
	Data *ptr = Serializer::deserialize(address);

	std::cout << "\nAfter deserialization:" << std::endl;
	std::cout << "Name: " << ptr->name << ", Age: " << ptr->age << std::endl;

	return 0;
}
