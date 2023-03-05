#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

    class ClapTrap{
        protected:
            std::string  name;
            int hitPoints;
            int maxHP;
            int energyPoints;
            int attackDamage ;
        public:
            ClapTrap();
            ~ClapTrap();
            ClapTrap(std::string name);
            ClapTrap(const ClapTrap &copy);
            ClapTrap &operator=(const ClapTrap &clapTrap);
            void attack(const std::string& target);
            void takeDamage(unsigned int damage);
            void beRepaired(unsigned int health);
            std::string getName(void);
		    int getAttackDamage(void);
    };

#endif