#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
	convert_char(str);
	convert_int(str);
}

void convert_char(const std::string &str)
{
	std::cout << "char: ";

	int i = atoi(str.c_str());

	if (is_char(str))
	{
		std::cout << "\'" << str << "\'";
	}
	else if ((i >= 0 && i < 32) || i == 127)
		std::cout << "Non displayable";
	else if (i >= 32 && i <= 126)
		std::cout << "\'" << static_cast<char>(i) << "\'";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

bool is_char(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str.c_str()[0]))
		return true;
	else
		return false;
}

void convert_int(const std::string &str)
{
	std::cout << "int: ";
	int i = atoi(str.c_str());

	if (str.length() != 1 && is_char(str))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;
}