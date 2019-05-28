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
#include "Bureaucrat.hpp"

Form::Form(void):
_name("Form"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	return ;
}
Form::Form(std::string name, int gradeToSign, int gradeToExecute):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToExecute > 150)
		throw Form::GradeTooLowException();
	return ;
}
Form::Form(Form const &src):
_name(src.getName()), _isSigned(src.getSigned()),
_gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
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
		this->_isSigned = rhs.getSigned();
	}
	return *this;
}

std::ostream 	&operator<<(std::ostream &out, Form const &rhs)
{
	out << "<" << rhs.getName();
	if (rhs.getSigned())
		out << "> is sign by <";
	else
		out << "> is not sign, but he can be by <";
	out << rhs.getGradeToSign() << "> and execute by <" << rhs.getGradeToExecute() << ">.";

	return out;
}

bool		Form::getSigned(void) const
{
	return this->_isSigned;
}
std::string	Form::getName(void) const
{
	return this->_name;
}
int			Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}
int			Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

void		Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeToSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
	return ;
}

void		Form::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (this->getSigned() == false)
		throw Form::NoSignException();
	return ;
}







