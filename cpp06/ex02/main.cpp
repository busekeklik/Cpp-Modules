#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "An error has occurred in the cast operation." << std::endl;

}

void identify(Base& p)
{
    try
    {
        if (dynamic_cast<A*>(&p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(&p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(&p))
            std::cout << "C" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
	srand(time(NULL));
	Base *ptr = generate();

    std::cout << ptr << std::endl;

    std::cout << "identify that take pointer" << std::endl;
	identify(ptr);
    std::cout << "identify that take reference" << std::endl;
	identify(*ptr);

	delete ptr;
	return (0);
}
