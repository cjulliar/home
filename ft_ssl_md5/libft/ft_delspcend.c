/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delspcend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:19:07 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 18:28:16 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delspcend(char const *s)
{
	size_t	i;
	size_t	y;
	char	*rep;
	char	*cs;

	cs = (char *)s;
	i = ft_strlen(s);
	y = 0;
	if (!s)
		return (NULL);
	if (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')
	{
		rep = (char *)malloc(sizeof(char) * (i + 1));
		if (rep == NULL)
			return (NULL);
		i = 0;
		while (s[i + 1] != '\0')
			rep[y++] = s[i++];
		rep[y] = '\0';
		return (ft_delspcend(rep));
	}
	return (cs);
}
