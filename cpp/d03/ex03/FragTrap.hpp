#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const enter);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &rhs);

		void		vaulthunter_dot_exe(std::string const &target);
		int			getVaulthunterDotExeDmg(void);
	
	private:
		std::string _name;
		int			_vaulthunterDotExeDmg;
};

#endif