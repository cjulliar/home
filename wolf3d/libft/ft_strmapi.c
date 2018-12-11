/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:50:36 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/19 15:00:40 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rep;

	rep = NULL;
	if (s && f)
	{
		i = 0;
		rep = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (rep == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			rep[i] = f(i, s[i]);
			i = i + 1;
		}
		rep[i] = '\0';
	}
	return (rep);
}
