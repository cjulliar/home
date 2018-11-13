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

int		isolation(char *str, int i, double n, t_values *v)
{
	if (str[i] != '*' && str[i] != 'X')
	{
		v->c += n;
		return (i);
	}
	if (str[i] == '*')
		i++;
	if (ft_isdigit(str[i]) == 1)
		return (-1);
	if (str[i + 1] != '^')
	{
		v->b = n;
		return(i + 1);
	}
	i += 2;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	if (ft_isdigit(str[i+1]) == 1)
		return (-1);
	if (str[i] == '2')
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
		if (str[i]=='.')
			return (-1);
	}
	i = isolation(str,i,ft_atoidouble(n),v);

	return (i);
}

int		parseur(char *strO, t_values *v, t_values *r)
{
	char *str;
	int		i;

	str = ft_nospace(strO);
	if (str[0] == '\0')
		return (-2);
	i = 0;
	while(str[i] != '=')
	{
		if (str[i] == '\0')
			return (0);
		if (str[i] == '+' && str[i+1] == 'X')
			v->b += 1;
		else if (str[i] == '-' && str[i+1] == 'X')
			v->b -= 1;
		else if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str,i,v) - 1;
			if (i < 0)
				return (i);
		}
		i++;
	}
	while(str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str,i,r) - 1;
			if (i < 0)
				return (i);
		}
		i++;
	}
	return (1);
}
