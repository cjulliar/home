/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:54:10 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/09 15:20:02 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rep;
	size_t	i;
	size_t	y;

	y = 0;
	i = ft_strlen(s1);
	rep = (char *)malloc(sizeof(char) * (i + 1));
	if (rep == NULL)
		return (NULL);
	while (y < i)
	{
		rep[y] = s1[y];
		y = y + 1;
	}
	rep[y] = '\0';
	return (rep);
}
