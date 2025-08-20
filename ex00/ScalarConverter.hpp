#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class ScalarConverter
{
public:
	static void convert(const std::string &str);

private:
};
const char *check_char(const std::string &str);

#endif