#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void): _name("Player")
{
	std::cout << "SuperTrap Default constructor called" << std::endl;
	*this = SuperTrap(_name);
	return ;
}
SuperTrap::SuperTrap(std::string enter): NinjaTrap(enter)
{
	std::cout << "SuperTrap Parametric constructor called" << std::endl;
	srand (time(NULL));
	this->_name = enter;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_maxHitPoints = FragTrap::_maxHitPoints;
	this->_energyPoints = NinjaTrap::_energyPoints;
	this->_maxEnergyPoints = NinjaTrap::_maxEnergyPoints;
	this->_meleeAttackDmg = NinjaTrap::_meleeAttackDmg;
	this->_rangeAttackDmg = FragTrap::_rangeAttackDmg;
	this->_armorDmgReduction = FragTrap::_armorDmgReduction;
	return ;
}
SuperTrap::SuperTrap(SuperTrap const &src)
{
	std::cout << "SuperTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}
SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap Destructor called" << std::endl;
	return ;
}

SuperTrap 		&SuperTrap::operator=(SuperTrap const &rhs)
{
	std::cout << "SuperTrap Assignment operator called" << std::endl;
	this->_name = rhs._name;
	return *this;
}
