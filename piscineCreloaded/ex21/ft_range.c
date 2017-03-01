/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:53:03 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/04 16:54:34 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*res;
	int		taille;
	int		i;

	i = 0;
	taille = max - min;
	if (min >= max)
		return (0);
	if (taille < 0)
	{
		res = malloc(sizeof(int) * 0);
		return (res);
	}
	res = malloc(sizeof(int) * taille);
	while (min < max)
	{
		res[i] = min;
		i = i + 1;
		min = min + 1;
	}
	return (res);
}
