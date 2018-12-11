/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:34:55 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/19 14:59:27 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*rep;
	char	*sc;

	rep = NULL;
	if (s && f)
	{
		sc = (char *)s;
		rep = (char *)malloc(sizeof(char) * ft_strlen(sc) + 1);
		if (rep == NULL)
			return (NULL);
		i = 0;
		while (sc[i] != '\0')
		{
			rep[i] = f(sc[i]);
			i = i + 1;
		}
		rep[i] = '\0';
	}
	return (rep);
}
