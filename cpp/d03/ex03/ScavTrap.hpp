#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const enter);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &rhs);

		void		challengeNewcomer(std::string const &target);

	private:
		std::string _name;
};

#endif



