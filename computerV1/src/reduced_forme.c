/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduced_forme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:27:11 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/28 09:25:53 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

void	reduced_forme2(double a, double b)
{
	ft_putstr("Reduced form: ");
	if (a != 0)
	{
		ft_putdouble(a);
		ft_putstr("x²");
	}
	if (b != 0)
	{
		if (b < 0 && a != 0)
		{
			ft_putstr(" - ");
			b *= -1;
		}
		else if (a != 0)
			ft_putstr(" + ");
		if (b != 1)
			ft_putdouble(b);
		ft_putchar('x');
	}
}

void	reduced_forme(double a, double b, double c)
{
	reduced_forme2(a, b);
	if (c != 0)
	{
		if (c < 0 && (a != 0 || b != 0))
		{
			ft_putstr(" - ");
			c *= -1;
		}
		else if (a != 0 || b != 0)
			ft_putstr(" + ");
		ft_putdouble(c);
	}
	if (a != 0 || b != 0 || c != 0)
		ft_putendl(" = 0");
	else
		ft_putendl("0 = 0");
}
