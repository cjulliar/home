/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:39:45 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/20 21:48:32 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s_s1;

	s_s1 = ft_strlen(s1);
	i = 0;
	while (i < n)
	{
		if (s2[i] == '\0')
		{
			s1[s_s1 + i] = '\0';
			break ;
		}
		else
			s1[s_s1 + i] = s2[i];
		i++;
	}
	s1[s_s1 + i] = '\0';
	return (s1);
}
