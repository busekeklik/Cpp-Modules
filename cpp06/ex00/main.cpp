#include "Casting.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "You should enter ./convert [value]" << std::endl;
    }
    else
    {
        Casting cast;
        cast.checkValue(av[1]);
        cast.convert(av[1]);
    }
    return (0);
}