#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
        std::cout << "could not open file." << std::endl;
    else
    {
        std::string fileName = av[1];
        std::ifstream readFile(fileName);
        if (!readFile.is_open())
	    {
            std::cout << "File cannot be opened" << std::endl;
            return (2);
	    }
    }
    return (0);
}