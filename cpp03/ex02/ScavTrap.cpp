#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "ScavTrap";
	this->hitPoints = 100;
	this->maxHP = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " is created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	this->maxHP = 100;
	std::cout << "ScavTrap " +  name << " is created." << std::endl;
} 

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " deleted." << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &clone) : ClapTrap(clone)
{
	*this = clone;
	std::cout << clone.name << "is cloned." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) 
{
	this->name = scavTrap.name;
	this->hitPoints = scavTrap.hitPoints;
	this->energyPoints = scavTrap.energyPoints;
	this->attackDamage = scavTrap.attackDamage;
	this->maxHP = scavTrap.maxHP;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is guard mode." << std::endl;
}


void ScavTrap::attack(const std::string &damage)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ScavTrap " + this->name + " attacks " +  damage + ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "ScavTrap " + this->name + "'s energy is too low to attack." << std::endl;
}
