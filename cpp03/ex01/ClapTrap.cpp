#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "ClapTrap";
	this->hitPoints = 10;
	this->maxHP = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap  "<< this->name << " is woken up." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
	hitPoints = 10;
	maxHP = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap  "<< this->name << " is woken up." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap  "<< name << " destroyed." << std::endl;
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
		std::cout << "ClapTrap  " + this->name + "does not have the necessary energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int damage)
{
	if (this->hitPoints > 0)
	{
		std::cout << "ClapTrap " + this->name + " takes " << damage << " points of damage";
		this->hitPoints -= damage;
		if (this->hitPoints <= 0)
			std::cout << " and died";
		std::cout << "!" << std::endl;
	}
	else
		std::cout << "ClapTrap " + this->name + " is" + " dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int health)
{
	if (this->energyPoints > 0)
	{
		if (this->hitPoints < maxHP)
		{
			std::cout << "ClapTrap " + this->name + " is repaired by " << health << " points." << std::endl;
			this->hitPoints += health;
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