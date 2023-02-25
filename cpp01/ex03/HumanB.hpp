#ifndef HUMANB_HPP
#define HUMANB_HPP

#include<iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
		std::string name;
		Weapon 	*weapon;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon *weapon);
		~HumanB();
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif