#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H
#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent(void);


		void			setZombieType(std::string);
		std::string		randomChump(void);
		Zombie*			newZombie(void);

	private:
		std::string	_type;
};

#endif