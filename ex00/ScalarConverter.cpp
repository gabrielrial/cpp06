#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
	// Caso: pseudoliterales
	if (isPseudoLiteral(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (literal == "nan" || literal == "+inf" || literal == "-inf")
		{
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		else
		{
			std::string d = literal.substr(0, literal.size() - 1);
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << d << std::endl;
		}
		return;
	}

	// Intentar convertir el literal a double
	char *end;
	double value = std::strtod(literal.c_str(), &end);
	bool impossible = (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'));

	int precision = detectPrecision(literal);

	convertChar(value, impossible);
	convertInt(value, impossible);
	convertFloat(value, impossible, precision);
	convertDouble(value, impossible, precision);
}

// ----------------------- Conversiones -----------------------------

void ScalarConverter::convertChar(double value, bool impossible)
{
	std::cout << "char: ";
	if (impossible || value < 0 || value > 127 || std::isnan(value))
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::convertInt(double value, bool impossible)
{
	std::cout << "int: ";
	if (impossible || value < INT_MIN || value > INT_MAX || std::isnan(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::convertFloat(double value, bool impossible, int precision)
{
	std::cout << "float: ";
	if (impossible || value < -FLT_MAX || value > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
	{
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << f << "f" << std::endl;
	}
}

void ScalarConverter::convertDouble(double value, bool impossible, int precision)
{
	std::cout << "double: ";
	if (impossible)
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << value << std::endl;
	}
}

// ----------------------- Helpers -----------------------------

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" ||
			literal == "+inf" || literal == "-inf" ||
			literal == "+inff" || literal == "-inff");
}

// Detectar cuántos decimales imprimir
int ScalarConverter::detectPrecision(const std::string &literal)
{
	size_t dot = literal.find('.');
	if (dot == std::string::npos)
		return 1; // no hay punto → imprimir ".0"

	size_t end = literal.find_first_not_of("0123456789", dot + 1);
	if (end == std::string::npos)
		end = literal.size();

	int precision = static_cast<int>(end - dot - 1);
	return (precision > 0 ? precision : 1);
}
