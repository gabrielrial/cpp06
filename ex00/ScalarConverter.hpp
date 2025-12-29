#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <limits.h>


enum Type {
    PSEUDO_LITERAL = 0,
    CHAR = 1,
    INT = 2,
	FLOAT = 3,
	DOUBLE = 4
};

class ScalarConverter
{
public:
	static void convert(const char *arg);

	~ScalarConverter();
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
};

void convertChar(std::string arg);
void convertInt(std::string arg);
void convertFloat(std::string arg);
void convertDouble(std::string arg);

bool isChar(const char *arg);
bool isInt(const char *arg);

void printPseudo(const std::string &str);

bool isPseudoLiteral(const char *arg);
int detectPrecision(const std::string &literal);

#endif
