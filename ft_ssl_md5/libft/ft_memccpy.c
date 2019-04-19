/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:49:01 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/06 13:18:03 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*retour;
	char	*entree;

	retour = (char *)dst;
	entree = (char *)src;
	i = 0;
	while (i < n)
	{
		retour[i] = entree[i];
		if (entree[i] == c)
		{
			i = i + 1;
			return (&retour[i]);
		}
		i = i + 1;
	}
	return (NULL);
}
