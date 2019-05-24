#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Player")
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	*this = FragTrap(_name);
	return ;
}
FragTrap::FragTrap(std::string enter): ClapTrap(enter)
{
	std::cout << "FragTrap Parametric constructor called" << std::endl;
	srand (time(NULL));
	this->_meleeAttackDmg = 30;
	this->_rangeAttackDmg = 20;
	this->_armorDmgReduction = 5;
	this->_vaulthunterDotExeDmg = 0;
	return ;
}
FragTrap::FragTrap(FragTrap const &src): ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}
FragTrap::~FragTrap(void)
{
	std::cout << " FragTrap Destructor called" << std::endl;
	return ;
}

FragTrap 		&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap Assignment operator called" << std::endl;
	this->_name = rhs._name;
	return *this;
}

void			FragTrap::rangeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->getName() << " attacks like a frag " << target << " at range, causing " << this->getRangeAttackDmg() << " points of damage !" << std::endl;
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

int				FragTrap::getVaulthunterDotExeDmg(void)
{
	return this->_vaulthunterDotExeDmg;
}