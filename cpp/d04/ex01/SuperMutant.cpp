#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" <<std::endl;
	return ;
}
SuperMutant::SuperMutant(SuperMutant const &src)
{
	std::cout << "Gaaah. Me want smash heads !" <<std::endl;
	*this = src;
	return ;
}
SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." <<std::endl;
	return ;
}
SuperMutant 		&SuperMutant::operator=(SuperMutant const &rhs)
{
	this->_hp = rhs._hp;
	this->_type = rhs._type;
	return *this;
}

void 				SuperMutant::takeDamage(int damage)
{
	this->_hp = this->_hp - 3 * damage;
	return ;
}