#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H
#include <iostream>
#include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int size);
		~ZombieHorde(void);

		std::string		randomChump(void);
		Zombie *		newZombie(void);
		void			announce(Zombie *);

	private:
		int			_size;
		std::string	_type;
};

#endif