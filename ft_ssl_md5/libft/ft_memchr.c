/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:44:22 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 15:38:01 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*entree;

	entree = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (entree[i] == (unsigned char)c)
		{
			return (&entree[i]);
		}
		i = i + 1;
	}
	return (NULL);
}
