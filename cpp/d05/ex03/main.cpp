/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:52:08 by cjulliar          #+#    #+#             */
/*   Updated: 2019/05/27 15:52:11 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	
	Bureaucrat Boring("Jean",1);
	Intern someRandomIntern;
	
	Form* robot;
	robot = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << robot->getName() << std::endl;

	Form* president;
	president = someRandomIntern.makeForm("presidential pardon", "Jack");
	std::cout << *president << std::endl;

	Form* shrub;
	shrub = someRandomIntern.makeForm("shrubbery creation", "violette");
	Boring.signForm(*shrub);
	Boring.executeForm(*shrub);

	Form* error;
	error = someRandomIntern.makeForm("space invador", "splush");

	
	return 0;
}
