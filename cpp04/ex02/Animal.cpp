#include "Animal.hpp"

Animal::Animal() 
{
    this->type = "Animal";
    std::cout << this->type << " constructor called"<<std::endl;
}

Animal::Animal(const Animal& animal) 
{
	*this = animal;
	std::cout << this->type << " copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) 
{
	this->type = animal.type;
	std::cout << this->type << " assignment operator called" << std::endl;
	return *this;
}

const std::string& Animal::getType() const 
{
	return this->type;
}

void Animal::makeSound() const 
{

}

Animal::~Animal() 
{
	std::cout << this->type << " destructor called" << std::endl;
}
