/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:03:18 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/05 19:41:18 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*retour;
	char	*entree;

	retour = (char *)dst;
	entree = (char *)src;
	i = 0;
	while (i < n)
	{
		retour[i] = entree[i];
		i = i + 1;
	}
	return (retour);
}
