#include "Dog.hpp"


Dog::Dog() 
{
    this->type = "Dog";
    std::cout << this->type << " constructor called"<<std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	*this = dog;
	std::cout << this->type << " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) 
{
	this->type = dog.type;
	std::cout << this->type << " assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog: hav havvvv" << std::endl;
}

Dog::~Dog() {
	std::cout << this->type << " destructor called" << std::endl;
}
