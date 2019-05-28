#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
Form("Robot", "target", 72, 45)
{
	srand (time(NULL));
	return ;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target):
Form("Robot", target, 72, 45)
{
	srand (time(NULL));
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

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	int rand = std::rand() % 2;
	if (rand == 1)
		std::cout << "*sound of creation* " << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "It’s a failure." << std::endl;
}
