#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Player")
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	*this = ClapTrap(_name);
	return ;
}
ClapTrap::ClapTrap(std::string enter): _name(enter)
{
	std::cout << "ClapTrap Parametric constructor called" << std::endl;
	srand (time(NULL));
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDmg = 70;
	this->_rangeAttackDmg = 50;
	this->_armorDmgReduction = 14;
	return ;
}
ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

ClapTrap 		&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	this->_name = rhs._name;
	return *this;
}

void			ClapTrap::rangeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " at range, causing " << this->getRangeAttackDmg() << " points of damage !" << std::endl;
	return ;
}
void			ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeAttackDmg() << " points of damage !" << std::endl;
	return ;
}
void			ClapTrap::takeDamage(unsigned int amount)
{
	int		dmgReceived;
	dmgReceived = amount - this->getArmorDmgReduction();
	this->_hitPoints = this->_hitPoints - dmgReceived;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "FR4G-TP " << this->getName() << " take " << dmgReceived << " points of dommage. His life is " << this->getHitPoints() << std::endl;
	return ;
}
void			ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints = this->_hitPoints + amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "FR4G-TP " << this->getName() << " take " << amount << " points of heal. His life is " << this->getHitPoints() << std::endl;
	return ;
}


std::string		ClapTrap::getName(void)
{
	return this->_name;
}
int				ClapTrap::getHitPoints(void)
{
	return this->_hitPoints;
}
int				ClapTrap::getMaxHitPoints(void)
{
	return this->_maxHitPoints;
}
int				ClapTrap::getEnergyPoints(void)
{
	return this->_energyPoints;
}
int				ClapTrap::getMaxEnergyPoints(void)
{
	return this->_maxEnergyPoints;
}
int				ClapTrap::getLevel(void)
{
	return this->_level;
}
int				ClapTrap::getMeleeAttackDmg(void)
{
	return this->_meleeAttackDmg;
}
int				ClapTrap::getRangeAttackDmg(void)
{
	return this->_rangeAttackDmg;
}
int				ClapTrap::getArmorDmgReduction(void)
{
	return this->_armorDmgReduction;
}