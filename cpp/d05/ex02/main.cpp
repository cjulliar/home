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

void main_test(Bureaucrat boring,
	ShrubberyCreationForm &p1, RobotomyRequestForm &p2, PresidentialPardonForm &p3)
{
	try
	{
		boring.executeForm(p1);

		boring.signForm(p1);
		boring.signForm(p2);
		boring.signForm(p3);


		boring.executeForm(p1);
		boring.executeForm(p2);
		boring.executeForm(p3);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	
	Bureaucrat Boring1("Jean",1);
	Bureaucrat Boring2("Bob",42);
	Bureaucrat Boring3("Martin",99);

	ShrubberyCreationForm paper1("form1");
	RobotomyRequestForm paper2("form2");
	PresidentialPardonForm paper3("form3");

	main_test(Boring1, paper1, paper2, paper3);
	std::cout << std::endl;
	main_test(Boring2, paper1, paper2, paper3);
	std::cout << std::endl;
	main_test(Boring3, paper1, paper2, paper3);


	
	return 0;
}
