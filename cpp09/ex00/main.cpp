#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
        std::cerr << "could not open file." << std::endl;
    else
    {
        BitcoinExchange btc;
        btc.fileName = av[1];
        btc.takeValue();
    }
    return (0);
}