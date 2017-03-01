/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:14:41 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/16 13:51:32 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_finded_little(char *big, char *little, int pos)
{
	int		find;
	size_t	s_big;
	size_t	s_little;

	find = -1;
	s_big = ft_strlen(big);
	s_little = ft_strlen(little);
	if (s_big - pos >= s_little && ft_strncmp(big + pos, little, s_little) == 0)
		find = pos;
	else if (s_big - pos > s_little)
	{
		pos++;
		find = ft_finded_little(big, little, pos);
	}
	return (find);
}

char			*ft_strstr(const char *big, const char *little)
{
	char	*tmp_big;
	char	*tmp_little;
	int		occ;

	tmp_big = (char*)big;
	tmp_little = (char*)little;
	if (ft_strcmp(tmp_little, "") == 0)
		return (tmp_big);
	else if (ft_strcmp(tmp_big, "") == 0)
		return (NULL);
	occ = ft_finded_little(tmp_big, tmp_little, 0);
	if (occ == -1)
		return (NULL);
	return (tmp_big + occ);
}
