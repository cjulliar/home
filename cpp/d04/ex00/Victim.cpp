#include "Victim.hpp"

Victim::Victim(void)
{
	_name = "Victim";
	std::cout << "Some random victim called " << this->getName() << " just popped !" << std::endl;
	return ;
}
Victim::Victim(std::string name): _name(name)
{
	std::cout << "Some random victim called " << this->getName() << " just popped !" << std::endl;
	return ;
}
Victim::Victim(Victim const &src)
{
	*this = src;
	return ;
}
Victim::~Victim(void)
{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
	return ;
}
Victim 		&Victim::operator=(Victim const &rhs)
{
	this->_name = rhs._name;
	return *this;
}
std::ostream 	&operator<<(std::ostream &out, Victim const &rhs)
{
	out << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return out;
}

std::string		Victim::getName(void) const
{
	return (this->_name);
}
void			Victim::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}