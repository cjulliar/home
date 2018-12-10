/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:40:07 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/28 11:14:21 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

int		firstpart(char *str, int i, t_values *v)
{
	if (str[0] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\0')
			return (0);
		if (str[i] == 'X' || (str[i] == '-' && str[i + 1] == 'X'))
		{
			if ((i = xalone(str, i, v)) == -1)
				return (-1);
		}
		else if (ft_isdigit(str[i]) == 1 || str[i] == '-')
		{
			i = analyse(str, i, v) - 1;
			if (i < 0)
				return (i);
		}
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

int		secondpart(char *str, int i, t_values *v)
{
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (0);
		if (str[i] == 'X' || (str[i] == '-' && str[i + 1] == 'X'))
		{
			if ((i = xalone(str, i, v)) == -1)
				return (-1);
		}
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
	i = firstpart(str, 0, v);
	if (i <= 0)
		return (i);
	i = secondpart(str, i + 1, r);
	if (i <= 0)
		return (i);
	free(str);
	return (1);
}
