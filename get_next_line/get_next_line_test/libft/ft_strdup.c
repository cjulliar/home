/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:46:04 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/08 15:32:28 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cp;
	size_t	sz1;
	size_t	i;

	sz1 = ft_strlen(s1);
	cp = (char*)malloc(sizeof(char) * sz1 + 1);
	i = 0;
	if (cp == NULL)
		return (NULL);
	while (i < sz1)
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
