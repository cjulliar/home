/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:40:29 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/15 15:49:13 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*rep;

	i = 0;
	rep = malloc(sizeof(char *) * size);
	if (rep == NULL)
		return (NULL);
	while (i < size)
		rep[i++] = 0;
	return (rep);
}
