/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:37:33 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 17:00:27 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (us1[i] != '\0' && us2[i] != '\0' && (i + 1) < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i = i + 1;
	}
	return (us1[i] - us2[i]);
}
