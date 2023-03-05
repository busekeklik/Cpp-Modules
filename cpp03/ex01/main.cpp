#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap scavTrap("ScavTrap");
	scavTrap.attack("Target");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();
	return 0;
}