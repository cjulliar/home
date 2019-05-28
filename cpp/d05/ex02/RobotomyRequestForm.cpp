#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
_target("Robot")
{
	srand (time(NULL));
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target):
_target(target)
{
	srand (time(NULL));
	if (_gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_gradeToSign > 72)
		throw Bureaucrat::GradeTooLowException();
	if (_gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_gradeToExecute > 45)
		throw Bureaucrat::GradeTooLowException();
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
	*this = src;
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getSigned();
	}
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void)
{
	return this->_target;
}

void		RobotomyRequestForm::action(void)
{
	int rand = std::rand() % 2;
	if (rand == 1)
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "It’s a failure." << std::endl;
}
