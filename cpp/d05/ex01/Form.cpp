/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:52:04 by cjulliar          #+#    #+#             */
/*   Updated: 2019/05/27 15:52:05 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
{
	return ;
}
Form::Form(std::string const form): _name(name), _isSigned(false)
{
	// if (grade < 1)
	// 	throw Bureaucrat::GradeTooHighException();
	// else if (grade > 150)
	// 	throw Bureaucrat::GradeTooLowException();
	// else
	// 	this->_grade = grade;
	return ;
}
Form::Form(Form const &src)
{
	*this = src;
}
Form::~Form(void)
{
	return ;
}
Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_isSigned = rhs.getSigned();
	}
	return *this;
}

std::ostream 	&operator<<(std::ostream &out, Bureaucrat const &rhs)
{
	if (rhs.getSigned())
		out << "<" << rhs.getName() << "> signs <" << rhs.getGrade() << ">";
	else
		out << "<" << rhs.getName() << "t> cannot sign <" << rhs.getGrade() << "t> cannot sign <" << "reason" << ">";

	return out;
}

bool	Form::getSigned(void) const
{
	return this->_isSigned;
}
std::string	Form::getName(void) const
{
	return thi->_name;
}
