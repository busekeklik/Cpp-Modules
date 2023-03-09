#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	delete cat;
	delete dog;
	delete meta;
	//Cat cat;
	//Cat cat2(cat);
	//cat.makeSound();
    return (0);
}
