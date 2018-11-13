/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degre2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:50:29 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 17:00:54 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

void	degre2reelnum(double a, double b, double d, char s)
{
	double r;

	if (s == '+')
		r = (-1 * b + ft_sqrtdouble(d)) / (2 * a);
	else
		r = (-1 * b - ft_sqrtdouble(d)) / (2 * a);
	if (ft_isinteger(r, 2) == 0)
	{
		if (s == '+')
			ft_putdouble(-1 * b + ft_sqrtdouble(d));
		else
			ft_putdouble(-1 * b - ft_sqrtdouble(d));
		ft_putstr(" / ");
		ft_putdouble(2 * a);
	}
	else
		ft_putdouble(r);
	ft_putendl("");
	if (s == '+')
		degre2reelnum(a, b, d, '-');
}

void	degre2dnul(double a, double b)
{
	ft_putendl("Discriminant is null, the solution is:");
	if (ft_isinteger((-1 * b) / (2 * a), 2) == 0)
	{
		if ((b < 0 && a > 0) || (b > 0 && a < 0))
		{
			ft_putdouble(b);
			ft_putstr(" / ");
			ft_putdouble(2 * a);
		}
		else
		{
			if (a < 0 && b < 0)
			{
				a *= -1;
				b *= -1;
			}
			ft_putstr("-");
			ft_putdouble(b);
			ft_putstr(" / ");
			ft_putdouble(2 * a);
		}
	}
	else
		ft_putdouble((-1 * b) / (2 * a));
	ft_putendl("");
}

void	degre2pn2(double b, double d)
{
	if (b != 0 && d != 0)
		ft_putstr("(");
	if (b < 0)
		ft_putdouble(-1 * b);
	else if (b > 0)
	{
		ft_putstr("-");
		ft_putdouble(b);
	}
	if (b != 0)
		ft_putstr(" ");
}

void	degre2pn(double a, double b, double d, char s)
{
	degre2pn2(b, d);
	if (b != 0 || s == '-')
		ft_putchar(s);
	ft_putstr(" ");
	if (d < 0)
		ft_putstr("i");
	if (ft_isinteger(ft_sqrtdouble(ft_absdouble(d)), 2) == 0)
	{
		ft_putstr("√");
		ft_putdouble(ft_absdouble(d));
	}
	else
		ft_putdouble(ft_sqrtdouble(ft_absdouble(d)));
	if (b != 0 && d != 0)
		ft_putstr(")");
	ft_putstr(" / ");
	ft_putdouble(2 * a);
	ft_putendl("");
	if (s == '+')
		degre2pn(a, b, d, '-');
}

void	degre2(double a, double b, double c)
{
	double d;

	ft_putendl("Polynomial degree: 2");
	d = b * b - 4 * a * c;
	ft_putstr("delta = ");
	ft_putdouble(d);
	ft_putendl("");
	if (d > 0)
	{
		ft_putendl("Discriminant is strictly positive, the two solutions are:");
		if (ft_isinteger(ft_sqrtdouble(d), 2) == 0)
			degre2pn(a, b, d, '+');
		else
			degre2reelnum(a, b, d, '+');
	}
	else if (d == 0)
		degre2dnul(a, b);
	else
	{
		ft_putendl("Discriminant is strictly negative, the two solutions are:");
		degre2pn(a, b, d, '+');
	}
}
