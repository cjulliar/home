/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:13:19 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 15:11:27 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
