/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:18:37 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/22 15:53:41 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	tmp = ft_strnew(ft_strlen(str));
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, str);
	while (j > 0)
	{
		str[i] = tmp[j];
		i++;
		j--;
	}
	str[i] = tmp[j];
	return (str);
}
