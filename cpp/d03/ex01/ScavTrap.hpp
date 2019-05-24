#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <iostream>
#include <time.h> 

class ScavTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const enter);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &rhs);

		void		rangeAttack(std::string const &targer);
		void		meleeAttack(std::string const &targer);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		challengeNewcomer(std::string const &target);

		std::string	getName(void);
		int			getHitPoints(void);
		int			getMaxHitPoints(void);
		int			getEnergyPoints(void);
		int			getMaxEnergyPoints(void);
		int			getLevel(void);
		int			getMeleeAttackDmg(void);
		int			getRangeAttackDmg(void);
		int			getArmorDmgReduction(void);

	private:
		std::string _name;
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergyPoints;
		int			_level;
		int			_meleeAttackDmg;
		int			_rangeAttackDmg;
		int			_armorDmgReduction;
};

#endif



