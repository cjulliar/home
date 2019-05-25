# ifndef PEON_H
#define PEON_H

#include <iostream>
#include <string>
#include "Victim.hpp"

class Peon: public Victim
{
	public:
		Peon(void);
		Peon(std::string const name);
		Peon(Peon const &src);
		~Peon(void);

		Peon			&operator=(Peon const &rhs);

		virtual void	getPolymorphed(void) const;	
};

# endif