#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->_type = name;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string	Weapon::getType(void) const
{
	return this->_type;
}
void		Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}