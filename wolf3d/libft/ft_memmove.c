/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:25:24 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/09 14:51:35 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*retour;
	char	*entree;

	retour = (char *)dst;
	entree = (char *)src;
	i = len - 1;
	if (len > 0 && (void*)src + (len - 1) >= dst && (void*)src <= dst)
	{
		while (i != 0)
		{
			retour[i] = entree[i];
			i = i - 1;
		}
		retour[i] = entree[i];
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
