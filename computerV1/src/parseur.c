/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:40:07 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/12 12:52:13 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"
#include <stdio.h>

char *ft_nospace(char *str)
{
	char	*rep;
	int		ts;
	int		tr;

	ts = 0;
	tr = 0;
	while (str[ts] != '\0')
	{
		// ajouter ici verif de carac valide
		if (ft_isspace(str[ts]) == 0)
			tr++;
		ts++;
	}
	if ((rep = (char *)malloc(sizeof(char) * (tr + 1))) == NULL)
		return (0);
	rep[tr] = '\0';
	ts = 0;
	tr = 0;
	while (str[ts] != '\0')
	{
		if (ft_isspace(str[ts]) == 0)
		{
			rep[tr] = str[ts];
			tr++;
		}
		ts++;
	}
	return (rep);
}

int		isolation(char *str, int i, double n, t_values *v)
{
//	printf("i:[%c] +1:[%c] +2:[%c] +3:[%c] +4:[%c]\n",str[i],str[i+1],str[i+2],str[i+3],str[i+4]);
	if (str[i] != '*' && str[i] != 'X')
	{
		v->c += n;
		return (i);
	}
	if (str[i] == '*')
		i++;
	if (str[i + 1] != '^')
	{
		v->b = n;
		return(i + 2);
	}
	i += 2;
	while (str[i] == '0' && str[i] != '\0')
		i++;
//	printf("--i:[%c] +1:[%c] . %d\n",str[i],str[i+1],ft_isdigit(str[i+1]));
	if (ft_isdigit(str[i+1]) == 1)
		return (-1);
	if (str[i] == '2') // si le mec met 02 ca marche pas, il faut atoi la puissance
		v->a += n;
	else if (str[i] == '1')
		v->b += n;
	else if (str[i] == '0')
		v->c += n;
	return (i+1);
}

int		analyse(char *str, int i, t_values *v)
{
	int		y;
	char	*n;

	if ((n = (char *)malloc(sizeof(char) * (ft_strlen(str)))) == NULL)
		return (0);
	y = 0;
	while (n[y] != '\0')
	{
		n[y] = '\0';
		y++;
	}

	y = 0;
	while (ft_isdigit(str[i]) || (str[i] == '-' && y == 0))
	{
		n[y] = str[i];
		y++;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		n[y] = '.';
		y++;
		while (ft_isdigit(str[i]))
		{
			n[y] = str[i];
			y++;
			i++;
		}
	}
	i = isolation(str,i,ft_atoidouble(n),v);

	return (i);
}

int		parseur(char *strO, t_values *v, t_values *r)
{
	char *str;
	int		i;

	str = ft_nospace(strO);
	i = 0;
	while(str[i] != '=')
	{
		printf("str[%d]: %c\n",i,str[i]);
		if (str[i] == '\0')
		{	printf("error pas de '='\n");
			return (0);}
		if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str,i,v) - 1;
			if (i == -1)
				return (-1);
		}
		i++;
	}
	while(str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str,i,r) - 1;
			if (i == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
