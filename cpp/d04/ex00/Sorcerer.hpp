# ifndef SORCERER_H
#define SORCERER_H

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(void);
		Sorcerer(std::string const name, std::string const title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		Sorcerer	&operator=(Sorcerer const &rhs);

		std::string		getName(void) const;
		std::string		getTitle(void) const;
		void 			polymorph(Victim const &vic) const;


	private:
		std::string	_name;
		std::string	_title;
	
};

std::ostream 	&operator<<(std::ostream &out, Sorcerer const &rhs);

# endif