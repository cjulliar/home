#include "Pony.hpp"

Pony::Pony(std::string name)
{
	this->_name = name;
	std::cout << "Pony \"" << this->_name << "\" is born" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << "Pony \"" << this->_name << "\" dead" << std::endl;
	return ;
}


std::string		Pony::getColor(void) const
{
	return this->_color;
}
void			Pony::setColor(std::string color)
{
	this->_color = color;
	return ;
}

int				Pony::getNumberLegs(void) const
{
	return this->_numberLegs;
}
void			Pony::setNumberLegs(int numb)
{
	this->_numberLegs = numb;
	return ;
}

double			Pony::getSpeed(void) const
{
	return this->_speed;
}
void			Pony::setSpeed(double speed)
{
	this->_speed = speed;
	return ;
}