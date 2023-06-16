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
    this->map.clear();
    std::map < t_date, float>::iterator its = copy.map.begin();
    std::map < t_date, float>::iterator ite = copy.map.end();
    while(it != ite)
    {
        this->map.insert(*its);
        its++;
    }
    this->day = copy.day;
    this->year = copy.year;
    this->month = copy.month;
    this->dataCSV = copy.dataCSV;
    this->fileName = copy.fileName;
    this->map = copy.map;
    this->valuef = copy.valuef;
    return *this;
}

bool BitcoinExchange::checkDate(void)
{
    bool acceptableDate = false;
    if(date.length() != 10)
        throw ("Invalid date");
    this->year = std::stoi(date.substr(0,4));
    this->month = std::stoi(date.substr(5,7));
    this->day = std::stoi(date.substr(8,10));
    if (((2009 <= this->year) && (this->year <= 2023)) && ((1 <= this->month) && (this->month <= 12)) && ((1 <= this->day) && (this->day < 32)))
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
        std::cerr << "invalid date" << std::endl;
    return acceptableDate;
}

bool BitcoinExchange::checkValue()
{
    bool acceptableValue = false;
    valuef = std::stof(value);
    if (valuef < 0)
        std::cerr << "not a positive number." << std::endl;
    else if (valuef > 1000)
        std::cerr << "too large a number." << std::endl; 
    else
        acceptableValue = true;
    return acceptableValue;
}

void BitcoinExchange::parseAndCheckContents2(std::string line)
{
    size_t a = line.find("|");

    if (a == line.length() -1)
        throw("invalid date");
    size_t i, j;
    this->date.resize(a);
    for(i = 0; i <= a; i++)
    {
        if(line[i] == ' ')
            continue;
        if(line[i] != ',')
            this->date[i] = line[i];
    }
    a = line.length() - a;
    this->value.resize(a);
    for(j = 0 ; i < line.length() ; j++)
    {
        if(line[i] == ' ')
            continue;
        value[j] = line[i];
        i++;
    }    
   
}

void BitcoinExchange::parseAndCheckContents1(std::string line)
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
    this->value2.resize(a);
    for(j = 0 ; i < line.length() ; j++)
    {
        value2[j] = line[i];
        i++;
    }
     valuef2 = std::stof(value2);
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
            if(line.find(',') == std::string::npos) 
	        {
		        std::cerr << "bad input => " + line << std::endl;
                return ;
	        }
            parseAndCheckContents1(line);
            std::pair<std::string, float> pair;
            pair = std::pair<std::string, float> (date2, valuef2);
            this->map.insert(pair);
        }
    }
    else
	{
        std::cerr << "could not open file." << std::endl;
        exit(2);
	}
}

void BitcoinExchange::reachIndexValues()
{
    std::ifstream readFile(fileName);
    if (!readFile.is_open())
	{
        std::cerr << "could not open file." << std::endl;
    }
    std::string line;
		while(getline(readFile, line))
        {
            if(line == "date | value")
                continue;
            if(line.find('|') == std::string::npos) 
	        {
		        std::cerr << "bad input => " + line << std::endl;
                return ;
	        }
            parseAndCheckContents2(line);

             if(!checkDate() || ! checkValue())
                return ;
            std::pair<std::string, float> pair;
            pair = std::pair<std::string, float> (date, valuef);
            std::map<std::string, float>::iterator it =  this->map.find(pair.first);

			if (it != this->map.end())
				std::cout << line.substr(0, line.find("|")) << "=> " << pair.second << " = " << pair.second * it->second << std::endl;
			else
			{
				std::map<std::string, float>::iterator it = this->map.lower_bound(pair.first);
				if (it != map.begin())
					it--;
				std::cout << line.substr(0, line.find("|")) << "=> " << pair.second << " = " << pair.second * it->second << std::endl;
			}
        }
}