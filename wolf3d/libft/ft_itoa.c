/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:20:46 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 14:57:57 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int i)
{
	int		rep;

	rep = 1;
	while (i / 10 != 0)
	{
		i = i / 10;
		rep = rep + 1;
	}
	return (rep);
}

char		*ft_itoa(int n)
{
	char	*rep;
	long	l;
	int		i;

	l = (long)n;
	i = ft_getlen(l);
	if (n < 0)
		i = i + 1;
	if (!(rep = ft_strnew(i)))
		return (NULL);
	if (l == 0)
		rep[0] = '0';
	if (l < 0)
	{
		l = l * -1;
		rep[0] = '-';
	}
	i = i - 1;
	while (l > 0)
	{
		rep[i] = (l % 10) + '0';
		l = l / 10;
		i = i - 1;
	}
	return (rep);
}
