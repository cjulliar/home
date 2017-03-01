/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:07:13 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/10 16:41:53 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	s_s;
	int		l_i;
	char	*tmp;

	i = 0;
	l_i = -1;
	s_s = ft_strlen(s) + 1;
	tmp = (char*)s;
	while (i < s_s)
	{
		if (s[i] == c)
			l_i = (int)i;
		i++;
	}
	if (l_i != -1)
		return (&tmp[l_i]);
	else
		return (NULL);
}
