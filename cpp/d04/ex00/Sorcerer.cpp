#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
	_name = "Sorcerer";
	_title = "no title yet";
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !" << std::endl;
	return ;
}
Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !" << std::endl;
	return ;
}
Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
	return ;
}
Sorcerer::~Sorcerer(void)
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
	return ;
}
Sorcerer 		&Sorcerer::operator=(Sorcerer const &rhs)
{
	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}
std::ostream 	&operator<<(std::ostream &out, Sorcerer const &rhs)
{
	out << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return out;
}

std::string		Sorcerer::getName(void) const
{
	return (this->_name);
}
std::string		Sorcerer::getTitle(void) const
{
	return (this->_title);
}
void 			Sorcerer::polymorph(Victim const &vic) const
{
	vic.getPolymorphed();
	return ;
}
