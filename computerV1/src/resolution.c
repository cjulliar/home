/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:42:11 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/09 14:33:30 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
#include <stdio.h>

int		ft_abs(int i)
{
	if (i == -2147483648)
		return(2147483647);
	if (i < 0)
		i *= -1;
	return (i);
}

double	ft_absdouble(double i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

void	ft_putdouble(double n)
{
	int		i;

	i = (int)n;
	ft_putnbr(i);
	n = n * 1000000;
	i = ft_abs((int)n % 1000000);
	if (i == 0)
		return ;
	while (i % 10 == 0)
	{
		i = i / 10;
	}
	ft_putchar('.');
	ft_putnbr(i);
}

double	ft_sqrtdouble(double n)
{
	double x = 1;
	double y = 0.5*(1+n);
	while (ft_absdouble(y-x) > 0.0001)
	{
		x = y;
		y = 0.5 * (x+n/x);
	}
	return (y);
}

int		ft_puissance(int i, int p)
{
	int		r;

	r = 1;
	while (p > 0)
	{
		r *= i;
		p--;
	}
	return (r);
}

int		ft_isinteger(double n, int v)
{
	if (n < 0)
		n *= -1;
	if (((int)(n * 1000000) % (1000000 / (ft_puissance(10,v)))) > 0)
		return (0);
	return (1);
}

void	reduced_forme(double a, double b, double c)
{
	if (a != 0 || b != 0 || c != 0)
		ft_putstr("Reduced form: ");
	if (a != 0)
	{
		ft_putdouble(a);
		ft_putstr("x²");
	}
	if (b != 0)
	{
		if (b < 0)
		{
			ft_putstr(" - ");
			b *= -1;
		}
		else
			ft_putstr(" + ");
		ft_putdouble(b);
		ft_putchar('x');
	}
	if (c != 0)
	{
		if (c < 0)
		{
			ft_putstr(" - ");
			c *= -1;
		}
		else
			ft_putstr(" + ");
		ft_putdouble(c);
	}
	if (a != 0 || b != 0 || c != 0)
		ft_putendl(" = 0");
}

void	degre0(double c)
{
	ft_putendl("Polynomial degree: 0");
	ft_putendl("The solution is:");
	ft_putdouble(c);
	ft_putendl("");
}

void	degre1nul()
{
	ft_putendl("Polynomial degree: 1");
	ft_putendl("All real number are solution.");
}

void	degre2nul()
{
	ft_putendl("Polynomial degree: 2");
	ft_putendl("All real number are solution.");
}

void	degre1(double b, double c)
{
	double r;

	r = -c/b;
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


void	degre2reeldev(double a, double b, double d, char s)
{

	printf("degre2reeldev\n");
	if (b > 0)
		ft_putstr("(-");
	else
		ft_putstr("(");
	ft_putdouble(b);
	ft_putstr(" ");
	ft_putchar(s);
	ft_putstr(" √");
	ft_putdouble(d);
	ft_putstr(") / ");
	ft_putdouble(2*a);
	ft_putendl("");
	if (s == '+')
		degre2reeldev(a, b, d, '-');
}

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

void	degre2dneg(double a, double b, double d, char s)
{
	ft_putstr("(");
	if(b < 0)
		ft_putdouble(-1 * b);
	else
	{
		ft_putstr("-");
		ft_putdouble(b);
	}
	ft_putstr(" ");
	ft_putchar(s);
	ft_putstr(" i");
	if (ft_isinteger(ft_sqrtdouble(ft_absdouble(d)), 2) == 0)
	{
		ft_putstr("√");
		ft_putdouble(ft_absdouble(d));
	}
	else
		ft_putdouble(ft_sqrtdouble(ft_absdouble(d)));
	ft_putstr(") / ");
	ft_putdouble(2*a);
	ft_putendl("");
	if (s == '+')
		degre2dneg(a, b, d, '-');
}

void	degre2(double a, double b, double c)
{
	double d;

	ft_putendl("Polynomial degree: 2");
	d = b*b - 4*a*c;
	ft_putstr("delta = ");
	ft_putdouble(d);
	ft_putendl("");
	
	if (d > 0)
	{
		ft_putendl("Discriminant is strictly positive, the two solutions are:");
		if (ft_isinteger(ft_sqrtdouble(d), 0) == 0)
			degre2reeldev(a, b, d, '+');
		else
			degre2reelnum(a, b, d, '+');
	}
	else if (d == 0)
		degre2dnul(a, b);
	else
	{
		ft_putendl("Discriminant is strictly negative, the two solutions are:");
		degre2dneg(a, b, d, '+');
	}
}

void	resolution(t_values *v, t_values *r)
{
	double	a;
	double	b;
	double	c;

	a = (double)v->a - (double)r->a;
	b = (double)v->b - (double)r->b;
	c = (double)v->c - (double)r->c;
	if (a < 0 || (a == 0 && b < 0) || (a == 0 && b == 0 && c < 0))
	{
		a *= -1;
		b *= -1;
		c *= -1;
	}
	reduced_forme(a, b, c);
	
	if (a == 0 && b == 0 && v->a == 0 && v-> b == 0)
		degre0(c);
	else if (a == 0 && c == 0 && v->a == 0 && b == 0 && v->b != 0)
		degre1nul();
	else if (a == 0 && v->a != 0 && b == 0 && v->b == 0 && c == 0)
		degre2nul();
	else if (a == 0 && v-> a == 0)
		degre1(b, c);
	else
		degre2(a, b, c);

}
