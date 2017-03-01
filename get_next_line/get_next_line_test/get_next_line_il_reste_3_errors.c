/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/12/20 20:15:54 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strndel_beg(char *texte, size_t y)
{
	char	*rep;
	size_t	i;
	size_t	yy;

	yy = y;
	if ((rep = ft_strnew(ft_strlen(texte) - y - 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(texte) - yy - 1))
	{
		y = y + 1;
		rep[i] = texte[y];
		i = i + 1;
	}
	ft_strdel(&texte);
	if ((texte = ft_strnew(i)) == NULL)
		return (NULL);
	ft_strncpy(texte, rep, i);
	ft_strdel(&rep);
	return (texte);
}

static char		*ft_strjoin_free(char *str1, char *str2, size_t n)
{
	char	*rep;

	rep = ft_strjoin(str1, str2);
	if (n == 1)
		ft_strdel(&str1);
	else if (n == 2)
		ft_strdel(&str2);
	else if (n == 3)
	{
		ft_strdel(&str1);
		ft_strdel(&str2);
	}
	return (rep);
}

static int		ft_lecture(int fd, char **line, char **texte, size_t y)
{
	int		b;
	char	*lecture;

	if ((lecture = ft_strnew(BUFF_SIZE))== NULL)
			return (-1);
	b = read(fd, lecture, BUFF_SIZE);
	*texte = ft_strjoin_free(*texte, lecture, 3);
	while (y < ft_strlen(*texte))
	{
		if ((*texte)[y] == '\n' || (*texte)[y] == '\0')
		{
			if ((*line = ft_strnew(y)) == NULL)
				return (-1);
			ft_strncpy(*line, *texte, y);
			if ((*texte)[y] != '\0')
			{
				if ((*texte = ft_strndel_beg(*texte, y)) == NULL)
					return (-1);
			}
			return (-2);
		}
		y = y + 1;
	}
	return (b);
}

int				get_next_line(int fd, char **line)
{
	static char		*texte = NULL;
	int				rep;

	if (texte == NULL || fd < 0)
	{
		if ((texte = ft_strnew(0)) == NULL || fd < 0)
			return (-1);
	}

	rep = ft_lecture(fd, line, &texte, 0);
	while (/**line == NULL &&*/ rep > 0)
		rep = ft_lecture(fd, line, &texte, 0);
	if (rep == -2)
		rep = 1;
	if (rep == 0 && texte[0] != '\0')
	{
		*line = ft_strnew(ft_strlen(texte));
		ft_strncpy(*line, texte, ft_strlen(texte));
		rep = 1;
		ft_strdel(&texte);
	}
	ft_putendl(texte);
	return (rep);
}
