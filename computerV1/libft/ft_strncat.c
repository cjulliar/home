/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:27:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/10 13:54:27 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	i = ft_strlen(s1);
	while (y < n && s2[y] != '\0')
	{
		s1[i] = s2[y];
		y = y + 1;
		i = i + 1;
	}
	s1[i] = '\0';
	return (s1);
}
