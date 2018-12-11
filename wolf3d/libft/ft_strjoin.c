/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 08:59:42 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/21 10:52:29 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rep;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	rep = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (rep == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		rep[y] = s1[i];
		i = i + 1;
		y = y + 1;
	}
	i = 0;
	while (s2[i] != '\0')
		rep[y++] = s2[i++];
	rep[y] = '\0';
	return (rep);
}
