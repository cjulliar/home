/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:03:23 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 16:49:07 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (size != 0 && dst[y] != '\0')
	{
		y = y + 1;
		size = size - 1;
	}
	if (size == 0)
		return (y + ft_strlen(src));
	while (size != 1 && src[i] != '\0')
	{
		dst[y + i] = src[i];
		i = i + 1;
		size = size - 1;
	}
	dst[y + i] = '\0';
	return (y + ft_strlen(src));
}
