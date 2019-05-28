#include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	return ;
}
Intern::Intern(Intern const &src)
{
	*this = src;
}
Intern::~Intern(void)
{
	return ;
}
Intern	&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getSigned();
	}
	return *this;
}

Form	*Intern::makeForm(std::string name, std::string target)
{

	if (name == "presidential pardon")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	else if (name == "robotomy request")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (name == "shrubbery creation")
	{
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else
	{
		std::cout << name << " don't exist." << std::endl;
		return NULL;
	}
}