#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
_target("Shrubbery")
{
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
_target(target)
{
	if (_gradeToSign < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_gradeToSign > 145)
		throw Bureaucrat::GradeTooLowException();
	if (_gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_gradeToExecute > 137)
		throw Bureaucrat::GradeTooLowException();
	return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
	*this = src;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getSigned();
	}
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void)
{
	return this->_target;
}

void		ShrubberyCreationForm::action(void)
{
	std::ofstream outfile (this->getTarget()+"_shrubbery");
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;
	outfile.close();
}
