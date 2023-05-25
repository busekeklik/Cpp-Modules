#include "Casting.hpp"

Casting::Casting()
{
}

Casting::~Casting()
{
}

Casting::Casting(Casting const &org)
{
	*this = org;
}

Casting &Casting::operator=(Casting const &other)
{
	if (this == &other) {
		*this = other;
	}
	return *this;
}

bool Casting::isStringEqual(const std::string& str)
{
    const std::string arr[] = {
        "nan",
        "nanf",
        "+inf",
        "-inf",
        "+inff",
        "-inff"
    };

    const int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
	{
        if (str == arr[i])
    	    return true;
	}
    return false;
}

void Casting::checkValue(const std::string &str)
{
	
	if (!isStringEqual(str) && str.length() != 1)
	{
		if (str.find_first_not_of("0123456789.f-+") != std::string::npos)
		{
			std::cerr << "The value you entered is not something I can convert." << std::endl;
			exit(2);
		}
	}
	if(str.find(".") != std::string::npos)
	{
		size_t d = str.find(".");
		if (d == 0 || d != str.find_last_of(".") || d == str.length() - 1)
		{
			std::cerr << ("The use of the dot in the entered value is incorrect.") << std::endl;
			exit(3);
		}
	}
	if (str.find("f") != std::string::npos)
	{
		size_t f = str.find("f");
		if ((f == 0 || f != str.find_last_of("f") || str[f-1] == '.') && str.length() != 1)
		{
			std::cerr << ("The use of the f in the entered value is incorrect.") << std::endl;
			exit(4);
		}
	}
	if ((str.find("+") != std::string::npos) || (str.find("-") != std::string::npos))
	{
		if(str.length() == 1 && (str[1] == '+' || str[1] == '-'))
		{
			std::cerr << ("Please don't just enter + or - also enter numbers.") << std::endl;
			exit(5);
		}
		if (str.find("-") != str.find_last_of("-") || str.find("+") != str.find_last_of("+"))
		{
			std::cerr << ("You should not use more than one + or - sign.") << std::endl;
			exit(6);
		}
		int a = str.find("-");
		if(a == 0 || a == 1)
		{	
			if (str[a + 1] == '+' || str[a - 1] == '+')
			{
				std::cerr << ("You should not use like that.") << std::endl;
				exit(7);
			}
		}
	}
}

void Casting::convert(const std::string &str)
{
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}

void Casting::toChar(const std::string &str)
{
	char ch = 0;
	int asch = 0;
	int a = 0;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "char : impossible" << std::endl;
		return ;
	}
	try {
		ch = std::stoi(str); 
		a = std::stoi(str);
	}
	catch(std::exception& e)
	{
		if ((str.length() == 1) && isprint(str[0]))
		{
			ch = str[0];
			asch = ch;
		}
	}
	if (((a >= 32 && a <= 127) && isprint(ch)) || (asch >= 32 && asch <= 127))
		std::cout << "char : " << ch << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
}

void Casting::toInt(const std::string &str)
{
	int nb;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "int : impossible" << std::endl;
		return ;
	}
	try
	{
		nb = std::stoi(str);
	}
	catch(const std::exception& e)
	{
		if(str.length() == 1 && isprint(str[0])){
			std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
			return ;
		}
		else
			std::cout << "int : impossible" << std::endl;
	}
	std::cout << "int : " << nb << std::endl;
}

void Casting::toFloat(const std::string & str)
{
	float nb;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "float: " << str << "f" << std::endl;
		return ;
	}
	try
	{
		nb = std::stof(str);
	}
	catch(const std::exception& e)
	{
		if(str.length() == 1 && isprint(str[0])){
			std::cout << "float : " << static_cast<float>(str[0]) << ".0f" << std::endl;
			return ;
		}
	}
	nb =  std::stof(str); 
	if (nb - static_cast<int>(nb) == 0)
		std::cout << "float: " << nb << ".0f" << std::endl;
	else
		std::cout << "float: " << nb << "f" << std::endl;
}

void Casting::toDouble(const std::string & str)
{
	double nb;
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "double: " << str << std::endl;
		return ;
	}
	try
	{
		nb = std::stod(str);
	}
	catch(const std::exception& e)
	{
		if(str.length() == 1 && isprint(str[0])){
			std::cout << "double : " << static_cast<double>(str[0]) << ".0" << std::endl;
			return ;
		}
	}
	nb =  std::stof(str); 
	if (nb - static_cast<int>(nb) == 0)
		std::cout << "double: " << nb << ".0" << std::endl;
	else
		std::cout << "double: " << nb << std::endl;
}
