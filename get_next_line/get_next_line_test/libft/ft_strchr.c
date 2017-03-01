/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:17:08 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/10 14:43:29 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_s;
	char	*s_tmp;

	i = 0;
	s_tmp = (char*)s;
	s_s = ft_strlen(s_tmp) + 1;
	while (i < s_s)
	{
		if (s_tmp[i] == c)
			return (&s_tmp[i]);
		i++;
	}
	return (NULL);
}
