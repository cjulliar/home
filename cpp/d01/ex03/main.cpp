#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <unistd.h>

int		main()
{
	srand (time(NULL));
	ZombieHorde	horde(14);
	Zombie* 	zombies;

	zombies = horde.newZombie();
	horde.announce(zombies);	
	return 0;
}