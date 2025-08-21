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
void convert_char(const std::string &str);
// is_char recognice when input is a,b,c,d ./Convert a
bool is_char(const std::string &str);

void convert_int(const std::string &str);

#endif