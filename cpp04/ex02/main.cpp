#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{

	const Animal* animals[4] = {new Cat, new Dog, new Cat, new Dog};

	for (unsigned long i = 0; i < sizeof(animals) / sizeof(Animal*); ++i) {
		animals[i]->makeSound();
		delete animals[i];
	}

	Dog basic;
	{
		Dog tmp = basic;
	}


	return 0;
}