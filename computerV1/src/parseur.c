/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:40:07 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 17:41:06 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

int		analyse2(char *str, int i, int y, char *n)
{
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
		if (str[i] == '.')
		{
			free(n);
			return (-1);
		}
	}
	return (i);
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
	i = analyse2(str, i, y, n);
	if (i < 0)
		return (i);
	i = isolation(str, i, ft_atoidouble(n), v);
	free(n);
	return (i);
}

int		parseur2(char *str, int i, t_values *v)
{
	if (str[0] == '\0')
		return (-2);
	i = 0;
	while (str[i] != '=')
	{
		if (str[i] == '\0')
			return (0);
		if (str[i] == '+' && str[i + 1] == 'X')
			v->b += 1;
		else if (str[i] == '-' && str[i + 1] == 'X')
			v->b -= 1;
		else if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str, i, v) - 1;
			if (i < 0)
				return (i);
		}
		i++;
	}
	return (i);
}

int		parseur(char *st, t_values *v, t_values *r)
{
	char	*str;
	int		i;

	str = ft_nospace(st);
	i = parseur2(str, 0, v);
	if (i <= 0)
		return (i);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str, i, r) - 1;
			if (i < 0)
			{
				free(str);
				return (i);
			}
		}
		i++;
	}
	free(str);
	return (1);
}
