#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* deserialize(uintptr_t raw)
{
    Data* ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}

int main()
{
    Data* data = new Data;
    
    data->str = "Hi 👻";
    data->nb = 17;
    data->nbd = 2.0;
    data->nbf = 2002.2f;


    uintptr_t raw = serialize(data);
    Data* ptr = deserialize(raw);
    
    std::cout << ptr << std::endl;
    std::cout <<"--------------------" << std::endl;

	std::cout << raw << std::endl;
    std::cout << ptr->str << std::endl;
    std::cout << ptr->nb << std::endl;
    std::cout << ptr->nbd << std::endl;
    std::cout << ptr->nbf << std::endl;
	std::cout << data << std::endl;

	delete data;	
	return 0;
}
