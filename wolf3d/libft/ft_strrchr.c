/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:36:45 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/10 16:30:23 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	y;
	char	*entree;

	entree = (char *)s;
	y = 0;
	i = ft_strlen(entree);
	if (c == '\0')
		return (&entree[ft_strlen(entree)]);
	while (i > y && entree[i] != c)
	{
		i = i - 1;
		if (entree[i] == c)
			y = 1;
	}
	if (y == 0 || entree[0] == '\0')
		return (NULL);
	return (&entree[i]);
}
