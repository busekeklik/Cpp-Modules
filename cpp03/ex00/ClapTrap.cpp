#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "ClapTrap";
	this->hitPoints = 10;
	this->maxHP = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap "<< this->name << " is woken up." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
	this->hitPoints = 10;
	maxHP = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap "<< this->name << " is woken up." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<< "ClapTrap " << name << " destroyed." << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &clone)
{
	*this = clone;
	std::cout << clone.name << "is cloned." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	this->maxHP = clapTrap.maxHP;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0)
	{
		std::cout << "ClapTrap " + this->name + " attacks " +  target + ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "ClapTrap " + this->name + "does not have the necessary energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		std::cout << "ClapTrap " + this->name + " takes " << amount << " points of damage!"<< std::endl;
		this->hitPoints -= amount;
		if (this->hitPoints <= 0)
			std::cout << " and died!" << std::endl;
	}
	else
		std::cout << "ClapTrap " + this->name + " is" + " dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energyPoints)
	{
		if (this->hitPoints < maxHP)
		{
			std::cout << "ClapTrap " + this->name + " is repaired by " << amount << " points." << std::endl;
			this->hitPoints += amount;
			this->energyPoints--;
		}
		else
			std::cout << "ClapTrap " + this->name + " is already full health." << std::endl;
	}
	else
		std::cout << "ClapTrap " + this->name + "have enough energy." << std::endl;
}


std::string ClapTrap::getName(void)
{
	return (this->name);
}

int ClapTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}