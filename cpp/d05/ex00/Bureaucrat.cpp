#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	return ;
}
Bureaucrat::Bureaucrat(std::string const name, int note): _name(name)
{
	if (note < 1 || note > 150)
		throw std::exception();
	else
		this->_note = note;
	return ;
}
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}
Bureaucrat::Bureaucrat(void)
{
	return ;
}
Bureaucrat	Bureaucrat::&operator=(Bureaucrat const &rhs)
{

}

std::ostream 	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << "";
	return out;
}
