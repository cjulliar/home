#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weap): _name(name), _weapon(weap)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attack with " << this->_weapon.getType() << std::endl;
	return ;
}