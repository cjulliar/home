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

int main()
{
	try
	{
		Bureaucrat Boring1("Jean", 14);
		Form paper1("form B.411", 15, 11);
		ShrubberyCreationForm paper2("form2");
		RobotomyRequestForm paper3("form3");
		PresidentialPardonForm paper4("form4");

		paper2.action();
		paper3.action();
		paper4.action();


	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
