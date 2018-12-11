/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:06:48 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/15 16:46:11 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*rep;
	size_t	i;

	i = 0;
	rep = malloc(sizeof(char) * (size + 1));
	if (rep == NULL)
		return (NULL);
	while (i < size)
		rep[i++] = 0;
	rep[i] = 0;
	return (rep);
}
