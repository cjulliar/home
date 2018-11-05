/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 08:14:00 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 18:47:10 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rep;
	int		y;
	int		debut;
	int		len2;

	if (!s)
		return (NULL);
	len2 = (int)len;
	debut = (int)start;
	y = 0;
	rep = (char *)malloc(sizeof(char) * (len + 1));
	if (rep == NULL)
		return (NULL);
	len2 = len2 + start;
	while (debut < len2)
	{
		rep[y] = s[debut];
		y = y + 1;
		debut = debut + 1;
	}
	rep[y] = '\0';
	return (rep);
}
