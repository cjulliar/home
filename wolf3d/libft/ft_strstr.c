/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:04:14 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/15 14:18:51 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	char	*rep;
	size_t	y;
	char	*ptiot;

	ptiot = (char *)little;
	rep = (char *)big;
	y = 0;
	i = 0;
	if (ptiot[0] == '\0')
		return (rep);
	while (rep[i] != '\0')
	{
		if (ft_strncmp(rep + i, ptiot, ft_strlen(ptiot)) == 0)
		{
			return (rep + i);
		}
		i = i + 1;
	}
	return (NULL);
}
