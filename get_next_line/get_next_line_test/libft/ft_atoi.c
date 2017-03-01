/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:29:50 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/20 21:14:17 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find_start(const char *str, int *sign)
{
	size_t	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] == 43)
	{
		*sign = 1;
		return ((char*)(str) + i + 1);
	}
	else if (str[i] == 45)
	{
		*sign = -1;
		return ((char*)(str) + i + 1);
	}
	else
		*sign = 1;
	return ((char*)(str) + i);
}

int			ft_atoi(const char *str)
{
	int		value;
	int		sign;
	char	*tmp;
	size_t	i;

	sign = 0;
	value = 0;
	i = 0;
	tmp = ft_find_start(str, &sign);
	while (tmp[i] != '\0')
	{
		if (tmp[i] >= 48 && tmp[i] <= 57)
			value = value * 10 + (tmp[i] - 48) * sign;
		else
			break ;
		i++;
	}
	return (value);
}
