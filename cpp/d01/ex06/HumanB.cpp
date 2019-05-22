#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon& weap)
{
	this->_weapon = &weap; 
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attack with " << this->_weapon->getType() << std::endl;
	return ;
}