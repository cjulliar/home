/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:11:32 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/19 19:01:42 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s_dst;

	s_dst = ft_strlen(dst);
	i = s_dst;
	if (s_dst > size)
		s_dst = size;
	j = 0;
	while (i < size - 1)
	{
		if (src[j] == '\0')
			break ;
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (s_dst + ft_strlen(src));
}
