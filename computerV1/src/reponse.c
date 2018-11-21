/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reponse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:27:25 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/21 12:57:57 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

void	degre0(double c)
{
	ft_putendl("Polynomial degree: 0");
	ft_putendl("The solution is:");
	if (c != 0)
		ft_putstr("false");
	else
		ft_putdouble(c);
	ft_putendl("");
}

void	allisgood(int i)
{
	ft_putstr("Polynomial degree: ");
	ft_putnbr(i);
	ft_putendl("\nAll real number are solution.");
}

void	degre2nul(void)
{
	ft_putendl("Polynomial degree: 2");
	ft_putendl("All real number are solution.");
}

void	degre1(double b, double c)
{
	double r;

	r = -c / b;
	ft_putendl("Polynomial degree: 1");
	ft_putendl("The solution is:");
	if (((int)(r * 1000000) % 10000) > 0)
	{
		ft_putdouble(-c);
		ft_putchar('/');
		ft_putdouble(b);
	}
	else
		ft_putdouble(r);
	ft_putendl("");
}

void	reponse(double a, double b, double c, t_values *v)
{
	if (a == 0 && b == 0 && v->a == 0 && v->b == 0 && v->c != 0)
		allisgood(0);
	else if (a == 0 && b == 0 && v->a == 0 && v->b == 0)
		degre0(c);
	else if (a == 0 && c == 0 && v->a == 0 && b == 0 && v->b != 0)
		allisgood(1);
	else if (a != 0 && b == 0 && c == 0)
		allisgood(2);
	else if (a == 0)
		degre1(b, c);
	else
		degre2(a, b, c);
}
