/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delspcbeg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:10:56 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 21:39:30 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delspcbeg(char const *s)
{
	size_t	i;
	size_t	y;
	char	*rep;
	char	*cs;

	cs = (char *)s;
	i = 1;
	y = 0;
	if (!s)
		return (NULL);
	if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
	{
		rep = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (rep == NULL)
			return (NULL);
		while (s[i] != '\0')
			rep[y++] = s[i++];
		rep[y] = '\0';
		return (ft_delspcbeg(rep));
	}
	return (cs);
}
