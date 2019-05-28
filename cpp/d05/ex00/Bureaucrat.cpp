/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:51:53 by cjulliar          #+#    #+#             */
/*   Updated: 2019/05/27 15:51:54 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	this->_name = "Bureaucrat";
	this->_grade = 1;
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
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
	return ;
}
void			Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
	return ;
}
