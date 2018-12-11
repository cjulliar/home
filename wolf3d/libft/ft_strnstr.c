/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:24:38 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 22:04:56 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int y;

	i = 0;
	y = 0;
	if (len == 0)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] && i < len)
	{
		while (big[i + y] == little[y] && little[y] && i < len)
			y = y + 1;
		if (little[y] == '\0' && i + y <= len)
			return ((char*)&big[i]);
		else
			y = 0;
		i = i + 1;
	}
	return (NULL);
}
