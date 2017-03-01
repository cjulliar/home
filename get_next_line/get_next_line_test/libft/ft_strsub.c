/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:46:57 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 15:15:10 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size || len > size)
		str = NULL;
	else
		str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s + start, len);
	return (str);
}
