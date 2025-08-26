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

class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    static void convertChar(double value, bool impossible);
    static void convertInt(double value, bool impossible);
    static void convertFloat(double value, bool impossible, int precision);
    static void convertDouble(double value, bool impossible, int precision);

    static bool isPseudoLiteral(const std::string &literal);
    static int  detectPrecision(const std::string &literal);
};

#endif
