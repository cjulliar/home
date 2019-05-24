#include "FragTrap.hpp"

FragTrap::FragTrap(void): _name("Player")
{
	std::cout << "Default constructor called" << std::endl;
	*this = FragTrap(_name);
	return ;
}
FragTrap::FragTrap(std::string enter): _name(enter)
{
	std::cout << "Parametric constructor called" << std::endl;
	srand (time(NULL));
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_level = 1;
	this->_meleeAttackDmg = 30;
	this->_rangeAttackDmg = 20;
	this->_armorDmgReduction = 5;
	this->_vaulthunterDotExeDmg = 0;
	return ;
}
FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}
FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

FragTrap 		&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_name = rhs._name;
	return *this;
}

void			FragTrap::rangeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " at range, causing " << this->getRangeAttackDmg() << " points of damage !" << std::endl;
	return ;
}
void			FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " at melee, causing " << this->getMeleeAttackDmg() << " points of damage !" << std::endl;
	return ;
}
void			FragTrap::takeDamage(unsigned int amount)
{
	int		dmgReceived;
	dmgReceived = amount - this->getArmorDmgReduction();
	this->_hitPoints = this->_hitPoints - dmgReceived;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "FR4G-TP " << this->getName() << " take " << dmgReceived << " points of dommage. His life is " << this->getHitPoints() << std::endl;
	return ;
}
void			FragTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints = this->_hitPoints + amount;
	if (this->_hitPoints > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	std::cout << "FR4G-TP " << this->getName() << " take " << amount << " points of heal. His life is " << this->getHitPoints() << std::endl;
	return ;
}
void			FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->_energyPoints < 25)
		std::cout << "FR4G-TP " << this->getName() << " need a minimum of 25 energys for this attack." << std::endl;
	int 		rand = std::rand() % 5;
	std::string	typeAttack[5];
	typeAttack[0] = "ball";
	typeAttack[1] = "suction cup";
	typeAttack[2] = "harmonica";
	typeAttack[3] = "control of time";
	typeAttack[4] = "lightsaber";
	this->_vaulthunterDotExeDmg = rand * 6 + 4;
	this->_energyPoints = this->_energyPoints - 25;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
	std::cout << "FR4G-TP " << this->getName() << " attacks " << target << " with " << typeAttack[rand] <<", causing " << this->getVaulthunterDotExeDmg() << " points of damage !" << std::endl;
}

std::string		FragTrap::getName(void)
{
	return this->_name;
}
int				FragTrap::getHitPoints(void)
{
	return this->_hitPoints;
}
int				FragTrap::getMaxHitPoints(void)
{
	return this->_maxHitPoints;
}
int				FragTrap::getEnergyPoints(void)
{
	return this->_energyPoints;
}
int				FragTrap::getMaxEnergyPoints(void)
{
	return this->_maxEnergyPoints;
}
int				FragTrap::getLevel(void)
{
	return this->_level;
}
int				FragTrap::getMeleeAttackDmg(void)
{
	return this->_meleeAttackDmg;
}
int				FragTrap::getRangeAttackDmg(void)
{
	return this->_rangeAttackDmg;
}
int				FragTrap::getArmorDmgReduction(void)
{
	return this->_armorDmgReduction;
}
int				FragTrap::getVaulthunterDotExeDmg(void)
{
	return this->_vaulthunterDotExeDmg;
}