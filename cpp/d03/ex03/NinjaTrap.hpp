#ifndef NINJATRAP_H
# define NINJATRAP_H

#include "ClapTrap.hpp"

class NinjaTrap: public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string const enter);
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);

		NinjaTrap	&operator=(NinjaTrap const &rhs);

		void		ninjaShoebox(std::string const &target);

	private:
		std::string _name;
};

#endif



