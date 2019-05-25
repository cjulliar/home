#include "Character.hpp"

Character::Character(void)
{
	this->_ap = 40;
	this->_aweapon = NULL;
	return ;
}
Character::Character(std::string const &name):
_name(name)
{
	this->_ap = 40;
	this->_aweapon = NULL;
	return ;
}
Character::Character(Character const &src)
{
	*this = src;
	return ;
}
Character::~Character(void)
{
	return ;
}
Character 			&Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_ap = rhs._ap;
		this->_aweapon = rhs._aweapon;
	}
	return *this;
}
std::ostream 		&operator<<(std::ostream &out, Character const &rhs)
{
	out << rhs.getName() << " has " << rhs.getAp() << " AP and ";
	if (rhs.getAweapon() == NULL)
		out << "is unarmed" << std::endl;
	else
		out << "wields a "<< rhs.getAweapon()->getName() << std::endl;
	return out;
}

void 				Character::recoverAP(void)
{
	this->_ap = this->_ap + 10;
	if (this->_ap > 40)
		this->_ap = 40;
	return ;
}
void 				Character::equip(AWeapon* aweapon)
{
	this->_aweapon = aweapon;
	return ;
}
void 				Character::attack(Enemy* enemy)
{
	if (this->getAweapon() != NULL)
	{
		std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->_aweapon->getName() << std::endl;
		this->_ap = this->_ap - this->_aweapon->getAPCost();
		enemy->takeDamage(this->_aweapon->getDamage());
		this->_aweapon->attack();
		if (enemy->getHP() < 1)
			enemy->~Enemy();
	}
	return ;
}
std::string const	Character::getName(void) const
{
	return this->_name;
}
int					Character::getAp(void) const
{
	return this->_ap;
}
AWeapon				*Character::getAweapon(void) const
{
	return this->_aweapon;
}