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
	double r;
	double x;

	r = 0;
	x = 1;
	n *= 10000;
	while (n > 0)
	{
		if (x*x > n)
		{
			x = x - 1;
			printf("%f (%f) - %f - %f - \n",x,x*x,n,r);
			r = r + x;
			n -= x*x;
			x = 1;
			printf("%f (%f) - %f - %f - \n\n",x,x*x,n,r);
		}
		else
		{
			x++;
		}
	}
	// r /= 1000;
	return (r);
}

void	reduced_forme(double a, double b, double c)
{
	if (a != 0 || b != 0 || c != 0)
		ft_putstr("Reduced form: ");
	if (a != 0)
	{
		ft_putdouble(a);
		if (b < 0)
		{
			ft_putstr("x² - ");
			b *= -1;
		}
		else
			ft_putstr("x² + ");
	}
	if (b != 0)
	{
		ft_putdouble(b);
		if (c < 0)
		{
			ft_putstr("x - ");
			c *= -1;
		}
		else
			ft_putstr("x + ");
	}
	if (c != 0)
		ft_putdouble(c);
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
	if (((int)(r * 1000000) % 10000) != 0)
	{
		ft_putdouble(-c);
		ft_putchar('/');
		ft_putdouble(b);
	}
	else
		ft_putdouble(r);
	ft_putendl("");
}

void	degre2(double a, double b, double c)
{
	double d;
	// double r;

	ft_putendl("Polynomial degree: 1");
	d = b*b - 4*a*c;
	if (d > 0)
	{
		ft_putendl("Discriminant is strictly positive, the two solutions are:");
		
		
	}
}

void	resolution(t_values *v, t_values *r)
{
	double kk = 16.34;
	printf("\nres: %f\n",ft_sqrtdouble(kk));

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
