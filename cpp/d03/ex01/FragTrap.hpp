#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include <time.h> 


class FragTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const enter);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &rhs);

		void		rangeAttack(std::string const &targer);
		void		meleeAttack(std::string const &targer);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const &target);

		std::string	getName(void);
		int			getHitPoints(void);
		int			getMaxHitPoints(void);
		int			getEnergyPoints(void);
		int			getMaxEnergyPoints(void);
		int			getLevel(void);
		int			getMeleeAttackDmg(void);
		int			getRangeAttackDmg(void);
		int			getArmorDmgReduction(void);
		int			getVaulthunterDotExeDmg(void);
	
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
		int			_vaulthunterDotExeDmg;
};

#endif