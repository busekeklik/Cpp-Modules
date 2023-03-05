#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	name = "FragTrap";
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " is created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "FragTrap " +  name << " is created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " deleted." << std::endl;
}


FragTrap::FragTrap(const FragTrap &clone) : ClapTrap(clone)
{
	*this = clone;
	std::cout << clone.name << "is cloned." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) 
{
	this->name = fragTrap.name;
	this->hitPoints = fragTrap.hitPoints;
	this->energyPoints = fragTrap.energyPoints;
	this->attackDamage = fragTrap.attackDamage;
	this->maxHP = fragTrap.maxHP;
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << ": High Five!" << std::endl;
}
