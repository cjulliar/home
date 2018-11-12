/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:25:00 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/12 12:40:50 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
#include <unistd.h>
#include <stdio.h>

char	*ft_upper(char *str)
{
	char	*rep;
	int		i;
	
	rep = (char *)malloc(sizeof(char) * ((int)ft_strlen(str) + 1));
	rep[ft_strlen(str)] = '\0';
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i]<= 'z')
			rep[i] = str[i] - 32;
		else
			rep[i] = str[i];
		i++;
	}
	return (rep);
}

int		main(int ac, char **ag)
{
	t_values	*v;
	t_values	*r;
	int			ok;

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
	printf("ac:%d\n",ac);
	ok = 0;
	if (ac == 1 || (ok = parseur(ft_upper(ag[1]), v, r)) == 0)
	{
		ft_putendl("You have to note an equation.");
		ft_putendl("Like this: a * X ^ 2 + b * X ^ 1 + c * X ^ 0 = 0");
		ft_putstr("or like this: a*X^2 + b*X^1 + c*X^0 = ");
		ft_putendl("a'*X^2 + b'*X^1 + c'*X^0");
		ft_putendl("with a, b and c numeric numbers.");
		printf("ok: %d\n",ok);
	}
	else if (ok == -1)
	{
		ft_putstr("The polynomial degree must below than 3 and positive, ");
		ft_putendl("I can't solve that.");
	}
	else
		resolution(v,r);

	return (0);
}
