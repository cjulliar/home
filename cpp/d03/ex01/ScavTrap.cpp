#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): _name("Player")
{
	std::cout << "Default constructor called" << std::endl;
	*this = ScavTrap(_name);
	return ;
}
ScavTrap::ScavTrap(std::string enter): _name(enter)
{
	std::cout << "Parametric constructor called" << std::endl;
	srand (time(NULL));
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDmg = 20;
	this->_rangeAttackDmg = 15;
	this->_armorDmgReduction = 3;
	return ;
}
ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

ScavTrap 		&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_name = rhs._name;
	return *this;
}


void			ScavTrap::rangeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " at range, causing " << this->getRangeAttackDmg() << " points of damage !" << std::endl;
	return ;
}
void			ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeAttackDmg() << " points of damage !" << std::endl;
	return ;
}
void			ScavTrap::takeDamage(unsigned int amount)
{
	int		dmgReceived;
	dmgReceived = amount - this->getArmorDmgReduction();
	this->_hitPoints = this->_hitPoints - dmgReceived;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "FR4G-TP " << this->getName() << " take " << dmgReceived << " points of dommage. His life is " << this->getHitPoints() << std::endl;
	return ;
}
void			ScavTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints = this->_hitPoints + amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "FR4G-TP " << this->getName() << " take " << amount << " points of heal. His life is " << this->getHitPoints() << std::endl;
	return ;
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


std::string		ScavTrap::getName(void)
{
	return this->_name;
}
int				ScavTrap::getHitPoints(void)
{
	return this->_hitPoints;
}
int				ScavTrap::getMaxHitPoints(void)
{
	return this->_maxHitPoints;
}
int				ScavTrap::getEnergyPoints(void)
{
	return this->_energyPoints;
}
int				ScavTrap::getMaxEnergyPoints(void)
{
	return this->_maxEnergyPoints;
}
int				ScavTrap::getLevel(void)
{
	return this->_level;
}
int				ScavTrap::getMeleeAttackDmg(void)
{
	return this->_meleeAttackDmg;
}
int				ScavTrap::getRangeAttackDmg(void)
{
	return this->_rangeAttackDmg;
}
int				ScavTrap::getArmorDmgReduction(void)
{
	return this->_armorDmgReduction;
}








