#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("Player")
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	*this = ScavTrap(_name);
	return ;
}
ScavTrap::ScavTrap(std::string enter): ClapTrap(enter)
{
	std::cout << "ScavTrap Parametric constructor called" << std::endl;
	srand (time(NULL));
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_meleeAttackDmg = 20;
	this->_rangeAttackDmg = 15;
	this->_armorDmgReduction = 3;
	return ;
}
ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return ;
}

ScavTrap 		&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap Assignment operator called" << std::endl;
	this->_name = rhs._name;
	return *this;
}


void			ScavTrap::challengeNewcomer(std::string const &target)
{
	int 		rand = std::rand() % 3;
	std::string	challenge[] = 
	{
		"recite The Alphabet Backwards",
		"walk hundred meters on your hands",
		"say ten times: 'Round the rough and rugged rock the ragged rascal rudely ran.'"
	};
	std::cout << "FR4G-TP " << this->getName() << " Challenge: " << target << "\n\"-You must " << challenge[rand] <<", good luck !\"" << std::endl;
}
