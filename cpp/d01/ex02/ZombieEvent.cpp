#include "ZombieEvent.hpp"
#include <cstdlib>
#include <time.h> 

ZombieEvent::ZombieEvent(void)
{
	return ;
}

ZombieEvent::~ZombieEvent(void)
{
	return ;
}

void			ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
	return ;
}

std::string		ZombieEvent::randomChump(void)
{
	int 			size = std::rand() % 5 + 3;
	std::string		name;
	int				letter;
	std::string	alphabet = "aaeiiomnrrrgggplvz";
	std::string	tmp;
	for (int i = 0; i < size; ++i)
	{
		letter = std::rand() % 18;
		tmp = alphabet[letter];
		name.append(tmp);
	}
	return name;
}

Zombie*			ZombieEvent::newZombie(void)
{
	Zombie* zombie = new Zombie;
	zombie->setType(this->_type);
	zombie->setName(randomChump());
	return zombie;
}