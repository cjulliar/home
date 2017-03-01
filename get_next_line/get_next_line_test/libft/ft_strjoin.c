/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:11:22 by tlapierr          #+#    #+#             */
/*   Updated: 2016/12/19 23:28:21 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = ft_strnew(size_s1 + size_s2 + 1);
	if (str == NULL)
		return (NULL);
	if (size_s1 > 0)
		ft_strcpy(str, s1);
	if (size_s2 > 0)
		ft_strcat(str, s2);
	return (str);
}
