/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:25:16 by cjulliar          #+#    #+#             */
/*   Updated: 2016/11/20 18:12:51 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrw(char const *s, char c)
{
	int		i;
	int		rep;

	rep = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			rep = rep + 1;
		i = i + 1;
	}
	return (rep);
}

static char	*ft_word(char const *s, int i, int l, char c)
{
	int		p;
	char	*rep;

	p = 0;
	rep = (char *)malloc(sizeof(char) * (l + 1));
	while (s[i] != c && s[i] != '\0')
	{
		rep[p] = s[i];
		p = p + 1;
		i = i + 1;
	}
	rep[p] = '\0';
	return (rep);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**rep;
	int		i;
	int		y;
	int		l;

	l = 0;
	i = 0;
	y = 0;
	if (!s || !c)
		return (NULL);
	if (!(rep = (char **)malloc(sizeof(char *) * (ft_nbrw(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
			l = l + 1;
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
		{
			rep[y++] = ft_word(s, (i - l + 1), l, c);
			l = 0;
		}
		i = i + 1;
	}
	rep[y] = NULL;
	return (rep);
}
