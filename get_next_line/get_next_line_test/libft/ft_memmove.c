/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:41:02 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/09 14:01:41 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dst;
	s2 = (char*)src;
	if (len > 0 && ((void*)(src) + (len - 1) >= dst) && (void*)src <= dst)
	{
		len--;
		while (len != 0)
		{
			s1[len] = s2[len];
			len--;
		}
		s1[len] = s2[len];
	}
	else if (len > 0)
		ft_memcpy(dst, src, len);
	return (dst);
}
