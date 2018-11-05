/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:25:00 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/05 12:32:54 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
#include <unistd.h>
#include <stdio.h>
// on decompose notre chaine en int
void	ft_decomposition(char *str)
{
	int		i = 0;
	int		y = 0;
//	int		*abc[3];

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			printf("%d\n",ft_atoi(str));
			y = i;
			while (str[y] == 'x' || str[y] == '\0')
			{
				if (str[y+1] == '^')
				{

				}
				y++;
			}
			while (str[i] >= '0' && str[i] <= '9')
			{
				str[i] = ' ';
				i++;
			}
		}
		i++;
	}
}

char	*ft_sansEspace(char *str)
{
	int		i = 0;
	int		s = 0;
	char	*ret;
	while (str[i] != '\0')
	{
		if (str[i] != '\f' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r' && str[i] != '\v' && str[i] != ' ')
			s++;
		i++;
	}
	ret = (char*)malloc(sizeof(char) * (s + 1));
	ret[s] = '\0';
	i = 0;
	s = 0;
	while(str[i] != '\0')
	{
		if (str[i] != '\f' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r' && str[i] != '\v' && str[i] != ' ')
		{
			ret[s] = str[i];
			s++;
		}
		i++;
	}
	return (ret);
}

// on check les erreurs evidente
void	ft_verif(char *str)
{
	int		i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'X')
			str[i] = 'x';
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^' && str[i] == '='
		&& str[i] != '\f' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
		&& str[i] != ' ' && (str[i] < '0' || str[i] > '9') && str[i] != 'x')
		{
			ft_putstr("Your equation contains an error on ");
			ft_putnbr(i + 1);
			if (i + 1 == 1)
				ft_putstr("st character: '");
			else if (i + 1 == 2)
				ft_putstr("nd character: '");
			else if (i + 1 == 3)
				ft_putstr("rd character: '");
			else
				ft_putstr("th character: '");
			ft_putchar(str[i]);
			ft_putendl("'.");
			return ;
		}
		i++;
	}
	str = ft_sansEspace(str);
	ft_decomposition(str);
}

int		main(int ac, char **ag)
{
	if (ac == 1)
		ft_putstr("You have to note an equation.\n\nLike this: a * X ^ 2 + b * X ^ 1 + c * X ^ 1.i\nwith a, b and c numeric numbers.\n");
	else
	{
		ft_verif(ag[1]);
	}
	return (0);
}
