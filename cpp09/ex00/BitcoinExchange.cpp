#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    
    return *this;
}

void BitcoinExchange::takeValue()
{
    std::ifstream readFile(btc.fileName);
    if (!readFile.is_open())
	{
        std::cerr << "could not open file." << std::endl;
        exit(2);
	}
}