/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlapierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:36:08 by tlapierr          #+#    #+#             */
/*   Updated: 2016/11/21 10:42:54 by tlapierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start_index(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static size_t	ft_end_index(char *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	if (i < 0)
		i = 0;
	return ((size_t)i);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i_start;
	size_t	i_end;

	if (!s)
		return (NULL);
	str = (char*)s;
	i_start = ft_start_index(str);
	i_end = ft_end_index(str);
	if (!ft_strcmp(str, ""))
		return ("");
	else if (i_start >= i_end)
		return (ft_strdup(""));
	str = ft_strnew(i_end - i_start + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s + i_start, i_end - i_start + 1);
	return (str);
}
