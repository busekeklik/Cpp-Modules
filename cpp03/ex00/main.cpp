#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap *soldiers = new ClapTrap[3];
    ClapTrap clapTrap("ClapTrap");
     for(int i = 0; i < 3; i++)
    {
        soldiers[i].attack(soldiers[i].getName());
        clapTrap.takeDamage(soldiers[i].getAttackDamage());
    }
	clapTrap.attack("enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
    delete[] soldiers;
    return (0);
}