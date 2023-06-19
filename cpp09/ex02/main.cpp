#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
	{
		if (ac < 2)
			throw "Error: not the right number of arguments.";
		PmergeMe pmerge;
		pmerge.sort(av);
	}
 	catch(const char *str)
 	{
 		std::cerr << str << std::endl;
 	}

}