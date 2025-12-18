#include "ScalarConverter.hpp"

int identify_type(const char *arg)
{
	if (isPseudoLiteral(arg))
		return 0;
	if (isChar(arg))
		return 1;
	if (isInt(arg))
		return 2;
	int len = strlen(arg);
	if (len > 1 && arg[len - 1] == 'f')
		return 3;
	for (int i = 0; i < len; i++)
		if (arg[i] == '.')
			return 4;
	return -1;
}

bool isChar(const char *arg)
{
	int len = strlen(arg);

	if (len == 1 && !isdigit(arg[0]))
		return true;

	if (len == 3 && arg[0] == '\'' && arg[2] == '\'')
		return true;

	return false;
}

bool isInt(const char *arg)
{
	if (!arg || !*arg)
		return false;

	int i = 0;
	bool negative = false;

	if (arg[0] == '+')
		i++;
	else if (arg[0] == '-')
	{
		negative = true;
		i++;
	}

	if (!isdigit(arg[i]))
		return false;

	long long num = 0;

	for (; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]))
			return false;

		num = num * 10 + (arg[i] - '0');
	}
	if (!negative && num > INT_MAX)
		return false;
	if (negative && -num < INT_MIN)
		return false;

	return true;
}

void convertChar(std::string str)
{
	std::cout << "char: ";
	if (str.size() != 1 && (str[0] < 0 || str[0] > 127 || std::isnan(str[0])))
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(str[0])))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(str[0]) << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(str[0]) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void convertInt(std::string arg)
{
	std::cout << "char: ";
	int i = atoi(arg.c_str());

	if (i < 0 || i > 127 || std::isnan(i))
		std::cout << "impossible" << std::endl;
	else if (!isprint((i)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void convertFloat(std::string arg)
{
    float f = strtof(arg.c_str(), NULL);

    std::cout << "char: ";
    if (f < 0 || f > 127 || std::isnan(f))
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<unsigned char>(f)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    if (f > 2147483647.0 || f < -2147483648.0 || std::isnan(f))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    int precision = detectPrecision(arg);

    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;

	//float test = 98765432.123f;
	//std::cout << "float: " << test << std::endl;
}


void convertDouble(std::string arg)
{
	std::cout << "char: ";
	double d = atof(arg.c_str());

	if (d < 0 || d > 127 || std::isnan(d))
		std::cout << "impossible" << std::endl;
	else if (!isprint((d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d > 2147483647.0 || d < -2147483648.0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

    int precision = detectPrecision(arg);

    std::cout << std::fixed << std::setprecision(precision);
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

	std::cout << "double: " << d << std::endl;
}

bool isPseudoLiteral(const char *arg)
{
	return (strcmp(arg, "nan") == 0 ||
			strcmp(arg, "nanf") == 0 ||
			strcmp(arg, "+inf") == 0 ||
			strcmp(arg, "-inf") == 0 ||
			strcmp(arg, "+inff") == 0 ||
			strcmp(arg, "-inff") == 0);
}

int detectPrecision(const std::string &literal)
{
	size_t dot = literal.find('.');
	if (dot == std::string::npos)
		return 1;

	size_t end = literal.find_first_not_of("0123456789", dot + 1);
	if (end == std::string::npos)
		end = literal.size();

	int precision = static_cast<int>(end - dot - 1);
	return (precision > 0 ? precision : 1);
}

void ScalarConverter::convert(const char *arg)
{
	int type = identify_type(arg);

	switch (type)
	{
	case PSEUDO_LITERAL:
	{
		printPseudo(arg);
		break;
	}
	case CHAR:
	{
		convertChar(arg);
		break;
	}
	case INT:
	{
		convertInt(arg);
		break;
	}
	case FLOAT:
	{
		convertFloat(arg);

		break;
	}
	case DOUBLE:
	{
		convertDouble(arg);
		break;
	}
	default:
		std::cout << "Error: tipo desconocido" << std::endl;
	}
}

void printPseudo(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "+inf" || str == "-inf")
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else
	{
		std::string d = str.substr(0, str.size() - 1);
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	return;
}
