# ifndef CLAPTTRAP_H
#define CLAPTTRAP_H

#include <iostream>
#include <time.h>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const enter);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &rhs);

		void		rangeAttack(std::string const &targer);
		void		meleeAttack(std::string const &targer);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void);
		int			getHitPoints(void);
		int			getMaxHitPoints(void);
		int			getEnergyPoints(void);
		int			getMaxEnergyPoints(void);
		int			getLevel(void);
		int			getMeleeAttackDmg(void);
		int			getRangeAttackDmg(void);
		int			getArmorDmgReduction(void);


	protected:
		std::string	_name;
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergyPoints;
		int			_level;
		int			_meleeAttackDmg;
		int			_rangeAttackDmg;
		int			_armorDmgReduction;



};

# endif