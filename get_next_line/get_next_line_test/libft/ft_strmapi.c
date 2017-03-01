/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:24:09 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 15:12:08 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (str);
}
