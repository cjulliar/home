/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:25:00 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/27 17:03:01 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

void	speak(void)
{
	ft_putendl("You have to note an equation.");
	ft_putendl("Like this: a * X ^ 2 + b * X ^ 1 + c * X ^ 0 = 0");
	ft_putstr("or like this: a*X^2 + b*X^1 + c*X^0 = ");
	ft_putendl("a'*X^2 + b'*X^1 + c'*X^0");
	ft_putendl("with a, b and c numeric numbers.");
}

void	to_error_on_not(int ac, char **ag, t_values *v, t_values *r)
{
	char	*s;
	int		ok;

	ok = 0;
	if (ac < 2 && (s = (char*)malloc(sizeof(char) * ft_strlen(ag[1]))) == NULL)
		return ;
	s = ft_upper(ag[1]);
	ok = parseur(s, v, r);
	if (ac == 1 || ok == 0)
		speak();
	else if (ok == -2)
	{
		ft_putstr("The polynomial degree must below than 3 and positive, ");
		ft_putendl("I can't solve that.");
	}
	else if (ok == -1)
	{
		ft_putendl("You have to note an equation.");
		ft_putendl("Like this: a * X ^ 2 + b * X ^ 1 + c * X ^ 0 = 0");
		ft_putendl("with a, a', b, b', c and c' numeric numbers.");
	}
	else
		resolution(v, r);
	free(s);
}

// pour le projet il faut:
//  5 * x^0 et les test autour
//  x + 3 = 0 marche
//  x^1 + 3 = 0 marche
//  x^2 + 3 = 0 marche
//  6x^2+x^2=0 marche
//  6x^1+x^1=0 marche
//  6x^0+x^0=0 marche
// 3x + 4 = 0, degre 1, solution doit etre equation si trop complique !
int		main(int ac, char **ag)
{
	t_values	*v;
	t_values	*r;

	if (ac < 2)
	{
		speak();
		return (0);
	}
	if ((v = (t_values *)malloc(sizeof(t_values))) == NULL)
		return (0);
	if ((r = (t_values *)malloc(sizeof(t_values))) == NULL)
		return (0);
	v->a = 0;
	v->b = 0;
	v->c = 0;
	r->a = 0;
	r->b = 0;
	r->c = 0;
	to_error_on_not(ac, ag, v, r);
	free(v);
	free(r);
	return (0);
}
