/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:37:20 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/05 15:36:17 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;
	int		y;

	i = 0;
	while (src[i] != '\0')
		i = i + 1;
	y = i;
	res = (char*)malloc(sizeof(char) * (i));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i <= y)
	{
		res[i] = src[i];
		i = i + 1;
	}
	return (res);
}
