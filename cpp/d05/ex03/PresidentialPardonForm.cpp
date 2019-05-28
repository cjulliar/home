#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
Form("Presidential", "target", 25, 3)
{
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form("Presidential", target, 25, 3)
{
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

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << Form::getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
