#include "RPN.hpp"

int main(int ac, char **av)
{
    try{
        if (ac == 2)
        {
            RPN rpn;
            rpn.line = av[1];
            rpn.fourTransactions(rpn.line);
        }
    }
    catch(...)
    {
        std::cerr << "Error" << std::endl;
		return 1;
    }
}