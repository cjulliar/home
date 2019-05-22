#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

void			Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}
void			Zombie::setType(std::string type)
{
	this->_type = type;
	return ;
}

void		Zombie::announce(void) const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
	return ;
}