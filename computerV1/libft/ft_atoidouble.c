/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:46:04 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/12 11:31:59 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	attribution(const char *str, int i)
{
	double	res;
	int		y;

	res = 0;
	y = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i = i + 1;
	}
	if (str[i] == '.' || str[i] == ',')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res + (str[i] - '0') * ft_puissancedouble(0.1, y);
			y++;
			i = i + 1;
		}
	}
	return (res);
}

double	ft_atoidouble(const char *str)
{
	int		i;
	int		n;
	double	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i = i + 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	res = attribution(str, i);
	return (n * res);
}
