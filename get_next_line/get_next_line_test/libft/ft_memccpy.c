/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:43:53 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/07 15:58:53 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	i = 0;
	str = (char*)dst;
	str2 = (char*)src;
	while (i < n)
	{
		str[i] = str2[i];
		if (str2[i] == c)
			return (dst + (i + 1));
		else
			i++;
	}
	return (NULL);
}
