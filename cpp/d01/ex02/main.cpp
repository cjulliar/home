#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <unistd.h>

int		main()
{
	srand (time(NULL));
	ZombieEvent		event;
	
	Zombie*		zombie1 = new Zombie;
	event.setZombieType("chasseur");
	zombie1 = event.newZombie();
	zombie1->announce();
	delete zombie1;
	
	Zombie*		zombie2 = new Zombie;
	event.setZombieType("cueilleur");
	zombie2 = event.newZombie();
	zombie2->announce();
	delete zombie2;

	Zombie*		zombie3 = new Zombie;
	event.setZombieType("Informaticien");
	zombie3 = event.newZombie();
	zombie3->announce();
	delete zombie3;
	return 0;
}