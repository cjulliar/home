#ifndef SUPERTRAP_H
# define SUPERTRAP_H

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap
{
	public:
		SuperTrap(void);
		SuperTrap(std::string const enter);
		SuperTrap(SuperTrap const &src);
		~SuperTrap(void);

		SuperTrap	&operator=(SuperTrap const &rhs);

	private:
		std::string _name;
};

#endif



