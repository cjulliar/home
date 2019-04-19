/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:10:44 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/10 15:04:58 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	y;
	char	*entree;

	entree = (char *)s;
	y = 0;
	i = 0;
	if (c == '\0')
		return (&entree[ft_strlen(entree)]);
	while (entree[i] != '\0' && entree[i] != c)
		i = i + 1;
	if (i >= ft_strlen(entree))
		return (NULL);
	return (&entree[i]);
}
