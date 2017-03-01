/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:44:06 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 13:36:36 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_finded_little_n(char *big, char *little, size_t len, int pos)
{
	char	tmp[(int)len - pos];

	ft_strncpy(tmp, big + pos, len - (size_t)pos);
	if (ft_strncmp(tmp, little, ft_strlen(little)) == 0)
		return (pos);
	else if (pos < (int)len && big[pos] != '\0')
		return (ft_finded_little_n(big, little, len, pos + 1));
	else
		return (-1);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*t_big;
	char	*t_little;
	int		occ;

	t_big = (char*)big;
	t_little = (char*)little;
	if (ft_strcmp(t_little, "") == 0)
		return (t_big);
	else if (ft_strcmp(t_big, "") == 0 || len == 0 || len < ft_strlen(t_little))
		return (NULL);
	occ = ft_finded_little_n(t_big, t_little, len, 0);
	if (occ == -1)
		return (NULL);
	return (t_big + occ);
}
