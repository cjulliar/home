/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:12:42 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/09 11:07:40 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	i = 0;
	str = (char*)src;
	str2 = (char*)dst;
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dst);
}
