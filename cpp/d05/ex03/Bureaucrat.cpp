/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:52:00 by cjulliar          #+#    #+#             */
/*   Updated: 2019/05/27 15:52:01 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
Bureaucrat::Bureaucrat(void)
{
	return ;
}
Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}
Bureaucrat::~Bureaucrat(void)
{
	return ;
}
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream 	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	out << "<" << rhs.getName() << ">, bureaucrat grade <" << rhs.getGrade() << ">";
	return out;
}

std::string		Bureaucrat::getName(void) const
{
	return this->_name;
}
int				Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void			Bureaucrat::incrementGrade(void)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return ;
}
void			Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}
void			Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " sign " << form.getName()  << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->_name <<  " can't sign " << form.getName();
		std::cout << ". Because " << e.what() << std::endl;
	}
}

void			Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() <<" execute " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->_name <<  " can't execute " << form.getName();
		std::cout << ". Because " << e.what() << std::endl;
	}
	return ;
}




