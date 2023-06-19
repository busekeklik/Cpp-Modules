#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
class BitcoinExchange{
    private:
      std::map<std::string, float> coin;
      std::string date;
      std::string value;
      std::string date2;
      std::string value2;
      float valuef2;
      float valuef;
    public:
        std::string dataCSV;
        std::string fileName;

        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator =(const BitcoinExchange &other);

        void reachDataValues();
        void reachIndexValues();
        void parseContents(std::string line);
        void parseAndCheckContents2(std::string line);
        bool checkDate();
        bool checkValue();
};

#endif