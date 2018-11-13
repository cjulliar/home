/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:50:35 by cjulliar          #+#    #+#             */
/*   Updated: 2018/11/13 14:51:42 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_upper(char *str)
{
	char	*rep;
	int		i;

	rep = (char *)malloc(sizeof(char) * ((int)ft_strlen(str) + 1));
	rep[ft_strlen(str)] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			rep[i] = str[i] - 32;
		else
			rep[i] = str[i];
		i++;
	}
	return (rep);
}
