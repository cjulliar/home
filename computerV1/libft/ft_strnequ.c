/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:12:58 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/21 11:12:30 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	res;

	res = 0;
	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && (i + 1) < n)
			i = i + 1;
		if (s1[i] - s2[i] == 0 || s1[0] == '\0' || s2[0] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
