#include "Brain.hpp"

Brain::Brain(void)
{
	std::stringstream   adr;
    adr << this;
    this->_address = adr.str();
	return ;
}

Brain::~Brain(void)
{
	return ;
}

std::string		Brain::identify(void)
{
	return this->_address;
}