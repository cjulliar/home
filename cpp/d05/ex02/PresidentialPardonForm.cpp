#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
_target("Shrubbery")
{
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target):
_target(target)
{
	if (_gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_gradeToSign > 25)
		throw Bureaucrat::GradeTooLowException();
	if (_gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_gradeToExecute > 5)
		throw Bureaucrat::GradeTooLowException();
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
	*this = src;
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getSigned();
	}
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void)
{
	return this->_target;
}

void		PresidentialPardonForm::action(void)
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
