/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:33:49 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 14:55:53 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lower(char *str)
{
	char	*rep;
	size_t	i;

	i = 0;
	rep = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (rep == NULL)
		return (NULL);
	while (i < ft_strlen(str))
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			rep[i] = str[i] + 'a' - 'A';
		else
			rep[i] = str[i];
		i += 1;
	}
	rep[i] = '\0';
	return (rep);
}
