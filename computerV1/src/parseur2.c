/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:26:54 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 16:56:09 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/computer.h"

int		isolation2(char *str, int i, double n, t_values *v)
{
	i += 2;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	if (ft_isdigit(str[i + 1]) == 1)
		return (-1);
	if (str[i] == '2')
		v->a += n;
	else if (str[i] == '1')
		v->b += n;
	else if (str[i] == '0')
		v->c += n;
	return (i + 1);
}

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
		return (i + 1);
	}
	i = isolation2(str, i, n, v);
	return (i);
}
