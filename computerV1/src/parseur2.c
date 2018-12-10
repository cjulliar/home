/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:10:49 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/28 12:21:34 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

int		isnumber(char *str, int i, int y, char *n)
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
	i = isnumber(str, i, y, n);
	if (i < 0)
		return (i);
	i = isolation(str, i, ft_atoidouble(n), v);
	free(n);
	return (i);
}

int		xalonerepa(char *str, int i, t_values *v, int y)
{
	if (str[i] == '2' && str[y - 1] == '-')
		v->a -= 1;
	else if (str[i] == '2')
		v->a += 1;
	else if (str[i] == '1' && str[y - 1] == '-')
		v->b -= 1;
	else if (str[i] == '1')
		v->b += 1;
	else if (str[i] == '0' && str[y - 1] == '-')
		v->c -= 1;
	else if (str[i] == '0')
		v->c += 1;
	return (i++);
}

int		xalone(char *str, int i, t_values *v)
{
	int		y;

	if (str[i] == '-')
		i++;
	y = i;
	if (str[i + 1] == '^')
	{
		i += 2;
		while (str[i] == '0' && ft_isnumeric(str[i + 1]) == 1)
			i++;
		if ((str[i] != '1' && str[i] != '0' && str[i] != '2')
				|| ft_isnumeric(str[i + 1]) == 1)
			return (-1);
		i = xalonerepa(str, i, v, y);
		i++;
	}
	else
	{
		if (str[y - 1] == '-')
			v->b -= 1;
		else
			v->b += 1;
		i++;
	}
	return (i - 1);
}
