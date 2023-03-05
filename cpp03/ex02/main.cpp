#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap *clapTrapHorde = new ClapTrap[3];
	ClapTrap target("Buse");
	for (int i = 0; i < 3; i++)
	{
		clapTrapHorde[i].attack(target.getName());
		target.takeDamage(clapTrapHorde[i].getAttackDamage());
	}
	delete [] clapTrapHorde;
	target.beRepaired(3);
	std::cout << "--------------------------------" << std::endl;
	ScavTrap s;
	s.attack("Buse");
	s.beRepaired(10);
	s.guardGate();
	s.takeDamage(15);
	std::cout << "--------------------------------" << std::endl;
	FragTrap f;
	f.attack("Buse");
	f.takeDamage(15);
	f.beRepaired(10);
	f.highFivesGuys();
	return (0);
}