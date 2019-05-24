#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void): ClapTrap("Player")
{
	std::cout << "NinjaTrap Default constructor called" << std::endl;
	*this = NinjaTrap(_name);
	return ;
}
NinjaTrap::NinjaTrap(std::string enter): ClapTrap(enter)
{
	std::cout << "NinjaTrap Parametric constructor called" << std::endl;
	srand (time(NULL));
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_meleeAttackDmg = 60;
	this->_rangeAttackDmg = 5;
	this->_armorDmgReduction = 0;
	return ;
}
NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
	std::cout << "NinjaTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}
NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap Destructor called" << std::endl;
	return ;
}

NinjaTrap 		&NinjaTrap::operator=(NinjaTrap const &rhs)
{
	std::cout << "NinjaTrap Assignment operator called" << std::endl;
	this->_name = rhs._name;
	return *this;
}


void			NinjaTrap::ninjaShoebox(std::string const &target)
{
	int 		rand = std::rand() % 3;
	std::string	ninja_begin[] = 
	{
		" take something from ",
		" don't stay next morning after sleeping with ",
		" slap "
	};
	std::string	ninja_end[] = 
	{
		" and run away",
		"",
		"'s neck"
	};
	std::cout << "FR4G-TP " << this->getName() << ninja_begin[rand] << target << ninja_end[rand] <<", juste like a NINJA !" << std::endl;
}
