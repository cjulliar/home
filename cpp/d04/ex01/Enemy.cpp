#include "Enemy.hpp"

Enemy::Enemy(void)
{
	return ;
}
Enemy::Enemy(int hp, std::string const &type):
_hp(hp), _type(type)
{
	return ;
}
Enemy::Enemy(Enemy const &src)
{
	*this = src;
	return ;
}
Enemy::~Enemy(void)
{
	return ;
}
Enemy 		&Enemy::operator=(Enemy const &rhs)
{
    if (this != &rhs)
    {
    	this->_hp = rhs._hp;
		this->_type = rhs._type;
    }
	return *this;
}

std::string	const	 Enemy::getType(void) const
{
	return this->_type;
}
int 				Enemy::getHP(void) const
{
	return this->_hp;
}
void 				Enemy::takeDamage(int damage)
{
	this->_hp = this->_hp - damage;
	return ;
}