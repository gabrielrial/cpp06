#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
	const char *c;
	// int			i;
	// float	f;
	// double	d;

	c = check_char(str);
	std::cout << "Result: " << c << std::endl;
}

const char *check_char(const std::string &str)
{
	static char result[2];
	result[1] = '\0';

	int i = atoi(str.c_str());
	if (i >= 32 && i <= 126)
	{
		result[0] = static_cast<char>(i);
		return result;
	}
	if ((i >= 0 && i < 32) || i == 127)
		return "Non displayable";

	return "impossible";
}