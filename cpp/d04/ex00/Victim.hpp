# ifndef VICTIM_H
#define VICTIM_H

#include <iostream>
#include <string>

class Victim
{
	public:
		Victim(void);
		Victim(std::string const name);
		Victim(Victim const &src);
		~Victim(void);

		Victim			&operator=(Victim const &rhs);

		std::string		getName(void) const;
		virtual void	getPolymorphed(void) const;


	protected:
		std::string	_name;
	
};

std::ostream 	&operator<<(std::ostream &out, Victim const &rhs);

# endif