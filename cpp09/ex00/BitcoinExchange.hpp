#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
class BitcoinExchange{
    private:
      std::map<std::string, float> map;
      std::string date;
      std::string value;
      std::string date2;
      std::string value2;
      float valuef2;
      float valuef;
    public:
        std::string dataCSV;
        std::string fileName;
        int month;
        int year;
        int day;

        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator =(const BitcoinExchange &other);

        void reachDataValues();
        void reachIndexValues();
        void parseAndCheckContents1(std::string line);
        void parseAndCheckContents2(std::string line);
        bool checkDate();
        bool checkValue();
};

#endif