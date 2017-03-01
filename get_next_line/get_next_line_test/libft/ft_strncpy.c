/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:34:50 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/08 16:07:55 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	s_src;
	size_t	s_dst;

	i = 0;
	s_src = ft_strlen(src);
	s_dst = ft_strlen(dst);
	while (i < len)
	{
		if (i < s_src)
			dst[i] = src[i];
		else if (i < s_dst)
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
