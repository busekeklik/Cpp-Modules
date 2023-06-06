#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include<fstream>

class BitcoinExchange{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator =(const BitcoinExchange &other);
        
};

#endif