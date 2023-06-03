#include "easyfind.hpp"

int main()
{
    std::vector <int> v;
    v.push_back(15);
    v.push_back(20);
    v.push_back(25);
    v.push_back(30);

    try {
	    std::cout << *easyfind(v, 25) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "This value is not found!" << std::endl;
    }

    try {
	    std::cout << *easyfind(v, 10) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "This value is not found!" << std::endl;
    }
    return (0);
}
