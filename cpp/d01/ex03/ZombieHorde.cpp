#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int size)
{

	this->_size = size;
	this->_type = "stalker";
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	return ;
}

std::string		ZombieHorde::randomChump(void)
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

void			ZombieHorde::announce(Zombie* horde)
{
	for (int i = 0; i < this->_size; ++i)
	{
		horde[i].announce();
	}
}

Zombie*			ZombieHorde::newZombie(void)
{
	Zombie* horde = new Zombie [this->_size];

	for (int i = 0; i < this->_size; ++i)
	{
		horde[i].setName(randomChump());
		horde[i].setType(this->_type);
	}
	return horde;
}