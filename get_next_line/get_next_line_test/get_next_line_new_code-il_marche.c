/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:17:17 by cjulliar          #+#    #+#             */
/*   Updated: 2016/12/20 18:09:16 by cjulliar         ###   ########.fr       */
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
	texte = ft_strnew(i);
	ft_strncpy(texte, rep, i);
	ft_strdel(&rep);
//	ft_putchar('[');
//	ft_putendl(texte);
//	ft_putendl("]");
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

	lecture = ft_strnew(BUFF_SIZE);
	b = read(fd, lecture, BUFF_SIZE);
	*texte = ft_strjoin_free(*texte, lecture, 3);
	while (y < ft_strlen(*texte))
	{
		if ((*texte)[y] == '\n' || (*texte)[y] == '\0')
		{
			*line = ft_strnew(y);
			ft_strncpy(*line, *texte, y);
			if ((*texte)[y] != '\0')
			{
				if ((*texte = ft_strndel_beg(*texte, y)) == NULL)
					return (-1);
			}
			return (1);
		}
		y = y + 1;
	}
	return (b);
}

int				get_next_line(int fd, char **line)
{
//	ft_putendl("");
	static char		*texte = NULL;
	int				rep;

	if (texte == NULL || fd < 0)
	{
//		ft_putendl("passe1");
		if ((texte = ft_strnew(0)) == NULL || fd < 0)
			return (-1);
//		if ((line = (char**)malloc(sizeof(char*))) == NULL)
//			return (-1);
	}
/*	if (line == NULL)	//inutile
	{
		ft_putendl("passe2");
		if ((line = (char**)malloc(sizeof(char*))) == NULL)
			return (-1);
	}
*/	if (*line != NULL)
	{
//		ft_putendl("passe3");
//		ft_putendl(*line);
		ft_strdel(line);
	}
	rep = ft_lecture(fd, line, &texte, 0);
	while (*line == NULL && rep > 0)
		rep = ft_lecture(fd, line, &texte, 0);
	if (rep == 0 && texte[0] != '\0')
	{
		*line = ft_strnew(ft_strlen(texte));
		ft_strncpy(*line, texte, ft_strlen(texte));
		rep = 1;
		ft_strdel(&texte);
	}
//			ft_putchar('[');
//			ft_putstr(texte);
//			ft_putendl("]");
	return (rep);
}
