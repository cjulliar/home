/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:25:00 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 17:40:51 by cjulliar         ###   ########.fr       */
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

void	to_error_on_not(int ac, char **ag, t_values *v, t_values *r, int ok)
{
	char	*s;

	if (ac < 2 && (s = (char*)malloc(sizeof(char) * ft_strlen(ag[1]))) == NULL)
		return ;
	s = ft_upper(ag[1]);
	ok = parseur(s, v, r);
	if (ac == 1 || ok == 0)
		speak();
	else if (ok == -1)
	{
		ft_putstr("The polynomial degree must below than 3 and positive, ");
		ft_putendl("I can't solve that.");
	}
	else if (ok == -2)
	{
		ft_putendl("You have to note an equation.");
		ft_putendl("Like this: a * X ^ 2 + b * X ^ 1 + c * X ^ 0 = 0");
		ft_putendl("with a, a', b, b', c and c' numeric numbers.");
	}
	else
		resolution(v, r);
	free(s);
}

int		main(int ac, char **ag)
{
	t_values	*v;
	t_values	*r;
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
	to_error_on_not(ac, ag, v, r, 0);
	free(v);
	free(r);
	return (0);
}
