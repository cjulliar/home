#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		void	setName(std::string);
		void	setType(std::string);
		void	announce(void) const;

	private:
		std::string _name;
		std::string	_type;
};

#endif