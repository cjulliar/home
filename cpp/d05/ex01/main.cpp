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

int main()
{
	try
	{
		Bureaucrat Boring1("Jean", 14);
		Form paper1("form A.112", 13, 12);
		Form paper2("form B.411", 12, 11);

		// paper1.beSigned(Boring1);
		std::cout << Boring1 << std::endl;
		std::cout << paper1 << std::endl;
		Boring1.incrementGrade();
		paper1.beSigned(Boring1);
		std::cout << Boring1 << std::endl;
		std::cout << paper1 << std::endl;

		Boring1.signForm(paper2);
		Boring1.incrementGrade();
		Boring1.signForm(paper2);

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
