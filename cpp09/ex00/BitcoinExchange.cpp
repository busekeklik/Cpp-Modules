#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
    this->map.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{

    std::map<std::string, float>::const_iterator it;
    for (it = copy.map.begin(); it != copy.map.end(); ++it)   
    {
        std::pair<std::string, float> pair;
        pair = std::pair<std::string, float> (it->first, it->second);            
        this->map.insert(pair);
    }

    this->dataCSV = copy.dataCSV;
    this->fileName = copy.fileName;
    this->map = copy.map;
    this->valuef2 = copy.valuef2;
    this->valuef = copy.valuef;
    this->date2 = copy.date2;
    this->date = copy.date;
    return *this;
}

bool BitcoinExchange::checkDate(void)
{
    bool acceptableDate = false;
    if(date.length() != 11)
       return acceptableDate;
    int year = std::stoi(date.substr(0,4));
    int month = std::stoi(date.substr(5,7));
    int day = std::stoi(date.substr(8,10));
    if (((2009 <= year) && (year <= 2023)) && ((1 <= month) && (month <= 12)) && ((1 <= day) && (day < 32)))
    {
        if(month == 2)
        {
            if ((year %= 4) && (day <= 29))
                acceptableDate = true;
            else if(((year %= 4) && (day > 29)) ||(!(year %= 4) && (day > 28)))
                acceptableDate = false;
        }
        if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) \
            && (day <= 31))
            acceptableDate = true;
        else if((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day <= 30)
            acceptableDate = true;
        else
            acceptableDate = false;
    }
    else 
        std::cerr << "Error: invalid date" << std::endl;
    return acceptableDate;
}

bool BitcoinExchange::checkValue()
{
    bool acceptableValue = false;
    valuef = std::stof(value);
    if (valuef < 0)
        std::cerr << "Error: not a positive number." << std::endl;
    else if (valuef > 1000)
        std::cerr << "Error: too large a number." << std::endl; 
    else
        acceptableValue = true;
    return acceptableValue;
}

void BitcoinExchange::parseAndCheckContents2(std::string line)
{
    size_t a = line.find("|");

    if (a == line.length() - 1)
    {
        std::cout << "invalid" << std::endl;
        return ;
    }
    size_t i, j;
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    this->date.resize(a);
    for(i = 0; i <= a - 1; i++)
    {
        if(line[i] != '|')
            this->date[i] = line[i];
    }
    a = line.length() - a;
    this->value.resize(a);
    for(j = 0 ; i < line.length() ; j++)
    {
        value[j] = line[i];
        i++;
    }
}

void BitcoinExchange::parseContents(std::string line)
{
    size_t a = line.find(",");
    size_t i, j;
    this->date2.resize(a);
    for(i = 0; i <= a; i++)
    {
        if(line[i] != ',')
            this->date2[i] = line[i];
    }
    a = line.length() - a;
    this->value2.resize(a-1);
    for(j = 0; i < line.length(); j++)
    {
        value2[j] = line[i];
        i++;
    }
    std::stringstream ss(value2);
    ss >> valuef2;
}

void BitcoinExchange::reachDataValues()
{
    std::ifstream readFile(this->dataCSV);
    if (readFile.is_open())
	{
        std::string line;
		while(getline(readFile, line))
        {
            if(line == "date,exchange_rate")
                continue;
            parseContents(line);
            std::pair<std::string, float> pair;
            pair = std::pair<std::string, float> (date2, valuef2);            
            this->map.insert(pair);
        }
    }
    else
	{
        std::cerr << "Error: could not open file." << std::endl;
        exit(2);
	}
}

void BitcoinExchange::reachIndexValues()
{
    std::ifstream readFile(fileName);
    if (readFile.is_open())
	{
        std::string line;
	    while (getline(readFile, line))
        {
            if(line == "date | value")
                continue;
            if(line.find('|') == std::string::npos) 
            {
                std::cerr << "Error: bad input => " + line << std::endl;
                continue;
            }
            parseAndCheckContents2(line);
            if(!checkDate() || ! checkValue())
                continue;
            std::pair<std::string, float> pair;
            pair = std::pair<std::string, float> (date, valuef);

            std::map<std::string, float>::iterator it;
            for (it = map.begin(); it != map.end(); ++it) {
                if (it->first == pair.first)
                {

                    std::cout << line.substr(0, line.find("|")) << "=> " << pair.second << " = " << pair.second * it->second  <<  std::endl;
                    break;
                }
                else if (it->first > pair.first)
                {
                    it--;
                    std::cout << line.substr(0, line.find("|")) << "=> " << pair.second << " = " << pair.second * it->second  <<  std::endl;
                    break;
                }
            }
        }
    }
    else
	{
        std::cerr << "Error: could not open file." << std::endl;
        exit(2);
	}
}